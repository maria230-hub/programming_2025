#include "Student.h"

// студент по умолчанию
Student::Student() : name("Ilya"), surname("Rozanov") {
    debts = std::vector<std::string>();
}

// конструктор с параметрами
Student::Student(const std::string& n, const std::string& s, const std::vector<std::string>& d)
    : name(n), surname(s), debts(d) {
    remove_duplicates(debts);
}

Student::~Student() {
    if (!debts.empty()) {
        debts.clear();
    }
    std::cout << "all information about student deleted" << std::endl;
}

Student::Student(const Student& other) {
    name = other.name;
    surname = other.surname;
    debts = other.debts;
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        name = other.name;
        surname = other.surname;
        debts = other.debts;
    }
    return *this;
}

Student Student::operator+(const Student& other) const {
    std::string new_name = name + " and " + other.name;
    std::string new_surname = surname + " and " + other.surname;
    std::vector<std::string> new_debts = merge_debts(debts, other.debts);
    return Student(new_name, new_surname, new_debts);
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
    return Student(new_name, new_surname, new_debts);
}

std::string Student::get_name() const { return name; }
std::string Student::get_surname() const { return surname; }
std::vector<std::string> Student::get_debts() const { return debts; }

void Student::set_name(const std::string& n) { name = n; }
void Student::set_surname(const std::string& s) { surname = s; }

void Student::set_debts(const std::vector<std::string>& d) {
    debts = d;
    remove_duplicates(debts);
}

void Student::add_debt(const std::string& debt) {
    debts.push_back(debt);
    remove_duplicates(debts);
}

void Student::printInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Surname: " << surname << std::endl;
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
    result.insert(result.end(), d2.begin(), d2.end());
    remove_duplicates(result);
    return result;
}

// вычитание долгов
std::vector<std::string> Student::subtract_debts(const std::vector<std::string>& d1,
    const std::vector<std::string>& d2) {
    std::vector<std::string> result;
    std::set<std::string> d2_set(d2.begin(), d2.end());

    for (const auto& debt : d1) {
        if (d2_set.find(debt) == d2_set.end()) { //!!! метод find возвращает итератор (лучше не юзать)
            result.push_back(debt);
        }
    }
    return result;
}

// общие долги
std::vector<std::string> Student::common_debts(const std::vector<std::string>& d1,
    const std::vector<std::string>& d2) {
    std::vector<std::string> result;
    std::set<std::string> d2_set(d2.begin(), d2.end());

    // set для учета уже добавленных общих долгов
    std::set<std::string> added;

    for (const auto& debt : d1) {
        if (d2_set.find(debt) != d2_set.end() && added.find(debt) == added.end()) {
            result.push_back(debt);
            added.insert(debt);
        }
    }
    return result;
}
void Student::remove_duplicates(std::vector<std::string>& debts) {
    std::set<std::string> unique_debts;
    std::vector<std::string> result;

    for (const auto& debt : debts) {
        if (unique_debts.find(debt) == unique_debts.end()) {
            unique_debts.insert(debt);
            result.push_back(debt);
        }
    }
    debts = result;
}