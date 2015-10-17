#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* tree node */
typedef struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    int key;
} TreeNode;

void inorderTraversal(TreeNode *root)
{
    if(!root)
        return;
    inorderTraversal(root->left);
    printf("%d ",root->key);
    inorderTraversal(root->right);
}
void posorderTraversal(TreeNode *root)
{
    if(!root)
        return;
    posorderTraversal(root->left);
    posorderTraversal(root->right);
    printf("%d ",root->key);
}

void q3_flatten_r(TreeNode *root)
{
    if(!root)
        return;
    TreeNode* temp0;
    TreeNode* temp1;
    if(root->left) {
        temp0 = root->right;
        temp1 = root->left;
        while(temp1->right)
            temp1=temp1->right;
        root->right = root->left;
        root->left = NULL;
        temp1->right = temp0;
    }
    q3_flatten_r(root->right);
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
    TreeNode* root;
    TreeNode* cursor;

    root = malloc(sizeof(TreeNode));
    root->key = 1;
    root->left = malloc(sizeof(TreeNode));
    root->right= malloc(sizeof(TreeNode));

    cursor = root->left;
    cursor->key = 2;
    cursor->left = malloc(sizeof(TreeNode));
    cursor->right= malloc(sizeof(TreeNode));

    cursor = root->right;
    cursor->key = 5;
    cursor->left = NULL;
    cursor->right= malloc(sizeof(TreeNode));

    cursor = (root->left)->left;
    cursor->key = 3;
    cursor->left = NULL;
    cursor->right= NULL;

    cursor = (root->left)->right;
    cursor->key = 4;
    cursor->left = NULL;
    cursor->right= NULL;

    cursor = (root->right)->right;
    cursor->key = 6;
    cursor->left = malloc(sizeof(TreeNode));
    cursor->right= NULL;

    cursor = (cursor)->left;
    cursor->key = 7;
    cursor->left = NULL;
    cursor->right= NULL;


    printf("Before:\nInorder:");
    inorderTraversal(root);
    printf("\nPosorder:");
    posorderTraversal(root);
    printf("\n");

    struct timespec start, end;
    double cpu_time;
    clock_gettime(CLOCK_REALTIME, &start);
    q3_flatten_r(root);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);

    printf("After:\nInorder:");
    inorderTraversal(root);
    printf("\nPosorder:");
    posorderTraversal(root);
    printf("\n");
    printf("execution time: %8lf\n", cpu_time);

    free(root);
    return 0;
}
