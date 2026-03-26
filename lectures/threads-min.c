#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define N 1000 // array size
#define M 4 // num threads

struct thread_data {
  int tid;
  int size;
  int* array;
  int local_min;
};

void* compute_min(void* usrdata) {
  struct thread_data* data = (struct thread_data*) usrdata;
  
  int local_min = RAND_MAX;
  int start_offset = data->tid * data->size;

  for (int i = 0; i < data->size; i++) {
    int idx = start_offset + i;
    local_min = data->array[idx] < local_min? data->array[idx] : local_min; 
  }

  data->local_min = local_min;
  
  return NULL;
}

int main() {
  int array[N];

  srand(time(0));
  //init with random values
  int min_test = RAND_MAX;
  for (int i = 0; i < N; i++) {
    int val = rand();
    array[i] = val;
    //printf("%d %d\n", val, array[i]);
    min_test = array[i] < min_test? array[i] : min_test;
  }

  printf("The minimim value should be: %d\n", min_test);

  struct thread_data data[M];
  pthread_t threads[M];   
  for (int i = 0; i < M; i++) {
    data[i].tid = i;
    data[i].size = N/M; // assumes N % M = 0
    data[i].array = array;
    data[i].local_min = RAND_MAX;
    pthread_create(&(threads[i]), 0, compute_min, &(data[i]));
  }

  int global_min = RAND_MAX;
  for (int i = 0; i < M; i++) {
    pthread_join(threads[i], 0);
    global_min = data[i].local_min < global_min? 
      data[i].local_min : global_min;
  }

  printf("The minimim value is: %d\n", global_min);
}
