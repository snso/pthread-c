#ifndef __PTHREAD__H
#define __PTHREAD__H

#include <stdio.h>		//��׼�������
#include <string.h>		//�ַ�������
#include <stdlib.h>		//��׼�⺯��
#include <unistd.h>		//ϵͳ������ԭ�� ���ݽṹ
#include <errno.h>		//������Ϣ
#include <pthread.h>	//�߳�
#include <semaphore.h>	//�ź�������ԭ�ͺ����ݽṹ����


#define ERR(s) do{fprintf(stderr,"[%s--%d--%s--%s\n]",__FILE__,__LINE__,s,strerror(errno));}while(0)
	
typedef enum{FALSE,TRUE}Bool;


//�����߳�
pthread_t create_pthread(void *(*func)(void*),void *arg);
//�̹߳���
Bool wait_pthread(pthread_t p_thread);
//�ر��߳�
void exit_pthread();

//��ʼ���߳���
pthread_mutex_t init_mutex();
//�̼߳���
Bool lock_mutex(pthread_mutex_t *p_mutex);
//�߳̽���
Bool unlock_mutex(pthread_mutex_t *p_mutex);
//������
Bool destroy_mutex(pthread_mutex_t *p_mutex);

//�ź�����ʼ��
sem_t init_sem(int num);
//��ȡ��Դ
void gain_sem(sem_t *sem_id);
//�ͷ���Դ
void release_sem(sem_t *sem_id);
//��ȡ�ź�����ֵ
int get_sem_value(sem_t *sem_id);
//�����ź���
Bool destroy_sem(sem_t *sem_id);














#endif