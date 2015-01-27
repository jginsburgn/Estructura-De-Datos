#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int ReadNumber(string);
int VectorComponentAddition(int*, int);

int main(int argc, char **argv)
{
	int Length = ReadNumber("Ingrese longitud de vector");
	int* Vector = new int[Length];
	for (int i = 0; i < Length; i++){
		string prompt = "Ingrese el componente " + to_string(i + 1);
		Vector[i] = ReadNumber(prompt);
	}
	cout << "La suma de los componentes del vector es: " << VectorComponentAddition(Vector, Length) << endl;
	delete [] Vector;
	return 0;
}

int VectorComponentAddition(int* Vector, int Length){
	if (Length == 0) return Vector[Length];
	else return Vector[Length] + VectorComponentAddition(Vector, Length - 1);
}

int ReadNumber(string prompt){
	cout << prompt << endl;
	int value = 0;
	cin >> value;
	return value;
}