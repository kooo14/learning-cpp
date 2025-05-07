// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

int main(){
    float GPA = 0.0f;
    int id;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    // Calculate the GPA for the selected student.
    // Write your code here

    std::string student_str;
    int total_credit = 0;
    student_str = "None";
    for(auto ts : students){
        if(ts.get_id() == id){
            student_str = ts.get_name();
            break;
        }
    }

    for(auto tg: grades){
        if(tg.get_student_id() == id){
            for(auto tc:courses){
                if(tc.get_id() == tg.get_course_id()){
                    GPA += tc.get_credits() * tg.get_grade_score();
                    total_credit += tc.get_credits();
                }
            }
        }
    }
    GPA /= total_credit;

    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
