#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void insertNode(BiTree tree, int data) {

    //二叉树为空 插入元素为根节点
    if (tree == NULL) {

        tree = (BiTree) malloc(sizeof(BiTNode));
        tree->data = data;
        tree->rchild = NULL;
        tree->lchild = NULL;

        return;
    }

    //出现相同元素 返回
    if (tree->data == data) {
        return;
    }

    //插入左子树
    if (data < tree->data) {
        insertNode(tree->lchild, data);
    }

    //插入右子树
    if (data > tree->data) {
        insertNode(tree->rchild, data);
    }
}

BiTNode *searchNode1(BiTree tree, int data) {

    if (tree == NULL) {
        return NULL;
    }

    if (tree->data == data) {
        return tree;
    }

    //查找左子树
    if (data < tree->data) {
        return searchNode1(tree->lchild, data);
    }
    //查找右子树
    if (data > tree->data) {
        return searchNode1(tree->rchild, data);
    }

}

BiTNode *searchNode2(BiTree tree, int data) {

    BiTNode *p = tree;
    if (p == NULL) {
        return NULL;
    }

    while (p != NULL) {
        if (p->data == data) {
            return p;
        }

        if (data < p->data) {
            p = p->lchild;
        }
        if (data > p->data) {
            p = p->rchild;
        }
    }

    return NULL;
}

void deleteNode(BiTree tree, int data) {

    //查找关键字为data的待删除节点
}

int main() {

    BiTree tree = NULL;

    srand((unsigned) time(NULL));
    for (int i = 0; i < 10; i++) {
        int data = rand() % 10;
        if (i == 0) {
            tree = (BiTree) malloc(sizeof(BiTNode));
            tree->data = data;
            tree->lchild = NULL;
            tree->rchild = NULL;
        }

        insertNode(tree, data);
    }

    return 0;
}