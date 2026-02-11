#include <iostream>
#include <vector>
#include <string>
#include "Student.h"

int main() {
    std::vector<std::string> debts1 = {"","",""};
    Student student1("Ilya", "Rozanov", debts1);
    student1.printInfo();

    std::vector<std::string> debts2 = {"Programming","History","Geometry"};
    Student student2("Shane", "Hollander", debts2);
    student2.printInfo();
    //долг 1 и 2
    Student student3 = student1 + student2;
    student3.printInfo();
    //долг 1 без 2
    Student student4 = student1;
    student4 -= student2;
    student4.printInfo();
    //общие долги
    Student student5 = student1 / student2;
    student5.printInfo();

    Student student6;
    student6 = student1;
    student6.printInfo();

    Student student7(student2);
    student7.printInfo();
    //с повторяющимися долгами
    std::vector<std::string> debts3 = {"English","English","Physics"};
    Student student8("Lee", "DongWook", debts3);
    student8.printInfo();
    //без долгов
    std::vector<std::string> debts4;
    Student student9("Wi", "HaJoon", debts4);
    student9.printInfo();

    return 0;
}