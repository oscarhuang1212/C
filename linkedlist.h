#pragma once
#include <iostream>


template <class T>
class linklist{
    public:
        //constructor of the linkedlist, set the default head and tail to nullptr
        linklist(): head_(nullptr), tail_(nullptr) {};

        class linklistNode{
            public:
                linklistNode *next, *prev;
                T data;
                
                //constructor of the nodes in the linkedlist.
                linklistNode(): next(nullptr), prev(nullptr){};
                linklistNode(const T &inputData): next(nullptr), prev(nullptr), data(inputData){};
                
                
            private:

        };

        linklistNode* getHeadPtr() {return head_;}
        linklistNode* getTailPtr() {return tail_;}

        linklistNode* pushFront(const T &inputData);
        linklistNode* pushBack(const T &inputData);
        linklistNode* popFront();
        linklistNode* popBack();
        
        ~linklist(){
            linklistNode *curr = head_;

            while(curr != nullptr){
                linklistNode* toDelete = curr;
                curr = curr->next;
                delete toDelete;
                toDelete = nullptr;
            }
            head_= nullptr;
        };

                   
        void printlist();

    private:
        linklistNode *head_, *tail_;
};


template <typename T> 
void linklist<T>::printlist(){
    //Check if the linklist is empty
    if(head_ == nullptr){
        std::cout<<"Null Linked List is being printed"<<std::endl;
        return ;
    }

    linklistNode* temp = getHeadPtr();
    while(temp!=nullptr){
        std::cout<<temp->data<<" ";
        temp = temp -> next;
    }
    std::cout<<std::endl;
}
        

template <typename T> 
typename linklist<T>::linklistNode* linklist<T>::pushFront(const T &inputData){
    linklistNode* temp = new linklistNode(inputData);
    
    if(head_ == nullptr){
        head_ = temp;
        tail_ = temp;    
    }
    else{
        head_ -> prev = temp;
        temp  -> next = head_;
        head_ = temp;
    }
    return head_;
}

template <typename T> 
typename linklist<T>::linklistNode* linklist<T>::pushBack(const T &inputData){
    linklistNode* temp = new linklistNode(inputData);
    
    if(head_ == nullptr){
        head_ = temp;
        tail_ = temp;    
    }
    else{
        tail_ -> next = temp;
        temp  -> prev = tail_;
        tail_ = temp;
    }
    return head_;
}



template <typename T> 
typename linklist<T>::linklistNode* linklist<T>::popFront(){
    if(head_==nullptr) return head_;

    if(head_->next == nullptr){
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
    }

    linklistNode* temp = head_;

    head_ = head_->next;
    head_ -> prev = nullptr;
    delete temp;
    temp = nullptr;

}


template <typename T> 
typename linklist<T>::linklistNode* linklist<T>::popBack(){
    if(tail_==nullptr) return head_;

    if(tail_->prev == nullptr){
        delete tail_;
        head_ = nullptr;
        tail_ = nullptr;
    }

    linklistNode* temp = tail_;

    tail_ = tail_->prev;
    tail_ -> next = nullptr;
    delete temp;
    temp = nullptr;

}
