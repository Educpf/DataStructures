#ifndef List_Queue_h
#define List_Queue_h


#include <iostream>
template<typename T>
class List_Queue {

    private:
    
        struct Node{
            T data;
            Node* next;
        };
        Node* front; // aka head;
        Node* rear;

    public:
        
        List_Queue () : front(nullptr), rear(nullptr){
        
        }
        bool Enqueue(T value){
            if (IsEmpty()){
                front = rear = new Node;
            }else {
                Node* added = new Node;
                rear->next = added;
                rear = added;
            } 
            rear->next = nullptr;
            rear->data = value;
            return true;
        }
        T Dequeue(){
            T value = T();
            if (IsEmpty()){
                std::cout << "Invalid: QUEUE is already empty\n";
            } else if (rear == front){
                value = rear->data;
                delete rear;
                rear = front = nullptr;
            } else {
                Node* del = front;
                value = del->data;
                front = front->next;
                delete del;
            }
            return value;
        }
        bool IsEmpty(){
            return (rear == nullptr && front == nullptr);
        }

};













#endif
