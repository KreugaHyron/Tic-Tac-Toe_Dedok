#include <iostream>
using namespace std;
//отрисовываем игровое поле циклом 
void drawBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << "\n";
        if (i < 2) {
            cout << "---------" << "\n";
        }
    }
    cout << "\n";
}
//функция для проверки победы(горизонтально,вертикально или диагонально) с помощью логических И,ИЛИ
bool checkWin(char board[3][3], char symbol) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }
    return false;
}
//проверка ничьи(все ли клетки поля заполнены или нет)
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
int main() {
    setlocale(LC_ALL, "RUS");
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    //код работает до того момента,пока одно из условий функций не выполнится(или победа или ничья)
    while (true) {
        drawBoard(board);
        int row, col;
        cout << "Ход игрока " << currentPlayer << ". Введите номер строки (1-3) и номер столбца (1-3): ";
        cin >> row >> col;
        //проверка на корректность(правильность) кода: Если игрок вводит неправильно,игра будет продолжатся до тех пор пока
        //игрок не введёт правильные координаты(от 1 до 3 или не будет повторятся одни и те же координаты)
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Некорректный ход. Попробуйте снова." << "\n";
            continue;
        }
        //расстановка символов Х или О на поле(в зависимости от хода игроков(Х или О))
        board[row - 1][col - 1] = currentPlayer;
        //победа
        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            cout << "Игрок " << currentPlayer << " выиграл!" << "\n";
            break;
        }
        //ничья
        if (checkDraw(board)) {
            drawBoard(board);
            cout << "Ничья!" << "\n";
            break;
        }
        //смена игрока через условный тернарный оператор
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}