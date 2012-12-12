#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime>
using namespace std;

int main(){
    srand((unsigned)time(0));
    int num = 1024; //(int)pow(2.0, (double)(rand()%15)+2);
    char alphabet[]={'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cout<<"Created values: "<<num<<endl;
    
    //Randomizer for integers (intTest.txt)
    ofstream outInt("C:/Users/Michael/Desktop/intTest.txt");
    outInt<<"int "<<num<<endl;
    for(int i=0;i<num;i++){
        outInt<<(rand()%100)+1<<" ";
    }
    outInt.close();

    //Randomizer for doubles (doubleTest.txt)
    ofstream outDbl("C:/Users/Michael/Desktop/doubleTest.txt");
    outDbl<<"double "<<num<<endl;
    for(int i=0;i<num;i++){
        outDbl<<((double)(rand()%100+1)/101)*100.0<<" ";
    }
    outDbl.close();

    //Randomizer for characters (charTest.txt)
    ofstream outChar("C:/Users/Michael/Desktop/charTest.txt");
    outChar<<"char "<<num<<endl;
    for(int i=0;i<num;i++){
        outChar<<alphabet[rand()%52]<<" ";
    }
    outChar.close();

    return 0;
}