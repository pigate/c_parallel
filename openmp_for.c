// gcc -fopenmp -o go openmp_for.c
// ./go

#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv)
{
  int i, thread_id;
  int glob_nloops, priv_nloops;
  glob_nloops = 0;

  //parallelize this chunk of code 
  //thread_id and priv_nloops become each thread's private variables 
  //reduce directive. synchronizes access to glob_nloops 
  #pragma omp parallel private(thread_id, priv_nloops) reduction(+:glob_nloops)
  {
    priv_nloops = 0;
    thread_id = omp_get_thread_num();

   //parallelize this for loop (every thread gets a chunk)
   #pragma omp for
    for(i = 0; i < 1000000; ++i)
    {
      ++priv_nloops; 
    }
    glob_nloops += priv_nloops;
    
    //"critical" code section for updating a global variable
    //only one thread can enter at a time
    #pragma omp critical
    {
      printf("Thread %d is adding its iterations (%d) to sum (%d), ",
      	thread_id, priv_nloops, glob_nloops);
      printf("total loops is now %d.\n", glob_nloops);
    } 
  } 
  printf("Total # loop iterations is %d\n",
      glob_nloops);
  return 0;
}
