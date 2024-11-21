/* X on the earth, to find his accurate position on the globe werequire the value of Pi. Write a program to compute the value of pi function by NumericalIntegration 
using OpenMP PARALLEL section.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
int main() {
    int num,i;
    printf("Enter the number of steps : ");
    scanf("%d",&num);
    time_t st,et;
    st=clock();
    double step=1.0/(double)num,pi=0.0;
    omp_set_num_threads(omp_get_max_threads());
    #pragma omp parallel for reduction(+:pi)
    for(i=0;i<num;i++) {
        double x=(i+0.5)*step;
        double local_pi=(4.0*step)/(1+x*x);
        pi+=local_pi;
    }
    et=clock();
    printf("Time Taken : %lf\n",(double)((double)(et-st)/CLOCKS_PER_SEC));
    printf("Value of Pi = %.16lf\n",pi);
}

