#include <iostream>
#include <cmath>
using namespace std;

/**
*@brief Recibe un vector por copia y evalua si el contenido de su interior es un palíndromo.
*@param -> char v[], vector de caracteres, pasado por copia ya que no se va a modificar.
*@param -> int v_util, tamaño útil del vector, necesario para recorrer las componentes del vector.
*@pre -> v_util>0
*@return bool palindromo -> devuelve true si el vector es un palíndromo o false de lo contrario.
**/
bool evaluaPalindromo(const char v[], int v_util){
	
	int contador1 = 0, contador2 = 0;
	bool palindromo = true;
	
	// Dependiendo de la longitud del vector habrá que hacer dos comprobaciones diferentes; los vectores de tamaño útil par tendrán dos posiciones centrales y los de tamaño útil impar tendrán una. A partir de esas posiciones centrales se evaluarán las posiciones adyacentes.
	// Caso tamaño útil PAR.
	if (v_util % 2 == 0){
		contador1=(v_util%2);
		cout << "El vector tiene un número PAR de elementos." << endl;
		// Si las dos posiciones centrales son iguales, se comprueba el resto del vector comparando las posiciones anteriores y posteriores a las dos posiciones centrales y repitiendo el proceso hasta recorrer todo el vector.
		contador1 = (v_util/2)-1;
		contador2 = contador1+1;
		cout << "Las posiciones centrales son: " << v[contador1] << " y " << v[contador2] << endl;
		if (v[contador1] == v[contador2]){
			contador1--;
			contador2++;
			while (contador1 >= 0 && palindromo == true){
			 if (v[contador1] == v[contador2]){
				cout << "Comparando " << v[contador1] << " con " << v[contador2] << endl;
				contador1--;
				contador2++;
			 }else
				 palindromo = false;
			}	
		}else
			palindromo = false;
	// Caso tamaño IMPAR.
	}else{
	//}if (v_util | 2 != 0){
		cout << "El vector tiene un número IMPAR de elementos." << endl;
		// El vector, al ser impar, tendrá una única posición en el centro. Empezamos a comparar, como en el caso anterior, las posiciones anteriores y posiciones a la posición central y repitiendo el proceso hasta recorrer todo el vector.
		contador1 = (v_util/2);
		contador2 = contador1;
		contador1-- ;
		contador2++;
		while (contador1 >= 0 && palindromo == true){
			 cout << "Comparando " << v[contador1] << " con " << v[contador2] << endl;
			 if (v[contador1] == v[contador2]){
				contador1--;
				contador2++;
			 }else
				 palindromo = false;
		}	
	}
	
	return palindromo;		
}
	
int main(){
	const int DIM_V = 30;
	/*char v[DIM_V] = {'d','a','b','a','l','e','a','r','r','o','z','a','l','l','a','z','o','r','r','a','e','l','a','b','a','d'};
	int v_util = 26;*/
	char v[DIM_V] = {'d','a','b','a','l','e','a','r','r','o','z','a','l','a','z','o','r','r','a','e','l','a','b','a','d'};
	int v_util = 25;
	
	if (evaluaPalindromo(v,v_util) == true)
		cout << "El vector introducido ES un palíndromo" << endl;
	else
		cout << "El vector introducido NO ES un palíndromo" << endl;
}