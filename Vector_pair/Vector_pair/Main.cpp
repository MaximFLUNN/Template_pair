#include "Menu.h"
#include "Vector_pair.h"


template <class T>
void print_short_info(states<T> info);

int main() {
	srand(time(0));
	Answer answer;

	Menu menu;
	menu.Blinking(false); // ���������� ��������� ������� � �������

	Vector_pair<double> pVector;

	
	while (true) {
		menu.reset_iKey();
		answer = menu.Enable();
		if (answer.iKey == KEY_EXIT || answer.choose == ITEMS::exit) { // ���� ����� ��
			system("cls");
			std::cout << "Program is closed!";
			break;
		}
		else if (answer.choose == ITEMS::create) { // ���� ������� �� 
			system("cls");
			pVector = Vector_pair<double>(answer.vSize);
			std::cout << "������ ������: ";
			print_short_info(pVector.return_short_info());
			_getch();
		}
		else if (answer.choose == ITEMS::print) { // ���� ���������� ��
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
		else if (answer.choose == ITEMS::search) { // ���� ����� ��
			system("cls");
			pVector.search(answer.iterator);
			_getch();
		}
	}
	return 0;
}
// ��������� ������� ������ �� �����
template <class T>
void print_short_info(states<T> info) {
	std::cout << "[������:" << info.size << "] " <<
		"[public: " << info._public << "] " <<
		"[protected: " << info._protected << "] " <<
		"[private: " << info._private << "] " <<
		"[min: " << info.min_value << "] " <<
		"[max: " << info.max_value << "] ";
}