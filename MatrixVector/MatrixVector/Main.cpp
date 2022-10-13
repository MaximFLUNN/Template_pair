#include "Menu.h"

bool chech_path(std::vector<std::string> anspath, std::vector<std::string> path);
void printMTRX(std::vector<std::vector<int>> matrix);
void MatrixMul(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B);
void transpose(std::vector<std::vector<int>>& matrix);

int main() {
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector<std::vector<std::vector<int>>> mainvec;
    mainvec.push_back(std::vector<std::vector<int>>(1, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }));
    Answer answer;
    Menu menu = Menu(
        Board(
            {
                Button(TYPE::common_choose, "Создание матрицы (нули)", {"Низ лево", "Верх право"}, Board(
                    {
                        Button(TYPE::common_choose, "Размер матрицы", {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"}, Board())
                    }
                )),
                Button(TYPE::common, "Просмотр матриц", {}, Board()),
                Button(TYPE::common, "Сложение матриц", {}, Board()),
                Button(TYPE::common, "Вычитание матриц", {}, Board()),
                Button(TYPE::common_choose, "Умножение матриц", {"На матрицу", "На вектор"}, Board()),
                Button(TYPE::common, "Транспонирование матрицы", {}, Board()),
                Button(TYPE::common_end, "Exit from program", {}, Board())
            }
        ));
    menu.Blinking(FALSE);
    menu.change_clear_method(CLEAR::_auto);
    Menu menucopy = menu;
    menucopy.Blinking(FALSE);
    menucopy.change_clear_method(CLEAR::_auto);
    while (true) {
        answer = menu.enable();
        system("cls");
        int tmp_choose = answer.horizontal + 1;
        if (!(answer.button_path.empty()) && answer.button_path[0] == "0") {
            menu.reset_key();
            answer = menu.enable();;
        }
       
        if (answer.iKey == static_cast<int>(keyboard::KEY_EXIT) || answer.type == TYPE::common_end) {
            system("cls");
            std::cout << color(red).print("Exit program!");
            _getch();
            break;
        }

        else if (chech_path(answer.button_path, { "0", "0" })) {
            int sizeMatrix = answer.horizontal + 1;
            std::vector<std::vector<int>> matrix(sizeMatrix, std::vector<int>(sizeMatrix));
            
            if (tmp_choose == 2) {
                // Вверх право
                for (int i = 0; i < sizeMatrix; i++) {
                    for (int j = 0; j < i; j++) {
                        matrix[i][j] = rand() % 10;
                    }
                }
            }
            else if (tmp_choose == 1) {
                // Низ лево
                for (int i = 0; i < sizeMatrix; i++) {
                    for (int j = i; j < sizeMatrix; j++) {
                        matrix[i][j] = rand() % 10;
                    }
                }
            }

            mainvec.push_back(matrix);

            printMTRX(matrix);
            _getch();
            system("cls");
            menu = menucopy;
        }

        else if (chech_path(answer.button_path, {"1"})) {
            int size = mainvec.size();
            system("cls");
            for (int i = 0; i < size; i++) {
                std::cout << color(yellow) << "=============================== " << color(azure) << "Matrix[" << i << "]" << color(yellow) << " ===============================\n";
                printMTRX(mainvec[i]);
            }
            _getch();
            system("cls");
        }

        else if (chech_path(answer.button_path, { "2" })) {
            system("cls");
            Answer a;
            std::vector<std::string> strs;
            int sizem = mainvec.size();
            for (int i = 0; i < sizem; i++) { strs.push_back(int_to_str(i + 1)); }
            Menu m(Board(
                {
                    Button(TYPE::common_choose, "Выберите номер первой матрицы", strs, Board(
                        {
                            Button(TYPE::common_choose, "Выберите номер второй матрицы", strs, Board())
                        }
                    ))
                }
            ));
            m.Blinking(FALSE);
            m.change_clear_method(CLEAR::buffer_fill_void_100);
            a = m.enable();
            system("cls");
            int tmpa = a.horizontal; + 1;
            if (!(a.button_path.empty()) && a.button_path[0] == "0") {
                m.reset_key();
                a = m.enable();
            }
            if (mainvec[tmpa].size() >= mainvec[a.horizontal].size()) {
                for (int i = 0; i < mainvec[tmpa].size(); i++) {
                    for (int g = 0; g < mainvec[tmpa].size(); g++) {
                        mainvec[tmpa][i][g] += mainvec[a.horizontal][i][g];
                    }
                }
            }
            else if (mainvec[tmpa].size() <= mainvec[a.horizontal].size()) {
                for (int i = 0; i < mainvec[a.horizontal].size(); i++) {
                    for (int g = 0; g < mainvec[a.horizontal].size(); g++) {
                        mainvec[tmpa][i][g] += mainvec[a.horizontal][i][g];
                    }
                }
            }
        }

        else if (chech_path(answer.button_path, { "3" })) {
            system("cls");
            Answer a;
            std::vector<std::string> strs;
            int sizem = mainvec.size();
            for (int i = 0; i < sizem; i++) { strs.push_back(int_to_str(i + 1)); }
            Menu m(Board(
                {
                    Button(TYPE::common_choose, "Выберите номер первой матрицы", strs, Board(
                        {
                            Button(TYPE::common_choose, "Выберите номер второй матрицы", strs, Board())
                        }
                    ))
                }
            ));
            m.Blinking(FALSE);
            m.change_clear_method(CLEAR::buffer_fill_void_100);
            a = m.enable();
            system("cls");
            int tmpa = a.horizontal; +1;
            if (!(a.button_path.empty()) && a.button_path[0] == "0") {
                m.reset_key();
                a = m.enable();
            }
            if (mainvec[tmpa].size() >= mainvec[a.horizontal].size()) {
                for (int i = 0; i < mainvec[tmpa].size(); i++) {
                    for (int g = 0; g < mainvec[tmpa].size(); g++) {
                        mainvec[tmpa][i][g] -= mainvec[a.horizontal][i][g];
                    }
                }
            }
            else if (mainvec[tmpa].size() <= mainvec[a.horizontal].size()) {
                for (int i = 0; i < mainvec[a.horizontal].size(); i++) {
                    for (int g = 0; g < mainvec[a.horizontal].size(); g++) {
                        mainvec[tmpa][i][g] -= mainvec[a.horizontal][i][g];
                    }
                }
            }
        }

        else if (chech_path(answer.button_path, { "4" })) {
            system("cls");
            Answer a;
            std::vector<std::string> strs;
            int sizem = mainvec.size();
            for (int i = 0; i < sizem; i++) { strs.push_back(int_to_str(i + 1)); }
            Menu m(Board(
                {
                    Button(TYPE::common_choose, "Выберите номер первой матрицы", strs, Board(
                        {
                            Button(TYPE::common_choose, "Выберите номер второй матрицы(если вектор то 1)", strs, Board())
                        }
                    ))
                }
            ));
            m.Blinking(FALSE);
            m.change_clear_method(CLEAR::buffer_fill_void_100);
            a = m.enable();
            system("cls");
            int tmpa = a.horizontal; +1;
            if (!(a.button_path.empty()) && a.button_path[0] == "0") {
                m.reset_key();
                a = m.enable();
            }
            if (mainvec[tmpa].size() == mainvec[a.horizontal].size()) {
                MatrixMul(mainvec[tmpa], mainvec[a.horizontal]);
            }
            else if (mainvec[tmpa].size() == 1 || mainvec[a.horizontal].size() == 1) {
                MatrixMul(mainvec[tmpa], mainvec[0]);
            }
        }

        else if (chech_path(answer.button_path, { "5" })) {
            system("cls");
            Answer a;
            std::vector<std::string> strs;
            int sizem = mainvec.size();
            for (int i = 0; i < sizem; i++) { strs.push_back(int_to_str(i + 1)); }
            Menu m(Board(
                {
                    Button(TYPE::common_choose, "Выберите номер первой матрицы", strs, Board())
                }
            ));
            m.Blinking(FALSE);
            m.change_clear_method(CLEAR::buffer_fill_void_100);
            a = m.enable();
            transpose(mainvec[a.horizontal]);
        }
    }
	return 0;
}

bool chech_path(std::vector<std::string> anspath, std::vector<std::string> path) {
    return anspath == std::vector<std::string>(path);
}

void printMTRX(std::vector<std::vector<int>> matrix) {
    // Принт
    if (!(matrix.empty())) {
        int x = matrix.size();
        int y = matrix[0].size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                std::cout << matrix[i][j] << "\t";
            }
            std::cout << "\n" << std::endl;
        }
    }
}

void MatrixMul(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) {
    int size = A.size();
    std::vector<std::vector<int>> C(size, std::vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    A = C;
}

void transpose(std::vector<std::vector<int>>& matrix) {
    int size = matrix.size();
    int tmp;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
}