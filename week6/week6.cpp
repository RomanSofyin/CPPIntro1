// week6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Array.h"
#include "ICloneable.h"
#include "ValueHolder.h"


int main()
{
	Array<int> ints(7, (int) 777);
	Array<int> ints2(ints);
	int s = ints.size();
    return 0;
}

