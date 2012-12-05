#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cuda.h>
#include <string>
#include <fstream>
#include "call.h"
#include "Sorting.h"
#include "Test.h"

using namespace std;

template <class T>
const void choice(const char selection, Sorting<T>* s){
	if(selection == '1'){
		//Bubble sort
		cout<<"\nBubble Sort Before: ";
		for(int i=0;i<s->Size();i++){
		    cout<<s->toArray()[i]<<" ";
		}

		(*s).bubbleSort();

		cout<<"\nBubble Sort After:  ";
		for(int i=0;i<s->Size();i++){
		    cout<<(*s).toArray()[i]<<" ";
		}

		cout << endl;

		(*s).resetArrays();

		//call<T>("bubble", (*s).toArray(), (*s).Size());

		cout<<"\nBubble Sort After:  ";
		for(int i=0;i<s->Size();i++){
		    cout<<(*s).toArray()[i]<<" ";
		}

		s->resetArrays();
	}
	else if(selection == '2'){
		//Merge sort
		cout<<"\n\nMerge Sort Before: ";
		for(int i=0;i<s->Size();i++){
		    cout<<(*s).toArray()[i]<<" ";
		}
		(*s).iterMerge();
		cout<<"\nMerge Sort After:  ";
		for(int i=0;i<s->Size();i++){
		    cout<<(*s).toArray()[i]<<" ";
		}

		(*s).resetArrays();
	}
	else if(selection == '3'){
		//Insertion sort
		cout<<"\n\nInsertion Sort Before: ";
		for(int i=0;i<s->Size();i++){
		    cout<<(*s).toArray()[i]<<" ";
		}
		(*s).insertionSort();
		cout<<"\nInsertion Sort After:  ";
		for(int i=0;i<s->Size();i++){
		    cout<<(*s).toArray()[i]<<" ";
		}

		(*s).resetArrays();
	}
	else if(selection == '4'){
		//Selection sort
		cout<<"\n\nSelection Sort Before: ";
		for(int i=0;i<s->Size();i++){
		    cout<<(*s).toArray()[i]<<" ";
		}
		(*s).selectionSort();
		cout<<"\nSelection Sort After:  ";
		for(int i=0;i<s->Size();i++){
		    cout<<(*s).toArray()[i]<<" ";
		}

		(*s).resetArrays();
	}
	else{
		cout << "please enter the correct value";
	}
}

int main(int argc, char** argv)
{
	int* intArray = NULL;
    double* doubleArray = NULL;
    char* charArray = NULL;
	Test* testArray = NULL;
	Sorting<int>* intSort;
	Sorting<double>* doubleSort;
	Sorting<char>* charSort;
	Sorting<Test>* testSort;
	char type = 0;

	if(argc == 2){
		string arg = argv[1];
		if(arg == "-help" || arg == "-h"){
			cout << "To use this program you can either run it with a txt file for loading in values for the array " <<
				"or you can run it without a text file and it will randomly fill the array with ints" << endl;

			exit(0);
		}
		else{
			ifstream myfile (argv[1]);
			int size;
			if(myfile.is_open()){
				string line;

				myfile >> line >> size;

				if(line == "int"){
					intArray = new int[size];

					for(int i = 0; i < size; ++i){
						myfile >> intArray[i];
					}

					intSort = new Sorting<int>(intArray, size);
				}
				else if(line == "double"){
					doubleArray = new double[size];

					for(int i = 0; i < size; ++i){
						myfile >> doubleArray[i];
					}

					doubleSort = new Sorting<double>(doubleArray, size);
				}
			}

			myfile.close();
			}
		}

	cout << "which algorithm do you want to sort by? " << endl;
	cout << "1 bubble \n2 merge \n3 insertion \n4 selection \n0 Quit\n" << endl;

	char selection = 0;

	cin >> selection;
	
	while(selection != '0'){
		if(selection == '1' || selection == '2' || selection == '3' || selection == '4'){
			cout << "What type would you like to sort";
			cout << "\n1 int \n2 double \n3 char \n4 Test \n0 Quit\n";
			cin >> type;
			if(type == '1')
			{
				choice(selection, intSort);
			}
			else if(type == '2')
			{
				choice(selection, doubleSort);
			}
			else if(type == '3'){
				choice(selection, charSort);
			}
			else if(type == '4'){
				//choice(selection, testSort);
			}
			else{
				cout << "What type would you like to sort";
				cout << "1 int \n2 double \n3 char \n4 Test \n0 Quit\n";
				cin >> type;
			}

			cout << "which algorithm do you want to sort by? " << endl;
			cout << "1 bubble \n2 merge \n3 insertion \n4 selection \n0 Quit\n" << endl;

			cin >> selection;
		}
		else{
			cout << "which algorithm do you want to sort by? " << endl;
			cout << "1 bubble \n2 merge \n3 insertion \n4 selection \n0 Quit\n" << endl;

			cin >> selection;
		}
	}

	if(intArray != NULL)
	{
		delete[] intArray;
	}

	if(doubleArray != NULL){
		delete[] doubleArray;
	}

	return 0;
}