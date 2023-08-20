#include "Linked_List.h"
#include <iostream>

LinkedList::LinkedList(){
    head = NULL;
    size = 0;
}
LinkedList::LinkedList(std::initializer_list<int> list){
    if (list.size() > 0){
        size = list.size();
        Node* prev_node= new Node;
        head = prev_node;
        auto it = list.begin();
        head->data = *it++;
        for (it; it != list.end(); it++){
            Node* folow_node = new Node;
            folow_node->data = *it;
            prev_node->next = folow_node;
            prev_node = folow_node;
    }
    prev_node->next = NULL;
    }
    
}
LinkedList::LinkedList(const std::vector<int>& vec){
    if (vec.size() > 0){
        size = vec.size();
        Node* prev_node = new Node;
        head = prev_node;
        auto it = vec.begin();
        head->data = *it++;
        for (it; it != vec.end(); it++){
            Node* currnt_node = new Node;
            currnt_node->data = *it;
            prev_node->next = currnt_node;
            prev_node = currnt_node;
        }
        prev_node->next = NULL;
    }
}
LinkedList::LinkedList(const LinkedList& linked_list){
    if (linked_list.size > 0){
        size = linked_list.size;
        Node* cpy_node = linked_list.head;
        Node* prev_node = new Node;
        prev_node->data = cpy_node->data;
        head = prev_node;
        for (size_t i=1; i < linked_list.size; i++){
            cpy_node = cpy_node->next;
            Node* currnt_node = new Node;
            currnt_node->data = cpy_node->data;
            prev_node->next = currnt_node;
            prev_node = currnt_node;
        }
        prev_node->next = NULL;
    }
}


// Changers
bool LinkedList::Insert(size_t idx, int value){
    if (idx < 0 || idx >= size) return false;
    size++;
    Node* new_node = new Node;
    new_node->data = value;
    if (idx == 0){
        new_node->next = head;
        head = new_node;
    } else {
        Node* node = head;
        for (size_t i=0; i<idx-1; i++){
            node = node->next;
        }
        Node* temp = node->next;
        node->next = new_node;
        new_node->next = temp; 
    }
    return true;
}

void LinkedList::Add(int value){
    Node* node = head;
    while (node->next != NULL){
        node = node->next;
    }
    node->next = new Node;
    node->next->data = value;
    node->next->next = NULL;
}

bool LinkedList::Delete(size_t idx){
    if (idx < 0 || idx >= size) return false;
    Node* node = head;
    for (size_t i =0; i<idx-1; i++){
        node = node->next;
    }
    Node* del_node = node->next;
    node->next = del_node->next;
    delete del_node;
    return true;
}


// Accesosrs

int LinkedList::at(size_t idx) const {
    if (idx < 0 || idx >= size) {
        std::cout << "Invalid number" << std::endl;
        return 0;
    }
    Node* node = new Node;
    for (idx; idx>0;idx--){
        node = node->next;
    }
    return node->data;
}

int LinkedList::operator [](size_t idx) const {
    return at(idx);
}

size_t LinkedList::get_size() const {
    return size;
}

// Transformations

void LinkedList::ReverseIt(){

}

void LinkedList::ReverseRec(){

}

void LinkedList::Print() const{

    Node* node = head;
    while (node->next!=NULL){
        std::cout << node->data << "->";
        node=node->next;
    }
    std::cout << "NULL\n";
}