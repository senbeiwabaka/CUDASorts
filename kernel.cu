#ifndef _KERNEL_H_
#define _KERNEL_H_

#include <iomanip>
#include "Test.h"

template <class T>
__global__ void BubbleKernel(int size, T* arr){
	bool swap = true;
	int x = 0; 
	T temp;
	while(swap){
		swap = false;
		x++;
		for( int i = 0; i < size; i++){
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
void createCUDAMem(T* arr, dim3 &block, dim3 &grid, int size, T* cudaArray){
	cudaMalloc((void**)&cudaArray, sizeof(arr) * size);
	cudaMemcpy(cudaArray, arr, sizeof(arr) * size, cudaMemcpyHostToDevice);
}

template <class T>
void destroyCUDAMem(T* cudaArray, T* arr, int size){
	cudaMemcpy(arr, cudaArray, sizeof(arr) * size, cudaMemcpyDeviceToHost);
	cudaFree(cudaArray);
}

template <class T>
void call(const char* name, T* arr, int size){
	char *n = new char[strlen(name)+1];
	strcpy(n, name);
	printf("name %s", n);

	T* cudaArray;

	dim3 block, grid;

	createCUDAMem(arr, block, grid, size, cudaArray);

	if(name == "bubble"){
		BubbleKernel<T><<<1, 1>>>(size, cudaArray);
	}

	destroyCUDAMem(cudaArray, arr, size);
}

template void
call<int>(const char* name, int *arr, int size);

template void
	call<double>(const char* name, double *arr, int size);

template void
	call<char>(const char* name, char *arr, int size);

#endif