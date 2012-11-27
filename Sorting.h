#pragma once

template <class T>
class Sorting
{
public:
	Sorting(T* values, int size){
		//unsorted = values;
	}

	~Sorting(void){
	}

	void quickSort(T* arr, int l, int r){
		int i=l,j=r,temp;
		int piv=arr[(l+r)/2];
		
		while(i<=j){
		    while(arr[i]<piv){i++;}
		    while(arr[j]>piv){j--;}
		    if(i<=j){
		        temp=arr[i];
		        arr[i]=arr[j];
		        arr[j]=temp;
		        i++;
		        j--;
		    }
		}

		if(l<j){quickSort(arr,l,j);}
		if(i<r){quickSort(arr,i,r);}
	}

	void insertionSort(T* arr, int size){
		int j, temp;
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

	void selectionSort(T* arr, int size){
		int index, temp;
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

	void iterMerge(T* arr, int size){
		int inc,left,leftMax,right,rightMax,cur;
		int *temp = new int[size];
		inc=1;
		while(inc<size){
		    left=0;
		    right=inc;
		    leftMax=right-1;
		    rightMax=(leftMax+inc<size)?leftMax+inc:size-1;
		    cur=0;
		    while(cur<size){
		        while(left<=leftMax && right<=rightMax){
		            if(arr[right]<arr[left]){temp[cur]=arr[right++];}
		            else{temp[cur]=arr[left++];}
		            cur++;
		        }
		        while(right<=rightMax){temp[cur++]=arr[right++];}
		        while(left<=leftMax){temp[cur++]=arr[left++];}
		        left=right;
		        right+=inc;
		        leftMax=right-1;
		        rightMax=(leftMax+inc<size)?leftMax+inc:size-1;
		    }
		    inc*=2;
		    for(int i=0;i<size;i++){arr[i]=temp[i];}
		}
	}


private:
	T* unsorted;
	T* sorted;
	void resetArrays();
};