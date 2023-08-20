
#ifndef H_Linked_List
#define H_Linked_List

#include <initializer_list>
#include <vector>
#include <cstddef>


struct Node {
    int data;
    Node* next;
};


class LinkedList {

    public:
        // Constructors
        LinkedList();
        LinkedList(std::initializer_list<int> list);
        LinkedList(const std::vector<int>& vec);
        LinkedList(const LinkedList& linked_list);
        // Desconstructor
        ~LinkedList();
        // Changers
        bool Insert(size_t idx, int value);
        void Add(int value);
        bool Delete(size_t idx);
        // Accessors
        int at(size_t idx) const;
        int operator [](size_t idx) const;
        size_t get_size() const;
        // Transformations
        void ReverseIt();
        void ReverseRec();

        void Print() const;

    private:
        Node* head; 
        size_t size;   

};






#endif