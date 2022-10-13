#include "Coordinates.h"

void test();

int main() {
	test();
	return 0;
}

void test() {
	Coordinates<double, double> a = Coordinates<double, double>(34, 35);
	Coordinates<double, double> b = Coordinates<double, double>(22, 23);
	std::cout << "Force print: a | ";
	a.iPrint(true);
	std::cout << "Force print: b | ";
	b.iPrint(true);
	std::cout << "Example: a + b | ";
	(a + b).iPrint(true);
	std::cout << "Example: a += b | ";
	(a += b).iPrint(true);
	a = Coordinates<double, double>(35, 34);
	std::cout << "Example: a - b | ";
	(a - b).iPrint(true);
	std::cout << "Example: a -= b | ";
	(a -= b).iPrint(true);
	a = Coordinates<double, double>(35, 34);
	std::cout << "Example: a * b | ";
	(a * b).iPrint(true);
	std::cout << "Example: a / b | ";
	(a / b).iPrint(true);
	std::cout << "Example: a % b | ";
	(a % b).iPrint(true);
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
	std::cout << "a: swap(a <=> b) | ";
	a.iPrint(true);
	std::cout << "b: swap(a <=> b) | ";
	b.iPrint(true);
	std::cout << "Example: a.swap() | ";
	a.iSwap();
	a.iPrint(true);
	std::cout << "\nExample: print methods\n\n";
	a.iPrint_type();
	std::cout << a;
	a.iPrint(false);
	a.iPrint(true);
}