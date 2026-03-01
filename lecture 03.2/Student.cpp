#include "Student.hpp"

// студент по умолчанию
Student::Student() : name("Ilya"), surname("Rozanov"), direction("FIZMAT"), course(1), group(101), variant(1) {
    debts = std::vector<std::string>();
}

// конструктор с параметрами
Student::Student(const std::string& n, const std::string& s, const std::string& dir, int c, int g, int v, const std::vector<std::string>& d)
    : name(n), surname(s), direction(dir), course(c), group(g), variant(v), debts(d) {
    remove_duplicates(debts);
}

Student::~Student() {
    if (!debts.empty()) {
        debts.clear();
    }
    std::cout << "all information about this student deleted" << std::endl;
}

Student::Student(const Student& other) {
    name = other.name;
    surname = other.surname;
    direction = other.direction;
    course = other.course;
    group = other.group;
    variant = other.variant;
    debts = other.debts;
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        name = other.name;
        surname = other.surname;
        direction = other.direction;
        course = other.course;
        group = other.group;
        variant = other.variant;
        debts = other.debts;
    }
    return *this;
}

Student Student::operator+(const Student& other) const {
    std::string new_name = name + " and " + other.name;
    std::string new_surname = surname + " and " + other.surname;
    std::vector<std::string> new_debts = merge_debts(debts, other.debts);
    return Student(new_name, new_surname, "Unknown", 1, 1, 1, new_debts);
}

Student& Student::operator-=(const Student& other) {
    name = name + " without " + other.name;
    surname = surname + " without " + other.surname;
    debts = subtract_debts(debts, other.debts);
    return *this;
}

Student Student::operator/(const Student& other) const {
    std::string new_name = name + " and " + other.name;
    std::string new_surname = surname + " and " + other.surname;
    std::vector<std::string> new_debts = common_debts(debts, other.debts);
    return Student(new_name, new_surname,"Unknown", 1, 1, 1, new_debts);
}

std::string Student::get_name() const { return name; }
std::string Student::get_surname() const { return surname; }
std::string Student::get_direction() const { return direction; }
int Student::get_course() const { return course; }
int Student::get_group() const { return group; }
int Student::get_variant() const { return variant; }
std::vector<std::string> Student::get_debts() const { return debts; }

void Student::set_name(const std::string& n) { name = n; }
void Student::set_surname(const std::string& s) { surname = s; }
void Student::set_direction(const std::string& dir) { direction = dir; }
void Student::set_course(int c) { course = c; }
void Student::set_group(int g) { group = g; }
void Student::set_variant(int v) { variant = v; }

void Student::set_debts(const std::vector<std::string>& d) {
    debts = d;
    remove_duplicates(debts);
}

void Student::add_debt(const std::string& debt) {
    debts.push_back(debt);
    remove_duplicates(debts);
}

Application Student::createApplicationForNextCourse() const {
    Application app;
    app.studentName = name;
    app.studentSurname = surname;
    app.statementType = "course transfer";
    app.comment = "request to move to the next course";
    app.data = course + 1;
    return app;
}

Application Student::createApplicationForTransferGroup(int newGroup) const {
    Application app;
    app.studentName = name;
    app.studentSurname = surname;
    app.statementType = "group transfer ";
    app.comment = "request to change group ";
    app.data = newGroup;
    return app;
}

void Student::printInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Surname: " << surname << std::endl;
    std::cout << "Direction: " << direction << std::endl;
    std::cout << "Course: " << course << std::endl;
    std::cout << "Group: " << group << std::endl;
    std::cout << "Variant: " << variant << std::endl;
    std::cout << "Debts: ";
    if (debts.empty()) {
        std::cout << "No Debts" << std::endl;
    }
    else {
        for (size_t i = 0; i < debts.size(); ++i) {
            std::cout << debts[i];
            if (i != debts.size() - 1) {
                std::cout << " , ";
            }
        }
        std::cout << std::endl;
    }
}

// объединение долгов без повторений
std::vector<std::string> Student::merge_debts(const std::vector<std::string>& d1,
    const std::vector<std::string>& d2) {
    std::vector<std::string> result = d1;
    for (int i = 0; i < d2.size(); i++) {
        result.push_back(d2[i]);
    }
    remove_duplicates(result);
    return result;
}

// вычитание долгов
std::vector<std::string> Student::subtract_debts(const std::vector<std::string>& d1,
    const std::vector<std::string>& d2) {
    std::vector<std::string> result;
    std::set<std::string> d2_set;

    for (int i = 0; i < d2.size(); i++) {
        d2_set.insert(d2[i]);
        }
    for (int i = 0; i < d1.size(); i++) {
        if (d2_set.find(d1[i]) == d2_set.end()) {
            result.push_back(d1[i]);
        }
    }
    return result;
}

// общие долги
std::vector<std::string> Student::common_debts(const std::vector<std::string>& d1,
    const std::vector<std::string>& d2) {
    std::vector<std::string> result;
    std::set<std::string> d2_set;

    // set для учета уже добавленных общих долгов
    std::set<std::string> added;

    for (int i = 0; i < d1.size(); i++) {
        if (d2_set.find(d1[i]) != d2_set.end() && added.find(d1[i]) == added.end()){
            result.push_back(d1[i]);
            added.insert(d1[i]);
        }
    }
    return result;
}
void Student::remove_duplicates(std::vector<std::string>& debts) {
    std::set<std::string> unique_debts;
    std::vector<std::string> result;

    for (int i = 0; i < debts.size(); i++) {
        if (unique_debts.find(debts[i]) == unique_debts.end()) {
            unique_debts.insert(debts[i]);
            result.push_back(debts[i]);
        }
    }
    debts = result;
}