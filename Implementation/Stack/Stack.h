

#ifndef Stack_H
#define Stack_H

#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <string>

template <typename T>
class Pure_Stack{

    private:
        
        struct Node {
            T data;
            Node* next; 
        };

    private:

        Node* top;
        size_t tam;

    public:

        Pure_Stack(): top(nullptr), tam(0){
            std::cout << "Stack created!\n"; 
        };
        Pure_Stack(const std::initializer_list<T>& list):top(nullptr), tam(list.size){
            if (!empty()){
                for (const T& value : list){
                    push_back(value);
                }
            }
        }
        ~Pure_Stack(){
            std::cout << "Destructor called! On size " << tam << "\n";
            while (!empty()){
                pop_back();
            }
        }

        void push_back(T value) {
            tam++;
            Node* temp= top;
            top = new Node;
            top->data = value;
            top->next = temp;
            std::cout << "added value: " << value << "\n";
        }
        T pop_back(){
            if (!empty()){
                tam--;
                T value = top->data;
                Node* del = top;
                top = top->next;
                delete del;
                std::cout << "Poped " << value << "\n"; 
                return value;
            } else throw std::length_error("Stack already empty");
        }
        T back(){
            if (tam > 0) return top->data;
            else throw std::length_error("Stack already empty");
        }
        size_t size(){
            return tam;
        }
        bool empty(){
            return (tam == 0);
        }
        
};
#endif
