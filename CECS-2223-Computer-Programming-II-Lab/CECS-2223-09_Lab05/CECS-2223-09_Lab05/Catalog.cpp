/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023
* Date: Ovtober 10, 2023
* Topic: Lab 6 - Composition and Dynamic Memory
* File name: Catalog.cpp
* This file declares a class named Catalog
* Complete the declaration as required.
* Name: Aleysha M. Rivera Cores, ID# 108408
* Name: Coral S. Schmidt Montilla, ID# 148830
*/
#include "Catalog.h"
Catalog::Catalog() {
	universityName = "";
	courseCount = 0;
	courses = nullptr;
}
Catalog::Catalog(const Catalog& other) {
	universityName = other.universityName;
	courseCount = other.courseCount;
	// Allocate memory for the courses array
	courses = new Course * [courseCount];
	// Deep copy the courses
	for (int i = 0; i < courseCount; i++) {
		courses[i] = new Course(*(other.courses[i]));
	}
}
Catalog::~Catalog() {
	for (int i = 0; i < courseCount; i++) {
		delete courses[i]; // Delete each Course object
	}
	delete[] courses; // Delete the array of Course pointers
	// No need to delete universityName;
// it's a std::string and will be managed automatically
}
void Catalog::sortCatalog() {
	for (int i = 0; i < courseCount - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < getCount(); j++) {
			if (courses[j]->getCourseCode() < courses[minIndex]->getCourseCode()) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			Course* temp = courses[i];
			courses[i] = courses[minIndex];
			courses[minIndex] = temp;
		}
	}
}
void Catalog::setUniversityName(string name) {
	universityName = name;
}
string Catalog::getUniversityName() const {
	return universityName;
}
void Catalog::addCourse(string code, string name, int credits) {
	// Check if a course with the same code already exists
	int existingIndex = findCourse(code);
	if (existingIndex != -1) {
		cout << "Course with code " << code << " already exists in the catalog. Duplicate course not added." << endl << endl;
	}
	else {
		// Create a new course
		Course* newCourse = new Course(code, name, credits);
		// Resize the array to accommodate the new course
		Course** newCourses = new Course * [courseCount + 1];
		for (int i = 0; i < courseCount; i++) {
			newCourses[i] = courses[i];
		}
		// Add the new course and update the course count
		newCourses[courseCount] = newCourse;
		delete[] courses;
		courses = newCourses;
		courseCount++;
		cout << "Course with code " << code << " added to the catalog." << endl
			<<
			endl;
		sortCatalog(); // Sort the catalog after adding
	}
}
int Catalog::findCourse(const string code) const {
	if (getCount() > 0) {
		for (int i = 0; i < getCount(); i++)
			if (courses[i]->getCourseCode().compare(code) == 0)
				return i;
	}
	return -1;
}
void Catalog::deleteCourse(int index) {
	if (index >= 0 && index < courseCount) {
		// Delete the course at the given index
		delete courses[index];
		// Create a new array without the deleted course
		Course** newCourses = new Course * [courseCount - 1];
		for (int i = 0, j = 0; i < courseCount; i++) {
			if (i != index) {
				newCourses[j++] = courses[i];
			}
		}
		delete[] courses;
		courses = newCourses;
		courseCount--;
	}
}
void Catalog::printCatalog() const {
	// Calculate the maximum lengths of course code and course name
	size_t maxCodeLength = 11; // "CODE" has 11 characters
	size_t maxNameLength = 11; // "NAME" has 11 characters
	for (int i = 0; i < courseCount; i++) {
		size_t codeLength = courses[i]->getCourseCode().length();
		size_t nameLength = courses[i]->getCourseName().length();
		if (codeLength > maxCodeLength) {
			maxCodeLength = codeLength;
		}
		if (nameLength > maxNameLength) {
			maxNameLength = nameLength;
		}
	}
	cout << "University: " << universityName << endl;
	cout << endl;
	printf("%-*s %--*s %s\n", int(maxCodeLength), "CODE", int(maxNameLength),
		"NAME", "CREDITS");
	cout << endl;
	for (int i = 0; i < courseCount; i++) {
		printf("%-*s %--*s %5d\n", int(maxCodeLength),
		courses[i]->getCourseCode().c_str(), int(maxNameLength), courses[i]->getCourseName().c_str(), courses[i] ->
		getCourseCredits());
		cout << endl;
	}
}
void Catalog::operator=(const Catalog& other) {
	if (this == &other) {
		return; // Avoid self-assignment
	}
	// Copy data from the other catalog
	universityName = other.universityName;
	courseCount = other.courseCount;
	courses = new Course * [courseCount];
	for (int i = 0; i < courseCount; i++) {
		courses[i] = new Course(*(other.courses[i]));
	}
}
int Catalog::getCount() const
{
	return courseCount;
}
