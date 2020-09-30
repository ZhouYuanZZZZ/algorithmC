#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <stdbool.h>//

typedef struct{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

LinkQueue * createLinkQueue(){
    LinkQueue * q = (LinkQueue *)malloc(sizeof(LinkQueue));
    q->front = NULL;
    q->rear = NULL;
    
    return q;
}

bool linkQueueIsEmpty(LinkQueue* queue){
    return (queue->rear == NULL)&&(queue->front == NULL);
}

void enLinkQueue(LinkQueue* q,int elem){

    LinkNode * node = (LinkNode*)malloc(sizeof(LinkNode));
    node->data = elem;
    node->next = NULL;

    if(q->rear == NULL){
        q->rear = node;
        q->front = q->rear;
    }else{
        q->rear->next = node;
        q->rear = node;
    }
}

int deLinkQueue(LinkQueue* queue){
    if(linkQueueIsEmpty(queue)){
        printf("queue empty");
        return -1;
    }

    LinkNode* p = queue->front;
    int x = p->data;

    queue->front = p->next;
    if(queue->front == NULL){
        queue->front = NULL;
        queue->rear = NULL;
    }

    free(p);

    return x;
}

int mainxxx(){

    LinkQueue *q = createLinkQueue();

    for (int i=0;i<35;i++){
        int elem = rand()%100;
        enLinkQueue(q,elem);
        printf("%d,",elem);

    }
    printf("\n");

    while (!linkQueueIsEmpty(q)){
        printf("%d,",deLinkQueue(q));
    }
    
    return 0;
}

