#Binary Search Tree

## Description

Creating a binary search tree (BST) structure and the operations for it.

##Structures

###node

The node structure include an integer *value* and two node pointers: *left_child* and *right_child*. The *left_child* is the address of the left child node. The *right_child* is the address of the right child node.

```
struct node
{
    int value;
    struct node* left_child;
    struct node* right_child;
};
```


##Functions
### insert_node
Inserts a value *input* into the BST with root *root*. A pointer of a node with value *input* will be returned if the *root* is NULL.   
  

```struct node* insert_node(struct node* root,int input)```  
  
&nbsp;&nbsp;&nbsp;&nbsp;**root**: address of the root  
&nbsp;&nbsp;&nbsp;&nbsp;**input**: value to insert into the BST

### search_key
Searches the BST with root *root* for the value *key*. The node with value *key* will be returned if the node is found. NULL will be returned if could not find a node with value*key*.   
  
  ```struct node* search_key(struct node* root, int key)```  
 
&nbsp;&nbsp;&nbsp;&nbsp;**root**: address of the root  
&nbsp;&nbsp;&nbsp;&nbsp;**key**: the key to search in the BST
  

### inorder_display
Inorder traversal for the BST with root *root* and print out the value in each node  
  
  ```void inorder_display(struct node*root)```  
  
&nbsp;&nbsp;&nbsp;&nbsp;**root**: address of the root  
### preorder_display
Preorder traversal for the BST with root *root* and print out the value in each node  
  
```void preorder_display(struct node*root)```  
  
&nbsp;&nbsp;&nbsp;&nbsp;**root**: address of the root  
### postorder_display
Postorder traversal for the BST with root *root* and print out the value in each node  
  
```void postorder_display(struct node*root)```  
  
&nbsp;&nbsp;&nbsp;&nbsp;**root**: address of the root  
