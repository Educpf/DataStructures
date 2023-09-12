
#include "Linked_List.h"
#include <iostream>


void print(LinkedList<int>& list){
    for (int i : list){
        std::cout << i << ',';
    }
    std::cout << '\n';
}



int main(){

    
    LinkedList<int> list{1,2,3,4};
    print(list);
    LinkedList<int>::Const_Iterator cit = list.cbegin();
    std::cout << *cit << '\n';
    LinkedList<int>::Iterator it = list.begin();
    *it = 10;
    print(list);

    return 0;
}