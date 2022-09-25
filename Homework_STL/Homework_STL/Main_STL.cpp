#include "Menu.h"
#include "Tasker.h"

int main() {
	srand(time(NULL));
	Answer answer;
	Menu menu;
	Tasker tasker;
	menu.Blinking(FALSE);

	while (true) {
		answer = menu.Enable();
		menu.reset_iKey();
		if (answer.iKey == KEY_EXIT || answer.choose == ITEMS::exit) {
			system("cls");
			std::cout << "Exit program!";
			_getch();
			break;
		}
		else if (answer.choose == ITEMS::btn1) {

		}
		else if (answer.choose == ITEMS::btn2) {
			if (answer.iterator == 0 || answer.iterator == 1 || answer.iterator == 3) {
				system("cls");
				tasker.analysis(answer.iterator);
				_getch();
				system("cls");
			}
			else if (answer.iterator == 2) {
				while (true) {
					menu.type_switch(TYPE::stack);
					system("cls");
					answer = menu.Enable();
					if (answer.iKey == KEY_EXIT || answer.choose == ITEMS::exit) {
						system("cls");
						std::cout << "Exit stack menu!";
						menu.type_switch(TYPE::main);
						break;
					}
					else if (answer.choose == ITEMS::btn1) {
						system("cls");
						std::cout << "Add element";
						tasker.t3.push(answer.value);
						_getch();
					}
					else if (answer.choose == ITEMS::btn2) {
						system("cls");
						if (tasker.t3.stack.empty()) { std::cout << "Stack is clear!"; }
						else { std::cout << "Element deleted: " << tasker.t3.stack.top(); }
						tasker.t3.pop();
						_getch();
					}
					else if (answer.choose == ITEMS::btn3) {
						system("cls");
						tasker.t3.print();
						_getch();
					}
					else if (answer.choose == ITEMS::btn4) {
						system("cls");
						std::cout << "Cleared!";
						tasker.t3.clear();
						_getch();
					}
				}
				_getch();
				system("cls");
			}
		}
	}
	return 0;
}