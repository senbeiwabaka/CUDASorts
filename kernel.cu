#ifndef _KERNEL_H_
#define _KERNEL_H_

#include <iostream>
#include "cuda_runtime.h"
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

template <class T>
__global__ void InsertionKernel(int size, T* arr){
	int j;
	T temp;
	for(int i = 1; i < size; ++i){
		j = i;
		while(j > 0 && arr[j - 1] > arr[j]){
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}

template <class T>
__global__ void IterMergeKernel(int size, T* arr){
	int inc,left,leftMax,right,rightMax,cur;
	T *temp = new T[size];
	inc = 1;
	while(inc < size){
	    left = 0;
	    right = inc;
	    leftMax = right - 1;
	    rightMax = (leftMax + inc < size) ? leftMax + inc : size - 1;
	    cur = 0;
	    while(cur < size){
	        while(left <= leftMax && right <= rightMax){
	            if(arr[right] < arr[left]){
					temp[cur]=arr[right++];
				}
	            else{
					temp[cur]=arr[left++];
				}
	            cur++;
	        }
	        while(right<=rightMax){
				temp[cur++]=arr[right++];
			}
	        while(left<=leftMax){
				temp[cur++]=arr[left++];
			}
	        left=right;
	        right+=inc;
	        leftMax=right-1;
	        rightMax=(leftMax+inc<size)?leftMax+inc:size-1;
	    }
	    inc*=2;
	    for(int i=0;i<size;i++){
			arr[i]=temp[i];
		}
	}

	delete[] temp;

	printf("hello");
}

template <class T>
__global__ void SelectionKernel(int size, T* arr){
	int index;
	T temp;
	for(int i = 0; i < size; ++i){
		index = i;
		for(int j = i + 1; j < size; ++j){
			if(arr[j] < arr[index]){
				index = j;
			}
		}
		if(index != i){
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
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
}

template <class T>
void destroyCUDAMem(T*& cudaArray, T*& arr, int size){
	cudaMemcpy(arr, cudaArray, sizeof(T) * size, cudaMemcpyDeviceToHost);
	cudaFree(cudaArray);
}

template <class T>
void call(const char* name, T* arr, int size){

	T* cudaArray;

	dim3 block, grid;

	createCUDAMem(arr, block, grid, size, cudaArray);

	if(strcmp(name, "bubble") == 0){
		BubbleKernel<T><<<1, 1>>>(size, cudaArray);
	}
	else if(strcmp(name, "merge") == 0){
		IterMergeKernel<T><<<1, 1>>>(size, cudaArray);
	}
	else if(strncmp(name, "selection", 9) == 0){
		SelectionKernel<T><<<1, 1>>>(size, cudaArray);
	}
	else if(strncmp(name, "insertion", 9) == 0){
		InsertionKernel<T><<<1, 1>>>(size, cudaArray);
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