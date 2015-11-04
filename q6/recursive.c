#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListNode {
    int key;
    struct ListNode* next;
} ListNode;

void printList(ListNode* head)
{
    printf("%d",head->key);
    while(head->next) {
        head = head->next;
        printf(",%d",head->key);
    }
}

ListNode* q6_reverseBetween_r(ListNode *head, int m, int n, ListNode *cursor, ListNode *prenode)
{
    if(cursor) {
        if(cursor->key == m) {
            ListNode* tempnode = NULL;
            ListNode* posenode = NULL;
            /* make sure m is exist. */
            posenode = cursor->next;
            while(posenode && (posenode->key != n))
                posenode = posenode->next;
            if(!posenode)
                return head;
            posenode = cursor->next;
            /* reverse */
            while(posenode && (posenode->key != n)) {
                tempnode = posenode->next;
                posenode->next = cursor;
                cursor = posenode;
                posenode = tempnode;
            }

            if(posenode) {
                if(prenode) {
                    (prenode->next)->next = posenode->next;
                    prenode->next = posenode;
                } else
                    head->next = posenode->next;
                posenode->next = cursor;
                return prenode?head:posenode;
            }
            return head;
        }
        return q6_reverseBetween_r(head, m, n, cursor->next, cursor);
    }
    return head;
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

    head = malloc(sizeof(ListNode));
    head->key = 1;
    head->next= malloc(sizeof(ListNode));

    cursor = head->next;
    cursor->key = 2;
    cursor->next = malloc(sizeof(ListNode));

    cursor = cursor->next;
    cursor->key = 3;
    cursor->next = malloc(sizeof(ListNode));

    cursor = cursor->next;
    cursor->key = 4;
    cursor->next = malloc(sizeof(ListNode));

    cursor = cursor->next;
    cursor->key = 5;
    cursor->next = NULL;

    printf("Before:");
    printList(head);

    struct timespec start, end;
    double cpu_time = 0;
    clock_gettime(CLOCK_REALTIME, &start);
    head = q6_reverseBetween_r(head,2,4,head,NULL);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);


    printf("\nAfter:");
    printList(head);
    printf("\nexecution time: %8lf\n", cpu_time);

    return 0;
    return 0;
}
