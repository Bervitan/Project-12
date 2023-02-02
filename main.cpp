#include <iostream>
#include <string>
#include "KPereodik.h"

int main()

{
	setlocale(LC_ALL, "");
	std::string txt = "abcdefabcdefabcdef";
	int K = 6;
	IsKPereodic(K, txt);
	return 0;
}