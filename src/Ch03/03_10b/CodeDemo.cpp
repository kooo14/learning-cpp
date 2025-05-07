// Learning C++ 
// Exercise 03_10
// Using Objects with Vectors, by Eduardo Corpeño 

#include <vector>
#include <iostream>
#include <string>
#include "cow.h"

int main(){
    std::vector<cow> cattle;

    cattle.push_back(cow("Betty",6,cow_purpose::meat));
    cattle.push_back(cow("Libby",7,cow_purpose::hide));

    std::cout << (cattle.end() - 1)->get_age();

    std::cout << std::endl << std::endl;
    return (0);
}
