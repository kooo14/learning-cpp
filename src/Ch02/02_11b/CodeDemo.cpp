// Learning C++ 
// Exercise 02_11
// Type Casting Examples, by Eduardo Corpeño 

#include <iostream>
#include <cstdint>

int main(){
    int fahrengeit = 100;
    int celsius = (5.0f / 9) * (fahrengeit - 32);

    std::cout << celsius;

    std::cout << std::endl << std::endl;
    return (0);
}
