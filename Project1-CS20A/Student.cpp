/*
* Implementations for the student.h functions
*
*/
#include "Student.h"

Student::Student(){ //setting members to arbitrary default values
	id = 00000000;
	name = "empty";
	school = "n/a";
}

Student::~Student() {

}

Student::Student(int id, string name, string school) {
	
	this->id = id;
	this->name = name;
	this->school = school;
}

string Student::toString(){

	return name + "," + to_string(id) + "," + school;

}

bool Student::operator ==(const Student& other) const {
	if (id == other.id)
		return true;
	return false;
}

bool Student::operator<(const Student & other) const
{
	if (id < other.id)
		return true;
	return false;
}

