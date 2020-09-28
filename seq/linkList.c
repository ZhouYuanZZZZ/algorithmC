#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *L;

L createLinkList() {

    L list = (L) malloc(sizeof(LNode));
    list->next = NULL;

    return list;
}

void showLinkList(L list) {

    printf("[");

    LNode *node = list;
    while (node->next != NULL) {
        printf("%d", node->next->data);
        printf(",");

        node = node->next;
    }

    printf("]");
    printf("\n");
}

void initLinkListHead(L list, int datas[],int size) {

    for (int i = 0; i < size; i++) {
        LNode *node = (LNode *) malloc(sizeof(LNode));
        node->next = list->next;
        node->data = datas[i];

        list->next = node;
    }
}

void initLinkListRear(L list, int datas[],int size){

    LNode * rear = list;
    for (int i = 0; i < size; i++) {

        //建立节点
        LNode *node = (LNode *) malloc(sizeof(LNode));
        node->next = NULL;
        node->data = datas[i];

        //插入元素
        rear->next = node;
        //后移节点
        rear = node;
    }
}

int main1100() {

    L list = createLinkList();

    int array[10] = {};
    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    //initLinkListHead(list,array,10);
    initLinkListRear(list,array,10);

    showLinkList(list);

    return 0;
}