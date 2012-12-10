#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include "call.h"
#include "Sorting.h"

using namespace std;

const int DISPLAY_SIZE = 10;

template <class T>
const void choice(const char selection, Sorting<T>* s){
	if(selection == '1'){
		//Bubble sort
		cout<<"\nBubble Sort Before: ";
		for(int i=0;i<DISPLAY_SIZE;i++){
		    cout<<s->toArray()[i]<<" ";
		}

		clock_t start = clock();

		(*s).bubbleSort();

		clock_t total = clock();

		cout<<"\nBubble Sort After:  ";
		for(int i=0;i<DISPLAY_SIZE;i++){
		    cout<<(*s).toArray()[i]<<" ";
		}

		cout << "time : " << (double)1000 * (total - start) / CLOCKS_PER_SEC << endl;

		cout << endl;

		(*s).resetArrays();

		cout<<"\nBubble Sort Before: ";
		for(int i=0;i<DISPLAY_SIZE;i++){
		    cout<<s->toArray()[i]<<" ";
		}

		start = clock();

		call<T>("bubble", s->toArray(), (*s).Size());

		total = clock();

		cout<<"\nBubble Sort After:  ";
		for(int i=0;i<DISPLAY_SIZE;i++){
		    cout<<(*s).toArray()[i]<<" ";
		}

		cout << endl;

		cout << (double)1000.0 * (total - start) / (double)CLOCKS_PER_SEC << endl;

		s->resetArrays();
	}
	else if(selection == '2'){
		//Merge sort
		cout<<"\n\nMerge Sort Before: ";
		for(int i=0;i<DISPLAY_SIZE;i++){
		    cout<<(*s).toArray()[i]<<" ";
		}

		clock_t start = clock();

		(*s).iterMerge();

		clock_t total = clock();

		cout<<"\nMerge Sort After:  ";
		for(int i=0;i<DISPLAY_SIZE;i++){
		    cout<<(*s).toArray()[i]<<" ";
		}

		cout << "time : " << (double)1000 * (total - start) / CLOCKS_PER_SEC << endl;

		(*s).resetArrays();

		cout<<"\n\nMerge Sort Before: ";
		for(int i=0;i<DISPLAY_SIZE;i++){
		    cout<<(*s).toArray()[i]<<" ";
		}



		call<T>("merge", s->toArray(), s->Size());

		cout<<"\nMerge Sort After:  ";
		for(int i=0;i<DISPLAY_SIZE;i++){
		    cout<<(*s).toArray()[i]<<" ";
		}

		cout << "time : " << (double)1000 * (total - start) / CLOCKS_PER_SEC << endl;

		cout << endl;

		s->resetArrays();
	}
}

int main(int argc, char** argv)
{
	int* intArray = NULL;
    double* doubleArray = NULL;
    char* charArray = NULL;
	Sorting<int>* intSort;
	Sorting<double>* doubleSort;
	Sorting<char>* charSort;
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
				else if(line == "char"){
					charArray = new char[size];

					for(int i = 0; i < size; ++i){
						myfile >> charArray[i];
					}

					charSort = new Sorting<char>(charArray, size);
				}
			}

			myfile.close();
		}
	}
	else if(argc == 3){
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
			else if(line == "char"){
				charArray = new char[size];

				for(int i = 0; i < size; ++i){
					myfile >> charArray[i];
				}

				charSort = new Sorting<char>(charArray, size);
			}
		}

		myfile.close();

		myfile = ifstream(argv[2]);
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
			else if(line == "char"){
				charArray = new char[size];

				for(int i = 0; i < size; ++i){
					myfile >> charArray[i];
				}

				charSort = new Sorting<char>(charArray, size);
			}
		}

		myfile.close();
	}
	else if(argc == 4){
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
			else if(line == "char"){
				charArray = new char[size];

				for(int i = 0; i < size; ++i){
					myfile >> charArray[i];
				}

				charSort = new Sorting<char>(charArray, size);
			}
		}

		myfile.close();

		myfile = ifstream(argv[2]);
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
			else if(line == "char"){
				charArray = new char[size];

				for(int i = 0; i < size; ++i){
					myfile >> charArray[i];
				}

				charSort = new Sorting<char>(charArray, size);
			}
		}

		myfile.close();

		myfile = ifstream(argv[3]);
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
			else if(line == "char"){
				charArray = new char[size];

				for(int i = 0; i < size; ++i){
					myfile >> charArray[i];
				}

				charSort = new Sorting<char>(charArray, size);
			}
		}

		myfile.close();
	}
	else{
	}


	cout << "which algorithm do you want to sort by? " << endl;
	cout << "1 bubble \n2 merge \n0 Quit" << endl;

	char selection = 0;

	cin >> selection;
	
	while(selection != '0'){
		if(selection == '1' || selection == '2'){
			cout << "What type would you like to sort";
			cout << "\n1 int \n2 double \n3 char \n0 Quit";
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
			else if(type != '0'){
				cout << "What type would you like to sort";
				cout << "\n1 int \n2 double \n3 char \n0 Quit\n";
				cin >> type;
			}

			cout << "which algorithm do you want to sort by? " << endl;
			cout << "1 bubble \n2 merge \n0 Quit\n" << endl;

			cin >> selection;
		}
		else{
			cout << "which algorithm do you want to sort by? " << endl;
			cout << "1 bubble \n2 merge \n0 Quit" << endl;

			cin >> selection;
		}
	}

	if(intArray != NULL){
		delete[] intArray;
	}

	if(doubleArray != NULL){
		delete[] doubleArray;
	}

	if(charArray != NULL){
		delete[] charArray;
	}

	return 0;
}