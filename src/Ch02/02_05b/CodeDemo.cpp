// Learning C++ 
// Exercise 02_05
// Type inference with auto, by Eduardo Corpeño 

#include <iostream>
#include <typeinfo>

int main(){
    auto a = 8;
    auto b = 123456789012;
    auto c = 3.24f;
    auto d = 32.1;
    auto e = true;
    auto f = 'd';
    auto g = "C++ rocks!";
    
    std::cout << "The type of a is " << typeid(a).name() << std::endl;

    std::cout << std::endl << std::endl;
    return (0);
}
