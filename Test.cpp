#include "Test.h"

Test::Test(void)
{
}

Test::~Test(void)
{
}

const void Test::setChar(char x){
	ch = x;
}

const void Test::setNum(int x){
	num = x;
}

char Test::getChar(){
	return ch;
}

int Test::getNum(){
	return num;
}