#include "pthread.h"


//�����߳�
pthread_t create_pthread(void *(*func)(void*),void *arg)
{
	pthread_t p_id;
	pthread_create(&p_id,NULL,func,arg);
	
	return p_id;
}
//�̹߳���
Bool wait_pthread(pthread_t p_thread)
{
	if(pthread_join(p_thread,NULL) == 0)
	{
		return TRUE;
	}
	return FALSE;
}
//�ر��߳�
void exit_pthread()
{
	pthread_exit(NULL);
}


//��ʼ���߳���
pthread_mutex_t init_mutex()
{
	pthread_mutex_t p_thread;
	pthread_mutex_init(&p_thread,NULL);
	
	return p_thread;
	
}
//�̼߳���
Bool lock_mutex(pthread_mutex_t *p_mutex)
{
	if(pthread_mutex_lock(p_mutex) == 0)
	{
		return TRUE;
	}
	return FALSE;
}
//�߳̽���
Bool unlock_mutex(pthread_mutex_t *p_mutex)
{
	if(pthread_mutex_unlock(p_mutex) == 0)
	{
		return TRUE;
	}
	return FALSE;
}
//������
Bool destroy_mutex(pthread_mutex_t *p_mutex)
{
	if(pthread_mutex_destroy(p_mutex) == 0)
	{
		return TRUE;
	}
	return FALSE;
}


//�ź�����ʼ��
sem_t init_sem(int num)
{
	sem_t sem_id;
	sem_init(&sem_id,0,num);		//0 -- ��ʾ�����ڽ��̼乲��		num -- ��Դ��
	return sem_id;
}
//��ȡ��Դ
void gain_sem(sem_t *sem_id)
{
	sem_wait(sem_id);
}
//�ͷ���Դ
void release_sem(sem_t *sem_id)
{
	sem_post(sem_id);
}
//��ȡ�ź�����ֵ
int get_sem_value(sem_t *sem_id)
{
	int sem_num = 0;
	sem_getvalue(sem_id, &sem_num);
	return sem_num;
}
//�����ź���
Bool destroy_sem(sem_t *sem_id)
{
	if(sem_destroy(sem_id) == 0)
	{
		return TRUE;
	}
	return FALSE;
}




