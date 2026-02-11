#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

class Student {
private:
    std::string name;
    std::string surname;
    std::vector<std::string> debts;
public:
    Student();
    Student(const std::string& n, const std::string& s, const std::vector<std::string>& d);
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
    std::vector<std::string> get_debts() const;

    // сеттеры
    void set_name(const std::string& n);
    void set_surname(const std::string& s);
    void set_debts(const std::vector<std::string>& d);
    void add_debt(const std::string& debt);

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