#include <iostream>
using namespace std;

/**
*@brief Función que recibe por referencia dos vectores ordenados y devuelve un tercer vector, también ordenado, resultado de fusionar el contenido de los dos vectores originales
*@param double v1[] -> Primer vector ordenado.
*@param int util_v1 -> Dimensión utilizada del vector v1, pasada por copia, no se modifica.
*@param double v2[] -> Segundo vector ordenado.
*@param int util_v2 -> Dimensión utilizada del vector v2, pasada por copia, no se modifica.
*@param double vFinal[] -> Vector fusión de los dos anteriores.
*@param int &util_vFinal -> Dimensión utilizada del vector vFinal, pasada por referencia puesto que se calculará dentro de esta función.
*@pre util_v1 > 0 && util_v2 > 0.
*@return En la función se creará un tercer vector.
**/
void fusionaVectores(const double v1[], int util_v1, const double v2[], int util_v2, double vFinal[], int &util_vFinal){

	int i = 0, j = 0, k = 0;

	//Se comparan las componentes de los dos vectores una a una; se toma la menor de cada dupla y se almacenará en el vector fusión. Se repite el proceso hasta que uno de los dos vectores se haya incorporado completamente al vector fusión.	
	while ((i < util_v1) && (j < util_v2)){
		cout << "Comparamos " << v1[i] << " con " << v2[j] << " / ";  
		if (v1[i] <= v2[j]){
			vFinal[k] = v1[i];
			cout << "Almacenamos " << vFinal[k] << endl;
			k++;
			i++;
			
		}else{
			vFinal[k] = v2[j];
			cout << "Almacenamos " << vFinal[k] << endl;
			k++;
			j++;
		}
	}

	// El primer vector ha llegado hasta su última componente; es decir, todavía quedan componentes en el segundo vector sin añadir al vector fusión.
	if (i == util_v1){
		while(j < util_v2){
			vFinal[k] = v2[j];
			cout << "Almacenamos " << vFinal[k] << endl;
			k++;
			j++;
		}
	}
	
	// El segundo vector ha llegado hasta su última componente; es decir, todavía quedan componentes en el primer vector sin añadir al vector fusión.
	if (j == util_v2){
		while(i < util_v1){
			vFinal[k] = v1[i];
			cout << "Almacenamos " << vFinal[k] << endl;
			k++;
			i++;
		}
	}
	
	util_vFinal = k;
} 

void imprimeVector(const double v[], int util_v){

	cout << "\n{ ";	
	for (int i = 0; i < util_v; i++)
		cout << v[i] << " ";
	cout << "}\n";
}

int main(){

	const int DIM_V1 = 10;
	const int DIM_V2 = 10;
	const int DIM_VFINAL = 20;
	int util_v1 = 10;
	int util_v2 = 9;
	int util_vFinal = 0;
	double v1[DIM_V1]={0,5,7,9,13,19,21,23,24,26};
	double v2[DIM_V2]={1,3,4,8,15,20,21,23,31,32};
	double vFinal[DIM_VFINAL];

	cout << "\nEl primer vector es: ";
	imprimeVector(v1,util_v1);
	cout << "\nEl segundo vector es: ";
	imprimeVector(v2,util_v2);
	fusionaVectores(v1, util_v1, v2, util_v2, vFinal, util_vFinal);
	cout << "\nEl vector mezcla de los anteriores es: ";
	imprimeVector(vFinal,util_vFinal);
	cout << "\n";

	
}
