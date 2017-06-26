#pragma once
#include "Reflection.h"
class POD {
public:
	int i;
	double d;
	std::string s;


	static void * createInstance()
	{
		return new POD();
	}

};