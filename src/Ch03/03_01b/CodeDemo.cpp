// Learning C++ 
// Exercise 03_01
// Structures, by Eduardo Corpeño 

#include <iostream>
#include <string>

enum class cow_purpose {dairy, meat, hide, pet};

class cow
{   
private :
    std::string name;
    int age;
    cow_purpose purpose;
public:
    cow(std::string name_i, int age_i, cow_purpose purpose_i){
        name = name_i;
        age = age_i;
        purpose = purpose_i;
    }

    std::string get_name() const{
        return name;
    }
    int get_age() const {
        return age;
    }
    cow_purpose get_purpose() const{
        return purpose;
    }

    void set_age(int new_age){
        age = new_age;
    }
};

int main(){
    cow my_cow("Besty", 5, cow_purpose::meat);

    std::cout << my_cow.get_name() << "is " << my_cow.get_age() << " years old.";

    std::cout << std::endl << std::endl;
    return (0);
}
