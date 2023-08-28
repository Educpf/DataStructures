
#include "Linked_List.h"
#include <vector>



int main(){

    std::vector<int> vec =  {1, 2, 3, 4};
    std::cout << "Vector created\n";
    LinkedList obj;
    std::cout << "Obj created\n";
    LinkedList obj_list = {1, 2, 3, 4};
    std::cout << "ObjList created\n";
    LinkedList obj_vec(vec);
    std::cout << "Objvec created\n";
    LinkedList obj_cpy(obj);
    std::cout << "Initialization done!\n";
    obj.add(1);
    std::cout << "First addition done!\n";
    obj.add(2);
    std::cout << "2 addition done!\n";
    obj.add(3);
    std::cout << "3 addition done!\n";
    obj.add(4);
    std::cout << "4 addition done!\n";
    obj.Print();
    obj_list.Print();
    obj_vec.Print();
    obj_cpy.Print();
    std::cout << "Print completed\n";
    LinkedList obj_cpy2 = obj;
    obj_cpy2.Print();
    std::cout << "------------\n";
    obj.Clear();
    obj.Print();
    obj.Insert(0, 2);
    obj.Print();
    obj.Insert(2, 3);
    obj.Print();
    obj.Pop();
    std::cout << "Poped\n";
    obj.Print();
    std::cout << "----------------------\n";
    obj.add(3);
    obj.add(6);
    obj.Insert(2, 5);
    obj.Print();
    obj.Insert(0, 10);
    obj.Print();
    obj.ReverseIt();
    obj.Print();
    obj.ReverseRec();
    obj.Print();
    obj.Pop();
    obj.Print();
    obj.Concatonation(obj_list);
    obj.Print();
    std::cout << "---------------------\n";
    obj.Delete(0);
    obj.Print();
    obj.Delete(100);
    obj.Print();
    obj.Modification(0, 77);
    obj.Print();
    obj_cpy2.Print();
    obj.Slipt(5, obj_cpy2);
    obj.Print();
    obj_cpy2.Print();
    std::cout << "---------------------\n";
    std::cout << obj.at(0) << "\n";
    std::cout << obj.at(1)<< "\n";
    std::cout << obj.at(2)<< "\n";
    std::cout << obj.at(3)<< "\n";
    std::cout << obj[4]<< "\n";
    std::cout << obj[5]<< "\n";
    std::cout << obj[6]<< "\n";

    std::cout << "---------------------\n";
    return 0;
}