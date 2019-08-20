#pragma once
#include <iostream>


template <class T>
class bst{
    public:
        bst(): root_(nullptr){};

        class bstNode{
            public:
                bstNode *left, *right;
                T data;
            
                bstNode(): left(nullptr), right(nullptr) {};
                bstNode(const T &inputData): left(nullptr), right(nullptr), data(inputData){};
                ~bstNode(){};
                  
            private:

        };

        
        bstNode* createRoot(const T &inputData);
        bstNode* getRoot() {return root_;};

        bstNode* insertNode(bstNode* node, const T &inputData);
        bool searchNode(bstNode* node, const T &inputData);
        bstNode* deleteNode(bstNode* node, const T &key);
                   
        void printPreorder(bstNode* node);
        void printInorder(bstNode* node);
        void printPostorder(bstNode* node);
        bstNode* minKey(bstNode* node);
        ~bst(){
            while(root_!=nullptr)
                root_=deleteNode(root_,root_->data);
        }

    private:
        bstNode *root_;
        
};





template <typename T> 
typename bst<T>::bstNode* bst<T>::createRoot(const T &inputData){
    bstNode* newNode = new bstNode(inputData);
    root_ = newNode;
    return root_;
}

template <typename T> 
void bst<T>::printPreorder(bstNode* node){    
    if(node == nullptr){
        return;
    }
    std::cout<<node->data<<std::endl;
    printPreorder(node->left);
    printPreorder(node->right);
}
        

template <typename T> 
void bst<T>::printInorder(bstNode* node){    
    if(node == nullptr){
        return;
    }
    printInorder(node->left);
    std::cout<<node->data<<std::endl;
    printInorder(node->right);
}


template <typename T> 
void bst<T>::printPostorder(bstNode* node){    
    if(node == nullptr){
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    std::cout<<node->data<<std::endl;
}


template <typename T> 
typename bst<T>::bstNode* bst<T>::insertNode(bstNode* node, const T &inputData){

    if(node == nullptr) return new bstNode(inputData);

    if(inputData < node->data)
        node->left = insertNode(node->left, inputData);
    else
        node->right = insertNode(node->right, inputData);
    
    return node;
}



template <typename T> 
bool bst<T>::searchNode(bstNode* node, const T &inputData){

    bool result = false;

    if(node == nullptr)
        return false;

    if(inputData == node->data)
        return true;
    else if(inputData>node->data)
        result = searchNode(node->right, inputData);
    else
        result = searchNode(node->left,inputData);
    
    return result;
}

template <typename T>
typename bst<T>::bstNode* bst<T>::deleteNode(bstNode* node, const T &key){
    if(node == nullptr)
        return node;
    
    if(key < node->data)
        node->left = deleteNode(node->left,key);
    else if (key > node->data)
        node->right = deleteNode(node->right,key);

    else{
        if(node->left == nullptr){
            bstNode* temp = node->right;
            delete(node);
            return temp;
        }
        else if (node->right == nullptr){
            bstNode* temp = node->left;
            delete(node);
            return temp;
        }

    bstNode* temp = minKey(node->right);
    node->data = temp->data;
    node->right = deleteNode(node->right,temp->data);
    }
    return node;
}


template <typename T>
typename bst<T>::bstNode* bst<T>::minKey(bstNode* node){
    bstNode* temp = node;

    if(temp==nullptr)
        return temp;

    while(temp->left!= nullptr){
        temp = temp->left;
    }
    return temp;
}