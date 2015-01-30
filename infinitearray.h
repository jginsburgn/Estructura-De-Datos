#ifndef _INFINITEARRAY_H_dkjsahkdsh78768
#define _INFINITEARRAY_H_dkjsahkdsh78768

#include <iostream>

// Here we are declaring a template class
// where T is a substitution for any data type
template <typename T>
class InfiniteArray {
	int currentSize;
	T* data;
	
	void expand(int newSize) {
		std::cout << "expand(" << newSize << ")" << std::endl;
		
		T* newData = new T[newSize];
		for (int i = 0; i < currentSize; ++i)
			newData[i] = data[i];
		delete [] data;
		data = newData;
		currentSize = newSize;
	}
public:
	InfiniteArray() {
		std::cout << "InfiniteArray()" << std::endl;
		
		currentSize = 1;
		data = new T[currentSize];
	}
	
	~InfiniteArray() {
		std::cout << "~InfiniteArray()" << std::endl;
		
		delete [] data;
	}
	
	T& operator[](int i) {
		std::cout << "operator[](" << i << ")" << std::endl;
		
		if (i < 0)
			throw "Cannot use negative index.";
			
		if (i >= currentSize)
			expand(i + 1);
			
		return data[i];
	}
};

#endif //_INFINITEARRAY_H_dkjsahkdsh78768