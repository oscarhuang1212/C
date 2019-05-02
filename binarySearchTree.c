// File:    binarySearchTree.c
// Name:    Oscar Huang
// Desc:    Creating binary tree strcture and the binary tree operation functions.
//
// Operations:  Details in readme file
//              insert_node(struct node* root,int input)
//              search_key(struct node* root, int key)
//              inorder_display(struct node*root)
//              preorder_display(struct node*root)
//              postorder_display(struct node*root)


#include "stdio.h"
#include "stdlib.h"
#include <math.h>


struct node
{
    int value; 
    struct node* left_child;
    struct node* right_child;
};


struct node* insert_node(struct node* root,int input);
struct node* search_key(struct node* root, int key);
void inorder_display(struct node*root); // Left, Root, Right
void preorder_display(struct node*root); //Root, Left, Right
void postorder_display(struct node*root); // Left, Right, Root


int main(int argc, char *argv[])
{
    struct node* root = NULL;

    //insert 5 numbers into the bst
    root = insert_node(root,10);
    insert_node(root,5);
    insert_node(root,2);
    insert_node(root,7);
    insert_node(root,12);

    //search 2 numbers in the bst (one exist and another does not exist in the bst)
    search_key(root,6);
    search_key(root,2);

    //Using three traversals to display the bst
    printf("inorder_display: \n");
    inorder_display(root);
    printf("\n");

    printf("preorder_display: \n");
    preorder_display(root);
    printf("\n");

    printf("postorder_display: \n");
    postorder_display(root);
    printf("\n");

    return 0;
}


struct node* insert_node(struct node* root, int input){
    
    struct node* temp = calloc(1,sizeof(struct node));
    temp -> value = input;

    if(root == NULL)
        return temp;

    if(input < root->value)
        root->left_child = insert_node(root->left_child,input);
    else
        root->right_child = insert_node(root->right_child,input);

}

struct node* search_key(struct node* root, int key){

    struct node* temp = malloc(sizeof(struct node));
    temp = root;

    if(temp==NULL){
        printf("Could not find key %d \n", key);
        return NULL;
    }
    
    if(temp->value == key){
        printf("Found key %d \n", temp->value);
        return temp;
    }
    
    else if(key < temp->value)
        temp->left_child = search_key(temp->left_child,key);
    else
        temp->right_child = search_key(temp->right_child,key);
}

void inorder_display(struct node*root) // Left, Root, Right
{
    if(root == NULL)
        return;
    
    inorder_display(root->left_child);

    printf("%d ", root->value);

    inorder_display(root->right_child);

}
void preorder_display(struct node*root) //Root, Left, Right
{
    if(root == NULL)
        return;
    
    printf("%d ", root->value);
    preorder_display(root->left_child);
    preorder_display(root->right_child);
}

void postorder_display(struct node*root) // Left, Right, Root
{
    if(root == NULL)
        return;    

    postorder_display(root->left_child);
    postorder_display(root->right_child);
    printf("%d ", root->value);
}
