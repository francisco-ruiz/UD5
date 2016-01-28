#include <iostream>
using namespace std;

/**
*@brief Función que recibe por referencia un vector y calcula el valor de la moda de sus componentes.
*@param double v[] -> Primer vector ordenado.
*@param int &util_vModa -> Dimensión utilizada del vector vModa, pasada por referencia puesto que se calculará dentro de esta función.
*@pre util_v > 0 && util_vModa > 0.
*@return La función devolverá un vector con dos componentes; el primero será el valor de la moda de sus componentes y el segundo el número de repeticiones de ese elemento en el vector.
**/
void calculaModa(const double v[], int util_v, double moda[]){

	int valorModa = v[0], contador = 0, repeticiones = 0;
	
	for (int i = 0; i < util_v; i++){
		contador = 0;
		for (int j = i; j < util_v; j++){
			if (v[i] == v[j]){
				contador++;
			}
		}
		if (contador > repeticiones){
			repeticiones = contador;
			valorModa = v[i];
		}
	}
			
	moda[0] = valorModa;
	moda[1] = repeticiones;
} 

void imprimeVector(const double v[], int util_v){

	cout << "\n{ ";	
	for (int i = 0; i < util_v; i++)
		cout << v[i] << " ";
	cout << "}\n";
}

int main(){

	const int DIM_V = 20;
	const int DIM_MODA = 2;
	int util_v = 20;
	double util_moda = 2;
	double v[DIM_V]={0,1,3,5,7,21,23,27,28,31,35,43,47,54,56,64,65,68,75,80};
	double moda[DIM_MODA];

	cout << "\nPara el vector:\n";
	imprimeVector(v,util_v);
	calculaModa(v, util_v, moda);
	if (moda[1] = 1)
		cout << "\nNo existen elementos repetidos en el vector y no hay moda" << endl;
	else
		cout << "\nEl valor de la moda es " << moda[0] << ", que aparece repetido " << moda[1] << " veces\n" << endl;
}
