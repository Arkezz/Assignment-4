#pragma once
#include <string>
using namespace std;
class Employee {
private:
	string name;
	int age;
	int salary;
	int experience;
public:
	//Default Constructor
	Employee();
	//Parameterized Constructor
	Employee(string name, int age, int salary, int experience);
	//Setters and Getters
	void setName(string name);
	void setAge(int age);
	void setSalary(int salary);
	void setExperience(int experience);
	string getName() const;
	int getAge() const;
	int getSalary() const;
	int getExperience() const;
};
