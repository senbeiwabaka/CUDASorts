__device__ void GPUquickSort(int arr[],int l,int r);
__device__ void GPUmerge(int arr[],int tempArr[],int x,int mid,int y);
__device__ void GPUmergeSort(int arr[],int tempArr[],int x,int y);
__device__ void GPUstartMerge(int arr[],int tempArr[],int arrSize);
__device__ void GPUinsertionSort(int arr[],int arrLength);
__device__ void GPUselectionSort(int arr[],int arrSize);

__device__ int Rec(int f);