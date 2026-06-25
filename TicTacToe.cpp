#include <iostream>
#include <array>
#include <limits>

using namespace std;

array<char, 9> board;

void initBoard() {
    for (int i = 0; i < 9; i++) {
        board[i] = '1' + i;
    }
}

void displayBoard() {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "\n";
}

bool checkWin(char symbol) {
    int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };
    for (auto& line : wins) {
        if (board[line[0]] == symbol &&
            board[line[1]] == symbol &&
            board[line[2]] == symbol) {
            return true;
        }
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}

int getMove(char symbol) {
    int move;
    while (true) {
        cout << "Player " << symbol << ", enter your move (1-9): ";
        cin >> move;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }
        move--;
        if (move < 0 || move > 8) {
            cout << "Out of range. Enter a number between 1 and 9.\n";
            continue;
        }
        if (board[move] == 'X' || board[move] == 'O') {
            cout << "Cell already taken. Choose another.\n";
            continue;
        }
        break;
    }
    return move;
}

void playGame() {
    initBoard();
    char current = 'X';
    int moves = 0;

    while (true) {
        displayBoard();
        int move = getMove(current);
        board[move] = current;
        moves++;

        if (checkWin(current)) {
            displayBoard();
            cout << "Player " << current << " wins!\n";
            return;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            return;
        }

        current = (current == 'X') ? 'O' : 'X';
    }
}

int main() {
    cout << "=== TIC-TAC-TOE ===\n";

    while (true) {
        playGame();

        char again;
        cout << "Play again? (y/n): ";
        cin >> again;
        if (again != 'y' && again != 'Y') {
            cout << "Thanks for playing!\n";
            break;
        }
    }

    return 0;
}