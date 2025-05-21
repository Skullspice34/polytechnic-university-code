// test cin: assessment 2
// Hecho por Coral y Angelica

#include <iostream>

using namespace std;

int main()

{
//declarando variables
double sBalance;
double deposits;
double withdrawls;
double mInterest;
double aCBalance;
double percentage; 

cout << "Account Balance";
cout << "\nEnter your balance";
cin >> sBalance;//pregunta su balance
cout <<"\nEnter your deposits";
cin >>deposits;//preguntas si tienes depositos
cout <<"\nEnter your withdrawls";
cin >> withdrawls;//preguntas si tienes withdrawals
cout <<"\nEnter your monthly interest";
cin >> mInterest;//preguntas si tienes monthly interest

aCBalance = sBalance+deposits-withdrawls; //calcula balance anted del minterest
percentage = aCBalance*(mInterest/100);//calcula el minterest
aCBalance = aCBalance-percentage;//le quita el minterest

std::cout<<"Your total balance is: $" ;
std::cout<< aCBalance;//imprime tu balance actual

}
