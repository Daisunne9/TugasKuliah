#include <iostream>
#include <vector>

using namespace std;

void transposeMatrix() {
    int rows, cols;
    cout << "Masukkan jumlah baris: ";
    cin >> rows;
    cout << "Masukkan jumlah kolom: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    vector<vector<int>> transposed(cols, vector<int>(rows));

    cout << "Masukkan elemen matriks:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    cout << "Matriks hasil transpose:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    transposeMatrix();
    return 0;
}