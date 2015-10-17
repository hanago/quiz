#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}


int main(int argc, char *argv[])
{
    int a[10000000+10];
    int j;
    FILE* fp;
    int num = atoi(argv[1]);

    fp = fopen("pattern.txt","w");

    /* Generate test pattern */
    memset(a, 0, MAXSIZE);
    for(j = 0; j < num; j++)
        fprintf(fp,"%d\n", rand() % 50 - 25);
    fclose(fp);

    return 0;
}
