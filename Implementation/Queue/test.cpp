
#include "Array_Queue.h"
#include "List_Queue.h"
#include <string>


int main(){

    ArrayQueue<int> a1;
    ArrayQueue<std::string> a2(3);
    List_Queue<int> l1;
    
    a1.Enqueue(1);
    a1.Enqueue(2);
    std::cout << a1.Front() << '\n';
    std::cout << a1.Dequeue() << '\n';
    std::cout << a1.Dequeue() << '\n';
    std::cout << a1.Dequeue() << '\n'; // error should happen here
    std::cout << a1.Dequeue() << '\n';
    std::cout << "-----------------\n";
    a2.Enqueue("1");
    a2.Enqueue("2");
    a2.Enqueue("3");
    a2.Enqueue("4");
    std::cout << "----------------------\n";
    l1.Enqueue(1);
    l1.Enqueue(3);
    l1.Enqueue(4);
    l1.Enqueue(5);
    l1.Enqueue(5);
    l1.Enqueue(6);
    l1.Enqueue(7);
    l1.Enqueue(9);
    l1.Enqueue(8);
    l1.Enqueue(7);
    l1.Enqueue(12);
    l1.Enqueue(15);
    l1.Enqueue(6);
    l1.Enqueue(1);
    l1.Enqueue(10);
    l1.Enqueue(1);
    l1.Enqueue(12);
    l1.Enqueue(5);
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';
    std::cout << l1.Dequeue() << '\n';




    return 0;
}
