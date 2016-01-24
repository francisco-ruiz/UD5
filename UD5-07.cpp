#include <iostream>
using namespace std;

/**
*@brief Recupera el contenido de un vector de partida y, a través de un bucle, almacena en un nuevo vector final los números pares del vector original. De esta forma el vector final contendrá únicamente valores pares.
*@param int v_Numeros -> Vector de partida en el que se almacena una serie de números reales.
*@param int v_Pares -> Vector final en el que se almacenan los números pares de la serie del vector de partida.
*@param int DIM_V_NUMEROS -> Variable que almacena el tamaño máximo del vector de partida v_Numeros.
*@param int util_v_Numeros -> Variable que almacena el número de elementos utilizados en el vector de partida v_Numeros.
*@param int util_v_Pares -> Variable que almacena el número de elementos utilizados en el vector de destino v_Pares.
*@pre DIM_V_NUMEROS >= util_v_Numeros.
*@return Devuelve por referencia los dos vectores actualizados.
*@post DIM_V_NUMEROS >= util_v_Numeros.
**/
void extrae_pares(int v_Numeros[],int v_Pares[],const int DIM_V_NUMEROS,int &util_v_Numeros,int &util_v_Pares){
	
	int j = 0;
	
	cout << "El vector de partida es:\n";
	for (int i=0; i < util_v_Numeros; i++){
		cout << v_Numeros[i] << " ";
	}
	cout << "\n" << endl;
	
	// Recorre y evalua si cada uno de los valores del vector de partida v_Numeros es par. Almacenará en el vector de destino v_Pares.
	for (int i=0; i < util_v_Numeros; i++){
		
		if ((v_Numeros[i]%2) == 0){
			v_Pares[j] = v_Numeros[i];
			cout << "El número " << v_Numeros[i] << " es un número par y se almacena en la posición "<< j+1 << endl;
			util_v_Pares++;
			j++;
		}else		
			cout << "El número " << v_Numeros[i] << " es impar" << endl;
	}
}

/**
*@brief Recupera el contenido del vector final con la serie de números pares procedentes del vector de partida y lo muestra por pantalla.
*@param int v_Pares -> Vector final en el que se almacenan los números pares de la serie del vector de partida.
*@param int util_v_Numeros -> Variable que almacena el número de elementos utilizados en el vector de partida v_Numeros.
*@param int util_v_Pares -> Variable que almacena el número de elementos utilizados en el vector de destino v_Pares.
*@pre DIM_V_NUMEROS >= util_v_Numeros.
*@return Devuelve por referencia los dos vectores actualizados.
*@post DIM_V_NUMEROS >= util_v_Numeros.
**/
void imprime_v_Pares(int v_Pares[],int &util_v_Numeros,int &util_v_Pares){
		
	cout << "\nLos " << util_v_Pares << " valores pares del vector de partida son:" << endl;
	
	for (int i=0; i < util_v_Pares; i++){
		cout << v_Pares[i] << " ";
	}
}

int main(){

	const int DIM_V_NUMEROS = 15;
	int util_v_Numeros = 15, util_v_Pares = 0;
	int v_Numeros[DIM_V_NUMEROS] = {1,1,1,2,2,3,3,3,4,5,6,6,7,8,8};
	int v_Pares[DIM_V_NUMEROS];
	
	extrae_pares(v_Numeros,v_Pares,DIM_V_NUMEROS,util_v_Numeros,util_v_Pares);
	imprime_v_Pares(v_Pares,util_v_Numeros,util_v_Pares);
}