#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <stdbool.h>

# define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front,rear;
} CirculationQueue;

CirculationQueue * createCirculationQueue(){

    CirculationQueue* queue = (CirculationQueue*)malloc(sizeof(CirculationQueue));
    queue->rear = queue->front = 0;
}

bool isEmptyQueue(CirculationQueue* queue){
  return queue->front == queue->rear;
}

void enQueue(CirculationQueue* queue,int elem){

    if((queue->rear+1)%MAX_SIZE == queue->front){
        printf("queue maxsize");
        return;
    }

    queue->data[queue->rear] = elem;
    queue->rear = (queue->rear+1)%MAX_SIZE;
}

int deQueue(CirculationQueue* queue){
    if(isEmptyQueue(queue)){
        printf("queue empty");
        return -1;
    }

    int x = queue->data[queue->front];
    queue->front = (queue->front+1)%MAX_SIZE;

    return x;
}

int main2323(){

    CirculationQueue *q = createCirculationQueue();

    for (int i=0;i<MAX_SIZE-1;i++){
        int elem = rand()%100;
        enQueue(q,elem);
        printf("%d,",elem);

    }
    printf("\n");

    while (!isEmptyQueue(q)){
        printf("%d,",deQueue(q));
    }
    
    return 0;
}







