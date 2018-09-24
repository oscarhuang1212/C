#Linked List

## Description

Creating a doubly linked list structure and the operations for it.

##Structures

###node

The node structure include a integer *value* and two node pointers: *next* and *prev*. The *next* is the address of the next node, and *prev* is the address of the previous node.

```  
struct node
{
    int value;
    struct node* next;
    struct node* prev;
}  
```  

  
###lnklst  
The lnklst structure include an integer *count* and two node pointers: *head* and *tail*. The *count* records the length of the linked list, and the two node pointers, *head* and *tail*, indicate the address of the head and the tail node of the linked list.

```  
struct lnklst
{
    struct node* head;
    struct node* tail;
    int count;
}  
```

##Functions
### display
Display the elements in linked list *ll*. Also  display the *head*, the *tail*, and the *count* of the list.   
  
```  
void display(struct lnklst* ll)``` 
  
&nbsp;&nbsp;&nbsp;&nbsp;**ll**: address of the linked list to display  

### insert
Insert *count* nodes with value from *input* to the linked list *ll*. Depends on the *direction*, the elements will be either linked to the head or the tail of the list on after another.
  
  ```void insert(struct lnklst* ll, int* input, int count, int direction)```  
 
&nbsp;&nbsp;&nbsp;&nbsp;**ll**: address of the linked list  
&nbsp;&nbsp;&nbsp;&nbsp;**input**: initial address of the input buffer  
&nbsp;&nbsp;&nbsp;&nbsp;**count**: number of elements to be inserted  
&nbsp;&nbsp;&nbsp;&nbsp;**direction**: inserting direction (see **Parameters**)  




### delete node
Remove single node *n* from the linked list *ll*.

  ```void delete_node(struct lnklst* ll, struct node* n )```  
 
&nbsp;&nbsp;&nbsp;&nbsp;**ll**: address of the linked list  
&nbsp;&nbsp;&nbsp;&nbsp;**n**: address of the node to be removed


### delete nodes
Remove *count* nodes from the linked list *ll*. Depends on the *direction*, the nodes be either removed from the head or the tail of the list.

  ```void delete_nodes(struct lnklst* ll, int count, int direction)```  
 
&nbsp;&nbsp;&nbsp;&nbsp;**ll**: address of the linked list  
&nbsp;&nbsp;&nbsp;&nbsp;**count**: number of elements to be deleted  
&nbsp;&nbsp;&nbsp;&nbsp;**direction**: deleting direction (see **Parameters**)  


### delete first key
Remove a node with value *delete_key* from the linked list *ll*. Depends on the *direction*, the first node counted from the head or the tail of the list will be removed.

  ```void delete_first_key(struct lnklst* ll, int* delete_keys, int delete_count, int direction)```  
 
&nbsp;&nbsp;&nbsp;&nbsp;**ll**: address of the linked list  
&nbsp;&nbsp;&nbsp;&nbsp;**delete_keys**: initial address of the deleting keys  
&nbsp;&nbsp;&nbsp;&nbsp;**delete_count**: number of elements in the delting keys  
&nbsp;&nbsp;&nbsp;&nbsp;**direction**: counting direction (see **Parameters**)  


### delete all key
Remove all nodes with value *delete_key* from the linked list *ll*.

  ```void delete_all_key(struct lnklst* ll, int* delete_keys, int delete_count)```  
 
&nbsp;&nbsp;&nbsp;&nbsp;**ll**: address of the linked list  
&nbsp;&nbsp;&nbsp;&nbsp;**delete_keys**: initial address of the deleting keys  
&nbsp;&nbsp;&nbsp;&nbsp;**delete_count**: number of elements in the deleting keys 


### search first
Search a node with value *search_key* in the linked list *ll*. Depends on the *direction*, the nodes will be counted from the head or the tail of the list.

  ```void search_first(struct lnklst* ll, int *search_key, int search_count,int direction, struct node** search_result)```  
 
&nbsp;&nbsp;&nbsp;&nbsp;**ll**: address of the linked list  
&nbsp;&nbsp;&nbsp;&nbsp;**search_key**: initial address of the searching keys  
&nbsp;&nbsp;&nbsp;&nbsp;**search_count**: number of elements in the searching keys  
&nbsp;&nbsp;&nbsp;&nbsp;**direction**: counting direction (see **Parameters**)  
&nbsp;&nbsp;&nbsp;&nbsp;**search_result**: initial address of the pointers that store the addresses of the searching results.  



### search all
Search all nodes with value *search_key* in the linked list *ll*.

  ```void search_all(struct lnklst* ll, int *search_key, int search_count, struct node** search_result, int* result_count)```  
 
&nbsp;&nbsp;&nbsp;&nbsp;**ll**: address of the linked list  
&nbsp;&nbsp;&nbsp;&nbsp;**search_key**: initial address of the searching keys  
&nbsp;&nbsp;&nbsp;&nbsp;**search_count**: number of elements in the searching keys  
&nbsp;&nbsp;&nbsp;&nbsp;**search_result**: initial address of the pointers that store the addresses of the searching results.  
&nbsp;&nbsp;&nbsp;&nbsp;**result_count**: initial address of the numbers of the elements found




##Parameters
### DIRECTION_HEAD
Insert / delete / search the node from the head of the list. 
### DIRECTION_TAIL
Insert / delete / search the node from the tail of the list. 




