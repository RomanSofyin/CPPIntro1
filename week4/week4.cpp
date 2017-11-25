// week4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void foo_says(const Foo& foo) { foo.say(); }

const Foo get_foo(const char * msg) {
	FooChild fooChild(msg);
	return fooChild;
}

bool check_equals(Expression1 const *left, Expression1 const *right)
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
	Number1 n(3);
	Number1 &bb = n;
	// to call virtual methods we dont's have to refferer to the object via a ponter
	n.bla();
	bb.bla();

	// 3 + 4.5 * 5
	Expression1 * sube = new BinaryOperation1(new Number1(4.5), '*', new Number1(5));
	Expression1 * expr = new BinaryOperation1(new Number1(3), '+', sube);
	std::cout << expr->evaluate() << std::endl;
	delete expr;

	BinaryOperation1 bo(new Number1(567.5),'/',new BinaryOperation1(new Number1(8.123), '-',new Number1(3.25)));
	check_equals(&n, &bo);
	check_equals(&bo, &n);
	check_equals(&n, &n);
	check_equals(&bo, &bo);

	expr = &bo;
	PrintVisitor1 pv;
	expr->visit(&pv);
    return 0;
}

