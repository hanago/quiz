#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListNode {
    int key;
    struct ListNode* next;
} ListNode;

ListNode* q5_detectCycle_r(ListNode *head, ListNode *target, int precount)
{
    int count = 0;
    ListNode* cursor = head;

    if(head == head->next)
        return head;
    if(!target)
        return NULL;
    while((cursor) &&  (cursor != target)) {
        cursor = cursor->next;
        count++;
    }
    if(count < precount)
        return target;
    return q5_detectCycle_r(head, target->next, count);
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

    ListNode* head;
    ListNode* cursor;
    ListNode* begin;

    head = malloc(sizeof(ListNode));
    head->key = 1;
    head->next= malloc(sizeof(ListNode));

    cursor = head->next;
    cursor->key = 2;
    cursor->next = malloc(sizeof(ListNode));
    begin = head;

    cursor = cursor->next;
    cursor->key = 3;
    cursor->next = malloc(sizeof(ListNode));

    cursor = cursor->next;
    cursor->key = 4;
    cursor->next = malloc(sizeof(ListNode));

    cursor = cursor->next;
    cursor->key = 5;
    cursor->next = malloc(sizeof(ListNode));

    cursor = cursor->next;
    cursor->key = 6;
    cursor->next = begin;

    struct timespec start, end;
    double cpu_time = 0;
    clock_gettime(CLOCK_REALTIME, &start);
    cursor = q5_detectCycle_r(head,head,0);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);

    if(!cursor)
        printf("%s", "No cycle");
    else
        printf("Cycle begin at %d",cursor->key);
    printf(" execution time: %8lf\n", cpu_time);

    return 0;
}
