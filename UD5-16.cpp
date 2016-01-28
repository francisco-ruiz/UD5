#include <iostream>
using namespace std;

/**
*@brief Invierte el contenido de un vector.
*@param const double v[] -> Recibe como sólo lectura un vector que se leerá dentro de la función;
*@param double inv_v[] -> Recibe por referencia un vector que se modificará dentro de la función para ser el inverso del vector v[]. Recorreremos el vector desde la primera hasta la última componente para generar el vector invertido.
*@param util_v -> Dimensión de los componentes efectivamente utilizados en el vector v[].
*@pre util_v > 0.
*@post Devuelve el vector de inicio con los componentes en orden inverso.
**/
void invierteVector1(const double v[], double inv_v[], int util_v){
	
	//Comenzando desde la primera posición utilizada en v[], vamos recorriendo el vector, almacenando su valor en la última posición utilizada en inv_v[]. Mientras v[] avanza hacia adelante posición a posición, se copia su valor en inv_v[] retrocediendo hasta la primera posición. Así obtendremos el vector invertido.
	
	int contador = util_v-1;
	
	for (int i = 0; i < util_v; i++){
		inv_v[contador] = v[i];
		contador--;
	}
}

/**
*@brief Invierte el contenido de un vector.
*@param const double v[] -> Recibe como sólo lectura un vector que se leerá dentro de la función;
*@param double inv_v[] -> Recibe por referencia un vector que se modificará dentro de la función para ser el inverso del vector v[]. Recorreremos el vector desde la última hasta la primera componente para generar el vector invertido.
*@param util_v -> Dimensión de los componentes efectivamente utilizados en el vector v[].
*@pre util_v > 0.
*@post Devuelve el vector de inicio con los componentes en orden inverso.
**/
void invierteVector2(const double v[], double inv_v[], int util_v){
	
	//Comenzando desde la última posición utilizada en v[], vamos recorriendo el vector, almacenando su valor en la primera posición utilizada en inv_v[]. Mientras v[] retrocede posición a posición, se copia su valor en inv_v[] avanzando posición a posición. Así obtendremos el vector invertido.
	
	int contador = 0;
		
	for (int i = util_v-1; i >= 0; i--){
		inv_v[contador] = v[i];
		contador++;
	}
}

void imprimeVector(const double v[], int util_v){
	
	cout << "\n{ " ;
	for (int i = 0; i < util_v; i++)
		cout << v[i] << " ";
	cout << "}\n";
	
}

int main(){
	
	int DIM_V = 20;
	int util_v = 16;	
	double v[DIM_V] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	double inv_v[DIM_V];
	
	cout << "\nEl vector original es: ";
	imprimeVector(v, util_v);
	cout << "\nEl vector invertido recorriendo el vector hacia adelante es: ";
	invierteVector1(v, inv_v, util_v);
	imprimeVector(inv_v, util_v);
	cout << "\nEl vector invertido recorriendo el vector hacia atrás es: ";
	invierteVector2(v, inv_v, util_v);
	imprimeVector(inv_v, util_v);
	
}