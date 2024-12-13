#ifndef FOUR_IN_AROW
#define FOUR_IN_AROW
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "boardgame_classes.h"
using namespace std;
//---------------------- FourInARow Class ----------------------//
template <typename T>
class FourInARow : public Board<T> {
public:
    FourInARow(int r=6, int c=7);
    ~FourInARow();
    bool update_board(int x,int col, T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};
//---------------------- FourInARowRandomPlayer Class ----------------------//
template <typename T>
class FourInARowRandomPlayer : public RandomPlayer<T> {
public:
    FourInARowRandomPlayer(T symbol);
    void getmove(int& x, int& y) override;
};
//---------------------- FourInARowPlayer Class ----------------------//
template <typename T>
class FourInARowPlayer : public Player<T> {
public:
    FourInARowPlayer(string name, T symbol);
    void getmove(int& x, int& y) override;
};
//---------------------- FourInARow Implementation ----------------------//
template <typename T>
FourInARow<T>::FourInARow(int r, int c) {
    this->rows = r;
    this->columns = c;
    this->n_moves = 0;

    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; ++i) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; ++j) {
            this->board[i][j] = ' ';  
        }
    }
}
template <typename T>
FourInARow<T>::~FourInARow() {
    for (int i = 0; i < this->rows; ++i) {
        delete[] this->board[i];
    }
    delete[] this->board;
}
template <typename T>
bool FourInARow<T>::update_board(int x, int col, T symbol) {
    for (int i = this->rows - 1; i >= 0; --i) {
        if (this->board[i][col] == ' ') {
            this->board[i][col] = symbol;
            ++this->n_moves;
            return true;
        }
    }
    return false;  
}
template <typename T>
void FourInARow<T>::display_board() {
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            cout << this->board[i][j] << " | "; 
        }
        cout << endl;
        if (i != this->rows - 1) { 
            for (int j = 0; j < this->columns; ++j) {
                cout << "----";  
            }
            cout << endl;
        }
    }
    for (int i = 0; i < this->columns; ++i) {
        cout << " " << i << "  ";  
    }
    cout << endl;
}
template <typename T>
bool FourInARow<T>::is_win() {
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns - 3; ++j) {
            if (this->board[i][j] != ' ' && this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2] && this->board[i][j] == this->board[i][j + 3]) {
                return true;
            }
        }
    }
    for (int i = 0; i < this->rows - 3; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            if (this->board[i][j] != ' ' && this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j] && this->board[i][j] == this->board[i + 3][j]) {
                return true;
            }
        }
    }

    for (int i = 0; i < this->rows - 3; ++i) {
        for (int j = 0; j < this->columns - 3; ++j) {
            if (this->board[i][j] != ' ' && this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2] && this->board[i][j] == this->board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    for (int i = 3; i < this->rows; ++i) {
        for (int j = 0; j < this->columns - 3; ++j) {
            if (this->board[i][j] != ' ' && this->board[i][j] == this->board[i - 1][j + 1] &&
                this->board[i][j] == this->board[i - 2][j + 2] && this->board[i][j] == this->board[i - 3][j + 3]) {
                return true;
            }
        }
    }
    return false;
}
template <typename T>
bool FourInARow<T>::is_draw() {
    return this->n_moves == this->rows * this->columns;
}
template <typename T>
bool FourInARow<T>::game_is_over() {
    return is_win() || is_draw();
}
//---------------------- FourInARowRandomPlayer Implementation ----------------------//
template <typename T>
FourInARowRandomPlayer<T>::FourInARowRandomPlayer(T symbol)
    : RandomPlayer<T>(symbol) {
    }
template <typename T>
void FourInARowRandomPlayer<T>::getmove(int& x, int& y) {
    x = 0;
    y = rand() % 7;
   cout << "Computer chooses: (" << y << ")" << endl;
}
 template <typename T>
FourInARowPlayer<T>::FourInARowPlayer(string name, T symbol) : Player<T>(name, symbol) {}
template <typename T>
void FourInARowPlayer<T>::getmove(int& x, int& y) {
    x=0;
    cout << "Enter the column to place your move (0-6): ";
    cin >> y;
}
  #endif 
  