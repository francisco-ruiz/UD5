#include <iostream>
using namespace std;

/**
*@brief Ordena las componentes del vector v_vector siguiendo el algoritmo de ordenación por selección.
*@param double v_vector -> recibe por referencia el vector v_vector, se modificará dentro de la función.
*@param util_vector -> recibe por copia el número máximo de elementos que almacenará el vector. No se modificará dentro de la función.
*@pre util_vector > 0.
*@return Devuelve el vector actualizado con sus componenetes ordenadas de menor a mayor.
**/
void ordenaVector(double v_vector[], int util_vector){
	int pos_min = 0, aux = 0;

	for (int i = 0; i < util_vector ; i++){
		pos_min = i;
		for (int j = i+1; j < util_vector ; j++){
			if (v_vector[j] < v_vector[pos_min])
				pos_min = j; 
		}
	aux = v_vector[i];
	v_vector[i] = v_vector[pos_min];
	v_vector[pos_min] = aux;	
	}
}

/**
*@brief Muestra por pantalla las componentes del vector v_vector.
*@param const double v_vector -> recibe por referencia el vector v_vector, no se modificará dentro de la función.
*@param util_vector -> recibe por copia el número máximo de elementos que almacenará el vector. No se modificará dentro de la función.
*@pre util_vector > 0.
**/
void imprimeVector(const double v_vector[],int util_vector){
		
	cout << "{ ";
	for (int i= 0; i < util_vector; i++){
		cout << v_vector[i] << " ";
	}
	cout << "}\n";
}


int main(){
	
	const int DIM_VECTOR=15;
	double v_vector[DIM_VECTOR]={1,2,45,6,7,8,99,33,22,2,1,5,6,2};
	int util_vector = 14;

	cout << "\nEl vector original es:\n";
	imprimeVector(v_vector,util_vector);
	ordenaVector(v_vector,util_vector);
	cout << "\nEl vector ordenado es:\n";
	imprimeVector(v_vector,util_vector);
	cout << "\n";

}
