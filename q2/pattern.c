#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000

int compare (const void * a, const void * b)
{
    return ( *(char*)a - *(char*)b );
}


int main(int argc, char *argv[])
{
    char a[10000000+10];
    int j;
    FILE* fp;
    int num = atoi(argv[1]);

    fp = fopen("pattern.txt","w");

    /* Generate test pattern */
    memset(a, '\0', MAXSIZE);
    for(j = 0; j < num; j++)
        a[j]= 65 + (rand() % 58);
    qsort(a, num, sizeof(a[0]), compare);
    fprintf(fp,"%s\n",a);
    fclose(fp);

    return 0;
}
