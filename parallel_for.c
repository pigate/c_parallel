// gcc -o go parallel_for.c
// ./go

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 6

void *hello(void *x)
{
  int tid = *((int *)x);
  printf("Hello from thread %d\n", tid);
  return NULL;
}

int main(int argc, char *argv[])
{
  pthread_t threads[NTHREADS];
  int thread_args[NTHREADS];
  int rc, i;

  for(i = 0; i < NTHREADS; ++i)
  {
    printf("spawning thread %d\n", i);
    thread_args[i] = i;
    rc = pthread_create(&threads[i], NULL, hello, &thread_args[i]); 
  }

  for(i = 0; i < NTHREADS; ++i)
  {
    rc = pthread_join(threads[i], NULL);
  }
}
