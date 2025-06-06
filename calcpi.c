#include <stdio.h>
#include <omp.h>

static long num_steps = 1000000;
double step;
#define NUM_THREADS 4
int main ()
{
    double pi=0.0,sum[NUM_THREADS];int nthreads;
    step = 1.0/(double) num_steps;
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        int i,id,tthreads;
        double x;
        id = omp_get_thread_num();
        tthreads = omp_get_num_threads();
        if(id==0){
            nthreads=tthreads;
        }
        for(i=id,sum[id]=0.0;i<num_steps;i=i+tthreads){
            x = (i+0.5)*step;
            sum[id] += 4.0/(1.0+x*x);
        }
    }
    for(int i=0;i<nthreads;i++) {
        pi += sum[i]*step;    
    }
    printf("pi = %f\n",pi);
    return 0;
}

