#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    std::string surname;
    std::string direction;
    int course;
    int group;
    int variant;

public:
    //конструктор по умолчанию
    Student() {
        name = "Ilya";
        surname = "Rozanov";
        direction = "Unknown";
        course = 1;
        group = 1;
        variant = 1;
    }

    //конструктор полного заполнения
    Student(const std::string& n, const std::string& s, const std::string& d, int c, int g, int v) {
        name = n;
        surname = s;
        direction = d;
        set_group(g);
        set_course(c);
        set_variant(v);
    }

    //конструктор копирования
    Student(const Student& other) {
        if (this == &other) {
            std::cout << "Self-copy attempt detected!" << std::endl;
            // Инициализируем значениями по умолчанию
            name = "Default";
            surname = "Default";
            direction = "Unknown";
            course = 1;
            group = 1;
            variant = 1;
        }
        else {
            name = other.name;
            surname = other.surname;
            direction = other.direction;
            course = other.course;
            group = other.group;
            variant = other.variant;
        }
    }

    //деструктор
    ~Student() {
        std::cout << "all information about student deleted" << std::endl;
    }

    //геттеры
    std::string get_name() const { return name; }
    std::string get_surname() const { return surname; }
    std::string get_direction() const { return direction; }
    int get_course() const { return course; }
    int get_group() const { return group; }
    int get_variant() const { return variant; }

    //сеттеры на вариант,курс,группу
    void set_group(int gr) {
        if (gr < 1) {
            std::cout << "no groups like this" << std::endl;
            group = 1;
        }
        else if (gr > 10) {
            std::cout << "no groups like this" << std::endl;
            group = 10;
        }
        else {
            group = gr;
        }
    }

    void set_variant(int var) {
        if (var < 1) {
            std::cout << "no variants like this" << std::endl;
            variant = 1;
        }
        else {
            variant = var;
        }
    }

    void set_course(int c) {
        if (c < 1) {
            std::cout << "Course cannot be less than 1" << std::endl;
            course = 1;
        }
        else if (c > 4) {
            std::cout << "Course cannot be more than 4" << std::endl;
            course = 4;
        }
        else {
            course = c;
        }
    }

    // Метод для ввода с клавиатуры
    void inputfromkeyboard() {
        int temp;

        std::cout << "enter course number: ";
        std::cin >> temp;
        set_course(temp);
        std::cin.ignore(); // очистка буфера

        std::cout << "enter group number: ";
        std::cin >> temp;
        set_group(temp);
        std::cin.ignore();

        std::cout << "enter variant number: ";
        std::cin >> temp;
        set_variant(temp);
        std::cin.ignore();
    }

    //вывод всей информации о студенте
    void printInfo() const {
        std::cout << "Name:" << name << std::endl;
        std::cout << "Surname:" << surname << std::endl;
        std::cout << "Direction:" << direction << std::endl;
        std::cout << "Course:" << course << std::endl;
        std::cout << "Group:" << group << std::endl;
        std::cout << "Variant:" << variant << std::endl;
    }

    //перевод на след. курс
    void newCourse() {
        if (course < 4) {
            course++;
            std::cout << name << " " << surname << " on next course succesfully" << std::endl;
        }
        else {
            std::cout << "student is already in final course" << std::endl;
        }
    }
};

int main() {
    Student student1;
    student1.inputfromkeyboard();
    student1.printInfo();
    Student student2("Shane", "Hollander", "HZ", 5, 10, -1);
    std::cout << "Name:" << student2.get_name() << std::endl;
    std::cout << "Surname:" << student2.get_surname() << std::endl;
    std::cout << "Direction:" << student2.get_direction() << std::endl;
    std::cout << "Course:" << student2.get_course() << std::endl;
    std::cout << "Group:" << student2.get_group() << std::endl;
    std::cout << "Variant:" << student2.get_variant() << std::endl;
    Student student3 = student2;
    student3.printInfo();
    student3.newCourse();
    return 0;
}