#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int ReadNumber(string);
int MatrixComponentAddition(int**, int, int, int);

int main(int argc, char **argv)
{
	int rows = ReadNumber("Ingrese el número de renglones de la matriz");
	int columns = ReadNumber("Ingrese el número de columnas de la matriz");
	int** matrix = new int*[rows];
	for(int i = 0; i < rows; ++i) matrix[i] = new int[columns];
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			string prompt = "Ingrese el componente " + to_string(i + 1) + ", " + to_string(j+1) + " de la matriz";
			matrix[i][j] = ReadNumber(prompt);
		}
	}
	cout << "La adición de todos los componentes de la matriz es: " << MatrixComponentAddition(matrix, rows - 1, columns - 1, columns - 1) << endl;
	return 0;
}

int MatrixComponentAddition(int** matrix, int rows, int columns, int totalColumns){
	if (rows == 0) {
		if (columns == 0) return matrix[rows][columns];
		else return matrix[rows][columns] + MatrixComponentAddition(matrix, rows, columns - 1, totalColumns);
	}
	else{
		if (columns == 0) return matrix[rows][columns] + MatrixComponentAddition(matrix, rows - 1, totalColumns, totalColumns);
		else return matrix[rows][columns] + MatrixComponentAddition(matrix, rows, columns - 1, totalColumns);
	}
}

int ReadNumber(string prompt){
	cout << prompt << endl;
	int value = 0;
	cin >> value;
	return value;
}