#include "Coordinates.h"

void test();

int main() {
	// Тестовый запуск
	Coordinates a = Coordinates(1, 1);
	Coordinates b = Coordinates(2, 2);
	Coordinates c = Coordinates(5, 4);
	c = a + b;
	c.iPrint();
	return 0;
}

void test() {
	// TODO: Добавить реализацию тестового метода!
}