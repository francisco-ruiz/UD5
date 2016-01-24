#include <iostream>
using namespace std;

/**
*@brief Módulo que recorre un vector que recibe por referencia y crea un segundo vector, copia del primero.
*@param const double v_original -> vector original, con paso como una constante; no se modificará en la función.
*@param double v_copia -> vector copia, con paso por referencia, el vector se generará en esta función.
*@param int v_util -> número de componentes efectivamente utilizadas en el vector original y, por tanto, también en el vector copia; paso por copia, no se modificará dentro de la función.
@return Devuelve por refencia el vector copia.
**/
void copiaVector(const double v_original[],double v_copia[],int v_util){
	
	for (int i=0; i < v_util; i++){
		v_copia[i] = v_original[i];
	}
}

/**
*@brief Imprime por pantalla el vector original.
*@param int v_original -> Vector original.
*@param int util_v_util -> Variable que almacena el número de elementos utilizados en el vector de partida v_original.
*@pre int v_util > 0.
**/
void imprime_v_original(const double v_original[],int v_util){
		
	cout << "{ ";
	for (int i= 0; i < v_util; i++){
		cout << v_original[i] << " ";
	}
	cout << "}\n";
}

/**
*@brief Imprime por pantalla el vector copia.
*@param int v_original -> Vector copia.
*@param int util_v_util -> Variable que almacena el número de elementos utilizados en el vector copiado v_copia.
*@pre int v_util > 0.
**/
void imprime_v_copia(const double v_copia[],int v_util){
		
	cout << "{ ";
	for (int i=0; i < v_util; i++){
		cout << v_copia[i] << " ";
	}
	cout << "}\n";
}

int main(){
	
	const int DIM_V_ORIGINAL=15;
	double v_original[DIM_V_ORIGINAL]={1,2,45,6,7,8,99,33,22,2,1,5,6,2};
	double v_copia[DIM_V_ORIGINAL];
	int v_util = 14;
	
	cout << "\nEl vector original es:" << endl;
	imprime_v_original(v_original,v_util);
	copiaVector(v_original,v_copia,v_util);	
	cout << "\nEl vector copia es:" << endl;
	imprime_v_copia(v_copia,v_util);
	
}