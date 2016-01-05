#include "pthread.h"


pthread_mutex_t m_a;
sem_t s_t;
int num = 10;
void *func_a(void *fd)
{
//	lock_mutex(&m_a);
	int data = 10;
	while(data--)
	{
//		gain_sem(&s_t);
		printf("thread ----------A: %d\n",num++);
		usleep(2000);
//		release_sem(&s_t);
	}	
//	unlock_mutex(&m_a);
	
	exit_pthread();

}

void *func_b(void *fd)
{
//	lock_mutex(&m_a);
	int data = 10;
	while(data--)
	{
//		gain_sem(&s_t);
		printf("thread B: %d\n",num--);
		usleep(5000);
//		release_sem(&s_t);
	}
//	unlock_mutex(&m_a);

	exit_pthread();
}





int main()
{
	m_a = init_mutex();
	
	//–≈∫≈¡ø
	s_t = init_sem(10);
	

	pthread_t p_a = create_pthread(func_a,NULL);
	pthread_t p_b = create_pthread(func_b,NULL);
	
	
	wait_pthread(p_a);
	wait_pthread(p_b);
	
	destroy_mutex(&m_a);
	return 0;
}








