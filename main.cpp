#include <Windows.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cuda.h>
#include <string>
#include <fstream>
#include "Sorting.h"
#include "Test.h"

using namespace std;

extern "C" void call(const char* name);

template <class T>
const void choice(const char selection, int size, Sorting<T>* s){
	if(selection == '1')
	{
		//Bubble sort
		cout<<"\nBubble Sort Before: ";
		for(int i=0;i<size;i++){
		    cout<<(*s).arrayReturn()[i]<<" ";
		}
		(*s).bubbleSort(size);
		cout<<"\nBubble Sort After:  ";
		for(int i=0;i<size;i++){
		    cout<<(*s).arrayReturn()[i]<<" ";
		}

		(*s).resetArrays();
	}
	else if(selection == '2')
	{
		//Merge sort
		cout<<"\n\nMerge Sort Before: ";
		for(int i=0;i<size;i++){
		    cout<<(*s).arrayReturn()[i]<<" ";
		}
		(*s).iterMerge(size);
		cout<<"\nMerge Sort After:  ";
		for(int i=0;i<size;i++){
		    cout<<(*s).arrayReturn()[i]<<" ";
		}

		(*s).resetArrays();
	}
	else if(selection == '3')
	{
		//Insertion sort
		cout<<"\n\nInsertion Sort Before: ";
		for(int i=0;i<size;i++){
		    cout<<(*s).arrayReturn()[i]<<" ";
		}
		(*s).insertionSort(size);
		cout<<"\nInsertion Sort After:  ";
		for(int i=0;i<size;i++){
		    cout<<(*s).arrayReturn()[i]<<" ";
		}

		(*s).resetArrays();
	}
	else if(selection == '4')
	{
		//Selection sort
		cout<<"\n\nSelection Sort Before: ";
		for(int i=0;i<size;i++){
		    cout<<(*s).arrayReturn()[i]<<" ";
		}
		(*s).selectionSort(size);
		cout<<"\nSelection Sort After:  ";
		for(int i=0;i<size;i++){
		    cout<<(*s).arrayReturn()[i]<<" ";
		}

		(*s).resetArrays();
	}
	else{
		cout << "please enter the correct value";
	}
}


int main(int argc, char *argv[]){
    int intArray[10]={4,10,3,1,5,9,7,8,6,2};
    float floatArray[10]={9,7,2,6,3,10,4,1,5,8};
    char charArray[10]={2,1,9,3,8,10,4,7,6,5};

	Sorting<int>* s = new Sorting<int>(intArray, 10);

	if(argc == 2)
	{
		string arg = argv[1];
		if(arg == "-help" || arg == "-h")
		{
			cout << "To use this program you can either run it with a txt file for loading in values for the array " <<
				"or you can run it without a text file and it will randomly fill the array with ints" << endl;

			Sleep(2000);

			exit(0);
		}
		else
		{
			cout << argv[1] << endl;
			ifstream myfile (argv[1]);
			if(myfile.is_open())
			{
				string line;

				while(myfile.good())
				{
					getline(myfile, line);
					cout << line << endl;
				}
			}

			myfile.close();
		}
	}

	cout << endl << endl;

	cout << "which algorithm do you want to sort by? " << endl;
	cout << "1 quick \n2 merge \n3 insertion \n4 selection \n0 Quit\n" << endl;

	char selection = 0;

	cin >> selection;
	
	while(selection != '0')
	{
		if(selection == '1' || selection == '2' || selection == '3' || selection == '4'){
			choice(selection, 10, s);

			cout << "which algorithm do you want to sort by? " << endl;
			cout << "1 quick \n2 merge \n3 insertion \n4 selection \n0 Quit\n" << endl;

			cin >> selection;
		}
		else{
			cout << "which algorithm do you want to sort by? " << endl;
			cout << "1 quick \n2 merge \n3 insertion \n4 selection \n0 Quit\n" << endl;

			cin >> selection;
		}
	}
    
    return 0;
}