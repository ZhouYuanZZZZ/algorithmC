
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define initSize 20

typedef struct{
    int* data;
    int maxSize,length;
} SeqList1;

typedef struct{
    int data[initSize];
    int length;
} SeqList2;

SeqList1* initSeqList1(){

    SeqList1* list = (SeqList1*)malloc(sizeof(SeqList1));
    list->data = (int *)malloc(sizeof(int));
    list->maxSize = initSize;
    list->length = 0;

    srand((unsigned)time(NULL));
    for (int i=0;i<10;i++){
        *(list->data+i) = rand()%10;
        list->length +=1;
    }

    return list;
}

void showArray(SeqList1* list){

    printf("[");
    for (int i = 0; i < list->length; i++) {
        printf("%d",*(list->data+i));
        printf(",");
    }
    printf("]");
    printf("\n");
}

void insertSeqList(SeqList1* list,int pos,int item){

    if(pos<1 || pos>list->length+1 ){
        printf("插入位置不合法");
    }

    if(list->length == list->maxSize){
        printf("表满,无法插入");
    }

    //移动元素
    for (int i = list->length; i >= pos-1 ; i--) {
        *(list->data+i) = *(list->data+i-1);
    }

    *(list->data+pos-1) = item;

    list->length++;
}

void deleteSeqList(SeqList1* list,int pos){

    if(pos<1||pos>list->length-1){
        printf("error position");
        return;
    }

    if(list->length == 0){
        printf("empty list");
        return;
    }

    //前移元素
    for (int i=pos;i<list->length;i++){
        *(list->data+i-1) = *(list->data+i);
    }

    list->length--;
}

int searchSeqList(SeqList1* list,int item){

    for(int i=0;i<list->length;i++){
        if(*(list->data+i) == item){
            return i;
        }
    }

    return -1;
}

int main111() {
    SeqList1 * list1 = initSeqList1();
    showArray(list1);

    //deleteSeqList(list1,10);
    //printf("\n");
    //showArray(list1);

    printf("%d",searchSeqList(list1,6));

    return 0;
}
