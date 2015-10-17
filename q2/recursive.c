#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100000
#define DICT_FILE "./pattern.txt"

char q2_smallest_character_r(char* str, char c, int lowerB, int upperB)
{
    if(lowerB > upperB)
        return NULL;

    int mid = lowerB + (upperB - lowerB) / 2;
    int diff = str[mid] - c;

    if(diff == 0 || (lowerB == upperB) || ((upperB -lowerB==1)&&diff<0))
        return str[mid];
    else if(diff > 0)
        return q2_smallest_character_r(str, c, lowerB, mid);
    else
        return q2_smallest_character_r(str, c, mid+1, upperB);
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
    int i, j;
    char c, result;
    struct timespec start, end;
    double cpu_time;
    FILE* fp;

    /* check file opening */
    char a[10000000+10];
    fp = fopen("pattern.txt", "r");
    if (fp == NULL) {
        printf("cannot open the file\n");
        return -1;
    }
    fscanf(fp,"%s\n",a);

    /* Find smallest character */
    c = 'z'+1;
    clock_gettime(CLOCK_REALTIME, &start);
    result = q2_smallest_character_r(a, c, 0, strlen(a)-1);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);
    printf("size=%8d (%c,%c) execution time: %10lf\n",strlen(a), c, result, cpu_time);


    return 0;
}
