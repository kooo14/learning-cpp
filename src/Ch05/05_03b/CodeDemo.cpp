// Learning C++ 
// Exercise 05_03
// Using Functions, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

int main(){
    int id;
    StudentRecords SR;

    SR.add_student(1, "George P. Burdell");
    SR.add_student(2, "Nancy Rhodes");

    SR.add_course(1, "Algebra", 5);
    SR.add_course(2, "Physics", 4);
    SR.add_course(3, "English", 3);
    SR.add_course(4, "Economics", 4);


    SR.add_grade(1, 1, 'B');
    SR.add_grade(1, 2, 'A'); 
    SR.add_grade(1, 3, 'C');
    SR.add_grade(2, 1, 'A'); 
    SR.add_grade(2, 2, 'A'); 
    SR.add_grade(2, 4, 'B');

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;


    std::string student_str = SR.get_student_name(id);
    std::cout << "The GPA for " << student_str << " is " << SR.get_GPA(id) << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
