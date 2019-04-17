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

Student::Student(int id, string name, string school) {
	
	this->id = id;
	this->name = name;
	this->school = school;

}



