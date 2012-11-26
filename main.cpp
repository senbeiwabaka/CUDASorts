#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cuda.h>
#include "Sorting.h"

using namespace std;

extern "C" void call(const char* name);

const int SIZE=10;

const char* choice(int s);

int main(int argc, char **argv){
    int quickArr[SIZE]={4,10,3,1,5,9,7,8,6,2};
    int mergeArr[SIZE]={9,7,2,6,3,10,4,1,5,8};
    int mergeTemp[SIZE];
    int insertArr[SIZE]={2,1,9,3,8,10,4,7,6,5};
    int selectArr[SIZE]={1,10,2,9,3,8,4,7,5,6};
	int iterMergeArr[SIZE]={10,1,9,2,8,3,7,4,6,5};

	Sorting s = Sorting(SIZE);

	srand(time(0));
    
	for(int i = 0; i < SIZE; ++i)
	{
		quickArr[i] = rand();
	}

	cout << argc << endl;
	cout << "usuage " << argv[1] << endl;

    //Quick sort
    cout<<"Quick Sort Before: ";
    for(int i=0;i<SIZE;i++){
        cout<<quickArr[i]<<" ";
    }
    cout<<"\nQuick Sort After:  ";
	s.quickSort(quickArr, 0, SIZE - 1);
    for(int i=0;i<SIZE;i++){
        cout<<quickArr[i]<<" ";
    }
    //Merge sort
    cout<<"\n\nMerge Sort Before: ";
    for(int i=0;i<SIZE;i++){
        cout<<mergeArr[i]<<" ";
    }
	s.startMerge(mergeArr,mergeTemp,SIZE);
    cout<<"\nMerge Sort After:  ";
    for(int i=0;i<SIZE;i++){
        cout<<mergeArr[i]<<" ";
    }
    //Insertion sort
    cout<<"\n\nInsertion Sort Before: ";
    for(int i=0;i<SIZE;i++){
        cout<<insertArr[i]<<" ";
    }
    s.insertionSort(insertArr,SIZE);
    cout<<"\nInsertion Sort After:  ";
    for(int i=0;i<SIZE;i++){
        cout<<insertArr[i]<<" ";
    }
    //Selection sort
    cout<<"\n\nSelection Sort Before: ";
    for(int i=0;i<SIZE;i++){
        cout<<selectArr[i]<<" ";
    }
    s.selectionSort(selectArr,SIZE);
    cout<<"\nSelection Sort After:  ";
    for(int i=0;i<SIZE;i++){
        cout<<selectArr[i]<<" ";
    }

	//Iterative Merge sort
    cout<<"\n\nIterative Merge Sort Before: ";
    for(int i=0;i<SIZE;i++){
        cout<<iterMergeArr[i]<<" ";
    }
    s.iterMerge(iterMergeArr,SIZE);
    cout<<"\nIterative Merge Sort After:  ";
    for(int i=0;i<SIZE;i++){
        cout<<iterMergeArr[i]<<" ";
    }

	cout << endl;

	cout << "which algorithm do you want to sort by? " << endl;
	cout << "1 quick \n2 merge \n3 insertion \n4 selection" << endl;

	int selection;

	cin >> selection;
	
	call(choice(selection));
    
    return 0;
}

const char* choice(int s){
	if(s == 1)
	{
		return "quick";
	}
	else if(s == 2)
	{
		return "merge";
	}
	else if(s == 3)
	{
		return "insertion";
	}
	else
	{
		return "selection";
	}
}