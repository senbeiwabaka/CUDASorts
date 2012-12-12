#ifndef __SORTING_H_
#define __SORTING_H_

//sorting class that is templated
template <class T>
class Sorting
{
public:
	//takes in any data type and a size then sets two arrays. one for sorting and the other to reset the sorted array
	Sorting<T>(T* values, int size){
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

	//bubble sort
	void bubbleSort(){
            bool swap=true;
            int x=0;
			T temp;

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

	//iterative merge sort
	void iterMerge(){
		int inc,left,leftMax,right,rightMax,cur;
		T *temp = new T[arrSize];
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

	//returns the array
	T* toArray(){
		return sorted;
	}

	//sets the sorted array to the unsorted array
	void resetArrays(){
		for(int i = 0; i < arrSize; ++i){
			sorted[i] = unsorted[i];
		}
	}

	//returns array size
	const int Size(){
		return arrSize;
	}


private:
	//for resetting sorted array
	T* unsorted;
	//the array to be sorted
	T* sorted;

	int arrSize;
};

#endif