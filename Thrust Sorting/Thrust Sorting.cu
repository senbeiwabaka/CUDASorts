#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/generate.h>
#include <thrust/sort.h>
#include <thrust/random.h>
#include <iostream>
#include <ctime>

struct Test{
	int key;
	float value;
	
	__host__ __device__
	bool operator<(const Test other) const{
		return key < other.key;
	}
};

void initlialize(thrust::device_vector<Test>& structures){
	thrust::default_random_engine rng;
	thrust::uniform_int_distribution<int> dist(0, 2147483647);
	
	thrust::host_vector<Test> h_structures(structures.size());
	
	for(size_t i = 0; i < h_structures.size(); i++){
		h_structures[i].key = (rand()%100)+1;
		h_structures[i].value = ((float)(rand()%100+1)/101)*100.0;
		
		std::cout << h_structures[i].key << " key" << std::endl;
		std::cout << h_structures[i].value << " value" << std::endl;
	}
	
	structures = h_structures;
}

int main(int argc, char** argv){
	srand((unsigned)time(0));
	
	thrust::host_vector<Test> testH;
	thrust::host_vector<double> doubleH;
	thrust::host_vector<char> charH;
	thrust::device_vector<Test> testD;
	thrust::device_vector<double> doubleD;
	thrust::device_vector<char> charD;
	
	char alphabet[]={'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'};
		
	if(argc == 2){
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
		
		initlialize(testD);
	}
	else{
		int N = 32;
		testH = thrust::host_vector<Test>(N);
		doubleH = thrust::host_vector<double>(N);
		charH = thrust::host_vector<char>(N);
		
		testD = thrust::device_vector<Test>(N);
		doubleD = thrust::device_vector<double>(N);
		charD = thrust::device_vector<char>(N);
		
		initlialize(testD);
	}
	
	thrust::sort(testD.begin(), testD.end());
	
	thrust::copy(testD.begin(), testD.end(), testH.begin());
	
	std::cout << std::endl;
	
	for(int i = 0; i < testH.size(); ++i){
		std::cout << testH[i].key << " key" << std::endl;
		std::cout << testH[i].value << " value" << std::endl;
	}
	
	std::cout << std::endl << "Worked!";

    return 0;
}