// week6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Array.h"
#include "ICloneable.h"
#include "ValueHolder.h"

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

int main()
{
	Array<int> ints1(7, (int) 777);
	Array<int> ints2(ints1);
	int s = ints1.size();

	ValueHolder<int> vh1(1);
	ICloneable* p_vh1 = vh1.clone();
	delete p_vh1;

	int ints[] = { 1, 2, 3, 4 };
	double doubles[4] = {};
	copy_n(doubles, ints, 4); // теперь в массиве doubles содержатся элементы 1.0, 2.0, 3.0 и 4.0


    return 0;
}

