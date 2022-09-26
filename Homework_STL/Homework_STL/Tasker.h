#pragma once
#include "Menu.h"

struct task_1 {
	std::vector<int> vector;
	void create(int count) { vector = std::vector<int>(count, 0); }
	void rundom_fill() { for (auto& elem : vector) { elem = rand() % 201 - 100; } }
	void print_vector(bool flag) { 
		if (flag) {
			std::cout << ": { ";
			for (auto it = begin(vector); it != end(vector); it++) {
				std::cout << *it;
				if (it != end(vector) - 1) {
					std::cout << ", ";
				}
			}
			std::cout << " } \n";
		}
		else {
			std::cout << ": { ";
			for (auto it = rbegin(vector); it != rend(vector); it++) {
				std::cout << *it;
				if (it != rend(vector) - 1) {
					std::cout << ", ";
				}
			}
			std::cout << " } \n";
		}
	}
	void max_min_elem() {
		std::cout << 
			": { min: " <<
			*std::min_element(begin(vector), end(vector)) << ", max: " <<
			*std::max_element(begin(vector), end(vector)) << " } \n";
	}
	void sorting() { sort(begin(vector), end(vector)); }
	void insert4numbers() { for (int i = 0; i < 4; i++) { vector.push_back(rand() % 201 - 100); } }
	void less10to0() { for (auto& elem : vector) { elem < 10 ? elem = 0 : elem; } }
	void more20() {
		byte flag = 0;
		std::cout << ": { ";
		for (auto& elem : vector) {
			if (flag == 1 && elem > 20) {
				std::cout << " , ";
			}
			if (elem > 20) {
				flag == 0 ? flag = 1 : flag;
				std::cout << elem;
			}
		}
		std::cout << " } \n";
	}
	void mult3() { for (auto& elem : vector) { elem & 1 ? elem : elem *= 3; } }
	void rundom_shuffle() { std::random_shuffle(begin(vector), end(vector)); }
	void delete50() {
		for (auto& elem : vector) {
			for (auto it = begin(vector); it != end(vector); it++) {
				if (*it > 50) {
					vector.erase(it);
					break;
				}
			}
		}
	}
	void elemen_count() {
		if (vector.size() & 1) {
			vector.pop_back();
			std::cout << ": {count: " << vector.size() << " }";
			print_vector(true);
		}
		else {
			std::cout << ": {count: " << vector.size() << " }";
			print_vector(false);
		}
	}
	void cleaner() { vector.clear(); }
};

struct task_2 {
	std::list<int> list;
	void print_list() {
		int i = 0;
		std::cout << " : { ";
		for (auto& elem : list) {
			i++;
			std::cout << elem;
			if (i != list.size()) {
				std::cout << ", ";
			}
		}
		std::cout << " } \n";
	}
	void add_back5() { for (int i = 0; i < 5; i++) { list.push_back(rand() % 201 - 100); } }
	void print_first() { std::cout << " : {first: " << list.front() << " }"; }
	void add_front2() { for (int i = 0; i < 2; i++) { list.push_front(rand() % 201 - 100); } }
	void delete4elem() { 
		int i = 0;
		for (auto it = begin(list); it != end(list); it++) {
			i++;
			if (i == 4) {
				list.erase(it);
				break;
			}
		}
	}
	void _3randpos3elem() {
		int element = rand() % 201 - 100;
		int size = list.size();
		std::cout << " : {position: ";
		for (int i = 0, j = 0; i < 3; i++) {
			int pos = rand() % size;
			if (i != 2) { std::cout << pos << ", "; }
			else { std::cout << pos << " }"; }
			for (auto& elem : list) { j++ == pos ? elem = element : elem; }
			j = 0;
		}
	}
	void del_last() { list.pop_back(); }
	void del_first() { list.pop_front(); }
	void insert_to_center() {
		int i = 0;
		for (auto it = begin(list); it != end(list); it++) {
			if (i == floor(list.size() * 0.5)) { 
				list.insert(it, { rand() % 201 - 100, rand() % 201 - 100 }); 
				break;
			}
			i++;
		}
	}
	void del_dublicate() {
		bool breaker = false;
		int number;
		int counter = 0;
		while (true) {
			for (auto it = begin(list); it != end(list); it++) {
				number = *it;
				for (auto ita = begin(list); ita != end(list); ita++) {
					if (*ita == number) {
						counter++;
						if (counter > 1) {
							list.erase(ita);
							counter = 0;
							breaker = true;
							break;
						}
					}
				}
				if (breaker) {
					breaker = 0;
					break;
				}
				counter = 0;
			}
			if (unique(list)) break;
		}
	}
	void cleaner() { list.clear(); }
	void if_clean() { if (list.empty()) { std::cout << " : { CLEAN! }"; } }

	bool unique(std::list<int> _list) {
		int number;
		int counter = 0;
		for (auto it = begin(_list); it != end(_list); it++) {
			number = *it;
			for (auto ita = begin(_list); ita != end(_list); ita++) {
				if (*ita == number) {
					counter++;
					if (counter > 1) {
						return false;
					}
				}
			}
			counter = 0;
		}
		return true;
	}
};

struct task_3 {
	std::stack<int> stack;
	void push(int value) { stack.push(value); }		
	void pop() { stack.empty() ? void() : stack.pop(); }
	void print() { 
		std::stack<int> buffer;
		int prnt = prtnt_bff();
		if (!(stack.empty())) std::cout << std::left << std::setw(3 + floor(prnt - 3 * 0.5)) << color(yellow) << "| "  << "..." << std::right << std::setw(3 + ceil(prnt - 3 * 0.5)) << color(yellow) << " |\n" << color();
		for (int i = 0;stack.size() > 0; i++) { 
			int flag_minus = 0;
			stack.top() < 0 && lenghtNUM(abs(stack.top())) & 1 ? flag_minus = 1 : flag_minus = 0;
			std::cout << std::left << std::setw(3 - flag_minus + floor(prnt - lenghtNUM(stack.top()) * 0.5)) << color(yellow) << "| " << color(azure) << stack.top() << color() << std::right << std::setw(2 + flag_minus + ceil(prnt - lenghtNUM(stack.top()) * 0.5)) << color(yellow) << " |" << color() << std::endl;
			buffer.push(stack.top());
			stack.pop();
		}
		for (; buffer.size() > 0;) {
			stack.push(buffer.top());
			buffer.pop();
		}
		if (stack.empty()) std::cout << color(yellow).print("Stack is clear!");
		else {
			for (int i = 0; i < floor(prnt * 0.5) + ceil(prnt * 0.5) + prnt + 5; i++) {
				std::cout << color(yellow).print("-");
			}
		}

	}
	std::string print_(int prnt) {
		for (int i = 0; i < prnt; i++) { std::cout << " "; };
		return "";
	}
	void clear() { for (; stack.size() > 0;) { stack.pop(); } }

	int prtnt_bff() {
		int buffer_print = 0;
		int ret_pr = 0;
		std::vector<int> rp;
		std::stack<int> stbf;
		for (; stack.size() > 0;) {
			int buffer_num = abs(stack.top());
			buffer_num == 0 ? buffer_num = 1 : NULL;
			while (buffer_num > 0) {
				buffer_print++;
				buffer_num = (buffer_num - buffer_num % 10) * 0.1;
			}
			buffer_print > ret_pr ? ret_pr = buffer_print : NULL;
			buffer_print = 0;
			stbf.push(stack.top());
			stack.pop();
		}
		for (; stbf.size() > 0;) {
			stack.push(stbf.top());
			stbf.pop();
		}
		return ret_pr;
	}
};

struct task_4 {
	std::set<int> A;
	std::set<int> B;
	void generation(std::set<int> &set) { for (auto elem : {1, 2, 3, 4, 5, 6, 7}) { set.insert(rand() % 10 + 1); } }
	void print(std::set<int> set, bool f) {
		int i = 0;
		std::cout << " : { ";
		for (auto& elem : set) {
			i++;
			std::cout << elem;
			if (i != set.size()) {
				std::cout << ", ";
			}
		}
		std::cout << " }";
		if (f) std::cout << "\n";
	}
	void intersection() {
		std::set<int> bf_set;
		for (auto& elem : A) { for (auto& _elem : B) { if (elem == _elem) { bf_set.insert(elem); } } }
		print(bf_set, true);
	}
	void unite() { 
		std::set<int> bf_set = B;
		for (auto& elem : A) { 
			bf_set.insert(elem);
		} 
		print(bf_set, true);
	}
	void difference() {
		std::set<int> bf_set;
		bool flag = false;
		for (auto& elem : A) { 
			for (auto& _elem : B) { 
				if (elem == _elem) { 
					flag = true;
				} 
			} 
			if (!flag) bf_set.insert(elem);
			flag = false;
		}
		for (auto& elem : B) {
			for (auto& _elem : A) {
				if (elem == _elem) {
					flag = true;
				}
			}
			if (!flag) bf_set.insert(elem);
			flag = false;
		}
		print(bf_set, true);
	}
	void univers(std::set<int> _set) {
		std::set<int> bf_set;
		bool flag = false;
		for (auto& elem : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
			for (auto& _elem : _set) {
				if (elem == _elem) {
					flag = true;
				}
			}
			if (!flag) bf_set.insert(elem);
			flag = false;
		}
		print(bf_set, true);
	}
	void cleaner() { 
		A.clear(); 
		B.clear();
	}
};

class Tasker {
private:task_1 t1;
private:task_2 t2;
public: task_3 t3;
private:task_4 t4;

public:
	Tasker() {
		t1 = task_1();
		t2 = task_2();
		t3 = task_3();
		t4 = task_4();
	}

	void test(int choose) { choose == 0 ? atest_1() : choose == 1 ? atest_2() : choose == 2 ? atest_3() : atest_4(); }

	void atest_1() {
		//===========================================
		// Step test 1
		bool passed = true;
		task_1 testVector;
		// test
		testVector.vector = std::vector<int>(20, 0);

		// task
		t1.create(20);

		// testing
		if (testVector.vector.size() == t1.vector.size()) {
			int size = testVector.vector.size();
			for (int i = 0; i < size; i++) {
				testVector.vector[i] == t1.vector[i] ? NULL : passed = false;
			}
		}
		else { passed = false; }
		std::cout << (true ? color(azure).print(" : Создание вектора размером 20 единиц, заполненный нулями\n") : "") << (passed ? color(green).print("[PASSED]") : color(red).print("[INVALID]")) << (true ? color(azure).print("Step 1 : ") : "");
		//===========================================
		// Step test 2
		passed = false;
		// test
		testVector = t1;
		// task
		t1.rundom_fill();

		// testing 
		if (testVector.vector.size() == t1.vector.size() && t1.vector.size() != 0) {
			int size = testVector.vector.size();
			for (int i = 0; i < size; i++) {
				testVector.vector[i] == t1.vector[i] ? NULL : passed = true;
			}
		}
		else if (t1.vector.size() == 0 && testVector.vector.size() == 0) { passed = true; }
		std::cout << (true ? color(azure).print(" : Заполнение вектора рандомными числами (от -100, до 100)\n") : "") << (passed ? color(green).print("[PASSED]") : color(red).print("[INVALID]")) << (true ? color(azure).print("Step 2 : ") : "");
		testVector = t1;
		//===========================================
		// Step test 3
		passed = false;
		int min = 100, max = -100;
		// test
		testVector = t1;
		// task
		for (int i = 0; i < testVector.vector.size(); i++) {
			if (testVector.vector[i] < min) min = testVector.vector[i];
			if (testVector.vector[i] > max) max = testVector.vector[i];
		}
		// testing
		int _max = *std::max_element(begin(t1.vector), end(t1.vector));
		int _min = *std::min_element(begin(t1.vector), end(t1.vector));

		if (min == _min && max == _max ) { passed = true; }
		std::cout << (true ? color(azure).print(" : Получение максимального и минимального элемента\n") : "") << (passed ? color(green).print("[PASSED]") : color(red).print("[INVALID]")) << (true ? color(azure).print("Step 3 : ") : "");
		//===========================================
		// Step test 4
		testVector = t1;
		passed = true;
		// task
		t1.sorting();
		// testing
		for (int i = 0; i < t1.vector.size() - 1; i++) { t1.vector[i] <= t1.vector[i + 1] ? passed : passed = false; }
		std::cout << (true ? color(azure).print(" : Отсортировать вектор\n") : "") << (passed ? color(green).print("[PASSED]") : color(red).print("[INVALID]")) << (true ? color(azure).print("Step 4 : ") : "");
		//===========================================
		// Step test 5
		passed = true;
		// test
		testVector = t1;
		// task
		t1.insert4numbers();
		// testing
		testVector.vector.size() == t1.vector.size() - 4 ? NULL : passed = !passed;
		std::cout << (true ? color(azure).print(" : Добавление в конец 4-ёх элементов\n") : "") << (passed ? color(green).print("[PASSED]") : color(red).print("[INVALID]")) << (true ? color(azure).print("Step 5 : ") : "");
		//===========================================
		// Step test 6
		passed = true;
		// test
		testVector = t1;
		// task
		t1.less10to0();
		// testing
		for (int i = 0; i < t1.vector.size(); i++) { t1.vector[i] == 0 ? testVector.vector[i] < 10 ? NULL : passed = false : NULL; }
		std::cout << (true ? color(azure).print(" : Все элементы меньше 10-ти заменить на 0\n") : "") << (passed ? color(green).print("[PASSED]") : color(red).print("[INVALID]")) << (true ? color(azure).print("Step 6 : ") : "");
		//===========================================
		// Step test 7
		passed = false;
		// test
		testVector = t1;
		// task
		for (int i = 0; i < t1.vector.size(); i++) { t1.vector[i] > 20 ? passed = true : NULL; }
		std::cout << (true ? color(azure).print(" : Найти все элементы больше 20\n") : "") << (passed ? color(green).print("[PASSED]") : color(red).print("[INVALID]")) << (true ? color(azure).print("Step 7 : ") : "");
		// testing
		//===========================================
		// Step test 8
		passed = true;
		// test
		testVector = t1;
		// task
		t1.mult3();
		// testing
		for (int i = 0; i < t1.vector.size(); i++) { !(testVector.vector[i] & 1) ? t1.vector[i] == testVector.vector[i] * 3 ? NULL : passed = false : NULL; }
		std::cout << (true ? color(azure).print(" : Все чётные элементы домножить на 3\n") : "") << (passed ? color(green).print("[PASSED]") : color(red).print("[INVALID]")) << (true ? color(azure).print("Step 8 : ") : "");
		//===========================================
		// Step test 9
		passed = false;
		// test
		testVector = t1;
		// task
		t1.rundom_shuffle();
		// testing
		for (int i = 0; i < t1.vector.size(); i++) { testVector.vector[i] != t1.vector[i] ? passed = true : NULL; }
		std::cout << (true ? color(azure).print(" : Произвольно перемешать элементы\n") : "") << (passed ? color(green).print("[PASSED]") : color(red).print("[INVALID]")) << (true ? color(azure).print("Step 9 : ") : "");
		//===========================================
		// Step test 10
		passed = false;
		bool t = false;
		// test
		testVector = t1;
		// task
		t1.delete50();
		// testing
		for (int i = 0; i < testVector.vector.size(); i++) { testVector.vector[i] > 50 ? t = true : NULL; }
		t ? testVector.vector.size() != t1.vector.size() ? passed = true : NULL : passed = true;
		std::cout << (true ? color(azure).print(" : Удалить элементы больше 50\n") : "") << (passed ? color(green).print("[PASSED]") : color(red).print("[INVALID]")) << (true ? color(azure).print("Step 10 : ") : "");
		//===========================================
		// Step test 11
		passed = true;
		// test
		testVector = t1;
		// task
		std::cout << (true ? color(azure).print(" : Если кол-во не чётное то удалить последний иначе печать в обратном порядке\n") : "") << (passed ? color(green).print("[PASSED]") : color(red).print("[INVALID]")) << (true ? color(azure).print("Step 11 : ") : "");
		// testing
		//===========================================
		// Step test 12
		passed = true;
		// test
		testVector = t1;
		// task
		t1.cleaner();
		// testing
		t1.vector.empty() ? NULL : passed = !passed;
		std::cout << (true ? color(azure).print(" : Очистить вектор\n") : "") << (passed ? color(green).print("[PASSED]") : color(red).print("[INVALID]")) << (true ? color(azure).print("Step 12 : ") : "");
	}

	void atest_2() {

	}

	void atest_3() {

	}

	void atest_4() {

	}

	void analysis(int choose) { choose == 0 ? atask_1() : choose == 1 ? atask_2() : choose == 2 ? atask_3() : atask_4(); }

	void atask_1() {
		// Step 1
		std::cout << color(blue).print("Step 1 ") << color(azure);
		t1.create(20);
		t1.print_vector(true);
		// Step 2
		std::cout << color(blue).print("Step 2 ") << color(azure);
		t1.rundom_fill();
		t1.print_vector(true);
		// Step 3
		std::cout << color(blue).print("Step 3 ") << color(azure);
		t1.max_min_elem();
		// Step 4
		std::cout << color(blue).print("Step 4 ") << color(azure);
		t1.sorting();
		t1.print_vector(true);
		// Step 5
		std::cout << color(blue).print("Step 5 ") << color(azure);
		t1.insert4numbers();
		t1.print_vector(true);
		// Step 6
		std::cout << color(blue).print("Step 6 ") << color(azure);
		t1.less10to0();
		t1.print_vector(true);
		// Step 7
		std::cout << color(blue).print("Step 7 ") << color(azure);
		t1.more20();
		// Step 8
		std::cout << color(blue).print("Step 8 ") << color(azure);
		t1.mult3();
		t1.print_vector(true);
		// Step 9
		std::cout << color(blue).print("Step 9 ") << color(azure);
		t1.rundom_shuffle();
		t1.print_vector(true);
		// Step 10
		std::cout << color(blue).print("Step 10 ") << color(azure);
		t1.delete50();
		t1.print_vector(true);
		// Step 11
		std::cout << color(blue).print("Step 11 ") << color(azure);
		t1.elemen_count();
		// Step 12
		std::cout << color(blue).print("Step 12 ") << color(azure);
		t1.cleaner();
		t1.print_vector(true);

	}

	void atask_2() {
		// Step 1
		std::cout << color(blue).print("Step 1 ") << color(azure);
		t2.print_list();
		// Step 2
		std::cout << color(blue).print("Step 2 ") << color(azure);
		t2.add_back5();
		t2.print_list();
		// Step 3
		std::cout << color(blue).print("Step 3 ") << color(azure);
		t2.print_first();
		t2.print_list();
		// Step 4
		std::cout << color(blue).print("Step 4 ") << color(azure);
		t2.add_front2();
		t2.print_list();
		// Step 5
		std::cout << color(blue).print("Step 5 ") << color(azure);
		t2.delete4elem();
		t2.print_list();
		// Step 6
		std::cout << color(blue).print("Step 6 ") << color(azure);
		t2._3randpos3elem();
		t2.print_list();
		// Step 7
		std::cout << color(blue).print("Step 7 ") << color(azure);
		t2.del_last();
		t2.print_list();
		// Step 8
		std::cout << color(blue).print("Step 8 ") << color(azure);
		t2.del_first();
		t2.print_list();
		// Step 9
		std::cout << color(blue).print("Step 9 ") << color(azure);
		t2.insert_to_center();
		t2.print_list();
		// Step 10
		std::cout << color(blue).print("Step 10 ") << color(azure);
		t2.del_dublicate();
		t2.print_list();
		// Step 11
		std::cout << color(blue).print("Step 11 ") << color(azure);
		t2.cleaner();
		t2.print_list();
		// Step 12
		std::cout << color(blue).print("Step 12 ") << color(azure);
		t2.if_clean();
		t2.print_list();
	}

	void atask_3() {
		
	}

	void atask_4() {
		// Step 1
		std::cout << color(blue).print("Step 1 ") << color(azure);
		t4.generation(t4.A);
		std::cout << " [A]";
		t4.print(t4.A, true);
		// Step 2
		std::cout << color(blue).print("Step 2 ") << color(azure);
		t4.generation(t4.B);
		std::cout << " [B]";
		t4.print(t4.B, true);
		// Step 3
		std::cout << color(blue).print("Step 3 ") << color(azure);
		std::cout << " [A & B]";
		t4.intersection();
		// Step 4
		std::cout << color(blue).print("Step 4 ") << color(azure);
		std::cout << " [A || B]";
		t4.unite();
		// Step 5
		std::cout << color(blue).print("Step 5 ") << color(azure);
		std::cout << " [A dif B]";
		t4.difference();
		// Step 6
		std::cout << color(blue).print("Step 6 ") << color(azure);
		std::cout << " [U || A]";
		t4.univers(t4.A);
		// Step 6.1
		std::cout << color(blue).print("Step 6.1 ") << color(azure);
		std::cout << " [U || B]";
		t4.univers(t4.B);
		// Cleaner
		t4.cleaner();
	}
};


//Понедельник: 4ч (9:00 - 13:00)
//Вторник: 5ч (13:00 - 18:00)
//Среда: 3ч (15:00 - 18:00)
//Четверг: 0ч
//Пятница: 9ч (9:00 - 18:00)
// 4 + 5 + 3 + 9 = 21ч
// 14:30

	