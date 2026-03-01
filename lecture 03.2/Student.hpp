#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

struct Application;

class Student {
private:
    std::string name;
    std::string surname;
    std::string direction;
    int course;
    int group;
    int variant;
    std::vector<std::string> debts;
public:
    Student();
    Student(const std::string& n, const std::string& s,const std::string& dir, int c, int g, int v, const std::vector<std::string>& d);
    ~Student();
    Student(const Student& other);
    Student& operator=(const Student& other);

    // перегрузка операторов
    Student operator+(const Student& other) const;
    Student& operator-=(const Student& other);
    Student operator/(const Student& other) const;

    // геттеры
    std::string get_name() const;
    std::string get_surname() const;
    std::string get_direction() const;
    int get_course() const;
    int get_group() const;
    int get_variant() const;
    std::vector<std::string> get_debts() const;

    // сеттеры
    void set_name(const std::string& n);
    void set_surname(const std::string& s);
    void set_direction(const std::string& dir);
    void set_course(int c);
    void set_group(int g);
    void set_variant(int v);
    void set_debts(const std::vector<std::string>& d);
    void add_debt(const std::string& debt);

    //новые методы для создания заявлений
    Application createApplicationForNextCourse() const;
    Application createApplicationForTransferGroup(int newGroup) const;

    // вспомогательные методы
    void printInfo() const;
    static std::vector<std::string> merge_debts(const std::vector<std::string>& d1,
        const std::vector<std::string>& d2);
    static std::vector<std::string> subtract_debts(const std::vector<std::string>& d1,
        const std::vector<std::string>& d2);
    static std::vector<std::string> common_debts(const std::vector<std::string>& d1,
        const std::vector<std::string>& d2);

private:
    static void remove_duplicates(std::vector<std::string>& debts);
};

struct Application {
    std::string studentName;
    std::string studentSurname;
    std::string statementType;
    std::string comment;
    int data;

    void PrintInfo() const {
        std::cout << "Student: " << studentName << studentSurname << std::endl;
        std::cout << "Statement type: " << statementType << std::endl;
        std::cout << "Comment: " << comment << std::endl;
        std::cout << "Data: " << data << std::endl;
    }
};