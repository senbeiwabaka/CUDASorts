#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/generate.h>
#include <thrust/sort.h>
#include <thrust/random.h>
#include <iostream>
#include <ctime>

//complex object for testing key-pair sorting
struct Test{
	int key; //key that is being tested for sorting
	float value;
	double value1;
	char value2;
	
	__host__ __device__
	bool operator<(const Test other) const{
		return key < other.key;
	}
};

//random generator for complex object
void initlialize(thrust::host_vector<Test>& structures){
	char alphabet[]={'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	for(size_t i = 0; i < structures.size(); i++){
		structures[i].key = (rand()%100)+1;
		structures[i].value = ((float)(rand()%100+1)/101)*100.0;
		structures[i].value1 = ((double)(rand()%100+1)/101)*100.0;
		structures[i].value2 = alphabet[rand()%52];
	}
}

int main(int argc, char** argv){
	srand((unsigned)time(0));
	clock_t start, end;
	
	//variables for sorting host vector (CPU)
	thrust::host_vector<Test> testH;
	thrust::host_vector<double> doubleH;
	thrust::host_vector<char> charH;
	//variables for sorting device vector (GPU)
	thrust::device_vector<Test> testD;
	thrust::device_vector<double> doubleD;
	thrust::device_vector<char> charD;
	
	char alphabet[]={'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'};
		
	//checking arguments
	if(argc == 2){
		if(strncmp(argv[1], "-help", 5) == 0 || strncmp(argv[1], "-h", 2) == 0){
			std::cout << "You can either enter a value for the size of the arrays to be sorted or leave it blank and it will generate arrays to be sorted of size around 20 million values";
			
			std::exit(0);
		}
		//accepts argument for the size to randomly generate for the arrays to sort
		else{
			testH = thrust::host_vector<Test>(atoi(argv[1]));
			doubleH = thrust::host_vector<double>(atoi(argv[1]));
			charH = thrust::host_vector<char>(atoi(argv[1]));
			
			testD = thrust::device_vector<Test>(atoi(argv[1]));
			doubleD = thrust::device_vector<double>(atoi(argv[1]));
			charD = thrust::device_vector<char>(atoi(argv[1]));
			
			for(int i = 0; i < atoi(argv[1]); ++i){
				doubleH[i] = ((double)(rand()%100+1)/101)*100.0;
				charH[i] = alphabet[rand()%52];
			}
			
			doubleD = doubleH;
			charD = charH;
			
			initlialize(testH);
		}
	}
	//sets the size to 128 then generates materials for the arrays.
	else{
		size_t N = 128;
		testH = thrust::host_vector<Test>(N);
		doubleH = thrust::host_vector<double>(N);
		charH = thrust::host_vector<char>(N);
		
		testD = thrust::device_vector<Test>(N);
		doubleD = thrust::device_vector<double>(N);
		charD = thrust::device_vector<char>(N);
		
		for(int i = 0; i < N; ++i){
				doubleH[i] = ((double)(rand()%100+1)/101)*100.0;
				charH[i] = alphabet[rand()%52];
		}
		
		doubleD = doubleH;
		charD = charH;
		
		initlialize(testH);
	}

	char selection = '0';
	
	std::cout << "What would you like to sort?" << std::endl;
	std::cout << "1 char \n2 double \n3 complex object \n0 quit?" << std::endl;
	std::cin >> selection;
	
	//loop so you can continue to choose a data type to sort and see timings
	while(selection != '0'){
		if(selection == '1'){
			thrust::host_vector<char> nonsort(charH.size());
			
			nonsort = charH;
			
			start = clock();
			
			thrust::sort(charH.begin(), charH.end());
			
			end = clock();
			
			for(int i = 0; i < 10; ++i){
				std::cout << charH[i] << " ";
			}
			
			std::cout << std::endl;
			
			std::cout << std::endl << "Time for host sort " << end - start << " milliseconds" << std::endl;
			
			start = clock();
			
			charD = nonsort;
			
			thrust::sort(charD.begin(), charD.end());
			
			cudaThreadSynchronize();
			
			thrust::copy(charD.begin(), charD.end(), nonsort.begin());
			
			end = clock();
			
			for(int i = 0; i < 10; ++i){
				std::cout << nonsort[i] << " ";
			}
			
			std::cout << std::endl;
			
			std::cout << "Time for device sort " << end - start << " milliseconds" << std::endl << std::endl;
			
			std::cout << "What would you like to sort?" << std::endl;
			std::cout << "1 char \n2 double \n3 complex object \n0 quit?" << std::endl;
			std::cin >> selection;
		}
		else if(selection == '2'){
			thrust::host_vector<char> nonsort(doubleH.size());
			nonsort = doubleH;
			
			start = clock();
			
			thrust::sort(doubleH.begin(), doubleH.end());
			
			end = clock();
			
			std::cout << std::endl << "Time for host sort " << end - start << " milliseconds" << std::endl;
			
			start = clock();
			
			doubleD = nonsort;
			
			thrust::sort(doubleD.begin(), doubleD.end());
			
			cudaThreadSynchronize();
			
			thrust::copy(doubleD.begin(), doubleD.end(), nonsort.begin());
			
			end = clock();
			
			std::cout << "Time for device sort " << end - start << " milliseconds" << std::endl << std::endl;
			
			std::cout << "What would you like to sort?" << std::endl;
			std::cout << "1 char \n2 double \n3 complex object \n0 quit?" << std::endl;
			std::cin >> selection;
		}
		else if(selection == '3'){
			thrust::host_vector<Test> nonsort(testH.size());
	
			nonsort = testH;
			
			start = clock();
			
			thrust::sort(testH.begin(), testH.end());
			
			end = clock();
			
			std::cout << std::endl << "Time for host sort " << end - start << " milliseconds" << std::endl;
			
			start = clock();
			
			testD = nonsort;
			
			thrust::sort(testD.begin(), testD.end());
			
			cudaThreadSynchronize();
			
			thrust::copy(testD.begin(), testD.end(), nonsort.begin());
			
			end = clock();
			
			std::cout << "Time for device sort " << end - start << " milliseconds" << std::endl << std::endl;
			
			std::cout << "What would you like to sort?" << std::endl;
			std::cout << "1 char \n2 double \n3 complex object \n0 quit?" << std::endl;
			std::cin >> selection;
		}
		else{
			std::cout << "What would you like to sort?" << std::endl;
			std::cout << "1 char \n2 double \n3 complex object \n0 quit?" << std::endl;
			std::cin >> selection;
		}
	}

    return 0;
}