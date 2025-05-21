"""
Author: Coral S. Schmidt Montilla
Student Number: 148830
Filename: main.py
This file demonstrates polymorphism with community members:
    It does this by by creating instances of `Employee` and  `Teacher`, prompting for information, 
    and printing out the details of each community member.
"""

from Employee import Employee
from Teacher import Teacher

def main():
    community_members = []

    while True:
        print("\nMenu:")
        print("1. Enter Employee Information")
        print("2. Enter Teacher Information")
        print("3. Exit")

        choice = input("Enter your choice (1, 2, or 3): ")

        if choice == "1":
            print("\nEmployee information ")
            employee = Employee()
            employee.ask()
            community_members.append(employee)
        elif choice == "2":
            print("\nTeacher information ")
            teacher = Teacher()
            teacher.ask()
            community_members.append(teacher)
        elif choice == "3":
            print("Exiting program...")
            break
        else:
            print("Invalid choice. Please enter 1, 2, or 3.")

    print("\nCommunity Members:")
    for member in community_members:
        print(member)
        print()

if __name__ == "__main__":
    main()

