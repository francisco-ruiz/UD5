#include <iostream>
using namespace std;

int main(){

	const int DIM_ALUMNOS = 50;
	double notas[DIM_ALUMNOS];
	double media = 0.0, nota = 0.0;
	int util_alumnos = 0;

	cout << "\n";

	do{	
	cout << "Introduzca un número de alumnos de la clase (valor entre 1 y " << DIM_ALUMNOS << "): ";
		cin >> util_alumnos;
		if (util_alumnos <1 || util_alumnos >DIM_ALUMNOS)
			cout << "El valor introducido no es válido, inténtelo de nuevo.\n";
	}while (util_alumnos <1 || util_alumnos >DIM_ALUMNOS);

	cout << "\n";

	for (int i = 0; i < util_alumnos; i++){
		do{
			cout << "Introduzca la nota del alumno " << i+1 << ": ";
			cin >> nota;
			if (nota <0 || nota >10)
				cout << "El valor introducido no es válido, inténtelo de nuevo.\n";

		}while (nota <0 || nota >10);	
		
		notas[i] = nota;
	}

	for (int i = 0; i < util_alumnos; i++){
		media += notas[i];
	}

	cout << "\nLa nota media de los alumnos es: " << media/util_alumnos << "\n" << endl;
}	
