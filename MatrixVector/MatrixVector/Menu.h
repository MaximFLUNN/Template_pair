#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <random>

unsigned int str_to_int(std::string _str);
std::string int_to_str(int _value);
void reverseSTR(std::string& str);

#define SPACE_NAME 5
#define SPACE_ARROW 1
#define ANSI 48
#define LEN_INPUT_NUMBER 6

#include "Color.h"

class Menu;
class Board;
class Button;

enum class CLEAR {
	cls,
	buffer_fill_void_100,
	_auto,
};

enum class TYPE {
	common,
	common_choose,
	common_value,
	custom,
	common_end,
	common_choose_end,
	common_value_end,
	custom_end
};

enum class keyboard {
	KEY_EXIT = 27,
	KEY_ENTER = 13,
	ARROW_KEY = 224,
	KEY_SPACE = 32,
	KEY_BACKSPACE = 8,

	KEY_ARROW_RIGHT = 77,
	KEY_ARROW_LEFT = 75,
	KEY_ARROW_UP = 72,
	KEY_ARROW_DOWN = 80,

	KEY_0 = 0x30,
	KEY_1 = 0x31,
	KEY_2 = 0x32,
	KEY_3 = 0x33,
	KEY_4 = 0x34,
	KEY_5 = 0x35,
	KEY_6 = 0x36,
	KEY_7 = 0x37,
	KEY_8 = 0x38,
	KEY_9 = 0x39,

	KEY_MINUS = 45,
};

struct Answer {
	HANDLE hStdOut;
	COORD cursorPos, startPos;
	TYPE type;
	int iKey, horizontal, vertical;
	std::vector<std::string> button_path;
};


class Board {
	friend class Menu;
	friend class Button;
private:
	std::vector<Button> buttons;

public:
	Board() {
		buttons = {};
	}

	Board(std::vector<Button> btns) {
		buttons = btns;
	}

	Board(const Board& brd) {
		buttons = brd.buttons;
	}
};

class Button {
	friend class Menu;
	friend class Board;
private:
	TYPE type;
	std::string name;
	std::vector<std::string> button_choose;
	Board next_board;
	int value;

public:
	Button() {
		type = TYPE::common;
		name = "Nothing";
		button_choose = {};
		next_board = Board({});
		value = 0;
	}

	Button(TYPE _type, std::string _name, std::vector<std::string> _button_choose, Board _next_board) {
		type = _type;
		name = _name;
		button_choose = _button_choose;
		next_board = _next_board;
		value = 0;
	}

	Button(const Button& btn) {
		type = btn.type;
		name = btn.name;
		button_choose = btn.button_choose;
		next_board = btn.next_board;
		value = btn.value;
	}
};

class Menu {
private:
	Answer answer = Answer();
	Board board;
	CLEAR method;
public:
	Menu() {
		board = Board();
		method = CLEAR::cls;
	}

	Menu(Board brd) {
		Install_first_start_settings();
		Blinking(false);

		board = brd;
		method = CLEAR::cls;
	}

	Menu(const Menu& menu) {
		answer = menu.answer;
		board = menu.board;
		method = CLEAR::cls;
	}

private:
	std::vector<Button> path_to_vector_buttons() {
		std::vector<Button> tmp_btns = board.buttons;
		for (int i = 0; i < answer.button_path.size(); i++) {
			std::vector<Button> tmp_tmp_btns = tmp_btns;
			tmp_btns = tmp_tmp_btns[(str_to_int(answer.button_path[i]) - ANSI)].next_board.buttons;
		}
		return tmp_btns;
	}

	int path_to_value(std::vector<Button>& _brd_btns, std::vector<std::string> _path, int value, bool flag) {
		std::vector<std::string> tmp_path = _path;
		tmp_path.pop_back();
		return _path.size() == 1 ? _brd_btns[str_to_int(_path[0]) - ANSI].value = (flag ? value : _brd_btns[str_to_int(_path[0]) - ANSI].value) :
			path_to_value(_brd_btns[str_to_int(_path[_path.size() - 1]) - ANSI].next_board.buttons, tmp_path, value, flag);
	}

	void DrawButtons() {
		std::vector<Button> tmp_btns = path_to_vector_buttons();
		int size = tmp_btns.size();
		for (int i = 0; i < size; i++) {
			SetConsoleCursorPosition(answer.hStdOut, { SPACE_NAME, static_cast<SHORT>(i) });
			std::cout <<
				(check_end(i) && answer.button_path.size() == 0 ?
					color(red) : i == answer.vertical ? check_end(i) ? color(red) :
					color(blue) : color(gray_dark)) <<
				tmp_btns[i].name << color();
		}
	}

	void DrawArrows() {
		// [THROW]
		answer.vertical >= path_to_vector_buttons().size() ?
			throw std::string("Draw -> " "DrawArrows() -> " "Вериткальная переменная выбора больше списка кнопок!") : NULL;

		SetConsoleCursorPosition(answer.hStdOut, { SPACE_ARROW, static_cast<SHORT>(answer.vertical) });
		std::cout << color(azure) << ">>" << color();
		if (!((path_to_vector_buttons())[answer.vertical].button_choose.empty()) ||
			path_to_vector_buttons()[answer.vertical].type == TYPE::common_value) {
			SHORT space = SPACE_ARROW * 2 + SPACE_NAME + static_cast<SHORT>((((path_to_vector_buttons())[answer.vertical]).name).size());
			SetConsoleCursorPosition(answer.hStdOut, { space, static_cast<SHORT>(answer.vertical) });
			// [THROW]
			TYPE type = path_to_vector_buttons()[answer.vertical].type;
			(type == TYPE::common || type == TYPE::common_value) && !(path_to_vector_buttons()[answer.vertical].button_choose.empty()) ?
				throw (std::string("Draw -> " "DrawArrows() -> " "Тип кнопки " +
					static_cast<std::string>(type == TYPE::common ? "\"обычный\"" : type == TYPE::common_value ? "\"значение\"" : "UNKNOWN")
					+ " но в него переданы параметры кнопки с выбором!").append(
						"\nBUTTON NAME: " + path_to_vector_buttons()[answer.vertical].name + "\nTYPE: " +
						(type == TYPE::common ? "cummon" : type == TYPE::common_value ? "cummon_value" : ""))) : "";

			if (type != TYPE::common) {
				std::cout << color(azure) << "[" << (
					type == TYPE::common_choose ?
					((path_to_vector_buttons())[answer.vertical].button_choose[answer.horizontal]) + "]" :
					(type == TYPE::common_value ?
						(int_to_str(path_to_vector_buttons()[answer.vertical].value) + "]") : ""));
			}
		}
	}

	void Draw() {
		DrawButtons();
		DrawArrows();
		answer.cursorPos = { 0, 0 };
	}

	void Install_first_start_settings() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		answer.hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		answer.cursorPos.X = answer.startPos.X = 0;
		answer.cursorPos.Y = answer.startPos.Y = 0;
		SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
		answer.iKey = 67;
		answer.horizontal = 0;
		answer.vertical = 0;
		answer.button_path = {};
	}

public:
	Answer enable() {
		while (true) {
			// Проверка пустого вектора или конечного вектора + проверка на end
			if (!(check_final_or_empty_vector()) && check_end()) {
				answer.type = TYPE::common_end;
			}
			if (check_final_or_empty_vector() || check_end()) {
				answer.vertical = 0;
				if (answer.button_path.empty()) { break; }
				else { answer.button_path.pop_back(); }
				reset_key();
			}
			// Проверка enter
			if (answer.iKey == static_cast<int>(keyboard::KEY_ENTER)) {
				answer.button_path.push_back(int_to_str(answer.vertical));
				if (check_final_or_empty_vector()) {
					return answer;
				}
				clear_screen();
			}
			// Проверка exit
			else if (answer.iKey == static_cast<int>(keyboard::KEY_EXIT)) {
				if (answer.button_path.empty()) { break; }
				answer.vertical = 0;
				if (answer.button_path.empty()) { break; }
				else { answer.button_path.pop_back(); }
				clear_screen();
			}
			// Проверка границ
			if (answer.horizontal > ((path_to_vector_buttons())[answer.vertical]).button_choose.size() - 1) {
				answer.horizontal = 0;
			}
			if (answer.vertical > (path_to_vector_buttons()).size() - 1) {
				answer.vertical = 0;
			}
			// Обработка нажатий на клавиши
			if ((path_to_vector_buttons()[answer.vertical]).type == TYPE::common_value) {
				std::vector<std::string> tmpstr = answer.button_path;
				tmpstr.push_back(int_to_str(answer.vertical));
				int val = path_to_value(board.buttons, tmpstr, NULL, false);
				if ((numbers_pressed(answer.iKey)) &&
					check_lenght_number_limits(val, LEN_INPUT_NUMBER)) {
					int minus = val < 0 ? -1 : 1;
					val = minus * (abs(val) * 10 + (static_cast<long long>(answer.iKey) - ANSI));
				}
				else if (answer.iKey == static_cast<int>(keyboard::KEY_MINUS)) {
					val *= -1;
				}
				else if (answer.iKey == static_cast<int>(keyboard::KEY_SPACE)) {
					std::random_device RANDOM_DEVICE;
					std::mt19937 gen(RANDOM_DEVICE());
					std::uniform_int_distribution<> Random(-999999, 999999);
					val = Random(gen);
				}
				else if (answer.iKey == static_cast<int>(keyboard::KEY_BACKSPACE)) {
					val = (val - val % 10) * 0.1;
				}
				path_to_value(board.buttons, tmpstr, val, true);
				tmpstr.clear();
			}
			if (answer.iKey == static_cast<int>(keyboard::KEY_ARROW_LEFT)) {
				answer.horizontal--;
				if (answer.horizontal < 0) {
					answer.horizontal = ((path_to_vector_buttons())[answer.vertical]).button_choose.size() - 1;
				}
			}
			else if (answer.iKey == static_cast<int>(keyboard::KEY_ARROW_RIGHT)) {
				answer.horizontal++;
				if (answer.horizontal > ((path_to_vector_buttons())[answer.vertical]).button_choose.size() - 1) {
					answer.horizontal = 0;
				}
			}
			else if (answer.iKey == static_cast<int>(keyboard::KEY_ARROW_UP)) {
				answer.vertical--;
				if (answer.vertical < 0) {
					answer.vertical = (path_to_vector_buttons()).size() - 1;
				}
			}
			else if (answer.iKey == static_cast<int>(keyboard::KEY_ARROW_DOWN)) {
				answer.vertical++;
				if (answer.vertical > (path_to_vector_buttons()).size() - 1) {
					answer.vertical = 0;
				}
			}
			check_horizontal();
			// Проверка пустого вектора или конечного вектора
			if (check_final_or_empty_vector()) { return answer; }
			clear_screen();
			//system("cls");
			try
			{
				//answer.vertical = 90;
				Draw();
			}
			catch (std::string& msg_err)
			{
				system("cls");
				std::cout << color(red) << "Exception: " << color(yellow) << msg_err;
				_getch();
				exit(0);
			}
			if (answer.iKey == static_cast<int>(keyboard::KEY_ENTER) && path_to_vector_buttons()[answer.vertical].type != TYPE::common_end) {
				return answer;
			}
			answer.iKey = _getch();
			clear_screen();
		}
		return answer;
	}

	void Blinking(bool flag) {
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(answer.hStdOut, &structCursorInfo);
		flag == false ? structCursorInfo.bVisible = FALSE : structCursorInfo.bVisible = TRUE;
		SetConsoleCursorInfo(answer.hStdOut, &structCursorInfo);
	}

	void reset_key() {
		answer.iKey = 67;
	}

	bool check_final_or_empty_vector() { return (path_to_vector_buttons().empty() || path_to_vector_buttons().empty()) ? true : false; }
	// Проверка мини меню
	void check_horizontal() {
		if (((((path_to_vector_buttons())[answer.vertical]).button_choose.size()) - 1) < answer.horizontal) {
			answer.horizontal = path_to_vector_buttons()[answer.vertical].button_choose.size() - 1;
		}
	}

	bool check_end() {
		// Проверка на тип end
		if ((path_to_vector_buttons()[answer.vertical].type == TYPE::common_end ||
			path_to_vector_buttons()[answer.vertical].type == TYPE::common_choose_end ||
			path_to_vector_buttons()[answer.vertical].type == TYPE::common_value_end ||
			path_to_vector_buttons()[answer.vertical].type == TYPE::custom_end) &&
			answer.iKey == static_cast<int>(keyboard::KEY_ENTER)) {
			return true;
		}
		return false;
	}
	bool check_end(int iter) {
		// Проверка на тип end
		if (path_to_vector_buttons()[iter].type == TYPE::common_end ||
			path_to_vector_buttons()[iter].type == TYPE::common_choose_end ||
			path_to_vector_buttons()[iter].type == TYPE::common_value_end ||
			path_to_vector_buttons()[iter].type == TYPE::custom_end) {
			return true;
		}
		return false;
	}

	bool numbers_pressed(int _key) {
		for (int i = 0; i < 10; i++) { if (_key == static_cast<char>(i) + ANSI) { return true; } }
		return false;
	}

	bool check_lenght_number_limits(int _value, int limit) {
		std::string val_str = int_to_str(_value);
		return val_str[0] != '-' && val_str.size() < limit ? true : val_str[0] == '-' ? val_str.size() < limit + 1 : NULL;
	}

	void clear_console_with_fill_void(bool flag) {
		SetConsoleCursorPosition(answer.hStdOut, { NULL, NULL });
		int size = path_to_vector_buttons().size();
		std::vector<Button> btns = path_to_vector_buttons();
		for (int i = 0; i < size; i++) {
			flag ? std::cout << std::string(100, ' ') << "\n" : std::cout << std::string(btns[i].name.size(), ' ') << std::string(btns[i].button_choose[answer.horizontal].size(), ' ') << std::string(10, ' ') << std::endl;
		}
	}

	void change_clear_method(CLEAR _method) {
		_method == CLEAR::cls ? method = CLEAR::cls : _method == CLEAR::buffer_fill_void_100 ? method = CLEAR::buffer_fill_void_100 : method = CLEAR::_auto;
	}

	void clear_screen() {
		// Очистка консоли
		if (method == CLEAR::cls) {
			system("cls");
		}
		else if (method == CLEAR::buffer_fill_void_100) {
			clear_console_with_fill_void(false);
		}
		else if (method == CLEAR::_auto) {
			clear_console_with_fill_void(true);
		}
	}
};

unsigned int str_to_int(std::string _str) {
	unsigned int tmp_value = 0;
	unsigned int size = _str.size();
	for (unsigned int i = 0; i < size; i++) {
		_str[i] == '-' ? tmp_value *= -1 : tmp_value = (tmp_value * 10) + static_cast<unsigned int>(_str[i]);
	}
	return tmp_value;
}

std::string int_to_str(int _value) {
	std::string tmp_str = "";
	bool minus = _value < 0 ? true, _value = abs(_value) : false;
	while (true) {
		tmp_str.push_back(static_cast<char>((_value - (floor(_value * 0.1) * 10) + ANSI)));
		_value = floor(_value * 0.1);
		if (_value == 0) { break; }
	}
	if (minus) tmp_str.push_back('-');
	//minus ? tmp_str + "-" : tmp_str;
	reverseSTR(tmp_str);
	return tmp_str;
}

void reverseSTR(std::string& str) {
	std::string tmpstr;
	int strSIZE = str.size();
	for (int i = strSIZE - 1; i >= 0; i--) {
		tmpstr.push_back(str[i]);
	}
	str = tmpstr;
}