#include "records.h"
#include <iostream>
#include <fstream>

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

void StudentRecords::add_student(int sid, std::string sname){
    students.push_back(Student(sid, sname));
}

void StudentRecords::add_course(int cid, std::string cname, unsigned char ccredits){
    courses.push_back(Course(cid, cname, ccredits));
}

void StudentRecords::add_grade(int sid, int cid, char grade){
    grades.push_back(Grade(sid, cid, grade));
}

float StudentRecords::get_num_grade(char letter) const{
    float num_grd;          // float for the numeric grade
    switch (letter){
        case 'A': num_grd = 4.0f;
            break;
        case 'B': num_grd = 3.0f;
            break;
        case 'C': num_grd = 2.0f;
            break;
        case 'D': num_grd = 1.0f;
            break;
        default:  num_grd = 0.0f;
            break;
    };
    return num_grd;
}

std::string StudentRecords::get_student_name(int sid) const{
    int i = 0;
    while (i < students.size() && students[i].get_id() != sid)
        i++;
    return students[i].get_name();
}

unsigned char StudentRecords::get_course_credits(int cid) const{
    int j = 0;
    while (j < courses.size() && courses[j].get_id() != cid)
        j++;
    return courses[j].get_credits();
}

float StudentRecords::get_GPA(int sid) const{
    float points = 0.0f, credits = 0.0f;
    for (const Grade& grd : grades)
        if (grd.get_student_id() == sid){
            // calculate total credits and points
            unsigned char current_credits = get_course_credits(grd.get_course_id());
            credits += current_credits;
            points += get_num_grade(grd.get_grade()) * current_credits;
        }
    return (points / credits);
}

std::string StudentRecords::get_course_name(int cid) const{
    int j = 0;
    while (j < courses.size() && courses[j].get_id() != cid)
        j++;
    return courses[j].get_name();
}

void StudentRecords::report_card(int sid){
    std::ofstream outFile;
    outFile.open("report.txt");

    float points = 0.0f, credits = 0.0f;
    outFile << std::endl << "Report Card for " << get_student_name(sid) << std::endl;
    for (Grade& grd : grades)
        if (grd.get_student_id() == sid){
            outFile << get_course_name(grd.get_course_id()) << ": " << grd.get_grade() << std::endl;
            unsigned char current_credits = get_course_credits(grd.get_course_id());
            credits += current_credits;
            points += get_num_grade(grd.get_grade()) * current_credits;
        }
    outFile << "GPA: " << (points / credits) << std::endl;
    outFile.close();
}

void StudentRecords::read_files(){
    std::ifstream inFile;

    // Read student data
    inFile.open("students.txt");
    while (!inFile.eof()){
        std::string line;
        int id;
        std::string name;

        getline(inFile,line);
        id = std::stoi(line);
        getline(inFile,name);
        
        add_student(id,name);
    }
    inFile.close();

    // Read course data
    inFile.open("courses.txt");
    while (!inFile.eof()){
        std::string line;
        int id;
        std::string name;
        int credits;

        getline(inFile,line);
        id = std::stoi(line);
        getline(inFile,name);
        getline(inFile,line);
        credits = std::stoi(line);
        
        add_course(id,name,credits);
    }
    inFile.close();

    // Read grade data
    inFile.open("grades.txt");
    while (!inFile.eof()){
        std::string line;
        int sid;
        int cid;
        char grade;

        getline(inFile,line);
        sid = std::stoi(line);
        getline(inFile,line);
        cid = std::stoi(line);
        getline(inFile,line);
        grade = line[0];
        
        add_grade(sid,cid,grade);
    }
    inFile.close();
}
