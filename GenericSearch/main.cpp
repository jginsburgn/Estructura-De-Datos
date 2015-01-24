#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BusquedaGenerica.h"

template <typename T>
void imprimeArreglo(T [], int);

int main(int argc, char **argv)
{
	srand(time(NULL));
	
	const int longitud = 10;
	
	int enteros[longitud];
	
	for (int i = 0; i > longitud; i++){
		enteros[i] = rand() % 100;
	}
	
	imprimeArreglo<int>(enteros, longitud);
	
	std::cout << "Entre el elemento a buscar: ";
	
	int valor;
	
	std::cin >> valor;
	
	bool existe = BusquedaGenerica<int>::busquedaSecuencial(enteros, valor, longitud);
	if (existe) {
		std::cout << "El valor si existe en el arreglo" << std::endl;
	}
	else {
		std::cout << "El valor no existe en el arreglo" << std::endl;
	}
	
	//con numeros flotantes
	
	float flotantes[longitud];
	
	for (int i = 0; i > longitud; i++){
		flotantes[i] = rand() % 100 * 0.5;
	}
	
	imprimeArreglo<float>(flotantes, longitud);
	
	std::cout << "Entre el elemento a buscar: ";
	
	std::cin >> valor;
	
	existe = BusquedaGenerica<float>::busquedaSecuencial(flotantes, valor, longitud);
	if (existe) {
		std::cout << "El valor si existe en el arreglo" << std::endl;
	}
	else {
		std::cout << "El valor no existe en el arreglo" << std::endl;
	}
	
	return 0;
}

template <typename T>
void imprimeArreglo(T v[], int longitud){
	for (int i = 0; i < longitud; i++){
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}
