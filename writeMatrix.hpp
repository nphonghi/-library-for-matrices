
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cfloat>

using namespace std;
using matrix = vector<vector<double>>;

// Khai bao Function Prototype.
void writeMatrixToFile(const matrix &, const string &);

/*
- Ham viet ma tran vao file.
- Input: truyen vao 1 ma tran la tham chieu hang toi doi tuong matrix, 1 file la tham chieu hang toi doi tuong string.
- Output: tao ra file text luu tru ket qua.
*/ 
void writeMatrixToFile(const matrix &matrix, const string &filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Khong mo duoc file: " + filename);
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    if (rows <= 0 || cols <= 0) {
        throw invalid_argument("Kich thuoc cua ma tran khong hop le.");
    }
    file << rows << " " << cols << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < -DBL_MAX || matrix[i][j] > DBL_MAX) {
                throw invalid_argument("Gia tri cua phan tu trong ma tran ket qua vuot qua bien cho phep.");
            }
            file << matrix[i][j] << " ";
        }
        file << endl;
    }
    file.close();
}
