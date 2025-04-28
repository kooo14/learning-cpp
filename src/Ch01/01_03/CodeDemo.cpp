// Learning C++ 
// Challenge 01_03
// Console Interaction, by Eduardo Corpeño 

#include <iostream>
#include <string>

int main(){
    std::cout << "Enter your name : ";
    std::string str;
    std::cin >> str;
    std::cout << "Your name is " << str << ". Nice to meet you!";



    std::cout << std::endl << std::endl;
    return (0);
}
