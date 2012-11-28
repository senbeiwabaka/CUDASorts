#pragma once

template <class T>
class Sorting
{
public:
	Sorting(T* values, int size){
		unsorted = values;
		sorted = new T[size];
		for(int i = 0; i < size; ++i){
			sorted[i] = unsorted[i];
		}
		arrSize = size;
	}

	~Sorting(void){
		delete[] unsorted;
		delete[] sorted;
	}

	/*void bubbleSort(int size){
            bool swap=true;
            int x=0,temp;

            while(swap){
                swap=false;
                x++;
                for(int i=0;i<size-x;i++){
                    if(sorted[i]>sorted[i+1]){
                        temp=sorted[i];
                        sorted[i]=sorted[i+1];
                        sorted[i+1]=temp;
                        swap=true;
                    }
                }
            }
        }*/

	void insertionSort(int size){
		int j, temp;
		for(int i = 1; i < size; ++i){
			j = i;
			while(j > 0 && sorted[j - 1] > sorted[j]){
				temp = sorted[j];
				sorted[j] = sorted[j - 1];
				sorted[j - 1] = temp;
				j--;
			}
		}
	}

	void selectionSort(int size){
		int index, temp;
		for(int i = 0; i < size; ++i){
			index = i;
			for(int j = i + 1; j < size; ++j){
				if(sorted[j] < sorted[index]){
					index = j;
				}
			}
			if(index != i){
				temp = sorted[i];
				sorted[i] = sorted[index];
				sorted[index] = temp;
			}
		}
	}

	void iterMerge(int size){
		int inc,left,leftMax,right,rightMax,cur;
		int *temp = new T[size];
		inc = 1;
		while(inc < size){
		    left = 0;
		    right = inc;
		    leftMax = right - 1;
		    rightMax = (leftMax + inc < size) ? leftMax + inc : size - 1;
		    cur = 0;
		    while(cur < size){
		        while(left <= leftMax && right <= rightMax){
		            if(sorted[right] < sorted[left]){
						temp[cur]=sorted[right++];
					}
		            else{
						temp[cur]=sorted[left++];
					}
		            cur++;
		        }
		        while(right<=rightMax){
					temp[cur++]=sorted[right++];
				}
		        while(left<=leftMax){
					temp[cur++]=sorted[left++];
				}
		        left=right;
		        right+=inc;
		        leftMax=right-1;
		        rightMax=(leftMax+inc<size)?leftMax+inc:size-1;
		    }
		    inc*=2;
		    for(int i=0;i<size;i++){
				sorted[i]=temp[i];
			}
		}
		delete[] temp;
	}

	T* arrayReturn(){
		return sorted;
	}

	void resetArrays()
	{
		cout<<arrSize << endl;
		for(int i = 0; i < arrSize; ++i){
			sorted[i] = unsorted[i];
		}
	}


private:
	T* unsorted;
	T* sorted;

	int arrSize;
};