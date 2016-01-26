#include <iostream>
using namespace std;

/**
*@brief Ordena los valores de un vector de menor a mayor a través del método de ordenación por intercambio directo o Método de la burbuja
*@param char v[] -> Recibe por referencia un vector para devolverlo ordenado.
*@param util_v -> Recibe por copia el número de elementos utilizados realmente en el vector.
*@pre util_v > 0.
*@return El vector pasado por referencia a la función se modifica y es devuelto con sus componentes ordenadas.
**/
void ordenaBurbuja(int v[], int util_v){
	
	bool cambio = true;
	int aux, izquierda;
	
	//Bucle exterior: irá controlando a través la posición izquierda y el booleano cambio el número de posiciones que necesitan ordenarse en cada momento. En la primera iteración recorrerá todo el vector; el bucle interior en cada iteración del exterior llevará a la posición izquierda el valor más pequeño de la parte sin ordenar del vector. A partir de ahí, la posición izquierda será la primera posición de la parte no ordenada del vector, que ordenará el bucle interior.
	for (int izquierda=0; izquierda < util_v && cambio == true; izquierda++){
		cambio = false;
		// Bucle interior: Recorre la parte no ordenada del vector desde la última posición utilizada (util_v-1) hacia atrás hasta llegar al principio de la parte no ordenada del vector (izquierda, que se va controlando desde el bucle exterior). Compara los elementos de dos en dos, comenzando desde el final hasta el valor de izquierda, que marca el límite de la parte no ordenada del vector. Si el valor de la derecha es menor al de la izquierda, intercambia ambas posiciones. Repitiendo este proceso en toda la parte no ordenada, conseguiremos que el elemento del vector que ocupa la posición izquierda sea el elemento más pequeño de dicha parte no ordenada, pero a su vez, mayor que el último elemento de la parte ordenada, que se actualizó en la iteración anterior del bucle exterior.
		for (int i=(util_v-1); i > izquierda; i--){
			if (v[i] < v[i-1]){
				cambio = true;
				aux = v[i];
				v[i] = v[i-1];
				v[i-1] = aux;
			}
		}
	}
	
}

void imprimeVector(int v[], int util_v){
	
	cout << "{ ";
	for (int i=0; i<util_v; i++)
		cout << v[i] << " ";
	cout << "}" << endl;
}

int main(){
	const int DIM_V = 30;
	int v[DIM_V] = {2,15,7,28,9,64,85,16,27,34,1,13,66,77,58,99,31,21,67,38,14,0,18,49,67};
	int util_v = 25;
	
	cout << "El vector original es: " << endl;
	imprimeVector(v, util_v);
	ordenaBurbuja(v,util_v);
	cout << "\nEl vector ordenado es: " << endl;
	imprimeVector(v, util_v);
}