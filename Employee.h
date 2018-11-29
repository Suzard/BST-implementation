#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
//used to add a next operator
class Employee {
private:
	int key;
	string name;
public:
	Employee() { key = 0; name = ""; };
	//in case where we just want to search by id
	Employee(int init_key) { key = init_key; };
	//when we initialize the employee from reading the text file
	Employee(int init_key, string init_name) { key = init_key; name = init_name; };
	int returnKey() const { return key; };
	string returnName() const { return name; };
	void setKey(int new_key) { key = new_key; };
	void setName(string new_name) { name = new_name; };
};
#endif