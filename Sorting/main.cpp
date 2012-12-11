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
		clock_t start = clock();

		(*s).bubbleSort();

		clock_t total = clock();

		cout << endl << "Host Time : " << total - start << endl;

		cout << endl;

		(*s).resetArrays();

		start = clock();

		call<T>("bubble", s->toArray(), (*s).Size());

		total = clock();

		cout << endl << "Device Time : " << total - start << endl << endl;

		s->resetArrays();
	}
	else if(selection == '2'){
		clock_t start = clock();

		(*s).iterMerge();

		clock_t total = clock();

		cout << endl << "Host Time : " << total - start << endl;

		(*s).resetArrays();

		start = clock();

		call<T>("merge", s->toArray(), s->Size());

		total = clock();

		cout << endl << "Device Time : " << total - start << endl << endl;

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

	char alphabet[]={'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'};

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
		int size = 1024;
		intArray = new int[size];
		doubleArray = new double[size];
		charArray = new char[size];

		for(int i = 0; i < size; ++i){
			intArray[i] = (rand()%1000)+1;
			doubleArray[i] = ((double)(rand()%100+1)/101)*100.0;
			charArray[i] = alphabet[rand()%52];
		}

		intSort = new Sorting<int>(intArray, size);
		doubleSort = new Sorting<double>(doubleArray, size);
		charSort = new Sorting<char>(charArray, size);
	}


	cout << "which algorithm do you want to sort by? " << endl;
	cout << "1 bubble \n2 merge \n0 Quit" << endl;

	char selection = 0;

	cin >> selection;
	
	while(selection != '0'){
		if(selection == '1' || selection == '2'){
			cout << "What type would you like to sort";
			cout << "\n1 int \n2 double \n3 char \n0 Quit" << endl;
			cin >> type;
			if(type == '1'){
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
				cout << "\n1 int \n2 double \n3 char \n0 Quit" << endl;
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