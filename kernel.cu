#ifndef _KERNEL_H_
#define _KERNEL_H_

#include <iostream>
#include "Test.h"

using namespace std;

template <class T>
__global__ void BubbleKernel(int size, T* arr){
	bool swap = true;
	int x = 0; 
	T temp;
	while(swap){
		swap = false;
		x++;
		for( int i = 0; i < size - x; i++){
			if(arr[i] > arr[i + 1]){
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swap = true;
			}
		}
	}
}

__global__ void InsertionKernel(){
}

template <class T>
void createCUDAMem(T*& arr, dim3 &block, dim3 &grid, int size, T*& cudaArray){
	cudaMalloc((void**)&cudaArray, sizeof(T) * size);
	cudaMemcpy(cudaArray, arr, sizeof(T) * size, cudaMemcpyHostToDevice);

	if(cudaArray == 0)
		cout << "couldn't allocate memory";

	cudaError_t error = cudaGetLastError();

	if(error != cudaSuccess)
		cout << "Cuda Error: " << cudaGetErrorString(error);

	cout << sizeof(T) * size << " " << sizeof(arr) << endl;
}

template <class T>
void destroyCUDAMem(T*& cudaArray, T* arr, int size){
	cudaMemcpy(arr, cudaArray, sizeof(T) * size, cudaMemcpyDeviceToHost);
	cudaFree(&cudaArray);
}

template <class T>
void call(const char* name, T* arr, int size){
	for(int i = 0; i < size; ++i){
		cout << arr[i] << endl;
	}

	cout << sizeof(arr) << " " << sizeof(T) << " " << sizeof(name) << endl;

	cout << typeid(arr).name() << " " << typeid(T).name() << endl;

	T* cudaArray;

	dim3 block, grid;

	createCUDAMem(arr, block, grid, size, cudaArray);

	cout << strcmp(name, "bubble");

	if(strcmp(name, "bubble") == 0){
		BubbleKernel<T><<<1, 1>>>(size, cudaArray);
	}

	destroyCUDAMem(cudaArray, arr, size);

	cout << "After bubble \n";
	for(int i = 0; i < size; ++i){
		cout << arr[i] << endl;
	}
}

template void
call<int>(const char* name, int *arr, int size);

template void
	call<double>(const char* name, double *arr, int size);

template void
	call<char>(const char* name, char *arr, int size);

#endif