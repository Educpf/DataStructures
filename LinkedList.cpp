#include <iostream>
#include <vector>

struct Node {
    int data;
    struct Node* link;
};

template<typename T>
class LinkedList {

public:
    LinkedList();
    LinkedList(int size, T value);
    LinkedList(std::vector<T>::iterator begin, std::vector<T>::iterator end);


private:
    Node* head;
};


int main(){


    return 0;
}