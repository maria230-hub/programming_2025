#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Student.hpp"

class Deanery {
private:
	std::string address;
	std::vector<Student> students;

public:
	Deanery(const Deanery&) = delete;
	Deanery& operator=(const Deanery&) = delete;

	Deanery(const std::string& addr);
	~Deanery();

	void attachStudent(const Student& student);
	bool removeStudent(const std::string& name, const std::string& surname);

	void printAllStudents() const;
	std::string getAddress() const;
};