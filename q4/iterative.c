#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int q4_maxSubArray_nr(int A[], int n)
{
    int temp, max, i, j, k;
    for(i = 0, max = 0; i < n; i++)
        for(j = i+1; j <= n; j++) {
            for(k = i, temp = 0; k < j; k++)
                temp += A[k];
            if(temp > max)
                max = temp;
        }
    return max;
}

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}


int main(int argc, char *argv[])
{
    /* check file opening */
    int A[1000000+10], i=0;
    FILE* fp;

    fp = fopen("pattern.txt", "r");
    if (fp == NULL) {
        printf("cannot open the file\n");
        return -1;
    }
    while(fscanf(fp,"%d\n",(A+(i++))) != EOF);

    /* Find Max sub-array */
    int result;
    int num = atoi(argv[1]);
    struct timespec start, end;
    double cpu_time;

    clock_gettime(CLOCK_REALTIME, &start);
    result = q4_maxSubArray_nr(A,num);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);
    printf("size=%8d (%8d) execution time: %10lf\n",num, result, cpu_time);

    return 0;
}
