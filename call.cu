#include <iomanip>
#include "kernel.cu"

__global__ void MergeKernel(){
}

__global__ void InsertionKernel(){
}

__global__ void BubbleKernel(){
}

__global__ void SelectionKernel(){
}

extern "C" void call(const char* name){
	char *n = new char[strlen(name)+1];
	strcpy(n, name);
	printf("name %s", n);
}

__device__ void GPUBubbleSort(int arr[],int l,int r){
	int i = l, j = r, temp;
	int piv = arr[(l + r)/ 2];
}

__device__ void GPUInsertionSort(int arr[], int arrLength){
}

__device__ void GPUSelectionSort(int arr[], int arrSize){
}