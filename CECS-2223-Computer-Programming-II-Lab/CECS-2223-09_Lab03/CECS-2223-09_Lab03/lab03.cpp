/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: August 30, 2023
* Topic: Lab 3
* File name: lab03.cpp
* Coral S. Schmidt Montilla, #148830
*/
#include "Grades.h"
#include <iostream>

/*To implement the class, declare a 5-element Grades array named students. Using a
for iteration control structure, call the appropriate methods to set the scores for each student and
print the grades.
*/
int main() {

    const int NUM_STUDENTS = 5; // Number of students
    Grades students[NUM_STUDENTS]; // Array of Grades objects

    for (int i = 0; i < NUM_STUDENTS; i++) //gets the scores for each student
    {
        students[i].setScores(i + 1);
        students[i].printGrades(i + 1);
    }

    printf("***** Program developed by Coral S. Schmidt Montilla, ID#148830 *****\n");
    
    system("pause");
    return 0;
}
