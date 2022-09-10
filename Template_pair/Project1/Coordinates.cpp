#include "Coordinates.h"

template <class Type_1, class Type_2>
Coordinates<Type_1, Type_2>::Coordinates() : first(0), second(0) {}

template <class Type_1, class Type_2>
Coordinates<Type_1, Type_2>::Coordinates(Type_1 _first, Type_2 _second) : first(_first), second(_second) {}

template <class Type_1, class Type_2>
Coordinates<Type_1, Type_2>::Coordinates(const Coordinates& data) : first(data.first), second(data.second) {}

template <class Type_1, class Type_2>
Coordinates<Type_1, Type_2> Coordinates<Type_1, Type_2>::operator * (Coordinates& data) {
	return Coordinates(first * data.first, second * data.second); 
}

template <class Type_1, class Type_2>
Coordinates<Type_1, Type_2> Coordinates<Type_1, Type_2>::operator / (Coordinates& data) {
	return Coordinates(first / data.first, second / data.second);
}

template <class Type_1, class Type_2>
Coordinates<Type_1, Type_2> Coordinates<Type_1, Type_2>::operator % (Coordinates& data) {
	return Coordinates(floor(first / data.first), floor(second / data.second));
}

template <class Type_1, class Type_2>
Coordinates<Type_1, Type_2> Coordinates<Type_1, Type_2>::operator += (Coordinates& data) {
	return Coordinates(first += data.first, second += data.second);
}

template <class Type_1, class Type_2>
Coordinates<Type_1, Type_2> Coordinates<Type_1, Type_2>::operator -= (Coordinates& data) {
	return Coordinates(first -= data.first, second -= data.second);
}

template <class Type_1, class Type_2>
Coordinates<Type_1, Type_2> Coordinates<Type_1, Type_2>::operator + (Coordinates& data) {
	return Coordinates(first + data.first, second + data.second);
}

template <class Type_1, class Type_2>
Coordinates<Type_1, Type_2> Coordinates<Type_1, Type_2>::operator - (Coordinates& data) {
	return Coordinates(first - data.first, second - data.second);
}

template <class Type_1, class Type_2>
Coordinates<Type_1, Type_2> Coordinates<Type_1, Type_2>::operator = (const Coordinates& data) {
	if (this != &data) {
		return Coordinates(first = data.first, second = data.second);
	}
}

template <class Type_1, class Type_2>
bool Coordinates<Type_1, Type_2>::operator == (Coordinates& data) {
	return ((first == data.first) && (second == data.second)) ? true : false;
}

template <class Type_1, class Type_2>
bool Coordinates<Type_1, Type_2>::operator >= (Coordinates& data) {
	return ((first >= data.first) && (second >= data.second)) ? true : false;
}

template <class Type_1, class Type_2>
bool Coordinates<Type_1, Type_2>::operator <= (Coordinates& data) {
	return ((first <= data.first) && (second <= data.second)) ? true : false;
}

template <class Type_1, class Type_2>
bool Coordinates<Type_1, Type_2>::operator > (Coordinates& data) {
	return ((first > data.first) && (second > data.second)) ? true : false;
}

template <class Type_1, class Type_2>
bool Coordinates<Type_1, Type_2>::operator < (Coordinates& data) {
	return ((first < data.first) && (second < data.second)) ? true : false;
}

template <class Type_1, class Type_2>
bool Coordinates<Type_1, Type_2>::operator != (Coordinates& data) {
	return ((first != data.first) && (second != data.second)) ? true : false;
}

template <class Type_1, class Type_2>
void Coordinates<Type_1, Type_2>::iPrint() {
	std::cout << "First: " << first << "\n" << "Second: " << second << "\n";
}

template <class Type_1, class Type_2>
void Coordinates<Type_1, Type_2>::iPrint(bool flag) {
	flag ? std::cout << "(" << first << "; " << second << ")" << "\n" : std::cout << first << "; " << second << "\n";
}

template <class Type_1, class Type_2>
void Coordinates<Type_1, Type_2>::iPrint_type() {
	std::cout << "First: " << first << " -> | " << typeid(first).name() << "\n" << "Second: " << second << " -> | " << typeid(second).name() << "\n";
}

template <class Type_1, class Type_2>
void Coordinates<Type_1, Type_2>::iSwap() {
	Type_1 tmp = first;
	first = second;
	second = tmp;
}

template <class Type_1, class Type_2>
void Coordinates<Type_1, Type_2>::iSwap(Coordinates& data) {
	Coordinates tmp = Coordinates(first, second);
	first = data.first;
	second = data.second;
	data.first = tmp.first;
	data.second = tmp.second;
}

// явное инстанцирование шаблона класса с различными параметрами !!!
// ѕозвол¤ет компил¤тору заранее скомпилировать код шаблона дл¤ данных наборов аргумента
template Coordinates<int, int>;
template Coordinates<float, float>;
template Coordinates<double, double>;
template Coordinates<int, float>;
template Coordinates<int, double>;
template Coordinates<float, int>;
template Coordinates<double, int>;
template Coordinates<float, double>;
template Coordinates<double, float>;
