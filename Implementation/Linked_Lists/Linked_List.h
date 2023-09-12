
#ifndef H_Linked_List
#define H_Linked_List

#include <initializer_list>
#include <vector>
#include <cstddef>
#include <iostream>

template <typename T>
class LinkedList;

template <class linked_list>
class ListIterator{
    private:

        using Category = std::forward_iterator_tag;
        using ValueType = typename linked_list::ValueType;
        using Distance = std::ptrdiff_t;
        using Pointer = ValueType*;
        using Reference = ValueType&;

        using Node_ptr = typename linked_list::Node*;

        
    public:
        // Constructors
        ListIterator():current(nullptr){};
        ListIterator(const Node_ptr& ptr) : current(ptr){}

    private:
        Node_ptr current;

    public:

        ListIterator& operator++(){
            if (current) current = current->next;
            return *this;
        }

        ListIterator operator++(int){
            ListIterator it = *this;
            ++(*this);
            return it;
        }

        bool operator!=(const ListIterator& other) const{
            return (current != other.current);
        }
        bool operator==(const ListIterator& other) const{
            return (current == other.current);
        }

        Reference operator*(){
            if (current) return current->data;
            throw std::out_of_range("Iterator is out of range.");
        }

        Pointer operator->(){
            return &operator*();
        }
};

template <typename T>
class LinkedList {
    private:
        struct Node {
            T data;
            Node* next;
        };

    public:

    using ValueType = T;
    using Iterator = ListIterator<LinkedList<T>>;
    using Const_Iterator = ListIterator<LinkedList<const T>>;
    friend class ListIterator<LinkedList<T>>;

    public:
        // Constructors
        LinkedList(): head(NULL), size(0){
            std::cout << "Default initializer\n";
        }

        LinkedList(std::initializer_list<T> list): head(NULL), size(0){
            std::cout << "Initializer list constructed\n";
            if (list.size() > 0){
                size = list.size();
                Node* prev_node= new Node;
                head = prev_node;
                auto it = list.begin();
                head->data = *it++;
                for (; it != list.end(); it++){
                    Node* folow_node = new Node;
                    folow_node->data = *it;
                    prev_node->next = folow_node;
                    prev_node = folow_node;
                }
            prev_node->next = NULL;
            }
        }
        
        LinkedList(const std::vector<T>& vec): head(NULL), size(0){
            std::cout << "Vec constructed\n";
            if (vec.size() > 0){
                size = vec.size();
                Node* prev_node = new Node;
                head = prev_node;
                auto it = vec.begin();
                head->data = *it++;
                for (; it != vec.end(); it++){
                    Node* currnt_node = new Node;
                    currnt_node->data = *it;
                    prev_node->next = currnt_node;
                    prev_node = currnt_node;
                }
                prev_node->next = NULL;
            }
        }
        
        LinkedList(const LinkedList<T>& linked_list) : head(NULL), size(0){
            std::cout << "Cpy constructor\n";
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
            }else{
                size=0;
                head=NULL;
            }
        }
        // Destructor
        ~LinkedList(){
            std::cout << "Destructor called\n";
            Node* node = head;
            while (node != NULL){
                Node* next = node->next;
                delete node;
                node = next;
            }
        }
        // Iterators
        Iterator begin(){
            return Iterator(head);
        }
        Iterator end(){
            return Iterator();
        }
        Const_Iterator cbegin(){
            return Const_Iterator(head);
        }
        Const_Iterator cend(){
            return Const_Iterator();
        }
        // Changers
        void Clear(){
            std::cout << "Cleared\n";
            Node* node = head;
            while(node != NULL){
                Node* next = node->next;
                delete node;
                node = next;
            }
            head = NULL;
            size = 0;
        }
        
        bool Insert(size_t idx, T value){
            if (idx < 0 || idx > size){
                std::cout << "Error inserting\n";
                return false;
            } 
            std::cout << "Inserted " << value << "at "<<idx<<"\n";
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
        
        void add(T value){
            std::cout << "Added value\n";
            size ++;
            if (head == NULL){
                head = new Node;
                head->data = value;
                head->next = NULL;
            }else
            {
                Node* node = head;
            while (node->next != NULL){
                node = node->next;
            }
            node->next = new Node;
            node->next->data = value;
            node->next->next = NULL;
            }
        }
        
        bool Delete(size_t idx){
            std::cout << "Deleted value\n";
            if (idx < 0 || idx >= size){
                std::cout << "Error: Invalid index!\n";
                return false;
            }
            size--;
            Node* del_node;
            if (idx == 0) {
                del_node = head;
                head = head->next;
            } else {
                Node* node = head;
                for (size_t i =0; i<idx-1; i++){
                    node = node->next;
                }
                Node* del_node = node->next;
                node->next = del_node->next;
            }
            delete del_node;
            return true;
        }
        
        T Pop(){
            if (size == 0){
                std::cout << "Impossible to pop, empty! \n";
                return 0;
            }
            std::cout << "Pooped\n";
            Node* last;
            if (size == 1){
                last = head;
                head = NULL;
            } else{
                Node* node = head;
                while (node->next->next != NULL){
                    node = node->next;
                }
                last = node->next;
                node->next = NULL;
            }
            size--;
            T ret = last->data;
            delete last;
            return ret;
        }
        
        bool Modification(size_t idx, T value){
            if (idx < 0 || idx >= size){
                std::cout << "Error: Invalid Index!";
                return false;
            } 
            std::cout << "Modification: value " << value << "Index" << idx << "\n";
            Node* node = head;
            for (; idx>0; idx--){
            node = node->next; 
            }
            node->data = value;
            return true;
        }
        
        void Concatonation(const LinkedList& second){
            std::cout << "Concatonated\n";
            size += second.size;
            if (size == 0) head = second.head;
            else {
                Node* node = head;
                while (node->next != NULL){
                    node=node->next;
                }
                Node* sec_node = second.head;
                while (sec_node != NULL){
                    Node* new_node = new Node;
                    new_node->data = sec_node->data;
                    node->next = new_node;
                    node = new_node;
                    sec_node = sec_node->next;
                }
                node->next = NULL;
            }
        }
        
        bool Slipt(size_t idx, LinkedList& second){
            if (idx <= 0 || idx >= size){
                std::cout << "Error: Invalid Index!\n";
                return false;
            }
            std::cout << "Slipt at index " << idx << '\n';
            second.Clear();
            second.size = size - idx;
            size = idx;
            Node* node = head;
            for (; idx>1;idx--){
                node = node->next;
            }
            second.head = node->next;
            node->next = NULL;
            return true; 
        }
        // Accessors
        T at(size_t idx) const {
            if (idx < 0 || idx >= size) {
                std::cout << "Invalid number" << std::endl;
                return 0;
            }
            Node* node = head;
            for (; idx>0;idx--){
                node = node->next;
            }
            return node->data;
        }
        
        T operator [](size_t idx) const {
            return at(idx);
        }
        
        size_t get_size() const {
            return size;
        }
        // Transformations
        void ReverseIt(){
            std::cout << "Reverse made\n";
            Node* prev, *current, *next;
            prev = NULL;
            current = head;
            while (current != NULL){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
        
        void ReverseRec(){
            std::cout << "Reverse made\n";
            RecursiveHelp(head);
        }

        void Print() const{
            std::cout << "Print:   ";
            if (size != 0) {
                Node* node = head;
                for (size_t i=0; i<size; i++){
                    std::cout << node->data << "->";
                    node=node->next;
                }
            }
            std::cout << "NULL\n";
        }

    private:
        Node* head; 
        size_t size;   

        void RecursiveHelp(Node* n){
            if (n->next == NULL){
                head = n;
                return;
            }
            RecursiveHelp(n->next);
            n->next->next = n;
            n->next = NULL;
        }

};



#endif
