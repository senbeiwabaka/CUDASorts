#pragma once
class Sorting
{
public:
	Sorting(int s);
	~Sorting(void);
	void quickSort(int arr[],int l,int r);
	void startMerge(int arr[],int tempArr[],int arrSize);
	void insertionSort(int arr[],int arrLength);
	void selectionSort(int arr[],int arrSize);
	void setSize(int s);

private:
	void merge(int arr[],int tempArr[],int x,int mid,int y);
	void mergeSort(int arr[],int tempArr[],int x,int y);
	int Size;
};