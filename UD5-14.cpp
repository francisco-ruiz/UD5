#include <iostream>
using namespace std;

/**
*@pre Recibe un vector por referencia y se modifica para ordenar sus componentes por el método de inserción
*@param double v -> vector a ordenar
*@param util_v -> tamaño utilizado del vector
*@pre util_v > 0
*@return Por referencia, el vector estará ordenado al finalizar la ejecución de la función.
**/
void ordenaVector(double v[],int util_v){

	int izda = 0, i=1;
	double valor = 0;

	for (izda=1; izda < util_v; izda++){
		valor = v[izda];

		for (i = izda; i > 0 && valor < v[i-1]; i--){
			v[i] = v[i-1];
		}
	v[i] = valor;	
	}
}

/**
*@brief Muestra por pantalla las componentes del vector v.
*@param const double v -> recibe por referencia el vector v, no se modificará dentro de la función.
*@param util_v -> recibe por copia el número máximo de elementos que almacenará el vector. No se modificará dentro de la función.
*@pre util_v > 0.
**/
void imprimeVector(const double v[],int util_v){
		
	cout << "{ ";
	for (int i= 0; i < util_v; i++){
		cout << v[i] << " ";
	}
	cout << "}\n";
}

int main(){

	const int DIM_V=15;
	double v[DIM_V]={15,10,11,14,87,5,14,7,88,99,3};
	int util_v =11;

	imprimeVector(v,util_v);	
	ordenaVector(v,util_v);
	imprimeVector(v,util_v);
}
