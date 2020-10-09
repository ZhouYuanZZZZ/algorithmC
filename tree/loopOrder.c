# define MAX_SIZE 50

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct {
    BiTNode *data[MAX_SIZE];
    int top;
} SeqStack;


SeqStack *createStack() {
    SeqStack *stack = (SeqStack *) malloc(sizeof(SeqStack));

    stack->top = -1;

    return stack;
}

bool isEmpty(SeqStack *stack) {

    return stack->top == -1;
}

void push(SeqStack *stack, BiTNode *elem) {

    if (stack->top == MAX_SIZE - 1) {
        printf("stack overflow");
        return;
    }

    stack->data[++stack->top] = elem;
}

BiTNode *pop(SeqStack *stack) {

    if (isEmpty(stack)) {
        printf("stack empty");
    }

    return stack->data[stack->top--];
}

BiTNode *createNode(int data) {

    BiTNode *node = (BiTNode *) malloc(sizeof(BiTNode));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;

    return node;

}

BiTree createBiTree() {

    BiTree root = (BiTree) malloc(sizeof(BiTNode));
    root->data = 0;

    BiTNode *node1 = createNode(1);
    BiTNode *node2 = createNode(2);
    BiTNode *node3 = createNode(3);
    BiTNode *node4 = createNode(4);
    BiTNode *node5 = createNode(5);
    BiTNode *node6 = createNode(6);
    BiTNode *node7 = createNode(7);

    root->lchild = node1;
    root->rchild = node2;

    node1->lchild = node3;
    node1->rchild = node4;

    node2->lchild = node5;
    node2->rchild = node6;

    node3->lchild = node7;

    return root;
}

void visitNode(BiTree tree) {
    if (tree != NULL) {
        printf("%d,", tree->data);
    }
}

void inOrder(BiTree tree) {

    SeqStack *stack = createStack();
    BiTNode *p = tree;

    while (!isEmpty(stack) || p != NULL) {
        
        if(p!=NULL){
            push(stack,p);
            p = p->lchild;
            continue;
        }

        p = pop(stack);
        visitNode(p);
        p = p->rchild;
    }
}

void preOrder(BiTree tree){
    SeqStack *stack = createStack();
    BiTNode *p = tree;

    while (!isEmpty(stack) || p != NULL) {

        if(p!=NULL){
            visitNode(p);

            push(stack,p);
            p = p->lchild;
            continue;
        }

        p = pop(stack);
        p = p->rchild;
    }
}

int main(){
    BiTree tree = createBiTree();
    preOrder(tree);
    return 0;
}


