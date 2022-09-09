#include <iostream>

void test1();
void test2();
void test3();
void test4();

class Coordinates {
private:
  int first;
  int second;

public:

  Coordinates() : first(0), second(0) { }

  Coordinates(int _first, int _second) {
    first = _first;
    second = _second;
  }

  Coordinates( const Coordinates& data) {
    first = data.first;
    second = data.second;
  }

  void operator + (const Coordinates& data) {
    first += data.first;
    second += data.second;
  }

  void operator = (const Coordinates& data) {
    if (this != &data) {
      first = data.first;
      second = data.second;
    }
  }

  void iPrint() {
    std::cout << "First: " << first << "\n" << "Second: " << second << "\n";
  }

  friend std::ostream& operator << (std::ostream& out, Coordinates& data) {
    out << "First: " << data.first << "\n" << "Second: " << data.second << "\n";
    return out;
  }
};


int main() {
  test1();
  test2();
  test3();
  test4();
  return 0;
}

void test1() {
  Coordinates a = Coordinates();
  a.iPrint();
}

void test2() {
  Coordinates a = Coordinates(7, -7);
  a.iPrint();
}

void test3() {
  Coordinates a = Coordinates(Coordinates(17, -17));
  a.iPrint();
}

void test4() {
  Coordinates a = Coordinates();
  std::cout << a;
}