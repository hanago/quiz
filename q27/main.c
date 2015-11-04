#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Card {
    int color;
    int num;
} Card;

void swapCard(Card* cards, int m, int n)
{
    Card temp;
    temp.color = cards[m].color;
    temp.num = cards[m].num;

    cards[m].color = cards[n].color;
    cards[m].num = cards[n].num;

    cards[n].color = temp.color;
    cards[n].num = temp.num;
}

Card* randCards(Card* cards,int size)
{
    int i;

    srand((unsigned)time(NULL));
    for(i = 0; i < 40; i++)
        swapCard(cards,rand()%size,size-1);

}

void printCards(Card* cards, int size)
{
    int i;

    for(i = 0; i < size; i++)
        printf("%2d-%2d\t",cards[i].color,cards[i].num);
    printf("\n");
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


int main()
{
    /* generate a new card deck */
    int i,j;
    Card cards[52];
    for(i = 1; i <= 13; i++)
        for(j = 1; j <= 4; j++) {
            cards[i-1+(j-1)*13].color = j;
            cards[i-1+(j-1)*13].num = i;
        }

    /* swap cards */
    struct timespec start, end;
    double cpu_time = 0;
    clock_gettime(CLOCK_REALTIME, &start);
    randCards(cards,52);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);

    printCards(cards,52);
    printf("execution time: %8lf\n", cpu_time);

    return 0;
}
