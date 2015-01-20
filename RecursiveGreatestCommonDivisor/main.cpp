#include <stdio.h>
#include <iostream>

using namespace std;

int GreatestCommonDivisor(int, int);
int ReadNumber(string);


int main(int argc, char **argv)
{
	int m = ReadNumber("Ingrese numero m");
	int n = ReadNumber("Ingrese numero n (menor que m)");
	cout << "El MCD es: " << GreatestCommonDivisor(m, n);
	return 0;
}

int GreatestCommonDivisor(int m, int n){
	int r = m % n;
	if (r == 0) return n;
	else{
		return GreatestCommonDivisor(n, r);
	}
}

int ReadNumber(string prompt){
	cout << prompt << endl;
	int value = 0;
	cin >> value;
	return value;
}