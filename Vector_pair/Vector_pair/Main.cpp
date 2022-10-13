#include "Menu.h"
#include "Vector_pair.h"


template <class T>
void print_short_info(states<T> info);

int main() {
	srand(time(0));
	Answer answer;

	Menu menu;
	menu.Blinking(false); // отключение мигающего курсора в консоли

	Vector_pair<double> pVector;

	
	while (true) {
		menu.reset_iKey();
		answer = menu.Enable();
		if (answer.iKey == KEY_EXIT || answer.choose == ITEMS::exit) { // если выход то
			system("cls");
			std::cout << "Program is closed!";
			break;
		}
		else if (answer.choose == ITEMS::create) { // если создать то 
			system("cls");
			pVector = Vector_pair<double>(answer.vSize);
			std::cout << "Массив создан: ";
			print_short_info(pVector.return_short_info());
			_getch();
		}
		else if (answer.choose == ITEMS::print) { // если напечатать то
			system("cls");
			if (answer.iterator == 0) { 
				pVector.print_table(); 
			}
			else if (answer.iterator == 1) { 
				print_short_info(pVector.return_short_info()); 
			}
			else if (answer.iterator == 2) {
				pVector.print_table();
				print_short_info(pVector.return_short_info());
			}
			_getch();
		}
		else if (answer.choose == ITEMS::search) { // если найти то
			system("cls");
			pVector.search(answer.iterator);
			_getch();
		}
	}
	return 0;
}
// шаблонная функция вывода на экран
template <class T>
void print_short_info(states<T> info) {
	std::cout << "[Размер:" << info.size << "] " <<
		"[public: " << info._public << "] " <<
		"[protected: " << info._protected << "] " <<
		"[private: " << info._private << "] " <<
		"[min: " << info.min_value << "] " <<
		"[max: " << info.max_value << "] ";
}