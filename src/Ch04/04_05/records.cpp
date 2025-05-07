#include "records.h"

Student::Student(int the_id, std::string the_name){
    id = the_id;
    name = the_name;
}
int Student::get_id() const{
    return id;
}
std::string Student::get_name() const{
    return name;
}

Course::Course(int the_id, std::string the_name, unsigned char the_credits){
    id = the_id;
    name = the_name;
    credits = the_credits;
}
int Course::get_id() const{
    return id;
}
std::string Course::get_name() const{
    return name;
}
int Course::get_credits() const{
    return credits;
}


Grade::Grade(int sid, int cid, char grd){
    student_id = sid;
    course_id = cid;
    grade = grd;
}
int Grade::get_student_id() const{
    return student_id;
}
int Grade::get_course_id() const{
    return course_id;
}
char Grade::get_grade() const{
    return grade;
}
int Grade::get_grade_score() const{
    int score = 0;
    switch (grade)
    {
    case 'A':
        score = 4;
        break;
    case 'B':
        score = 3;
        break;
    case 'C':
        score = 2;
        break;
    case 'D':
        score = 1;
        break;
    case 'F':
        score = 0;
        break;
    
    default:
        break;
    }

    return score;
}