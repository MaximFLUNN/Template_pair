#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <list>
#include <math.h>
#include <stack>
#include <iomanip>
#include <set>
#include <sstream>
#include <random>

#include "Color.h"

int lenghtNUM(int val);

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8


#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

#define KEY_0 0x30
#define KEY_1 0x31
#define KEY_2 0x32
#define KEY_3 0x33
#define KEY_4 0x34
#define KEY_5 0x35
#define KEY_6 0x36
#define KEY_7 0x37
#define KEY_8 0x38
#define KEY_9 0x39

#define KEY_MINUS 45

enum class ITEMS : int { none, btn1, btn2, btn3, btn4, exit };
enum class TYPE : int { main, stack };

int blockUP = 2;
int blockDOWN = 2;

inline ITEMS operator++ (ITEMS& item, int postfix) { 
    if (blockUP == 4) {
        return (int)item > blockUP ? ITEMS::btn1 : (ITEMS)((int)(item)+1);
    }
    else if (blockUP == 2) {
        return (int)item > blockUP ? ITEMS::btn1 : item == ITEMS::btn2 ? item = ITEMS::exit : (ITEMS)((int)(item)+1);
    }
}
inline ITEMS operator-- (ITEMS& item, int postfix) { 
    if (blockUP == 4) {
        return (int)item < blockDOWN ? ITEMS::exit : (ITEMS)((int)(item)-1);
    }
    else if (blockUP == 2) {
        return (int)item < blockDOWN ? ITEMS::exit : item == ITEMS::exit ? item = ITEMS::btn2 : (ITEMS)((int)(item)-1);
    }
}

struct Answer {
    HANDLE hStdOut;
    COORD cursorPos, startPos;
    ITEMS choose;
    TYPE type;
    int iKey, vSize, iterator, value;
};

class Menu {
private:
    std::vector<std::string> test_btn;
    std::vector<std::string> detail_btn;
    Answer answer;
public:

    Menu() {
        answer.choose = ITEMS::btn1;
        answer.iKey = 67;
        answer.vSize = 50;
        answer.iterator = 0;
        SetConsoleCP(1251);						                       
        SetConsoleOutputCP(1251);					                    
        answer.hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);               
        answer.cursorPos.X = answer.startPos.X = 0;						
        answer.cursorPos.Y = answer.startPos.Y = 0;						
        SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);     
        test_btn.push_back("One");
        test_btn.push_back("Two");
        test_btn.push_back("Three");
        test_btn.push_back("Four");
        detail_btn.push_back("One");
        detail_btn.push_back("Two");
        detail_btn.push_back("Three");
        detail_btn.push_back("Four");
        answer.type = TYPE::main;
        answer.value = 0;
    }

    Menu(const Menu& menu) {
        answer.choose = menu.answer.choose;
        answer.iKey = menu.answer.iKey;
        answer.vSize = menu.answer.vSize;
        answer.iterator = menu.answer.iterator;
        answer.hStdOut = menu.answer.hStdOut;
        answer.cursorPos = menu.answer.cursorPos;
        answer.startPos = menu.answer.startPos;
        test_btn = menu.test_btn;
        answer.type = menu.answer.type;
        answer.value = menu.answer.value;
    }
private:
    void DrawButtons() {
        if (answer.type == TYPE::main) {
            answer.cursorPos = { 5, 0 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << (answer.choose == ITEMS::btn1 ? color(blue) : color(gray_dark)) << "Summary of the task test " << color() << std::endl;
            answer.cursorPos = { 5, 1 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << (answer.choose == ITEMS::btn2 ? color(blue) : color(gray_dark)) << "Detailed analysis of task" << color() << std::endl;
            answer.cursorPos = { 5, 2 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << (answer.choose == ITEMS::exit ? color(red) : color(gray_dark)) << "Exit from program" << color() << std::endl;
        }
        else if (answer.type == TYPE::stack) {
            answer.cursorPos = { 5, 0 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << (answer.choose == ITEMS::btn1 ? color(blue) : color(gray_dark)) << "Push element " << color() << std::endl;
            answer.cursorPos = { 5, 1 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << (answer.choose == ITEMS::btn2 ? color(blue) : color(gray_dark)) << "Pop element " << color() << std::endl;
            answer.cursorPos = { 5, 2 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << (answer.choose == ITEMS::btn3 ? color(blue) : color(gray_dark)) << "Print element " << color() << std::endl;
            answer.cursorPos = { 5, 3 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << (answer.choose == ITEMS::btn4 ? color(blue) : color(gray_dark)) << "Clear elements " << color() << std::endl;
            answer.cursorPos = { 5, 4 };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << (answer.choose == ITEMS::exit ? color(red) : color(gray_dark)) << "Exit from stack menu " << color() << std::endl;
        }
    }

    void DrawArrows() {
        if (answer.type == TYPE::main) {
            if (answer.choose == ITEMS::btn1) {
                answer.cursorPos = { 1, 0 };
                SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
                std::cout << color(azure).print(">>");
                answer.cursorPos = { 30, 0 };
                SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
                std::cout << color(azure).print("[" + test_btn[answer.iterator] + "]");
            }
            else if (answer.choose == ITEMS::btn2) {
                answer.cursorPos = { 1, 1 };
                SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
                std::cout << color(azure).print(">>");
                answer.cursorPos = { 31, 1 };
                SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
                std::cout << color(azure).print("[" + detail_btn[answer.iterator] + "]");
            }
            else if (answer.choose == ITEMS::exit) {
                answer.cursorPos = { 1, 2 };
                SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
                std::cout << color(red).print(">>");
            }
        }
        else if (answer.type == TYPE::stack) {
            if (answer.choose == ITEMS::btn1) {
                answer.cursorPos = { 1, 0 };
                SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
                std::cout << color(azure).print(">>");
                answer.cursorPos = { 18, 0 };
                SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
                std::cout << color(azure).print("[" + std::to_string(answer.value) + "]");
            }
            else if (answer.choose == ITEMS::btn2) {
                answer.cursorPos = { 1, 1 };
                SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
                std::cout << color(azure).print(">>");
            }
            if (answer.choose == ITEMS::btn3) {
                answer.cursorPos = { 1, 2 };
                SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
                std::cout << color(azure).print(">>");
            }
            else if (answer.choose == ITEMS::btn4) {
                answer.cursorPos = { 1, 3 };
                SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
                std::cout << color(azure).print(">>");
            }
            else if (answer.choose == ITEMS::exit) {
                answer.cursorPos = { 1, 4 };
                SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
                std::cout << color(red).print(">>");
            }
        }
    }

    void Draw() {
        DrawButtons();
        DrawArrows();
        answer.cursorPos = { 0, 0 };
    }

public:
    void Blinking(bool flag) {
        CONSOLE_CURSOR_INFO structCursorInfo;
        GetConsoleCursorInfo(answer.hStdOut, &structCursorInfo);
        flag == false ? structCursorInfo.bVisible = FALSE : structCursorInfo.bVisible = TRUE;
        SetConsoleCursorInfo(answer.hStdOut, &structCursorInfo);
    }
    Answer Enable() {
        while (answer.iKey != KEY_EXIT && answer.iKey != KEY_ENTER) {
            if (answer.type == TYPE::main) {
                if (answer.iKey == KEY_ARROW_LEFT) {
                    if (answer.choose == ITEMS::btn1 || answer.choose == ITEMS::btn2) answer.iterator > 0 ? answer.iterator-- : answer.iterator = 3;
                }
                else if (answer.iKey == KEY_ARROW_RIGHT) {
                    if (answer.choose == ITEMS::btn1 || answer.choose == ITEMS::btn2) answer.iterator < 3 ? answer.iterator++ : answer.iterator = 0;
                }
                else if (answer.iKey == KEY_ARROW_UP) answer.choose = answer.choose--;
                else if (answer.iKey == KEY_ARROW_DOWN) answer.choose = answer.choose++;
                clear_buffers_part();
            }
            else if (answer.type == TYPE::stack) {
                if ((num1_9pressed()) && lenghtNUM(answer.value) < 9) {
                    int minus = answer.value < 0 ? -1 : 1;
                    answer.value = minus * (abs(answer.value) * 10 + (static_cast<long long>(answer.iKey) - 48));
                }
                else if (answer.iKey == VK_SPACE) { 
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> Random(-999999999, 999999999);
                    answer.value = Random(gen);
                }
                else if (answer.iKey == KEY_MINUS) { answer.value = answer.value * (-1); }
                else if (answer.iKey == KEY_BACKSPACE) { answer.value = (answer.value - answer.value % 10) * 0.1; }
                else if (answer.iKey == KEY_ARROW_UP) answer.choose = answer.choose--;
                else if (answer.iKey == KEY_ARROW_DOWN) answer.choose = answer.choose++;
                clear_buffers_part();
            }
            Draw();
            answer.iKey = _getch();
        }
        return answer;
    }

    void reset_iKey() {
        answer.iKey = 67;
    }

    void clear_buffers_part() {
        for (short i = 0; i < 5; i++) {
            answer.cursorPos = { 0, i };
            SetConsoleCursorPosition(answer.hStdOut, answer.cursorPos);
            std::cout << "                                                       " << std::endl;
        }
    }

    void type_switch(TYPE _type) {
        answer.type = _type;
        reset_iKey();
        answer.iterator = 0;
        if (answer.type == TYPE::main) {
            blockUP = 2;
            answer.choose = ITEMS::btn1;
        }
        else if (answer.type == TYPE::stack) {
            blockUP = 4;
        }
    }

    bool num1_9pressed() {
        for (int i = 0; i < 10; i++) { if (answer.iKey == static_cast<char>(i) + 48) { return true; } }
        return false;
    }
};

int lenghtNUM(int val) {
    auto l = [&val]() {
        int buffer_print = 0;
        if (val < 0) {
            buffer_print++;
            val = abs(val);
        }
        while (val > 0) {
            buffer_print++;
            val = (val - val % 10) * 0.1;
        }
        return buffer_print;
    };
    return val == 0 ? 1 : l();
}
