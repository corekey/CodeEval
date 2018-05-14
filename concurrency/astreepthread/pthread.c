#include <pthread.h>

#define EAGAIN 11

#define LEN(x) (sizeof(x) / sizeof*(x))

#define NTHREADS 10
#define NMUTEXES 10

#define TID2MUTEX(x) ((x) * 2)
#define MID2MUTEX(x) ((x) * 2 + 1)

typedef void *pthread_func_t(void*);

typedef struct pthread_info_t {
	pthread_func_t *start;
	void           *arg;
	int             running;
	void           *retval;
} pthread_info_t;

static pthread_info_t pthread_infos[NTHREADS] = { 0 };
static unsigned       pthread_tid             = 0;
static unsigned       pthread_mid             = 0;

static int dummy_ctx;

pthread_t pthread_self(void)
{
	unsigned id;
	__astree_id_process(&id);
	return id;
}

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg)
{
	int res;
	__astree_lock_mutex(-1);
	if (pthread_tid < NTHREADS) {
		unsigned        id   = pthread_tid++;
		pthread_info_t *info = &pthread_infos[id];
		info->start   = start_routine;
		info->arg     = arg;
		info->running = 1;
		info->retval  = 0;
		res = 0;

		*thread = id;
	} else {
		res = EAGAIN;
	}
	__astree_unlock_mutex(-1);
	return res;
}

int pthread_join(pthread_t thread, void **retval)
{
	__astree_wait_process_stop(thread);
	__astree_lock_mutex(TID2MUTEX(thread));
	pthread_info_t *info = &pthread_infos[thread];
	if (retval)
		*retval = info->retval;
	return 0;
}

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)
{
}

int pthread_mutex_destroy(pthread_mutex_t *mutex)
{
	__astree_lock_mutex(mutex);
	if (mutex->count != 0)
		__ASTREE_alarm((raise_at_caller; invalid_usage_of_os_service; "destroying locked mutex"));
	__astree_unlock_mutex(mutex);
}

int pthread_mutex_lock(pthread_mutex_t *mutex)
{
	__astree_lock_mutex(mutex);
	if (mutex->count != 0)
		__ASTREE_alarm((raise_at_caller; invalid_usage_of_os_service; "locking already locked mutex"));
	++mutex->count;
	return 0;
}

int pthread_mutex_unlock(pthread_mutex_t *mutex)
{
	__astree_lock_mutex(mutex);
	if (mutex->count == 0) {
		__ASTREE_alarm((raise_at_caller; invalid_usage_of_os_service; "unlocking unlocked mutex"));
	} else {
		--mutex->count;
	}
	__astree_unlock_mutex(mutex);
	return 0;
}

static int volatile __astree_random;
__ASTREE_volatile_input((__astree_random));

void pthread_pool_func(void)
{
	while (__astree_random) {
		unsigned id;
		__astree_id_process(&id);

		pthread_info_t *info = &pthread_infos[id];
		__astree_lock_mutex(-1);
		pthread_func_t *start = info->start;
		void           *arg   = info->arg;
		__astree_unlock_mutex(-1);
		if (start) {
			__ASTREE_known_fact((arg != &dummy_ctx));
			__astree_lock_mutex(TID2MUTEX(id));
			void *res = start(arg);
			__astree_lock_mutex(-1);
			info->start   = 0;
			info->running = 0;
			info->retval  = res;
			__astree_unlock_mutex(-1);
			__astree_unlock_mutex(TID2MUTEX(id));
			__astree_stop_process(id);
		}
	}
}

void __astree_pthread_wrapper(void (*main)(void))
{
	__ASTREE_unroll((NTHREADS))
	for (unsigned i = 0; i < NTHREADS; ++i) {
		pthread_infos[i].arg = &dummy_ctx;
		__astree_create_process(&pthread_pool_func, i, 0);
		__astree_start_process(i);
	}

	__astree_create_process(main, -1, 0);
	__astree_start_process(-1);
}
