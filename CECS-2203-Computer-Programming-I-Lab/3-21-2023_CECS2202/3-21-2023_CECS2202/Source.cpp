

//Una funcion que reciba la calif. deun estudiante en un curso (A, B, C, D o F)
// y retorne 'P' si paso o 'N' si no paso la clase.

#include <iostream>
using namespace std;

char gradeCal(char letter) {

	if (letter == 'a' || letter == 'A' || letter == 'b' || letter == 'B' || letter == 'c' || letter == 'C')
		return 'P';
	else if (letter == 'd' || letter == 'D' || letter == 'f' || letter == 'F')
		return 'N';
	else
		cout << "No es valido";
		return;
}

int main() {
	char x;
	
	cout << ("Entra la calificacion del estudiante: ");
	cin >> x;
	
	gradeCal(x);

	return 0;
}