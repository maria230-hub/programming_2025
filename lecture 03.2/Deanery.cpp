#include "Deanery.hpp"
#include <iostream>

Deanery::Deanery(const std::string& addr) : address(addr) {
	std::cout << "Deanery created at: " << address << std::endl;
}
Deanery::~Deanery() {
	std::cout << "Deanery at" << address << "is being destroyed" << std::endl;
}

void Deanery::attachStudent(const Student& student) {
		students.push_back(student);
		std::cout << "Student " << student.get_name() << " " << student.get_surname() << "attached to deanery" << std::endl;
}

bool Deanery::removeStudent(const std::string& name, const std::string& surname) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].get_name() == name && students[i].get_surname() == surname) {
			std::cout << "Removing student " << students[i].get_name() << " " << students[i].get_surname() << std::endl;
			for (int j = i; j < students.size() - 1; j++) {
				students[j] = students[j + 1];
			}
			students.pop_back();
			return true;
		}

	}
	std::cout << " Student " << name << " " << surname << std::endl;
	return false;
} 

void Deanery::printAllStudents() const {
	std::cout << "List of students in deanery: " << address << std::endl;
	if (students.size() == 0) {
		std::cout << " No students attached to deanery " << std::endl;
	}
	else {
		for (int i = 0; i < students.size(); i++) {
			students[i].printInfo();
		}
	}
}
std::string Deanery::getAddress() const {
	return address;
}