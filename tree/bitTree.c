#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


BiTNode* createNode(int data){

    BiTNode *node = (BiTNode*)malloc(sizeof(BiTNode));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;

    return node;

}

BiTree createBiTree(){

    BiTree root = (BiTree)malloc(sizeof(BiTNode));
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

void visitNode(BiTree tree){
    if(tree != NULL){
        printf("%d,",tree->data);
    }
}

void preOrder(BiTree tree){
    if(tree !=NULL){
        visitNode(tree);
        preOrder(tree->lchild);
        preOrder(tree->rchild);
    }
}

void inOrder(BiTree tree){
    if(tree != NULL){
        inOrder(tree->lchild);
        visitNode(tree);
        inOrder(tree->rchild);
    }
}

void postOrder(BiTree tree){
    if(tree != NULL){
        postOrder(tree->lchild);
        postOrder(tree->rchild);
        visitNode(tree);
    }
}



int main(){
    BiTree tree =  createBiTree();
    //preOrder(tree);
    //inOrder(tree);
    postOrder(tree);
}