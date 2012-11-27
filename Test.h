#pragma once

class Test
{
public:
	Test(void);
	~Test(void);
	const void setChar(char x);
	char getChar();
	const void setNum(int x);
	int getNum();

private:
	char ch;
	int num;
};