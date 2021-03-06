// week5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Rational.h"
#include "../week3/String.h"
#include "../week4/Expression.h"
#include "../week4/Number.h"
#include "../week4/BinaryOperation.h"
#include "ScopedPtr.h"
#include "SharedPtr.h"

int main()
{
	Rational r1 = 5;
	r1 += 5;
	r1 /= 2;
	r1 = -r1;

	Rational r3 = (Rational)5 / r1;

	double d = r1;

	String const str1 = "Hello";
	String const str2 = str1[0][4];
	String const str3 = str1[1][4];
	String const str4 = str1[0][5];
	String const str5 = str1[2][2];
	String const str6 = str1[1][2];

	SharedPtr shrPtr1(new BinaryOperation(new Number(3),'+', new Number(4)));
	SharedPtr shrPtr2(new BinaryOperation(new Number(5), '+', new Number(6)));
	SharedPtr shrPtr3 = shrPtr1;
	shrPtr3 = shrPtr2;
	shrPtr3 = shrPtr2;
	shrPtr3 = shrPtr3;

	SharedPtr shrPtr4(NULL);
	shrPtr4 = shrPtr4;
	SharedPtr shrPtr5 = shrPtr4;
	shrPtr5.reset(new Number(7));

    return 0;
}

