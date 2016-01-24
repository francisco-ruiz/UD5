#include <iostream>
#include <cmath>
using namespace std;

/**
*@brief Módulo que recibe un número entero. Si es primo, devuelve true y false si no lo es.
*@param int numero -> Número entero que se pasa por copia, ya que no será modificado.
*@pre int numero ha de ser un valor entero.
*@return bool primo será true si es primo y false si no lo es.
**/
int compruebaPrimo(int numero){
	
bool primo = true;

	//Una vez introducido, dentro del bucle se evalua si el número tiene algún divisor. Si esto se da, el número no sería primo y se asigna el valor false a la variable booleana primo. Esto hace que el bucle se detenga ya que se ha definido como condición para que el bucle siga evaluando que el valor de primo sea true. En la primera iteración suponemos que el número es primo (primo se inicializa a true) y se siguen comprobando todos los valores comprendidos entre 2 (ya que todos los números enteros son divisibles entre 1 y es una comprobación trivial) y el propio valor del número introducido. Si se completa el ciclo de repeticiones sin que se cumpla la condición de que sea divisible por un número distinto de sí mismo (es decir, que contador == numero), saldría del bucle for con primo == true.
	for (int contador= 2; ((contador < abs(numero)) && (primo == true)); contador++){
		if ((abs(numero) % contador)!=0 == true)
			primo = true;
		else
			primo = false;
	}
	
return primo;
}

/**
*@brief Recupera el contenido de un vector de partida y, a través de un bucle, almacena en un nuevo vector final los números pares del vector original. De esta forma el vector final contendrá únicamente valores pares.
*@param int v_Numeros -> Vector de partida en el que se almacena una serie de números reales.
*@param int v_Primos -> Vector final en el que se almacenan los números pares de la serie del vector de partida.
*@param int DIM_V_NUMEROS -> Variable que almacena el tamaño máximo del vector de partida v_Numeros.
*@param int util_v_Numeros -> Variable que almacena el número de elementos utilizados en el vector de partida v_Numeros.
*@param int util_v_Primos -> Variable que almacena el número de elementos utilizados en el vector de destino v_Primos.
*@pre DIM_V_NUMEROS >= util_v_Numeros.
*@return Devuelve por referencia los dos vectores actualizados.
*@post DIM_V_NUMEROS >= util_v_Numeros.
**/
void extraePrimos(int v_Numeros[],int v_Primos[],const int DIM_V_NUMEROS,int &util_v_Numeros,int &util_v_Primos){
	
	int j = 0;
	
	cout << "El vector de partida es:\n";
	for (int i=0; i < util_v_Numeros; i++){
		cout << v_Numeros[i] << " ";
	}
	cout << "\n" << endl;
	
	// Recorre y evalua si cada uno de los valores del vector de partida v_Numeros es par. Almacenará en el vector de destino v_Primos.
	for (int i=0; i < util_v_Numeros; i++){
		
		if ((compruebaPrimo(v_Numeros[i]) == true)){
			v_Primos[j] = v_Numeros[i];
			cout << "El número " << v_Numeros[i] << " ES un número primo y se almacena en la posición "<< j+1 << endl;
			util_v_Primos++;
			j++;
		}else		
			cout << "El número " << v_Numeros[i] << " NO ES primo" << endl;
	}
}

/**
*@brief Recupera el contenido del vector final con la serie de números pares procedentes del vector de partida y lo muestra por pantalla.
*@param int v_Primos -> Vector final en el que se almacenan los números pares de la serie del vector de partida.
*@param int util_v_Numeros -> Variable que almacena el número de elementos utilizados en el vector de partida v_Numeros.
*@param int util_v_Primos -> Variable que almacena el número de elementos utilizados en el vector de destino v_Primos.
*@pre DIM_V_NUMEROS >= util_v_Numeros.
*@return Devuelve por referencia los dos vectores actualizados.
*@post DIM_V_NUMEROS >= util_v_Numeros.
**/
void imprime_v_Primos(int v_Primos[],int &util_v_Numeros,int &util_v_Primos){
		
	cout << "\nLos " << util_v_Primos << " valores primos del vector de partida son:" << endl;
	
	for (int i=0; i < util_v_Primos; i++){
		cout << v_Primos[i] << " ";
	}
}

int main(){

	const int DIM_V_NUMEROS = 15;
	int util_v_Numeros = 15, util_v_Primos = 0;
	int v_Numeros[DIM_V_NUMEROS] = {1,1,1,2,2,3,3,3,4,5,6,6,7,8,8};
	int v_Primos[DIM_V_NUMEROS];
	
	extraePrimos(v_Numeros,v_Primos,DIM_V_NUMEROS,util_v_Numeros,util_v_Primos);
	imprime_v_Primos(v_Primos,util_v_Numeros,util_v_Primos);
}