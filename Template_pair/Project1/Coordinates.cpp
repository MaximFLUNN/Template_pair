#include "Coordinates.h"

std::ostream& operator << (std::ostream& out, Coordinates& data) {
	out << "First: " << data.first << "\n" << "Second: " << data.second << "\n";
	return out;
}

Coordinates::Coordinates() : first(0), second(0) {};

Coordinates::Coordinates(int _first, int _second) {
	first = _first;
	second = _second;
}

Coordinates::Coordinates(const Coordinates& data) {
	first = data.first;
	second = data.second;
}

Coordinates Coordinates::operator + (const Coordinates& data) {
	return Coordinates(first + data.first, second + data.second);
}

Coordinates Coordinates::operator = (const Coordinates& data) {
	if (this != &data) {
		return Coordinates(first = data.first, second = data.second);
	}
}

void Coordinates::iPrint() {
	std::cout << "First: " << first << "\n" << "Second: " << second << "\n";
}

