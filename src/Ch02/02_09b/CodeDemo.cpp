// Learning C++ 
// Exercise 02_09
// Strings, by Eduardo Corpeño 

#include <iostream>
#include <string>
#include <cstring>

int main(){
    const size_t LENGTH1 = 25;
    char array_str1[LENGTH1] = "Hey guys! ";
    char array_str2[LENGTH1] = "What't up?";

    std::string std_str1 = "Hi everyone! ";

    std::cout << strncat(array_str1, array_str2, LENGTH1) << std::endl; 
    std::cout << std_str1 + "How's the going?" << std::endl;

    std::cout << std::endl << std::endl;
    return (0);
}
