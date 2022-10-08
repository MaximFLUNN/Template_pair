#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <random>

// Глобальные полезные функции
int str_to_int(std::string _str);
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

/// <summary>Перечисление видов очистки</summary>
enum class CLEAR {
	cls,
	buffer_fill_void_100,
	_auto,
};

/// <summary>Перечисление видов кнопок</summary>
enum class TYPE {
	common,
	common_choose,
	common_value,
	common_end,
	common_choose_end,
	common_value_end,
};

/// <summary>Перечисление виртуальных клавиш клавиатуры</summary>
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
/// <summary> Структура ответа который возвращает класс меню </summary>
/// <param name='HANDLE'>hStdOut</param>
/// <param name='COORD'>cursorPos</param>
/// <param name='COORD'>startPos</param>
/// <param name='TYPE'>type</param>
/// <param name='int'>iKey</param>
/// <param name='int'>horizontal</param>
/// <param name='int'>vertical</param>
/// <param name='std::vector(std::string)'>button_path</param>
/// <param name='bool'>lastBTN</param>
struct Answer {
	HANDLE hStdOut;
	COORD cursorPos, startPos;
	TYPE type;
	int iKey, horizontal, vertical;
	std::vector<std::string> button_path;
	bool lastBTN;
};
/// <summary> Класс контейнера хранящего кнопки</summary>
/// <param name='std::vector(Button)'>buttons</param>
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
/// <summary> Класс кнопки в меню </summary>
/// <param name='TYPE'>type</param>
/// <param name='std::string'>name</param>
/// <param name='std::vector(std::string) CLEAR'>button_choose</param>
/// <param name='Board'>next_board</param>
/// <param name='int'>value</param>
class Button {
	friend class Menu;
	friend class Board;
protected:
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

	bool operator == (const Button& btn) {
		bool flag = true;
		type == btn.type ? NULL : flag = false;
		name == btn.name && flag ? NULL : flag = false;
		button_choose == btn.button_choose ? NULL : flag = false;
		value == btn.value && flag ? NULL : flag = false;
		return flag;
	}
};
/// <summary> Класс кастомного меню </summary>
/// <param name='(protected) Answer'>answer</param>
/// <param name='(protected) Board'>board</param>
/// <param name='(protected) CLEAR'>method</param>
/// <param name='(protected) bool'>return_every_iteration</param>
/// <param name='(protected) int'>switch_time</param>
/// <returns>struct Answer</returns>
/// <exception cref="switch_time меньше 0 "></exception>
/// <exception cref="switch_time больше 1000 "></exception>
/// <exception cref="answer.vertical больше списка кнопок "></exception>
/// <exception cref="answer.type не соответствует параметрам "></exception>
class Menu {
	friend void clear_screen_by_menu(Menu menu);
protected:
	Answer answer = Answer();
	Board board;
	CLEAR method;
	bool return_every_iteration;
	int switch_time;

public:
	Menu() {
		board = Board();
		method = CLEAR::cls;
		return_every_iteration = false;
		switch_time = 15;
	}

	Menu(Board brd) {
		Install_first_start_settings();
		Blinking(false);

		board = brd;
		method = CLEAR::cls;
		switch_time = 15;
	}

	Menu(const Menu& menu) {
		answer = menu.answer;
		board = menu.board;
		method = menu.method;
		return_every_iteration = menu.return_every_iteration;
		switch_time = menu.switch_time;
	}

protected:
	/// <summary>Функция возвращающая кнопки по пути в меню</summary>
	/// <returns>std::vector(Button) - кнопки по располажению path в меню</returns>
	std::vector<Button> path_to_vector_buttons() {
		std::vector<Button> tmp_btns = board.buttons;
		for (int i = 0; i < answer.button_path.size(); i++) {
			std::vector<Button> tmp_tmp_btns = tmp_btns;
			tmp_btns = tmp_tmp_btns[(str_to_int(answer.button_path[i]))].next_board.buttons;
		}
		return tmp_btns;
	}
	/// <summary>Функция возвращающая значение кнопки по пути в меню </summary>
	/// <returns>int value - значение кнопки по располажению path в меню</returns>
	int path_to_value(std::vector<Button>& _brd_btns, std::vector<std::string> _path, int value, bool flag) {
		std::vector<std::string> tmp_path = _path;
		tmp_path.pop_back();
		return _path.size() == 1 ? _brd_btns[str_to_int(_path[0])].value = (flag ? value : _brd_btns[str_to_int(_path[0])].value) :
			path_to_value(_brd_btns[str_to_int(_path[_path.size() - 1])].next_board.buttons, tmp_path, value, flag);
	}
	/// <summary>Функция отрисовки меню</summary>
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

	/// <summary>Функция отрисовки стрелочек и дополнительной информации кнопки</summary>
	/// <exception cref="Вертикальная переменныя выбора больше списка кнопок!"></exception>
	/// <exception cref="Не верные параметры переданный с указанным типом кнопки"></exception>
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
	/// <summary>Функция вызова отрисовки кнопок и стрелок</summary>
	void Draw() {
		DrawButtons();
		DrawArrows();
		answer.cursorPos = { 0, 0 };
	}
	/// <summary>Установка начальных параметров и устрановка для консоли кодировки 1251</summary>
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
	/// <summary>Функция проверки вложенного меню</summary>
	void check_horizontal() {
		if (((((path_to_vector_buttons())[answer.vertical]).button_choose.size()) - 1) < answer.horizontal) {
			answer.horizontal = path_to_vector_buttons()[answer.vertical].button_choose.size() - 1;
		}
	}
	/// <summary>Функция проверки нажатия цифры от 0 до 9</summary>
	/// <returns>bool (true - если нажата/false - если не нажата)</returns>
	bool numbers_pressed(int _key) {
		for (int i = 0; i < 10; i++) { if (_key == static_cast<char>(i) + ANSI) { return true; } }
		return false;
	}
	/// <summary>Функция проверки лимита длинны значения кнопки</summary>
	/// <returns>bool (true - если не превышен/false - если превышен)</returns>
	bool check_lenght_number_limits(int _value, int limit) {
		std::string val_str = int_to_str(_value);
		return val_str[0] != '-' && val_str.size() < limit ? true : val_str[0] == '-' ? val_str.size() < limit + 1 : false;
	}
	/// <summary>Функция заполняющая консоль пустотой (очистка для пользователя)</summary>
	void clear_console_with_fill_void(bool flag) {
		SetConsoleCursorPosition(answer.hStdOut, { NULL, NULL });
		int size = path_to_vector_buttons().size();
		std::vector<Button> btns = path_to_vector_buttons();
		for (int i = 0; i < size; i++) {
			if (flag) {
				std::cout << std::string(100, ' ') << "\n";
			}
			else if (!flag) {
				std::cout << std::string(btns[i].name.size(), ' ');
				if (btns[i].type == TYPE::common) {
					std::cout << std::string(1, ' ');
				}
				else if (btns[i].type == TYPE::common_choose) {
					if (btns[i] == btns[answer.vertical]) {
						std::cout << std::string(btns[i].button_choose[answer.horizontal].size(), ' ');
					}
				}
				else if (btns[i].type == TYPE::common_value) {
					std::cout << std::string(int_to_str(btns[i].value).size(), ' ');
				}
			}
			std::cout << std::string(10, ' ');
			std::cout << std::endl;
			//flag ? std::cout << std::string(100, ' ') << "\n" : std::cout << std::string(btns[i].name.size(), ' ') << (btns[i].type == TYPE::common ? std::string(1, ' ') : btns[i].type == TYPE::common_choose ? std::string(btns[i].button_choose[answer.horizontal].size(), ' ') : btns[i].type == TYPE::common_value ? std::string(int_to_str(btns[i].value).size(), ' ') : std::string(1, ' ')) << std::string(10, ' ') << "\n";
		}
	}
	
public:
	/// <summary>Функция активации меню</summary>
	/// <returns>struct Answer</returns>
	/// <exception cref="Вертикальная переменныя выбора больше списка кнопок!"></exception>
	/// <exception cref="Не верные параметры переданный с указанным типом кнопки"></exception>
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
				clear_screen_by_menu(*this);
			}
			// Проверка exit
			else if (answer.iKey == static_cast<int>(keyboard::KEY_EXIT)) {
				if (answer.button_path.empty()) { break; }
				answer.vertical = 0;
				if (answer.button_path.empty()) { break; }
				else { answer.button_path.pop_back(); }
				clear_screen_by_menu(*this);
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
					if (((path_to_vector_buttons())[answer.vertical]).button_choose.size() != 0) {
						answer.horizontal = ((path_to_vector_buttons())[answer.vertical]).button_choose.size() - 1;
					}
					else answer.horizontal = 0;
				}
			}
			else if (answer.iKey == static_cast<int>(keyboard::KEY_ARROW_RIGHT)) {
				answer.horizontal++;
				if (((path_to_vector_buttons())[answer.vertical]).button_choose.size() != 0) {
					if (answer.horizontal > ((path_to_vector_buttons())[answer.vertical]).button_choose.size() - 1) {
						answer.horizontal = 0;
					}
				}
				else answer.horizontal = 0;
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
			clear_screen_by_menu(*this);
			try
			{
				Draw();
				switch_time < 0 ? throw std::string("Menu -> switch_time меньше 0!") : switch_time > 1000 ? throw std::string("Menu -> switch_time больше 1000!") : NULL;
				Sleep(switch_time);
			}
			catch (std::string& msg_err)
			{
				system("cls");
				std::cout << color(red) << "Exception: " << color(yellow) << msg_err;
				_getch();
				exit(0);
			}
			if (return_every_iteration && answer.iKey == static_cast<int>(keyboard::KEY_ENTER)) {
				return answer;
			}
			answer.iKey = _getch();
			clear_screen_by_menu(*this);
		}
		return answer;
	}

	/// <summary>Функция отключающая мерцание курсора вконсоли</summary>
	void Blinking(bool flag) {
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(answer.hStdOut, &structCursorInfo);
		flag == false ? structCursorInfo.bVisible = FALSE : structCursorInfo.bVisible = TRUE;
		SetConsoleCursorInfo(answer.hStdOut, &structCursorInfo);
	}

	/// <summary>Функция спроса ключа в меню</summary>
	void reset_key() {
		answer.iKey = 67;
	}

	/// <summary>Функция проверки пустой ли вектор по пути в меню</summary>
	/// <returns>bool (true - пуст/falses - не пуст)</returns>
	bool check_final_or_empty_vector() { 
		return (path_to_vector_buttons().empty()) ? true : false; 
	}

	/// <summary>Функция проверки типа кнопки + если нажат enter</summary>
	/// <returns>bool (true - если тип конечный/false - если тип не понечный)</returns>
	bool check_end() {
		// Проверка на тип end
		if ((path_to_vector_buttons()[answer.vertical].type == TYPE::common_end ||
			path_to_vector_buttons()[answer.vertical].type == TYPE::common_choose_end ||
			path_to_vector_buttons()[answer.vertical].type == TYPE::common_value_end) &&
			answer.iKey == static_cast<int>(keyboard::KEY_ENTER)) {
			return true;
		}
		return false;
	}

	/// <summary>Функция проверки типа кнопки + если нажат enter</summary>
	/// <returns>bool (true - если тип конечный/false - если тип не понечный)</returns>
	bool check_end(int iter) {
		// Проверка на тип end
		if (path_to_vector_buttons()[iter].type == TYPE::common_end ||
			path_to_vector_buttons()[iter].type == TYPE::common_choose_end ||
			path_to_vector_buttons()[iter].type == TYPE::common_value_end) {
			return true;
		}
		return false;
	}
	
	/// <summary>Функция изменения метода очистки (CLEAR)</summary>
	void change_clear_method(CLEAR _method) {
		_method == CLEAR::cls ? method = CLEAR::cls : _method == CLEAR::buffer_fill_void_100 ? method = CLEAR::buffer_fill_void_100 : method = CLEAR::_auto;
	}

	/// <summary>Функция изменения режима ответа (true - каждую итерацию/false - если дошёл до конца меню)</summary>
	void change_return_every_iteration(bool flag) {
		return_every_iteration = flag;
	}

	/// <summary>Функция изменения времени ожидания между сменой меню выбора</summary>
	void change_switch_time(int milleseconds) {
		switch_time = milleseconds;
	}
	
	/// <summary>Функция принудительного получения ответа от меню</summary>
	/// <returns>struct Answer</returns>
	Answer get_answer() {
		return answer;
	}
};

/// <summary>Функция преобразования строки в число</summary>
/// <returns>int - число полученное из строки</returns>
int str_to_int(std::string _str) {
	int tmp_value = 0;
	bool minus = false;
	int size = _str.size();
	for (unsigned int i = 0; i < size; i++) { _str[i] == '-' ? minus = true : tmp_value = (tmp_value * 10) + (static_cast<unsigned int>(_str[i]) - ANSI); }
	minus ? tmp_value *= -1 : NULL;
	return tmp_value;
}

/// <summary>Функция преобразования числа в строку</summary>
/// <returns>std::string - строка полученная из числа</returns>
std::string int_to_str(int _value) {
	std::string tmp_str = "";
	bool minus = _value < 0 ? true, _value = abs(_value) : false;
	while (true) {
		tmp_str.push_back(static_cast<char>((_value - (floor(_value * 0.1) * 10) + ANSI)));
		_value = floor(_value * 0.1);
		if (_value == 0) { break; }
	}
	if (minus) tmp_str.push_back('-');
	reverseSTR(tmp_str);
	return tmp_str;
}

/// <summary>Функция разворота строки</summary>
void reverseSTR(std::string& str) {
	std::string tmpstr;
	int strSIZE = str.size();
	for (int i = strSIZE - 1; i >= 0; i--) {
		tmpstr.push_back(str[i]);
	}
	str = tmpstr;
}

/// <summary>Очистка консоли</summary>
void clear_screen_by_menu(Menu menu) {
	// Очистка консоли
	if (menu.method == CLEAR::cls) {
		system("cls");
	}
	else if (menu.method == CLEAR::buffer_fill_void_100) {
		menu.clear_console_with_fill_void(true);
	}
	else if (menu.method == CLEAR::_auto) {
		menu.clear_console_with_fill_void(false);
	}
}

/// <summary>Установка кодировки консоли 1251</summary>
void console_set_CP1251() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}