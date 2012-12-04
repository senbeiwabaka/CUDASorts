#ifndef __SORTING_H_
#define __SORTING_H_

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

	void bubbleSort(){
            bool swap=true;
            int x=0,temp;

            while(swap){
                swap=false;
                x++;
                for(int i=0;i<arrSize-x;i++){
                    if(sorted[i]>sorted[i+1]){
                        temp=sorted[i];
                        sorted[i]=sorted[i+1];
                        sorted[i+1]=temp;
                        swap=true;
                    }
                }
            }
        }

	void insertionSort(){
		int j, temp;
		for(int i = 1; i < arrSize; ++i){
			j = i;
			while(j > 0 && sorted[j - 1] > sorted[j]){
				temp = sorted[j];
				sorted[j] = sorted[j - 1];
				sorted[j - 1] = temp;
				j--;
			}
		}
	}

	void selectionSort(){
		int index, temp;
		for(int i = 0; i < arrSize; ++i){
			index = i;
			for(int j = i + 1; j < arrSize; ++j){
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

	void iterMerge(){
		int inc,left,leftMax,right,rightMax,cur;
		int *temp = new T[arrSize];
		inc = 1;
		while(inc < arrSize){
		    left = 0;
		    right = inc;
		    leftMax = right - 1;
		    rightMax = (leftMax + inc < arrSize) ? leftMax + inc : arrSize - 1;
		    cur = 0;
		    while(cur < arrSize){
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
		        rightMax=(leftMax+inc<arrSize)?leftMax+inc:arrSize-1;
		    }
		    inc*=2;
		    for(int i=0;i<arrSize;i++){
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
		//cout<<arrSize << endl;
		for(int i = 0; i < arrSize; ++i){
			sorted[i] = unsorted[i];
		}
	}

	const int Size(){
		return arrSize;
	}


private:
	T* unsorted;
	T* sorted;

	int arrSize;
};

#endif