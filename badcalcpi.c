#include <stdio.h>
#include <omp.h>

int steps = 1000000;
int main(){
    int id,tthreads;
    double step = 1.0/(double) steps;
    double pi;
    double sum = 0.0;
    #pragma omp parallel
    {
        id = omp_get_thread_num();
        tthreads = omp_get_num_threads();
        for(int i=id; i<steps; i+=tthreads){
            double x = (i+0.5)*step;
            sum += 4.0/(1.0+x*x);
        }
    }
    pi = sum*step;
    printf("pi = %f\n",pi);
    return 0;
}