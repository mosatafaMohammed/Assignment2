
#include "numerical_Tic_Tac_Toe.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    // تهيئة العشوائية
    srand(static_cast<unsigned int>(time(nullptr)));

    // إنشاء لوحة NumericalBoard
    NumericalBoard<int> board(3, 3); // لوحة 3x3

    // إعداد الأرقام المتاحة لكل لاعب
    vector<int> player1_numbers = {1, 3, 5, 7, 9}; // أرقام فردية
    vector<int> player2_numbers = {2, 4, 6, 8};    // أرقام زوجية

    // إنشاء اللاعبين
    NumericalPlayer<int> player1("Player 1", 1, player1_numbers);
    RandomNumericalPlayer<int> player2("Player 2 (Random)", player2_numbers);

    // تعيين اللوحة للاعبين
    player1.setBoard(&board);
    player2.setBoard(&board);

    // إعداد اللاعبين
    Player<int>* players[2] = {&player1, &player2};

    // عرض اللوحة في البداية
    cout << "Numerical TicTacToe Game Starts!\n";
    board.display_board();

    // إنشاء مدير اللعبة وتشغيل اللعبة
    GameManager<int> gameManager(&board, players);
    gameManager.run();

    return 0;
}
