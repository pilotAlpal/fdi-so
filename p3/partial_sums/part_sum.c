#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int total_sum = 0;
pthread_mutex_t sum_mutex;

void * partial_sum(void * arg) {
  int j = 0;
  int ni=((int*)arg)[0];
  int nf=((int*)arg)[1];

  for (j = ni; j <= nf; j++){
	pthread_mutex_lock(&sum_mutex);
	total_sum = total_sum + j;
	pthread_mutex_unlock(&sum_mutex);
  }

  pthread_exit(0);
}

int main(void) {
  pthread_t th1, th2;
  pthread_mutex_init(&sum_mutex, NULL);
  int num1[2]={  1,   4999};
  int num2[2]={5000, 10000};

  /* create 3 threads with default attributes */
  pthread_create(&th1, NULL, partial_sum, (void*)num1);
  pthread_create(&th2, NULL, partial_sum, (void*)num2);

  printf("Main thread continues running\n");

  /* join created threads */
  pthread_join(th1, NULL);
  pthread_join(th2, NULL);

  printf("Total sum is: %d,  should be: 50005000\n", total_sum);

  return 0;
}
