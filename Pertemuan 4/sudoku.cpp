/*
Nama: Mario Jeconiah Purba
NIM: 241401046
*/

#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak papan Sudoku
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) {
                cout << " ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

// Fungsi untuk memeriksa apakah sebuah angka valid di posisi tertentu
bool isValid(const vector<vector<int>>& board, int i, int j, int num) {
    // Periksa baris dan kolom
    for (int x = 0; x < 9; x++) {
        if (board[i][x] == num || board[x][j] == num) {
            return false;
        }
    }

    // Periksa sub-kotak 3x3
    int startRow = i - i % 3;
    int startCol = j - j % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Fungsi utama pemecah Sudoku menggunakan rekursif DFS
bool solveSudoku(vector<vector<int>>& board) {
    // Cari sel kosong (nilai 0)
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                // Coba angka dari 1 hingga 9
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, i, j, num)) {
                        // Masukkan angka sementara
                        board[i][j] = num;

                        // Rekursi (DFS ke langkah berikutnya)
                        if (solveSudoku(board)) {
                            return true;
                        }

                        // Jika gagal, backtrack (kosongkan lagi)
                        board[i][j] = 0;
                    }
                }
                // Jika tidak ada angka valid, kembalikan false
                return false;
            }
        }
    }
    // Tidak ada sel kosong → Sudoku sudah terpecahkan
    return true;
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    

    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}   