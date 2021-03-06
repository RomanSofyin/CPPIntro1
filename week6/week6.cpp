// week6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Array.h"
#include "ICloneable.h"
#include "ValueHolder.h"
#include "Greater.h"
#include "Any.h"
#include "SameTypes.h"

// Параметры функции copy_n идут в следующем
// порядке:
//   1. целевой массив
//   2. массив источник
//   3. количество элементов, которые нужно
//      скопировать
//
// Вам нужно реализовать только функцию copy_n,
// чтобы ее можно было вызвать так, как показано
// в примере.
//
// ключевые слова typename и class - синонимы
template <typename T, class U>
void copy_n(T* p_tgt, U* p_src, size_t n) {
	while (n--)
		p_tgt[n] = T(p_src[n]);
}

bool less(int a, int b) { return a < b; }

template <class T, class Comp>
T minimum(const Array<T> & arr, Comp less) {
	size_t n = arr.size();
	T res = arr[0];
	for (size_t i = 1; i < n; i++)
		if (less(arr[i], res))
			res = arr[i];
	return res;
}


template <typename T>
void flatten(const T&, std::ostream&);
// Весь вывод должен осуществляться в поток out,
// переданный в качестве параметра.
//
// Можно заводить любые вспомогательные функции,
// структуры или даже изменять сигнатуру flatten,
// но при этом все примеры вызова из задания должны
// компилироваться и работать.
template <typename T>
void flatten(const Array<T>& array, std::ostream& out) {
	for (size_t i = 0; i < array.size(); i++)
		flatten(array[i], out);
}

template <typename T>
void flatten(const T& value, std::ostream& out) {
	out << " " << value;
}

struct Dummy { };
typedef int type;

template<class T, size_t N>
size_t array_size(const T(&arr)[N]) {
	return N;
}

int main()
{
	Array<int> ints1(7, (int) 777);
	Array<int> ints2(ints1);
	size_t s = ints1.size();

	ValueHolder<int> vh1(1);
	ICloneable* p_vh1 = vh1.clone();
	delete p_vh1;

	int ints3[] = { 1, 2, 3, 4 };
	double doubles1[4] = {};
	copy_n(doubles1, ints3, 4); // теперь в массиве doubles1 содержатся элементы 1.0, 2.0, 3.0 и 4.0

	Array<int> ints4(3);
	ints4[0] = 10;
	ints4[1] = 2;
	ints4[2] = 15;
	int min = minimum(ints4, less); // в min должно попасть число 2
	int max = minimum(ints4, Greater()); // в max должно попасть число 15

	Array<int> ints5(2, 0);
	ints5[0] = 10;
	ints5[1] = 20;
	flatten(ints5, std::cout); // выводит на экран строку "10 20"
	Array< Array<int> > array_of_ints(2, ints5);
	flatten(array_of_ints, std::cout); // выводит на экран строку "10 20 10 20"
	Array<double> doubles2(10, 0.0);
	flatten(doubles2, std::cout); // работать должно не только для типа int

	Any empty;
	Any i(10);
	Any copy(i); // copy хранит 10, как и i
	empty = copy; // empty хранит 10, как и copy
	empty = 0; // а теперь empty хранит 0
	int *iptr1 = i.cast<int>(); // *iptr1 == 10
	char *cptr = i.cast<char>(); // cptr == 0, потому что i хранит int, а не char
	Any empty2;
	int *p = empty2.cast<int>(); // p == 0

	std::cout << SameType<int, int>::value << std::endl; // выведет 1, т. е. true
	std::cout << SameType<int, type>::value << std::endl; // 1, type == int
	std::cout << SameType<int, int&>::value << std::endl; // 0, int и ссылка на int - различные типы
	std::cout << SameType<Dummy, Dummy>::value << std::endl; // 1
	std::cout << SameType<int, const int>::value << std::endl; // 0, const - часть типа
	
	int ints6[] = { 1, 2, 3, 4 };
	int *iptr2 = ints6;
	double doubles3[] = { 3.14 };
	array_size(ints6); // вернет 4
	array_size(doubles3); // вернет 1
//	array_size(iptr2); // тут должна произойти ошибка компиляции
	
    return 0;
}

