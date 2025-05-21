/*
* CECS 2203, Computer Programming I Laboratory
* Spring 2023, Sec. 06
* Date: March 23, 2023
* Topic: Lab 2 - Methods that return a value, functions
* File name: lab02.cpp
*
* Instructions and problem statement:
* A college professor needs a solution to compute a student's final letter grade.
* Each student has scores for three 100-point exams. The rubric to be used is:
* -If the final grade is greater than 88, the student earns an A
* -If the final grade is greater than 78, but less than 89, the student earns a B
* -If the final grade is greater than or equal to 69, but less than 79, the student earns a C
* -If the final grade is greater than 58, but less than or equal to 68, the student earns a D
* -If the final grade is less than 59, the student is awarded an F
* The solution must first compute a student's final average, after obtaining all three scores.
* The final average will then be submitted to the rubric, and the final output will be the letter grade.
*
* Complete the program by writing the correct C++ statements.
*
* You should execute the program five times to make sure that all letter grades (A,B,C,D,F) are
* possible. Save a screenshot for each instance of the program's execution, and include them in your report.
*
* Name: CORAL S. SCHMIDT MONTILLA, YOUR ID# 148830
*/
// write the appropriate preprocessor directive
#include <iostream>

// write the appropriate using directive
using namespace std;

// declare a method named getScore that receives 2 integers as parameters
// and returns an integer value
int getScore(int, int);

// declare a method named getAverage that receives 3 integers as parameters
// and returns an integer value
int getAverage(int, int, int);

// declare a method named getGrade that receives an integer as parameter
// and returns character value
char getGrade(int);

int main() {
	// Write the statement that declares the integer variables named
	// finalAverage, score1, score2, score3 and initializes them to 0 
	int finalAverage = 0, score1 = 0, score2 = 0, score3 = 0;

	// Write the statement that declares a character variable named
	// letterGrade and initializes it to X
	char letterGrade = 'X';

	// Develop a for iteration control structure which uses the integer variable i as the counter.
	// The structure will repeat the associated block of code 5 times
	for (int i = 1; i < 6 ; i++) {

		// call getScore to assign a value to score1, use the value of the counter as the first argument
		score1 = getScore(i, 1);

		// call getScore to assign a value to score2, use the value of the counter as the first argument
		score2 = getScore(i, 2);

		// call getScore to assign a value to score3, use the value of the counter as the first argument
		score3 = getScore(i, 3);

		// call getAverage to assign a value to finalAverage
		finalAverage = getAverage(score1, score2, score3);

		// call getGrade to assign a value to letterGrade
		letterGrade = getGrade(finalAverage);

		// print the following phrase, substituting the square brackets and 
		// the text within with the correct values:
		// "The student with test scores [score1], [score2], and [score3], 
		// scored a final average of [finalAverage] and earned a(n) [letterGrade].\n"
		cout << "The student with test scores " << score1 <<", " << score2 << ", and " << score3 << ", scored a final average of " << finalAverage << " and earned a(n) " << letterGrade << ".\n";
		cout << endl;
	}

	// write a statement which prints the phrase "Program developed by [YOUR NAME], ID#[YOUR ID NUMBER]"
	// where the square brackets and the text within is substituted with your personal information.
	cout << "Program developed by CORAL S. SCHMIDT MONTILLA, ID#148830";
	cout << endl;
	system("pause"); // for Visual Studio only
	return 0;
}

// The getScore method receives 2 integer values as parameters and returns an integer value.
// The value of the first parameter is the student number and the second paramter is the test 
// number, both are used in the prompt. Declare a local integer variable named score and initialize
// it to 0. Use the following phrase: "Enter the score for student #[student number], test #[test number]: ". 
// Store the value entered by the user in score, and return the value.
int getScore(int studNum, int testNum)
{
	int score = 0;
	cout << "Enter the score for student #" << studNum << ", test #" << testNum << ": ";
	cin >> score;
	return score;
}

// The getAverage method receives 3 integer values as parameters and returns an integer value.
// The values of the parameters represent three test scores. The function adds the test scores
// and divides the sum by 3, returning this value. 
// DO NOT DECLARE any variables in this method!
int getAverage(int score1, int score2, int score3)
{
	return ((score1 + score2 + score3) / 3);
}

// The getGrade method receives an integer value as parameter and returns a character value.
// The value of the parameter represents the average score for the exams. Develop an 
// if / else if / else selection control structure to implement the rubric, using the value of the 
// parameter in the conditions. Use only single conditions! Once a condition is true, the function
// returns the corresponding character value, which represents the letter grade earned. 
// DO NOT DECLARE any variables in this method!
char getGrade(int finalAverage)
{
	if (finalAverage > 88)
	{
		return 'A';
	}
	else if (finalAverage > 78 and finalAverage < 89)
	{
		return 'B';
	}
	else if (finalAverage >= 69 and finalAverage < 79)
	{
		return 'C';
	}
	else if (finalAverage > 58 and finalAverage <= 68)
	{
		return 'D';
	}
	else if (finalAverage < 59)
	{
		return 'F';
	}
	return 0;
}
