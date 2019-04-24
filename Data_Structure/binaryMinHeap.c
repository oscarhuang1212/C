// File:    binaryMinHeap.c
// Name:    Oscar Huang
// Desc:    Creating binary min heap strcture and the operation functions for the structure.
//
// Operations:  Details in readme file
//              printHeap(struct minHeap* h)
//              percUp(struct minHeap* h, int index)
//              heapInsert(struct minHeap* h, int key)
//              minChild(struct minHeap* h, int index)
//              percDown(struct minHeap* h, int index)
//              heapDelMin(struct minHeap* h)

#include "stdio.h"
#include "stdlib.h"

struct minHeap{
    int *heapList;
    int currentSize;
};

void printHeap(struct minHeap* h){
    for(int i=1; i<=h->currentSize; i++)
        printf("%d ", h->heapList[i]);
        printf("\n");
};


void percUp(struct minHeap* h, int index){
    int temp;

    while(index/2>0){
        if(h->heapList[index]<h->heapList[index/2]){
            temp = h->heapList[index];
            h->heapList[index] = h->heapList[index/2];
            h->heapList[index/2] = temp;
        }
        index = index/2;
    }
};

void heapInsert(struct minHeap* h, int key){
    h->currentSize++;
    h->heapList[h->currentSize] = key;
    percUp(h,h->currentSize);
};

int minChild(struct minHeap* h, int index){
    if(index*2+1 > h->currentSize)
        return index *2;
    else{ 
        if(h->heapList[index*2+1] > h->heapList[index*2])
            return index*2;
        else
            return index*2+1;
        }
};

void percDown(struct minHeap* h, int index){
    int mc;
    int temp;

    while(index*2 < h->currentSize){
        mc = minChild(h,index); 
        if(h->heapList[index] > h->heapList[mc]){
            temp = h->heapList[index];
            h->heapList[index] = h->heapList[mc];
            h->heapList[mc] = temp;
            index = mc;
        }

    }

};

int heapDelMin(struct minHeap* h){
    int min = h->heapList[1];
    h->heapList[1] = h->heapList[h->currentSize];
    h->currentSize--;
    percDown(h,1);

    return min;
};


int main(int argc, char *argv[]){

    int maxHeapSize = 1024;

    struct minHeap* myHeap = malloc(sizeof(struct minHeap));
    myHeap->heapList = calloc(maxHeapSize , sizeof(int));
    myHeap->currentSize = 0;
    

    heapInsert(myHeap, 5);
    heapInsert(myHeap, 9);
    heapInsert(myHeap, 11);
    heapInsert(myHeap, 14);
    heapInsert(myHeap, 18);
    heapInsert(myHeap, 19);
    heapInsert(myHeap, 21);
    heapInsert(myHeap, 33);
    heapInsert(myHeap, 17);
    heapInsert(myHeap, 27);

  
    int min = heapDelMin(myHeap);
    printf("delete min: %d \n",min);

    min = heapDelMin(myHeap);
    printf("delete min: %d \n",min);

    printHeap(myHeap);

    return 0;
}



