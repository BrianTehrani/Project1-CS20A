#pragma once
/*
 * Student.h
 *
 *  Do not change this header file.
 *  Just implement it in Student.cpp
 */
#include <string>
using namespace std;

class Student {
	int id;
	string name;
	string school;

public:
	/*
	 * Default ctor
	 */
	Student();

	/*
	 * Overloaded ctor
	 */
	Student(int id, string name, string school);

	/*
	 * Returns a string representation of a student object
	 * like "Caroline Greene,10537229,SMC"
	 */
	string toString();

	/*
	 * Compares two students by ID for equality
	 */
	bool operator == (const Student& other) const;

	/*
	 * Compares two students by ID for ordering
	 */
	bool operator < (const Student& other) const;

	virtual ~Student();
};

