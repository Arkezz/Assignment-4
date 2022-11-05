// Assignment-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Employee.h"
#include "LinearHashTable.h"
#include "ChainHashTable.h"
using namespace std;

int main()
{
	//Create 9 employees
	Employee e1("Mina", 30, 10000, 4);
	Employee e2("Fawzy", 45, 5000, 8);
	Employee e3("Yara", 19, 2000, 0);
	Employee e4("Mariam", 32, 8000, 2);
	Employee e5("Ayman", 33, 4000, 8);
	Employee e6("Roshdy", 28, 9000, 3);
	Employee e7("Aya", 26, 6000, 3);
	Employee e8("Abdallah", 29, 7000, 4);
	Employee e9("Fatma", 21, 3000, 1);

	//Create a hash table
	LinearHashTable<string, Employee> l;
	ChainHashTable<string, Employee> c;
	//Fill the hash table
	l.insert(e1.getName(), e1); c.insert(e1.getName(), e1);
	l.insert(e2.getName(), e2); c.insert(e2.getName(), e2);
	l.insert(e3.getName(), e3);	c.insert(e3.getName(), e3);
	l.insert(e4.getName(), e4);	c.insert(e4.getName(), e4);
	l.insert(e5.getName(), e5);	c.insert(e5.getName(), e5);
	l.insert(e6.getName(), e6);	c.insert(e6.getName(), e6);
	l.insert(e7.getName(), e7);	c.insert(e7.getName(), e7);
	l.insert(e8.getName(), e8);	c.insert(e8.getName(), e8);
	l.insert(e9.getName(), e9);	c.insert(e9.getName(), e9);

	//Remove fatma from the hash table
	//l.remove("Fatma");
	//c.remove("Fatma");

	//Switch that allows the user to choose between linear probing and chaining
	int choice;
	cout << "Choose between linear probing and chaining" << endl;
	cout << "1- Linear Probing" << endl;
	cout << "2- Chaining" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		//Print the hash table
		l.print();
		l.collisionRate();
		break;
	case 2:
		//Print the hash table
		c.print();
		c.collisionRate();
		break;
	}
}