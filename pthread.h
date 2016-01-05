#ifndef __PTHREAD__H
#define __PTHREAD__H

#include <stdio.h>		//标准输入输出
#include <string.h>		//字符串处理
#include <stdlib.h>		//标准库函数
#include <unistd.h>		//系统服务函数原型 数据结构
#include <errno.h>		//错误信息
#include <pthread.h>	//线程
#include <semaphore.h>	//信号量函数原型和数据结构定义


#define ERR(s) do{fprintf(stderr,"[%s--%d--%s--%s\n]",__FILE__,__LINE__,s,strerror(errno));}while(0)
	
typedef enum{FALSE,TRUE}Bool;


//创建线程
pthread_t create_pthread(void *(*func)(void*),void *arg);
//线程挂起
Bool wait_pthread(pthread_t p_thread);
//关闭线程
void exit_pthread();

//初始化线程锁
pthread_mutex_t init_mutex();
//线程加锁
Bool lock_mutex(pthread_mutex_t *p_mutex);
//线程解锁
Bool unlock_mutex(pthread_mutex_t *p_mutex);
//销毁锁
Bool destroy_mutex(pthread_mutex_t *p_mutex);

//信号量初始化
sem_t init_sem(int num);
//获取资源
void gain_sem(sem_t *sem_id);
//释放资源
void release_sem(sem_t *sem_id);
//获取信号量的值
int get_sem_value(sem_t *sem_id);
//销毁信号量
Bool destroy_sem(sem_t *sem_id);














#endif