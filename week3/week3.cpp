// week3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String.h"

int main()
{
	String s1 = String("abc");
	String s2 = String("def");
	s1.append(s2);
	s1.append(s1);
    return 0;
}

