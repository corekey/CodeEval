#ifndef __PTHREAD_H
#define __PTHREAD_H

typedef unsigned pthread_t;

typedef struct pthread_attr_t {
} pthread_attr_t;

typedef enum __pthread_mutex_state_t {
	__MUTEX_DESTROYED = 0,
	__MUTEX_INITIALIZED
} __pthread_mutex_state_t;

typedef struct pthread_mutex_t {
	__pthread_mutex_state_t state;
	unsigned                count;
	unsigned                id;
} pthread_mutex_t;

#define PTHREAD_MUTEX_INITIALIZER { __MUTEX_INITIALIZED }

typedef struct pthread_mutexattr_t {
} pthread_mutexattr_t;

pthread_t pthread_self(void);

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg);

int pthread_join(pthread_t thread, void **retval);

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);

int pthread_mutex_destroy(pthread_mutex_t *mutex);

int pthread_mutex_lock(pthread_mutex_t *mutex);

int pthread_mutex_unlock(pthread_mutex_t *mutex);

void __astree_pthread_wrapper(void (*main)(void));

#endif
