#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cuda.h>
#include "Sorting.h"
#include "Test.h"

using namespace std;

extern "C" void call(const char* name);

const int SIZE=10;

template <class T>
const char* choice(int selection, T* arr, int size, Sorting<T> s){
	if(selection == 1)
	{
		//Quick sort
		cout<<"Quick Sort Before: ";
		for(int i=0;i<size;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\nQuick Sort After:  ";
		s.quickSort(arr, 0, size - 1);
		for(int i=0;i<size;i++){
			cout<<arr[i]<<" ";
		}

		return "quick";
	}
	else if(selection == 2)
	{
		//Merge sort
		cout<<"\n\nMerge Sort Before: ";
		for(int i=0;i<size;i++){
		    cout<<arr[i]<<" ";
		}
		s.iterMerge(arr, size);
		cout<<"\nMerge Sort After:  ";
		for(int i=0;i<size;i++){
		    cout<<arr[i]<<" ";
		}

		return "merge";
	}
	else if(selection == 3)
	{
		//Insertion sort
		cout<<"\n\nInsertion Sort Before: ";
		for(int i=0;i<size;i++){
		    cout<<arr[i]<<" ";
		}
		s.insertionSort(arr,size);
		cout<<"\nInsertion Sort After:  ";
		for(int i=0;i<size;i++){
		    cout<<arr[i]<<" ";
		}

		return "insertion";
	}
	else
	{
		//Selection sort
		cout<<"\n\nSelection Sort Before: ";
		for(int i=0;i<size;i++){
		    cout<<arr[i]<<" ";
		}
		s.selectionSort(arr,size);
		cout<<"\nSelection Sort After:  ";
		for(int i=0;i<size;i++){
		    cout<<arr[i]<<" ";
		}

		return "selection";
	}
}


int main(int argc, char **argv){
    int intArray[SIZE]={4,10,3,1,5,9,7,8,6,2};
    float floatArray[SIZE]={9,7,2,6,3,10,4,1,5,8};
    char charArray[SIZE]={2,1,9,3,8,10,4,7,6,5};

	Sorting<int> s = Sorting<int>(intArray, 10);

	
	Test penis;
	penis.setChar('a');
	penis.setNum(10);

	cout << argc << endl;
	cout << "usuage " << argv[1] << endl;

	cout << endl << endl;

	cout << penis.getChar() << " " << penis.getNum() << endl;

	cout << "which algorithm do you want to sort by? " << endl;
	cout << "1 quick \n2 merge \n3 insertion \n4 selection" << endl;

	int selection;

	cin >> selection;
	
	call(choice(selection, intArray, 10, s));
    
    return 0;
}