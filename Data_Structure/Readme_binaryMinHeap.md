#Binary Minimum Heap

## Description

Creating binary min heap strcture and the operation functions for the structure.

##Structures

###minHeap

The heap structure include an pointer of integer *heapList* and an integer *currentSize*. The *heapList* is the address of the head of the array that stores the keys. The *currentSize* is the number of the keys in the *heapList*

```
struct minHeap{
    int *heapList;
    int currentSize;
};
```


##Functions
### printHeap
Print all the keys in binary minimum heap *h*.  

```void printHeap(struct minHeap* h)```  
  
&nbsp;&nbsp;&nbsp;&nbsp;**h**: address of the binary minimum heap 


### heapInsert
Insert a key *key* into the binary minimum heap *h*.
  
  ```void heapInsert(struct minHeap* h, int key)```  
 
&nbsp;&nbsp;&nbsp;&nbsp;**h**: address of the binary minimum heap  
&nbsp;&nbsp;&nbsp;&nbsp;**key**: the key to insert to the binary minimum heap
  

### heapDelMin
Delete the minimum value(root) from the binary minimum heap *h*, and return the key of the minimum value.
  
  ```int heapDelMin(struct minHeap* h)```  

&nbsp;&nbsp;&nbsp;&nbsp;**h**: address of the binary minimum heap   

### percUp
Percolate from the index *index* upward to the root to the binary minimum heap *h*.
  
```void percUp(struct minHeap* h, int index)```  
  
&nbsp;&nbsp;&nbsp;&nbsp;**h**: address of the binary minimum heap
  
&nbsp;&nbsp;&nbsp;&nbsp;**index**: index of the percolation starts from

### percDown
Percolate from the index *index* downward to the point that the key of both children are smaller than the key at *index*.
  
```void percDown(struct minHeap* h, int index)```  
  
&nbsp;&nbsp;&nbsp;&nbsp;**h**: address of the binary minimum heap
  
&nbsp;&nbsp;&nbsp;&nbsp;**index**: index of the percolation starts from

### minChild
Return the index of the child with smaller key of index *index*. If there is only one child, retrun the index of the only child.
  
```int minChild(struct minHeap* h, int index)```  
  
&nbsp;&nbsp;&nbsp;&nbsp;**h**: address of the binary minimum heap
  
&nbsp;&nbsp;&nbsp;&nbsp;**index**: check the children of the key at *index*
