


#ifndef Array_Queue_h
#define Array_Queue_h

#include <cstddef>
#include <iostream>
#include <stdexcept>
// this thisa thisano
template<typename T>
class ArrayQueue{

    private:
        size_t size;
        int front;
        int rear;
        T* array;

    public:

        // Destructors
        ~ArrayQueue(){
            delete[] array;
        }
        // Constuctors
        ArrayQueue(size_t n) : size(n), front(-1), rear(-1){
            array = new T[n]; 
        }
        ArrayQueue() : size(10), front(-1), rear(-1){
            array = new T[10]; 
        }
        
        bool Enqueue(T value){
            std::cout << "Added the value " << value << '\n'; 
            if ((int)((rear + 1)%size) == front){
                std::cout << "Sorry, Queue is already full\n";
                return false;
            } else if (IsEmpty()){
                rear = front = 0;
            } else {
                rear = (rear+1)%size;
            }
            array[rear] = value;
            return true;
        }


        T Dequeue(){
            T value = T();
            if (IsEmpty()){
                std::cout << "The Queue is already empty\n";
                return value;
            } else if (front == rear) {
                value = array[rear];
                front = rear = -1;
            } else {
                value = array[rear];
                front  = (front+1)%size;
            }
            return value;
        }
        T Front(){
            if (IsEmpty()) {
                std::cout << "The Queue is empty\n";
                throw std::length_error ("The QUEUE is Empty\n");
            } else {
                return array[rear];
            }
        }
        bool IsEmpty(){
            return (rear == -1 && front == -1);
        }





};





#endif
