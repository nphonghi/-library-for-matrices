
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cfloat>

using namespace std;
using matrix = vector<vector<double>>;

// Khai bao Function Prototype.
matrix readMatrixFromFile(const string &);

/*
- Ham doc ma tran tu file.
- Input: truyen vao 1 file la tham chieu hang toi doi tuong string.
- Output: tao ra ma tran doc duoc tu file text.
*/ 
matrix readMatrixFromFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Khong mo duoc file: " + filename);
    }

    int rows, cols;
    file >> rows >> cols;
    if (file.fail()) {
        throw runtime_error("Khong doc duoc kich thuoc ma tran: " + filename);
    }
    if (rows <= 0 || cols <= 0) {
        throw invalid_argument("Kich thuoc cua ma tran khong hop le.");
    }

    matrix matrix(rows, vector<double>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(file >> matrix[i][j])) {
                throw runtime_error("Khong doc duoc du lieu tu file: " + filename);
            }
            if (matrix[i][j] < -DBL_MAX || matrix[i][j] > DBL_MAX) {
                throw invalid_argument("Gia tri cua phan tu trong ma tran vuot qua bien cho phep.");
            }
        }
    }

    file.close();
    return matrix;
}
