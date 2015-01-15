#include <stdio.h>
#include <iostream>

using namespace std;

void hanoi(int, int, int, int);

int main(int argc, char **argv)
{
	int numero_discos = 0;
	
	cout << "Entre el número de discos: " << endl;
	cin >> numero_discos;
	
	if(numero_discos < 1){
		cout << "El número de discos debe ser > 0" << endl;
		return 1;
	}
	
	hanoi(numero_discos, 1, 3, 2);
	
	return 0;
}

void hanoi(int n, int x, int y, int z){
	if (n == 1){
		cout << n << ": " << x << "-->" << y << endl;
	}
	else {
		hanoi(n-1, x, z, y);
		
		//Mover los discos
		cout << n << ": " << x << "-->" << y << endl;
		hanoi(n-1, z, y, x);
	}
}