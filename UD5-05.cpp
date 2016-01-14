#include <iostream>
#include <cmath>
using namespace std;

int leer_alumnos (const int DIM_ALUMNOS){

	int util_alumnos = 0;

	cout << "\n";
	
	do{	
		cout << "Introduzca un número de alumnos de la clase (valor entre 1 y " << DIM_ALUMNOS << "): ";
		cin >> util_alumnos;
		if (util_alumnos <1 || util_alumnos >DIM_ALUMNOS)
			cout << "El valor introducido no es válido, inténtelo de nuevo.\n";
	}while (util_alumnos <1 || util_alumnos >DIM_ALUMNOS);

	return util_alumnos;
}

void leer_notas (double v_notas[], const int DIM_ALUMNOS, int &util_alumnos){

	double nota = 0.0;

	util_alumnos = leer_alumnos(DIM_ALUMNOS);	

	cout << "\n";

	for (int i = 0; i < util_alumnos; i++){
		do{
			cout << "Introduzca la nota del alumno " << i+1 << ": ";
			cin >> nota;
			if (nota <0 || nota >10)
				cout << "El valor introducido no es válido, inténtelo de nuevo.\n";

		}while (nota <0 || nota >10);	
		
		v_notas[i] = nota;
	}

}

double calcular_media (double v_notas[], const int DIM_ALUMNOS, int &util_alumnos){

	double media = 0.0;
	
	for (int i = 0; i < util_alumnos; i++){
		media += v_notas[i];
	}

	media /= util_alumnos;

return media;
}

double calcular_varianza (double v_notas[], const int DIM_ALUMNOS, int &util_alumnos){

	double varianza = 0.0, media = 0.0;
	
	media = calcular_media(v_notas, DIM_ALUMNOS, util_alumnos);
	
	for (int i = 0; i < util_alumnos; i++)
		varianza += pow((media - v_notas[i]),2);
	
	varianza /= util_alumnos;
	
return varianza;
}

double calcular_desviacion (double v_notas[], const int DIM_ALUMNOS, int &util_alumnos){

	double desviacion = 0.0, media = 0.0;
	
	desviacion = sqrt(calcular_varianza(v_notas, DIM_ALUMNOS, util_alumnos));

return desviacion;
}

int main(){

	const int DIM_ALUMNOS = 50;
	double v_notas[DIM_ALUMNOS];
	double media = 0.0, nota = 0.0;
	int util_alumnos = 0;

	leer_notas (v_notas, DIM_ALUMNOS, util_alumnos);

	cout << "\nLa nota media de los alumnos es: " << calcular_media(v_notas, DIM_ALUMNOS, util_alumnos) << "\n" << endl;
	cout << "La varianza de la nota de los alumnos es: " << calcular_varianza(v_notas, DIM_ALUMNOS, util_alumnos) << "\n" << endl;
	cout << "La desviación típica de la nota de los alumnos es: " << calcular_desviacion(v_notas, DIM_ALUMNOS, util_alumnos) << "\n" << endl;

}	
