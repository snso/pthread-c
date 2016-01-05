#include "pthread.h"


//创建线程
pthread_t create_pthread(void *(*func)(void*),void *arg)
{
	pthread_t p_id;
	pthread_create(&p_id,NULL,func,arg);
	
	return p_id;
}
//线程挂起
Bool wait_pthread(pthread_t p_thread)
{
	if(pthread_join(p_thread,NULL) == 0)
	{
		return TRUE;
	}
	return FALSE;
}
//关闭线程
void exit_pthread()
{
	pthread_exit(NULL);
}


//初始化线程锁
pthread_mutex_t init_mutex()
{
	pthread_mutex_t p_thread;
	pthread_mutex_init(&p_thread,NULL);
	
	return p_thread;
	
}
//线程加锁
Bool lock_mutex(pthread_mutex_t *p_mutex)
{
	if(pthread_mutex_lock(p_mutex) == 0)
	{
		return TRUE;
	}
	return FALSE;
}
//线程解锁
Bool unlock_mutex(pthread_mutex_t *p_mutex)
{
	if(pthread_mutex_unlock(p_mutex) == 0)
	{
		return TRUE;
	}
	return FALSE;
}
//销毁锁
Bool destroy_mutex(pthread_mutex_t *p_mutex)
{
	if(pthread_mutex_destroy(p_mutex) == 0)
	{
		return TRUE;
	}
	return FALSE;
}


//信号量初始化
sem_t init_sem(int num)
{
	sem_t sem_id;
	sem_init(&sem_id,0,num);		//0 -- 表示不可在进程间共享		num -- 资源数
	return sem_id;
}
//获取资源
void gain_sem(sem_t *sem_id)
{
	sem_wait(sem_id);
}
//释放资源
void release_sem(sem_t *sem_id)
{
	sem_post(sem_id);
}
//获取信号量的值
int get_sem_value(sem_t *sem_id)
{
	int sem_num = 0;
	sem_getvalue(sem_id, &sem_num);
	return sem_num;
}
//销毁信号量
Bool destroy_sem(sem_t *sem_id)
{
	if(sem_destroy(sem_id) == 0)
	{
		return TRUE;
	}
	return FALSE;
}




