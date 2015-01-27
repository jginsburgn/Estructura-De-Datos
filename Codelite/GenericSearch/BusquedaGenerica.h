#include <iostream>

template <typename T>
class BusquedaGenerica {
public:
	static bool busquedaSecuencial(T v[], T valor, int longitud){
		int indice = 0;
	
		if (longitud <= 0) return false;
		
		while (indice < longitud){
			if (v[indice++] == valor) return true;
		}
		return false;
	};
};
