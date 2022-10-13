#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8


#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

enum class ITEMS : int { none, create, print, search, exit };

inline ITEMS operator++ (ITEMS& item, int postfix) { return (int)item > 3 ? ITEMS::create : (ITEMS)((int)(item) + 1); }
inline ITEMS operator-- (ITEMS& item, int postfix) { return (int)item < 2 ? ITEMS::exit : (ITEMS)((int)(item) - 1); }

struct Answer {
    HANDLE hStdOut;
    COORD cursorPos, startPos;
    ITEMS choose;
    int iKey, vSize, iterator;
};

class Menu {
private:
    std::vector<std::string> state;
    std::vector<std::string> print;
    Answer answer;
public:

	Menu() {
        answer.choose = ITEMS::create;
        answer.iKey = 67;
        answer.vSize = 50;
        answer.iterator = 0;
		SetConsoleCP(1251);						                        // установка кодовой страницы win-cp 1251 в поток ввода
		SetConsoleOutputCP(1251);					                    // установка кодовой страницы win-cp 1251 в поток вывода
        answer.hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);               // получаем дескриптор окна для обращения к консоли
        answer.cursorPos.X = answer.startPos.X = 0;						// зануляем координату X
        answer.cursorPos.Y = answer.startPos.Y = 0;						// зануляем координату Y
		SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);     // Устанавливаем позицию в стандартное положение
        state.push_back("public");
        state.push_back("protected");
        state.push_back("private");
        print.push_back("Print table");
        print.push_back("Short info");
        print.push_back("All info");
    }

    Menu(const Menu& menu) {
        answer.choose = menu.answer.choose;
        answer.iKey = menu.answer.iKey;
        answer.vSize = menu.answer.vSize;
        answer.iterator = menu.answer.iterator;
        answer.hStdOut = menu.answer.hStdOut;
        answer.cursorPos = menu.answer.cursorPos;
        answer.startPos = menu.answer.startPos;
        state = menu.state;
        print = menu.print;
    }
private:
	// отрисовка кнопок 
	void DrawButtons() {
        answer.cursorPos = { 5, 0 };
		SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
		std::cout << "Create vector " << std::endl;
        answer.cursorPos = { 5, 1 };
		SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
		std::cout << "Print on display" << std::endl;
        answer.cursorPos = { 5, 2 };
        SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
        std::cout << "Search by status " << std::endl;
        answer.cursorPos = { 5, 3 };
		SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
		std::cout << "Exit from program" << std::endl;
	}

    // отрисовка стрелочек
    void DrawArrows() {
        if (answer.choose == ITEMS::create) {
            answer.cursorPos = { 1, 0 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << ">>";
            answer.cursorPos = { 19, 0 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << "[" << answer.vSize << "]";
        }
        else if (answer.choose == ITEMS::print) {
            answer.cursorPos = { 1, 1 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << ">>";
            answer.cursorPos = { 22, 1 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << "[" << print[answer.iterator] << "]";
        }
        else if (answer.choose == ITEMS::search) {
            answer.cursorPos = { 1, 2 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << ">>";
            answer.cursorPos = { 22, 2 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << "[" << state[answer.iterator] << "]";
        }
        else if (answer.choose == ITEMS::exit) {
            answer.cursorPos = { 1, 3 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << ">>";
        }
    }

    // отрисовка меню
    void Draw() {
        DrawButtons();
        DrawArrows();
        answer.cursorPos = { 0, 0 };
    }

public:
    // отключение мерциния
    void Blinking(bool flag) {
        CONSOLE_CURSOR_INFO structCursorInfo;
        GetConsoleCursorInfo(answer.hStdOut, &structCursorInfo);
        flag == false ? structCursorInfo.bVisible = FALSE : structCursorInfo.bVisible = TRUE;
        SetConsoleCursorInfo(answer.hStdOut, &structCursorInfo);
    }
    // включение меню (основной цикл работы)
    Answer Enable() {
        while (answer.iKey != KEY_EXIT && answer.iKey != KEY_ENTER) {
            if (answer.iKey == KEY_ARROW_LEFT) {
                if (answer.vSize > 10 && answer.choose == ITEMS::create) answer.vSize -= 10;
                else if (answer.choose == ITEMS::print || answer.choose == ITEMS::search) answer.iterator > 0 ? answer.iterator-- : answer.iterator = 2;
            }
            else if (answer.iKey == KEY_ARROW_RIGHT) {
                if (answer.vSize < 100 && answer.choose == ITEMS::create) answer.vSize += 10;
                else if (answer.choose == ITEMS::print || answer.choose == ITEMS::search) answer.iterator < 2 ? answer.iterator++ : answer.iterator = 0;
            }
            else if (answer.iKey == KEY_ARROW_UP) answer.choose = answer.choose--;
            else if (answer.iKey == KEY_ARROW_DOWN) answer.choose = answer.choose++;
            system("CLS");
            Draw();
            answer.iKey = _getch();
        }
        return answer;
    }

    // сброс кнопки
    void reset_iKey() {
        answer.iKey = 67;
    }
};

