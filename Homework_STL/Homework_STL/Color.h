#pragma once

enum colors {
    white,
    yellow,
    azure,
    red,
    blue,
    violet,
    green,
    violet_dark,
    blue_dark,
    gray_dark,
};

class color {
private:
    colors type;

public:
    color() : type(colors::white) {};
    color(colors _type) : type(_type) {};
    friend std::ostream& operator << (std::ostream& os, const color& color) {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        color.type == white ? SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) :
            color.type == yellow ? SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY) :
            color.type == azure ? SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY) :
            color.type == red ? SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY) :
            color.type == blue ? SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY) :
            color.type == violet ? SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE) :
            color.type == green ? SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY) :
            color.type == violet_dark ? SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE) :
            color.type == blue_dark ? SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN) :
            color.type == gray_dark ? SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY) :
            NULL;
        return os;
    }

    std::string print(std::string word) {
        std::cout << color(type) << word << color();
        return "";
    }
};
