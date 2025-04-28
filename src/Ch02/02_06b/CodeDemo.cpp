// Learning C++ 
// Exercise 02_06
// Preprocessor directives, by Eduardo Corpeño 

#include <iostream>
#include <string>
#include <cstdint>

int main(){
    int32_t large = 5000;
    uint8_t small = 37;
    large += small;

    std::cout << "The value is " << large;
    std::cout << std::endl << std::endl;
    return (0);
}
