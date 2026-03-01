#include <iostream>
#include <vector>
#include <string>
#include "Student.hpp"
#include "Deanery.hpp"
void printMyLabRate() {
    std::cout << "My lab num 3 experience: " << std::endl;
    std::cout << "Was it iteresting: yes" << std::endl;
    std::cout << "Fullness: 100%" << std::endl;
    std::cout << "Complexity: i'd rate this lab 6/10" << std::endl;
}
int main() {
    std::vector<std::string> debts1 = { "Krit Mishlenie", "Math" };
    Student student1("Ilya", "Rozanov", "IT", 2, 201, 5, debts1);

    std::vector<std::string> debts2 = { "Krit Mishlenie", "History" };
    debts2.push_back("Krit mishlenie");
    Student student2("Shane", "Hollander", "Physics", 1, 101,2, debts2);
    
    std::vector<std::string> debts3 = { "English" };
    Student student3("Lee", "DongWook", "Mathematics", 1, 101, 2, debts3);

    student1.printInfo();
    student2.printInfo();
    student3.printInfo();

    Application app1 = student1.createApplicationForNextCourse();
    std::cout << "Application from " << student1.get_name() << " " << student1.get_surname() << ":" << std::endl;
    app1.PrintInfo();

    Application app2 = student2.createApplicationForNextCourse();
    std::cout << "Application from " << student2.get_name() << " " << student2.get_surname() << ":" << std::endl;
    app2.PrintInfo();
    Deanery deanery("main building, room 101");
    deanery.attachStudent(student1);
    deanery.attachStudent(student2);
    deanery.attachStudent(student3);

    deanery.printAllStudents();
    deanery.removeStudent("Shane", "Hollander");
    deanery.printAllStudents();

    Student student4 = student1 + student2;
    student4.printInfo();

    printMyLabRate();

    return 0;
}