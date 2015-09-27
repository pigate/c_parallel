// gcc -fopenmp -o go openmp_for.c
// ./go

#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv)
{
  int i, thread_id, nloops;
 
  //thread_id and nloops become each thread's private variables 
  #pragma omp parallel private(thread_id, nloops)
  {
    nloops = 0;
    thread_id = omp_get_thread_num();
   #pragma omp for
    for(i = 0; i < 1000000; ++i)
    {
      ++nloops; 
    }
    printf("Thread %d performed %d iterations of the loop.\n",
	thread_id, nloops);   
  } 
  return 0;
}
