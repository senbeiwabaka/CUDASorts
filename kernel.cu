#ifndef _KERNEL_H_
#define _KERNEL_H_

#include <iomanip>
#include "Test.h"

template <class T>
__global__ void BubbleKernel(int size, T* arr){
	bool swap = true;
	int x = 0; int temp;
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
void call(const char* name, T* arr, int size){
	char *n = new char[strlen(name)+1];
	strcpy(n, name);
	//printf("name %s", n);

	if(name == "bubble"){
		BubbleKernel<T><<<1, 1>>>(size, arr);
	}
}

template void
call<int>(const char* name, int *arr, int size);

template void
	call<float>(const char* name, float *arr, int size);

template void
	call<char>(const char* name, char *arr, int size);

#endif