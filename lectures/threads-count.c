#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>

static unsigned long long count = 0;

pthread_mutex_t mutex;

void *thread_count(void* args) {
  int myid, i;
  myid = *((int*) args); 
  printf("hello I'm thread %d\n", myid);
 
  int sum = 0;
  for(i = 0; i < 100000; i++) {
    sum++;
  }
  pthread_mutex_lock(&mutex);
  count += sum;
  pthread_mutex_unlock(&mutex);

  printf("goodbye I'm thread %d\n",myid);
  return (void *)0;
}

int main(int argc, char *argv[]) {
  pthread_t threads[4];
  int ids[4];
  int i = 0;

  pthread_mutex_init(&mutex, NULL);

  struct timeval tstart, tend;
  gettimeofday(&tstart, NULL);

  for (i = 0; i < 4; i++) {
    ids[i] = i;
    pthread_create(&threads[i], NULL, thread_count, &ids[i]); 
  }

  for (i = 0; i < 4; i++) {
    pthread_join(threads[i], NULL); 
  }
  printf("count = %llu\n", count);

  gettimeofday(&tend, NULL);
  float timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
  printf("count time is %g\n", timer);

  pthread_mutex_destroy(&mutex);

  return 0;
}

