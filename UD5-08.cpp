#include <iostream>
using namespace std;

/**
*@brief Recupera el contenido de un vector de partida y, a través de un bucle, compara el valor de cada posición con el de la siguiente. En caso de que sean iguales, repite el proceso con la siguiente dupla de valores. En caso de que sean diferentes, almacena en un nuevo vector final el valor del primer elemento de la dupla. De esta forma el vector final tendrá los mismos valores que el vector original sin parejas de elementos repetidos.
*@param double v_Repetidos -> Vector de partida en el que se almacena una serie de números reales.
*@param double v_NoRepetidos -> Vector final en el que se almacena la serie del vector de partida sin repeticiones de elementos consecutivos.
*@param int DIM_V_REPETIDOS -> Variable que almacena el tamaño máximo del vector de partida v_Repetidos.
*@param int util_v_Repetidos -> Variable que almacena el número de elementos utilizados en el vector de partida v_Repetidos.
*@param int util_v_NoRepetidos -> Variable que almacena el número de elementos utilizados en el vector de destino v_NoRepetidos.
*@pre DIM_V_REPETIDOS >= util_v_Repetidos.
*@return Devuelve por referencia los dos vectores actualizados.
*@post DIM_V_REPETIDOS >= util_v_Repetidos.
**/
void elimina_repeticiones(double v_Repetidos[],double v_NoRepetidos[],const int DIM_V_REPETIDOS,int &util_v_Repetidos,int &util_v_NoRepetidos){
	
	int j=0; // Variable auxiliar para almacenar el contador del vector auxiliar.
	
	cout << "El vector de partida es:\n";
	for (int i=0; i < util_v_Repetidos; i++){
		cout << v_Repetidos[i] << " ";
	}
	cout << "\n" << endl;
	
	// 1) Recorre y compara dos a dos los componentes del vector de partida. Se detendrá en la penúltima posición para evaluar el último elemento como un caso especial. Es necesaria esta excepción porque, de lo contrario, el último elemento del vector de partida, definido por la posición util_v_Repetidos-1, se compararía con su siguiente, un valor que excede el número de elementos declarados en el vector, por lo que siempre sería igual a 0.
	for (int i=0; i < util_v_Repetidos-1; i++){
		
		cout << "Comparamos " << v_Repetidos[i] << " con " << v_Repetidos[i+1] << endl;
		
		if (v_Repetidos[i] != v_Repetidos[i+1]){
			v_NoRepetidos[j] = v_Repetidos[i];
			cout << "Almacenamos " << v_NoRepetidos[j] << " en la posición "<< j+1 << endl;
			util_v_NoRepetidos++;
			j++;
		}		
	}
				
	// 2) Vuelve a realizar una comparación, en este caso se comparan los últimos elementos de cada vector, ubicados en la posición util_v_Repetidos-1 y util_v_NoRepetidos-1 repspectivamente. Si son distintos, quiere decir que el último valor del vector de partida no está repetido y se añadiría a la última posición del vector auxiliar de elementos sin repeticiones.
	if (v_Repetidos[util_v_Repetidos] != v_NoRepetidos[util_v_NoRepetidos-1]){
		cout << "Comparamos " << v_Repetidos[util_v_Repetidos-1] << " con " << v_NoRepetidos[util_v_NoRepetidos-1] << endl;
		v_NoRepetidos[j] = v_Repetidos[util_v_Repetidos-1];
		util_v_NoRepetidos++;
	}
}

/**
*@brief Recupera el contenido del vector final sin repeticiones y lo muestra por pantalla.
*@param double v_NoRepetidos -> Vector final en el que se almacena la serie del vector de partida sin repeticiones de elementos consecutivos.
*@param int util_v_NoRepetidos -> Variable que almacena el número de elementos utilizados en el vector de destino v_NoRepetidos.
*@pre DIM_V_REPETIDOS >= util_v_Repetidos.
*@return void.
**/
void imprime_v_No_Repetidos(double v_NoRepetidos[],int &util_v_NoRepetidos){
		
	cout << "\nEl nuevo vector tiene " << util_v_NoRepetidos << " elementos: " << endl;
	
	for (int i=0; i < util_v_NoRepetidos; i++){
		cout << v_NoRepetidos[i] << " ";
	}
}

int main(){

	const int DIM_V_REPETIDOS = 15;
	int util_v_Repetidos = 15, util_v_NoRepetidos = 0;
	double v_Repetidos[DIM_V_REPETIDOS] = {1,1,1,2,2,3,3,3,4,5,6,6,7,8,8};
	double v_NoRepetidos[DIM_V_REPETIDOS];
	
	elimina_repeticiones(v_Repetidos,v_NoRepetidos,DIM_V_REPETIDOS,util_v_Repetidos,util_v_NoRepetidos);
	imprime_v_No_Repetidos(v_NoRepetidos,util_v_NoRepetidos);
}