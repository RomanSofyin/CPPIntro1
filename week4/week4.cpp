// week4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Foo.h"
#include "Expression.h"

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
	// to call virtual methods we dont's have to refferer to the object via a ponter
	n.bla();
	bb.bla();

	// 3 + 4.5 * 5
	Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
	Expression * expr = new BinaryOperation(new Number(3), '+', sube);
	std::cout << expr->evaluate() << std::endl;
	delete expr;

	BinaryOperation bo(&n,'+',&n);
	check_equals(&n, &bo);
	check_equals(&bo, &n);
	check_equals(&n, &n);
	check_equals(&bo, &bo);

    return 0;
}

