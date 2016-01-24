#include <iostream>
using namespace std;

/**
*@brief Módulo que recorre un vector que recibe por referencia y crea un segundo vector, copia del primero.
*@param const double v_original -> vector original, con paso como una constante; no se modificará en la función.
*@param int v_util -> número de componentes efectivamente utilizadas en el vector original; paso por copia, no se modificará dentro de la función.
*@pre v_util > 0.
@return Devuelve un valor booleano true si el elemento ha sido encontrado en el vector; false si no.
**/
int leeValor(int &valor){
	
	cout << "Introduzca el valor que desea encontrar en la cadena: ";
	cin >> valor;
	
	return valor;
}

/**
*@brief Módulo que recorre un vector que recibe por referencia y crea un segundo vector, copia del primero.
*@param const double v_original -> vector original, con paso como una constante; no se modificará en la función.
*@param int v_util -> número de componentes efectivamente utilizadas en el vector original; paso por copia, no se modificará dentro de la función.
*@pre v_util > 0.
@return Devuelve un valor booleano true si el elemento ha sido encontrado en el vector; false si no.
**/
bool buscaVector(const double v_original[], int v_util, int valor){
	
	int contador = 0;
	bool encontrado = false;
	
	while /*(*/(contador < v_util)/* && (encontrado == false))*/{
		if (v_original[contador] == valor){
			encontrado = true;
			}
		contador++;
	}	
	
	return encontrado;
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
void imprimeResultadoBusqueda(const double v_original[], int v_util, int valor, bool encontrado){
		
	if (encontrado==true){
		cout << "\nEl valor " << valor << " SÍ se encuentra en el vector: \n";
		imprime_v_original(v_original,v_util);
	}else{
		cout << "\nEl valor " << valor << " NO se encuentra en el vector: \n";
		imprime_v_original(v_original,v_util);
	}
}

int main(){
	
	const int DIM_V_ORIGINAL=15;
	double v_original[DIM_V_ORIGINAL]={1,2,45,6,7,8,99,33,22,2,1,5,6,2};
	double v_copia[DIM_V_ORIGINAL];
	int v_util = 14;
	int valor = 0;
	
	valor=leeValor(valor);
	imprimeResultadoBusqueda(v_original,v_util,valor,buscaVector(v_original,v_util,valor));
}