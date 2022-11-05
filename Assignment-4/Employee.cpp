#include "Employee.h"

Employee::Employee() {
	name = "empty";
	age = 0;
	salary = 0;
	experience = 0;
}

Employee::Employee(string name, int age, int salary, int experience) {
	this->name = name;
	this->age = age;
	this->salary = salary;
	this->experience = experience;
}

void Employee::setName(string name) {
	this->name = name;
}

void Employee::setAge(int age) {
	this->age = age;
}

void Employee::setSalary(int salary) {
	this->salary = salary;
}

void Employee::setExperience(int experience) {
	this->experience = experience;
}

string Employee::getName() const {
	return name;
}

int Employee::getAge() const {
	return age;
}

int Employee::getSalary() const {
	return salary;
}

int Employee::getExperience() const {
	return experience;
}