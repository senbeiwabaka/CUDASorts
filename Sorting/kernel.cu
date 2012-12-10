#ifndef _KERNEL_H_
#define _KERNEL_H_

#include <iostream>

using namespace std;

template <class T>
__global__ void BubbleKernel(int size, T* arr){
	int id = blockDim.x * blockIdx.x + threadIdx.x;

	//run the sorting algorithm  for ARRAY_SIZE^2
	for(int i = 0; i < size; i++)
	{
	  //check if the thread id number is even
	  if((id % 2) == 0 && id + 1 < size )
	    {
	      if(arr[id] > arr[id + 1])
	        {
	          T temp = arr[id + 1];
	          arr[id + 1] = arr[id];
	          arr[id] = temp;
	        }
	    }
	
	 __syncthreads();
	
	  //check if the thread id number is odd
	  if((id % 2) != 0 && id + 1 < size )
	    {
	    if(arr[id] > arr[id + 1])
	      {
	         T temp = arr[id + 1];
	         arr[id + 1] =arr[id];
	         arr[id] = temp;
	      }
	   }
	__syncthreads();
	
	}
}

template <class T>
__device__ void Merge(T* arr, T* results, int l, int r, int u){
	int i,j,k;
	i=l; j=r; k=l;
	while (i<r && j<u) { 
	  if (arr[i]<=arr[j]) {
		  results[k]=arr[i]; 
		  i++;} 
	  else {
		  results[k]=arr[j]; 
		  j++;}
	  k++;
	}
	
	while (i<r) { 
	  results[k]=arr[i]; i++; k++;
	}
	
	while (j<u) { 
	  results[k]=arr[j]; j++; k++;
	}
	for (k=l; k<u; k++) { 
	  arr[k]=results[k]; 
	}
}

//come back to this one
template <class T>
__global__ void IterMergeKernel(int size, T* arr){
    int tid = threadIdx.x;
    int k,u,i;

	T* results = new T[size];
    
    k = 1;
    while(k < size)
    {
        i = 1;
        while(i+k < size)
        {
            u = i+k*2;
            if(u > size)
            {
                u = size+1;
            }
            Merge(arr, results, i, i+k, u);
            i = i+k*2;
        }
        k = k*2;
        __syncthreads();
    }
}

template <class T>
void createCUDAMem(T*& arr, int size, T*& cudaArray){
	cudaError_t error;

	error = cudaMalloc((void**)&cudaArray, sizeof(T) * size);

	if(error != cudaSuccess)
		cout << "Cuda Error: " << cudaGetErrorString(error);

	error = cudaMemcpy(cudaArray, arr, sizeof(T) * size, cudaMemcpyHostToDevice);

	if(cudaArray == 0)
		cout << "couldn't allocate memory";

	if(error != cudaSuccess)
		cout << "Cuda Error: " << cudaGetErrorString(error);
}

template <class T>
void destroyCUDAMem(T*& cudaArray, T*& arr, int size){
	cudaError_t error;
	error = cudaMemcpy(arr, cudaArray, sizeof(T) * size, cudaMemcpyDeviceToHost);

	if(error != cudaSuccess)
		cout << "Cuda Error: " << cudaGetErrorString(error);
	error = cudaFree(cudaArray);
}

template <class T>
void call(const char* name, T* arr, int size){

	T* cudaArray;

	dim3 grid(1, 1);
	dim3 block(size / 2, 1);

	createCUDAMem(arr, size, cudaArray);

	if(strcmp(name, "bubble") == 0){
		BubbleKernel<T><<<grid, block>>>(size, cudaArray);
	}
	else if(strcmp(name, "merge") == 0){
		IterMergeKernel<T><<<grid, block>>>(size, cudaArray);
	}

	cudaThreadSynchronize();

	cudaError_t wrong = cudaGetLastError();

	if(wrong != cudaSuccess)
	{
		cout << cudaGetErrorString(wrong) << endl;
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