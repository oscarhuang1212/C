// File:    stack.c
// Name:    Oscar Huang
// Desc:    Creating stack strcture and the stack operation functions.
//          The size of stack will be resize to double when the stack is full.
//          The size of stack will be resize to half when the stack is half full.
// Operations:  Details in readme file
//              display(struct stack *s)
//              resize(struct stack* s, int count, int  op)
//              push(struct stack *s, int* push_input, int push_count)
//              pop(struct stack *s, int* pop_dest, int pop_count)
//              head(struct stack *s)


#include "stdio.h"
#include "stdlib.h"
#define STACK_OP_PUSH 1
#define STACK_OP_POP 0


struct stack
{
    int* data;
    int size;
    int ptr;
};

void display(struct stack* s);
void resize(struct stack* s, int count, int  op);
void push(struct stack* s, int* push_input, int push_count);
int  pop(struct stack* s, int* pop_dest, int pop_count);
void head(struct stack* s);



void main(int argc, char *argv[]){

    struct stack*  s =  calloc(1,sizeof(struct stack));

    //pushing 50 elements into stack
    int push_count =50;
    int* push_input = malloc(push_count*sizeof(int));
    for(int i=0; i<push_count; i++)
        push_input[i]=i;
     push(s, push_input, push_count);

    //pop 20 elements from the stack
    int pop_count = 20;
    int* pop_dest = malloc(pop_count*sizeof(int));
    
    if(!pop(s,pop_dest,pop_count))
        return;
    printf("Popped elements: \n");
    for(int i=0; i<pop_count;i++)
    {
        printf("%d ", pop_dest[i]);
        if(i%20==19)
            printf("\n");
    }

    //display current stack
    printf("\n\n");    
    display(s);

    //display current head
    printf("\n\n");
     head(s);
    
    return ;
}


void display(struct stack *s)
{

    if(s->ptr == 0)
    {
        printf("Empty stack\n");
        return;
    }
    printf("Current size: %d \n",s->size);
    printf("Elements remain in the stack: \n");
    for(int i=0; i<s->ptr;i++)
    {
        printf("%d ",s->data[i]);
        if(i%20==19)
            printf("\n");
    }
    printf("\n");    

}

void resize(struct stack* s, int count, int  op)
{
    if( op == STACK_OP_PUSH)
        while(count+s->ptr >=s->size)
            s->size*=2;
    
    if( op == STACK_OP_POP)
        while(s->ptr <= s->size/2)
            s->size=s->size/2;
        
    s->data = realloc(s->data,s->size*sizeof(int));
    
}

void  push(struct stack* s, int* push_input, int push_count)
{
     
    if(s->data == NULL)
    {
        s->data = calloc(1,sizeof(int));
        s->size=1;

    }
    resize(s, push_count, STACK_OP_PUSH);
  
    for(int i=0; i<push_count;i++)
    {
        s->data[s->ptr] = push_input[i];
        s->ptr++;    
    }
  
}

int  pop(struct stack* s, int* pop_dest, int pop_count)
{

    if(pop_count>s->ptr)
    {
        printf("Not enough elements to pop. \nCurrent elements in the stack: %d\nElements you want to pop: %d\n",s->ptr,pop_count);
        return 0;
    }
    
    for(int i=0 ; i<pop_count; i++)
    {
        pop_dest[i] = s->data[s->ptr-1];
        s->ptr--;
    }
    
    if(s->ptr==0)
        s->size=1;
    else
        resize(s, pop_count, STACK_OP_POP);
    
    return 1;
}


void  head(struct stack* s)
{
    
        if(s->ptr == 0)
    {
        printf("Empty stack\n");
        return;
    }
    printf("Current head: %d\n", s->data[s->ptr-1]);

}