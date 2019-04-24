// File:    linkedlist.c
// Name:    Oscar Huang
// Desc:    Creating linkedlist strcture and the linkedlist operation functions.
//
// Operations:  Details in readme file
//              display(struct lnklst* ll)
//              insert(struct lnklst* ll, int* input, int count, int direction)
//              delete_nodes(struct lnklst* ll, int count, int direction)
//              delete_first_key(struct lnklst* ll, int* delete_keys, int delete_count, int direction)
//              delete_all_key(struct lnklst* ll, int* delete_keys, int delete_count)
//              search_first(struct lnklst* ll, int *search_key, int search_count,int direction, struct node** search_result)
//              search_all(struct lnklst* ll, int *search_key, int search_count, struct node** search_result, int* result_count)
//


#include "stdio.h"
#include "stdlib.h"
#define DIRECTION_HEAD 0
#define DIRECTION_TAIL 1

struct node
{
    int value;
    struct node* next;
    struct node* prev;
};

struct lnklst
{
    struct node* head;
    struct node* tail;
    int count;
};


void display(struct lnklst* ll); 
void insert(struct lnklst* ll, int* input, int count, int direction);
void delete_node(struct lnklst* ll, struct node* n );
void delete_nodes(struct lnklst* ll, int count, int direction);
void delete_first_key(struct lnklst* ll, int* delete_keys, int delete_count, int direction);
void delete_all_key(struct lnklst* ll, int* delete_keys, int delete_count);
void search_first(struct lnklst* ll, int *search_key, int search_count,int direction, struct node** search_result);
void search_all(struct lnklst* ll, int *search_key, int search_count, struct node** search_result, int* result_count);


int main(int argc, char *argv[]){

    struct lnklst* lnklst= malloc(sizeof(struct lnklst));


    //insert 20 elements into the lnklst 
    int input_count=20;
    int* input = malloc(input_count*sizeof(int));
    for(int i=0; i<input_count;i++)
        input[i]=i*10;
    
    input[2]=10;
    input[4]=10;
    input[6]=10;
    input[8]=10;

    insert(lnklst,input,input_count,DIRECTION_TAIL);
    printf("Insert 20 elements:\n");
    display(lnklst);
    printf("\n");


    //Create keys for searching
    int search_count = 5;
    int* search_keys = malloc(search_count*sizeof(int));
    search_keys[0]=10;
    search_keys[1]=10;
    search_keys[2]=20;
    search_keys[3]=80;
    search_keys[4]=190;

    
    //Search_first 
    struct node** search_first_result = calloc(search_count,sizeof(struct node*));
    
    search_first(lnklst,search_keys,search_count,DIRECTION_HEAD,search_first_result);

    printf("Search_first Result: \n");
    for(int i=0; i<search_count; i++)
        if(search_first_result[i]!=NULL)
            printf("Found first element with value %d\n", search_first_result[i]->value);
                
        else
            printf("Could not find node with value %d\n", search_keys[i]);
    printf("\n");


    //Search_all
    struct node** search_all_result = calloc(search_count,sizeof(struct node*));
    int* search_all_result_count = calloc(search_count,sizeof(int));
    
    search_all(lnklst,search_keys,search_count,search_all_result,search_all_result_count);
    
    printf("Search_all Result: \n");
    for(int i=0; i<search_count; i++)
        if(search_all_result[i]!=NULL)
            printf("Found %d element with value %d \n", search_all_result_count[i],search_all_result[i]->value);
        else
            printf("Could not find node with value %d\n", search_keys[i]);
    printf("\n");


    //Create keys for deletion
    int delete_count = 5;
    int* delete_keys = malloc(delete_count*sizeof(int));
    delete_keys[0]=10;
    delete_keys[1]=10;
    delete_keys[2]=20;
    delete_keys[3]=80;
    delete_keys[4]=190;

    //delete_first_key
    delete_first_key(lnklst,delete_keys,delete_count,DIRECTION_HEAD);
    printf("List after delete_first_key:\n");
    display(lnklst);
    printf("\n");

    //delete_all_key
    delete_all_key(lnklst,delete_keys,delete_count);
    printf("List after delete_all_key:\n");
    display(lnklst);
    printf("\n");


    //delete_nodes
    delete_nodes(lnklst, 5 , DIRECTION_TAIL);
    printf("List after delete 5 keys from the tail:\n");
    display(lnklst);
    printf("\n");

    return 0;
}

void display(struct lnklst* ll)
{

    if(ll->count ==0)
    {
        printf("NULL list\n");
        return;
    }

    printf("Current list: ");
    struct node* temp = malloc(sizeof(struct node));
    temp = ll->head;

    while(1)
    {
        printf("%d ",temp->value);
        
        if(temp == ll->tail)
            break;

        temp = temp->next;
    }

    printf("\n");

    printf("Head: %d \n",ll->head->value);
    printf("Tail: %d \n",ll->tail->value);
    printf("Count: %d \n",ll->count);

}

void insert(struct lnklst* ll, int* input, int count, int direction)
{
    struct node* temp = calloc(1,sizeof(struct node));
    temp->value = *input;

    if(ll->head == NULL)
    {
        ll->head = temp;
        ll->tail = temp;
    }
    else{
        if(direction)
        {
            temp->prev = ll->tail;
            ll->tail->next = temp;
            ll->tail = temp;
        }
        else
        {
            temp->next = ll->head;
            ll->head->prev = temp;
            ll->head = temp;
        }
    }

    ll->count++;

    if(count!=1)
        insert(ll,input+1,count-1,direction);    
}


void delete_node(struct lnklst* ll, struct node* n){
    if(n != ll-> head)
        n->prev->next = n->next;
    if(n != ll->tail)
        n->next->prev = n->prev;

    if(n == ll->head)
        ll->head = n->next;
    else if(n == ll->tail)
        ll->tail = n->prev;

    ll->count--;
}

void delete_nodes(struct lnklst* ll, int delete_count, int direction){
    
    if(ll->count < delete_count)
    {
        printf("No enough nodes to delete. \nCurrent number of nodes: %d\nNodes you want to delete: %d\n",ll->count,delete_count);
        return;
    }
    
    for(int i=0; i<delete_count;i++)
        if(direction)
            delete_node(ll,ll->tail);
        else
            delete_node(ll,ll->head);     
}

void delete_first_key(struct lnklst* ll, int* delete_keys, int delete_count, int direction)
{
    struct node* temp = malloc(sizeof(struct node));


    struct node** search_result = malloc(delete_count*sizeof(struct node*));
    
    search_first(ll,delete_keys,delete_count,direction,search_result);

    for(int i=0; i<delete_count; i++)
    {
        if(search_result[i]!=NULL)
            if(search_result[i] == ll->head ?search_result[i]->next->prev==search_result[i]:search_result[i]->prev->next==search_result[i])
                delete_node(ll,search_result[i]);
    }


}


void delete_all_key(struct lnklst* ll, int* delete_keys, int delete_count)
{

    struct node* temp = malloc(sizeof(struct node));

    for(int i=0; i<delete_count;i++)
    {    
        temp = ll->head;
        while(temp != NULL)
        {
            if(temp->value == delete_keys[i])
                delete_node(ll,temp);
            temp = temp->next;
        }
    }
}


void search_first(struct lnklst* ll, int *search_key, int search_count,int direction, struct node** search_result)
{
 
    struct node* temp = malloc(sizeof(struct node));
    for(int i=0; i<search_count;i++)
    {
        temp = direction?ll->tail:ll->head;
        while(temp->value != search_key[i])
        {
            temp = direction?temp->prev:temp->next;

            if(temp==NULL)
                break;
        }

        if(temp == NULL)
            search_result[i] = NULL;
        else
        {
            search_result[i] = malloc(sizeof(struct node));
            search_result[i] = temp;
        }
    }
    
}

void search_all(struct lnklst* ll, int *search_key, int search_count, struct node** search_result, int* result_count)
{

    struct node* temp = malloc(sizeof(struct node));

    for(int i=0; i<search_count;i++)
    {    
        temp = ll->head;
        while(temp != NULL)
        {
            if(temp->value == search_key[i])
                {
                    result_count[i]++;
                    search_result[i] = realloc(search_result[i],result_count[i]*sizeof(struct node));
                    search_result[i][result_count[i]-1] = *temp;
                }
            temp = temp->next;
        }
    }
}
