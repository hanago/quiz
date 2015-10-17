#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int q4_maxSubArray_r(int A[], int n)
{
    if(n == 1)
        return A[0];
    else if(n == 2)
        return A[0] > A[1] ? A[0] : A[1];

    int mid = n/2, i, j;
    int leftSub_max, rightSub_max, temp;
    for(leftSub_max = 0, i = mid-1, temp = 0; i >= 0; i--) {
        temp += A[i];
        if(temp > leftSub_max)
            leftSub_max = temp;
    }
    for(rightSub_max = 0, i = mid+1, temp = 0; i < n; i++) {
        temp += A[i];
        if(temp > rightSub_max)
            rightSub_max = temp;
    }

    int left_max = q4_maxSubArray_r(A, mid);
    int right_max = q4_maxSubArray_r(A+mid+1, (n-1)/2);
    int mid_max = leftSub_max + A[mid] + rightSub_max;

    return (left_max > right_max && left_max > mid_max) ? left_max :
           (right_max> left_max  && right_max> mid_max) ? right_max: mid_max;
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
    int A[10000000+10], i=0;
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
    result = q4_maxSubArray_r(A,num);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);
    printf("size=%8d (%8d) execution time: %10lf\n",num ,result, cpu_time);

    return 0;
}
