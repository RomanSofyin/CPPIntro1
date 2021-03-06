// week4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void foo_says(const Foo& foo) { foo.say(); }

const Foo get_foo(const char * msg) {
	FooChild fooChild(msg);
	return fooChild;
}

bool check_equals(Expression const *left, Expression const *right)
{
	void **pp_lvft = (void**)left;
	void *p_lvft = *pp_lvft;
	void **pp_rvft = (void**)right;
	void *p_rvft = *pp_rvft;
	return p_lvft == p_rvft ? true : false;
}

int main()
{
	
	foo_says(get_foo("abcdefghigklmnopqrstuvwxyz"));
	Number n(3);
	Number &bb = n;
	// to call virtual methods we don't have to refferer to the object via a ponter
	n.bla();
	bb.bla();

	// 3 + 4.5 * 5
	Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
	Expression * expr = new BinaryOperation(new Number(3), '+', sube);
	std::cout << expr->evaluate() << std::endl;
	delete expr;

	BinaryOperation bo(new Number(567.5),'/',new BinaryOperation(new Number(8.123), '-',new Number(3.25)));
	check_equals(&n, &bo);
	check_equals(&bo, &n);
	check_equals(&n, &n);
	check_equals(&bo, &bo);

	/*
		I haven't managed to make it working because of compile reasons. The code in AllInOne.h worked.
		For now I leave this code commented out to have the project compiling.

	expr = &bo;
	PrintVisitor pv;
	expr->visit(&pv);
    return 0;
	*/
}

