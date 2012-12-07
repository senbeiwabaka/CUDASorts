#pragma once

class Test{
public:
	void setChar(char x){
		ch = x;
	}
	char getChar() {
		return ch;
	}
	void setNum(int x){
		num = x;
	}
	int getNum() {
		return num;
	}
	bool operator<(const Test& other) {
		return ch < other.getChar();
	}
	bool operator>(const Test& other) {
		return ch > other.getChar();
	}

private:
	char ch;
	int num;
};