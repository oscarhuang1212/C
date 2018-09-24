#Stack

## Description

Creating stack structure and the operations for it. The size of the stack will be resize to double when the stack is full, and the size of the stack will be resize to half when the stack is half full.

##Structures

###stack

The stack structure include a pointer of integer: *data*, an integer of *size*, and a integer of *ptr*. The *data* is the initial address of the data in the stack. The *size* is the size of the stack. The *ptr* is the currend head location.

```
struct stack
{
    int* data;
    int size;
    int ptr;
}
```
##Functions
### display
Display current size of the stack *s*, and the elements remain in the stack *s*.

```void display(struct stack *s)```  
  
&nbsp;&nbsp;&nbsp;&nbsp;**s**: address of the stack  

###resize
Resize the stack *s*. When the stack is full, resize the stack to double. When the stack is half full, resize the stack to half.

```resize(struct stack* s, int count, int  op)```  
  
&nbsp;&nbsp;&nbsp;&nbsp;**s**: address of the stack  
&nbsp;&nbsp;&nbsp;&nbsp;**count**: push/pop count  
&nbsp;&nbsp;&nbsp;&nbsp;**op**: The operation is currently processing (See **Parameters**)   



### push
Push *push_count* elements from *push_input* to the stack *s*.
  
  ```push(struct stack* s, int* push_input, int push_count)```  
 
&nbsp;&nbsp;&nbsp;&nbsp;**s**: address of the stack  
&nbsp;&nbsp;&nbsp;&nbsp;**push_input**: the initial address of the input buffer  
&nbsp;&nbsp;&nbsp;&nbsp;**push_count**: the number of inputs to push into the stack
  

### pop
Pop *pop_count* elements from stack *s* to *pop_dest*. Return 1 while sucessfully pop elements from stack *s*, return 0 while not enough elements to be poped in the stack *s*.

  ```int  pop(struct stack* s, int* pop_dest, int pop_count)```  
  
&nbsp;&nbsp;&nbsp;&nbsp;**s**: address of the stack  
&nbsp;&nbsp;&nbsp;&nbsp;**pop_dest**: the initial address of the popped out elements  
&nbsp;&nbsp;&nbsp;&nbsp;**pop_count**: the number of elements to be popped


### head
Print the current head of the stack *s*.
  
```void head(struct stack* s);```  
&nbsp;&nbsp;&nbsp;&nbsp;**s**: address of the stack  

##Parameters
### STACK_OP_PUSH
Push operation is using.
### STACK_OP_POP
Pop operation is using
