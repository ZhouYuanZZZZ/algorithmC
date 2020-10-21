#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int binarySearch(int list[],int length,int elem){
    int mid;
    int low = 0;
    int high = length -1;

    while(low<=high){
        mid = (high - low)/2;

        if(elem == list[mid]){
            return mid;
        }

        //在前半部分查找
        if(elem < list[mid]){
            high = mid -1;
        }

        //在后半部分查找
        if(elem > list[mid]){
            low = mid + 1;
        }
    }

    return -1;
}

int main(){

    return 0;
}

