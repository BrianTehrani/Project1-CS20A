//============================================================================
// Name        : CS20AProj1.cpp
// Author      : Brian Tehrani
// Description : CS 20A Programming Project 1
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
//#include <ctime> 
#include <time.h>
#include "Student.h"
using namespace std;

/*
 * Read in a file containing student records and create an array of Student
 * objects
 *
 * @param file The filename
 * @param num The number of students in the file
 * @return An array of Student objects
 */
Student* readStudentsFromFile(string filename, int num) {
	ifstream studentsStream;
	studentsStream.open(filename.c_str());
	if (!studentsStream.is_open()) {
		cerr << "Couldn't open the file " << filename << endl;
		return NULL;
	}
	
	// getline(studentsStream, line); - you might find useful
	
	// YOUR CODE HERE
	int id = 0;
	string line, name, school;
	Student* studentArray = new Student[num];
	
	for (int i = 0; i < num; i++) {

		getline(studentsStream, line);

		name = line.substr(0, line.find_first_of(","));
		id = stoi(line.substr(line.find_first_of(",") + 1, line.find_last_of(",") - 1));
		school = line.substr(line.find_last_of(",") + 1, line.find("\n"));
		Student temp(id, name, school);
		studentArray[i] = temp;
	}

	return studentArray;
}

/*
 * Write an array of Student objects to a file
 *
 * @param students The array of Student objects to write out
 * @param filename The output filename
 */
void writeStudentsToFile(Student students[], int num, string filename) {
	ofstream output(filename.c_str());
	// can write to output just like you write to cout:  output<<...
	
	// YOUR CODE HERE
	for (int i = 0; i < num; i++) {
		output << students[i].toString() << endl;
	}
	output.close();
}

/*
 * Find students belonging to both groups.
 *
 * This function checks each student in group1 for membership in group2 by
 * comparing it with every student in group2.
 *
 * @param group1 A group of Students
 * @param group2 A group of Students
 * @param numCommon number of students belonging to both groups
 * @return An array of Students which belong to both group1 and group2
 */
Student* findCommonStudents1(Student group1[], int len1, Student group2[],
		int len2, int numCommon) {
	
	// YOUR CODE HERE
	
	Student* ucCommonStudent = new Student[numCommon];
	int k = 0;
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			
			if (group1[i] == group2[j]) {
				ucCommonStudent[k] = group1[i];
				k++;
			}
				
		}

	}
	return ucCommonStudent;
}

/*
 * Find students belonging to both groups.
 *
 * This function checks each student in group1 for membership in group2 by
 * doing a binary search on group2.
 *
 * @param group1 A group of Students
 * @param group2 A group of Students
 * @param numCommon number of students belonging to both groups
 * @return An array of Students which belong to both group1 and group2
 */
Student* findCommonStudents2(Student group1[], int len1, Student group2[],
		int len2, int numCommon) {
	
		/*
		 * library function to binary search an array for the given value
		 * Note that values must be comparable with the < operator
		 *
		 * bool found = binary_search(arr, arr + size, value);
		 */

  
  // YOUR CODE HERE	
	Student* commonStudents = new Student[numCommon];
	int k = 0;
	
	sort(group2, group2 + len2);

	
	for (int i = 0; i < len1; i++) {
		if (binary_search(group2, group2 + len2, group1[i]) == true) {
			commonStudents[k] = group1[i]; 
			k++;
		}		
	}
	return commonStudents;
}


int main() {

			/*
			 * DO NOT CHANGE ANY OF THE CODE BELOW
			 * Here just to help you with testing and timing your functions
			 */

	/***** These files provided to help you with initial testing *****/
	/*const int UC_SIZE = 10;
	const int SMC_SIZE = 5;
	const int SMC_UC_GRADS_SIZE = 2;
	Student* uc = readStudentsFromFile("sample_uc_students.txt", UC_SIZE);
	Student* smc = readStudentsFromFile("sample_smc_grads.txt", SMC_SIZE);
	*/
	/********************************** Use these files for the output you submit *************************/
	const int UC_SIZE = 350000;
	const int SMC_SIZE = 75000;
	const int SMC_UC_GRADS_SIZE = 25000;
	Student* uc = readStudentsFromFile("uc_students.txt", UC_SIZE);
	Student* smc = readStudentsFromFile("smc_grads.txt", SMC_SIZE);

	// Rough timing
	//clock_t start, end;
	time_t start, end;

	time(&start);

	Student* common1 = findCommonStudents1(uc, UC_SIZE, smc, SMC_SIZE,
			SMC_UC_GRADS_SIZE);
	time(&end);
	
	cout << "Using linear search it took " << difftime(end, start) << " seconds."
			<< endl;

	 // library sort function to sort an array: sort(arr, arr+size)
	 // Note that values must be comparable with the < operator
	 
	sort(common1, common1 + SMC_UC_GRADS_SIZE);
	writeStudentsToFile(common1, SMC_UC_GRADS_SIZE, "smc_grads_at_uc_1.txt");

	time(&start);
	Student* common2 = findCommonStudents2(uc, UC_SIZE, smc, SMC_SIZE,
			SMC_UC_GRADS_SIZE);
	time(&end);
	cout << "Using binary search it took " << difftime(end, start)
			<< " seconds." << endl;

	sort(common2, common2 + SMC_UC_GRADS_SIZE);
	writeStudentsToFile(common2, SMC_UC_GRADS_SIZE, "smc_grads_at_uc_2.txt");

	delete[] smc;
	delete[] uc;
	delete[] common1;
	delete[] common2;
	return 0;

}
