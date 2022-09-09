#include "Coordinates.h"

void test();

int main() {
	test();
	return 0;
}

void test() {
	Coordinates a = Coordinates(34, 35);
	Coordinates b = Coordinates(22, 23);
	std::cout << "Force print: a\n";
	a.iPrint();
	std::cout << "Force print: b\n";
	b.iPrint();
	std::cout << "Example: a + b \n";
	(a + b).iPrint();
	std::cout << "Example: a += b \n";
	(a += b).iPrint();
	a = Coordinates(35, 35);
	std::cout << "Example: a - b \n";
	(a - b).iPrint();
	std::cout << "Example: a -= b \n";
	(a -= b).iPrint();
	a = Coordinates(35, 35);
	std::cout << "Example: a * b \n";
	(a * b).iPrint();
	std::cout << "Example: a / b \n";
	(a / b).iPrint();
	std::cout << "Example: a % b \n";
	(a % b).iPrint();
	std::cout << "Example: a == b \n";
	(a == b) ? std::cout << "true\n" : std::cout << "false\n";
	std::cout << "Example: a >= b \n";
	(a >= b) ? std::cout << "true\n" : std::cout << "false\n";
	std::cout << "Example: a <= b \n";
	(a <= b) ? std::cout << "true\n" : std::cout << "false\n";
	std::cout << "Example: a > b \n";
	(a > b) ? std::cout << "true\n" : std::cout << "false\n";
	std::cout << "Example: a < b \n";
	(a < b) ? std::cout << "true\n" : std::cout << "false\n";
	std::cout << "Example: a != b \n";
	(a != b) ? std::cout << "true\n" : std::cout << "false\n";
	std::cout << "Example: swap(a <=> b)\n";
	a.iSwap(b);
	std::cout << "a: swap(a <=> b)\n";
	a.iPrint();
	std::cout << "b: swap(a <=> b)\n";
	b.iPrint();
	std::cout << "Example: a.swap()\n";
	a.iSwap();
	a.iPrint();
}