/*
* CECS 2223, Computer Programming II Laboratory
* Fall 2023, Sec. 09
* Date: August 30, 2023
* Topic: Lab 3
* File name: Grades.cpp
* Coral S. Schmidt, #148830
*/

#include "Grades.h"

Grades::Grades() {
	scores = new int[TESTS] { 0 };//Initializes the instance variable using "TESTS" as the size
}

// Class Destructor
Grades::~Grades()//No code needed
{
}

/*The setScores method receives an integer value as parameter and has no return value.
It prompts the user for a test score, validates the score, and stores it in the array.The parameter is
the student’s number(1, 2, 3, …).It uses a for iteration control structure to prompt the user
TESTS times using the phrase "Enter the score for student #[student
number], test #[test number]: ". The scores must be in the range [0, 100], and the
method must print an error message indicating that the value is out of range before requesting a
new value.
*/
void Grades::setScores(int studentNum)
{
    for (int i = 0; i < TESTS; i++) {//prompt the user TESTS times

       //asks user for test score
       printf("Enter the score for student #%i, test #%i:", studentNum, i + 1);
       cin >> scores[i];//saves test score in the array
       
       if (scores[i] < 0 || scores[i] > 100) //Checks that scores must be in the range [0, 100] prints error if it isnt in range
           {
            printf("Error: Score is out of range (0-100). Please enter a valid score.\n");
            i--;
           }
    }
}

//The getScore method receives the index number of the score as parameter and returns the score.
int Grades::getScores(int indexNum) const
{
    if (indexNum >= 0 && indexNum < TESTS) //Checks if valid index
    {
        return scores[indexNum];
    }
    else // Incase we get an invalid index
    {    
        return -1;
    }
}
/*The getAverage method has no parameters and returns an integer value. Using a for
iteration control structure, it adds all test scores and returns the average. Use a local integer variable
named total to store the sum.*/
int Grades::getAverage() const 
{
    int total = 0;

    for (int i = 0; i < TESTS; i++)//Adds all test scores and returns the average
    {
        total += scores[i] / TESTS;
    }

    return total;
}

/*The getGrade method receives an integer value as parameter and returns a character
value. The parameter is the student’s number (1, 2, 3, …).It implements the rubric using an if /
else if / else selection control structure.*/
char Grades::getGrades(int studentNum) const
{
    if (getAverage() > 89)
    {
        return 'A';
    }
    else if (getAverage() > 79)
    {
        return 'B';
    }
    else if (getAverage() >= 70)
    {
        return 'C';
    }
    else if (getAverage() > 59)
    {
        return 'D';
    }
    else 
    {
        return 'F';
    }
}

/*The printGrades method receives an integer value as parameter and has no return
value. The parameter is the student’s number (1, 2, 3, …). It prints the phrase "Student
#[student number], with test scores [score1], [score2], and
[score3], scored a final average of [final average] and earned
a(n) [letter grade]." Make sure to add a blank line before and after the phrase is printed.*/
void Grades::printGrades(int studentNum) const
{
    printf("\nStudent #%i, with test scores: ", studentNum);

    for (int i = 0; i < TESTS; i++) 
    {
        printf("%i", scores[i]);

        if (i < TESTS - 1) 
        {
            printf(", ");
        }
    }
    printf(", scored a final average of %i and earned a(n) %c.\n", getAverage(), getGrades(studentNum));
}