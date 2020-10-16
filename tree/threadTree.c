#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct ThreadNode {
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

ThreadNode *createThreadNode(int data) {

    ThreadNode *node = (ThreadNode *) malloc(sizeof(ThreadNode));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    node->ltag = 0;
    node->rtag = 0;

    return node;

}

ThreadTree createThreadTree() {

    ThreadTree root = (ThreadTree) malloc(sizeof(ThreadNode));
    root->data = 0;

    ThreadNode *node1 = createThreadNode(1);
    ThreadNode *node2 = createThreadNode(2);
    ThreadNode *node3 = createThreadNode(3);
    ThreadNode *node4 = createThreadNode(4);
    ThreadNode *node5 = createThreadNode(5);
    ThreadNode *node6 = createThreadNode(6);
    ThreadNode *node7 = createThreadNode(7);

    root->lchild = node1;
    root->ltag = 0;

    root->rchild = node2;
    root->rtag = 0;

    node1->lchild = node3;
    node1->rchild = node4;

    node2->lchild = node5;
    node2->rchild = node6;

    node3->lchild = node7;

    return root;
}


void inThread(ThreadTree root, ThreadNode **pre) {
    if (root != NULL) {
        inThread(root->lchild, pre);

        if (root->lchild == NULL) {
            root->ltag = 1;
            root->lchild = *pre;
        }

        if ((*pre) != NULL && (*pre)->rchild == NULL) {
            (*pre)->rchild = root;
            (*pre)->rtag = 1;
        }
        (*pre) = root;

        inThread(root->rchild, pre);
    }
}

void processInThread(ThreadTree root) {

    ThreadNode *pre = NULL;
    ThreadNode **preNode = &pre;
    if (root != NULL) {
        inThread(root, preNode);
        (*preNode)->rchild = NULL;
        (*preNode)->rtag = 1;
    }
}

ThreadNode *firstNode(ThreadNode *p) {
    while (p->ltag == 0) {
        p = p->lchild;
    }
    return p;
}

ThreadNode *nextNode(ThreadNode *p) {
    if (p->rtag == 0) {
        return firstNode(p->rchild);
    }
    return p->rchild;
}

void inOrder(ThreadTree root) {
    ThreadNode *node = firstNode(root);
    while (node != NULL) {
        printf("%d ",node->data);
        node = nextNode(node);
    }
}

int main() {

    ThreadTree root = createThreadTree();
    processInThread(root);

    inOrder(root);

    return 0;
}