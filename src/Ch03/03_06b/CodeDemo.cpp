// Learning C++ 
// Exercise 03_06
// Pointers, by Eduardo Corpeño 

#include <iostream>
#include <string>

int main(){
    int a = 37;
    int *ptr = &a;

    std::cout << a << std::endl;
    std::cout << ptr << std::endl;
    std::cout << &a << std::endl;
    std::cout << *ptr << std::endl;

    std::cout << std::endl << std::endl;
    return (0);
}
