#include "kernel.cu"

__global__ void MergeKernel(int *result, int f)
{
	*result = Rec(f);
}

__global__ void InsertionKernel()
{
}

extern "C" void call(char* name)
{
	int f = 10;
	int *result;
	cudaMalloc((void**)&result, sizeof(int));
	cudaMalloc((void**)&f, sizeof(int));
	MergeKernel<<<1,1>>>(result, f);
}

__device__ void GPUquickSort(int arr[],int l,int r)
{

}

__device__ int Rec(int f)
{
	if(f==0)
	{
		return 1;
	}
}