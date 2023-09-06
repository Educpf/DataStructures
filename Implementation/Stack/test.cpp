

#include <iostream>
#include "Stack.h"

int main(){


    Pure_Stack<int> s;

    s.push_back(1);
    s.push_back(3);
    s.push_back(6);
    s.push_back(8);
    std::cout << s.back() << '\n';




    return 0;
}
