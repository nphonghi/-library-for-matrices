
#include <iostream>
#include <vector>
#include <cmath>
#include <future>
#include <stdexcept>
#include <fstream>

using namespace std;
using matrix = vector<vector<double>>;

// Khai bao cac Function Prototype.
void printMatrix(const matrix &matrix);
bool checkSameSize(int rowsA, int colsA, int rowsB, int colsB);
matrix addMatrices(const matrix &mtxA, const matrix &mtxB);
matrix subMatrices(const matrix &mtxA, const matrix &mtxB);
matrix mulByScalar(const matrix &mtx, double val);
bool checkMulMatrix(int colsA, int rowsB);
matrix mulMatricesSingleThread(const matrix &mtxA, const matrix &mtxB);
matrix mulMatricesMultiThread(const matrix &mtxA, const matrix &mtxB);
void mulMatricesPartially(const matrix &mtxA, const matrix &mtxB, matrix &result, int startRow, int endRow);
bool checkSquareMatrix(int rows, int cols);
matrix inverseMatrix(const matrix &mtx);
double calculateDeterminant(const matrix &mtx);
matrix transposeMatrix(const matrix &mtx);
double cofactor(const matrix &mtx, int i, int j);
matrix randMatrix(int rows, int cols);


/*
- Ham hien thi ma tran ra man hinh.
- Input: truyen vao 1 ma tran la tham chieu hang toi doi tuong matrix.
- Output: hien thi ma tran tren man hinh console.
*/
void printMatrix(const matrix &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // cout << "\t\t\tMatran doc duoc tu file la:\n";
    for (int i = 0; i < rows; i++) {
        cout << "\t\t\t\t";
        for (int j = 0; j < cols; j++) {
            printf("%10.4f", matrix[i][j]);
        }
        cout << "\n";
    }
}


/*
- Ham kiem tra 2 ma tran co cung cap hay khong?
- Input: so dong va cot cua 2 ma tran.
- Output: tra ve gia tri true kieu boolean neu 2 ma tran cung co.
*/ 
bool checkSameSize(int rowsA, int colsA, int rowsB, int colsB) {
    // Neu 2 ma tran khong cung cap, tra ve false.
    if (rowsA != rowsB || colsA != colsB) {
        return false;
    }
    // Nguoc lai.
    return true;
}


/*
- Ham cong 2 ma tran.
- Input: truyen vao 2 ma tran la tham chieu hang toi doi tuong matrix.
- Output: tra ve ma tran kieu matrix la ket qua khi cong hai ma tran.
*/ 
matrix addMatrices(const matrix &mtxA, const matrix &mtxB) {
    int rowsA = mtxA.size();
    int colsA = mtxA[0].size();
    int rowsB = mtxB.size();
    int colsB = mtxB[0].size();

    // Khai bao ma tran ket qua. 
    matrix resultAddMatrices(rowsA, vector<double>(colsA));

    if (checkSameSize(rowsA, colsA, rowsB, colsB) == 0) {
        throw invalid_argument("Khong thuc hien duoc phep cong 2 ma tran do 2 ma tran khong cung cap.");
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            resultAddMatrices[i][j] = mtxA[i][j] + mtxB[i][j];
        }
    }

    return resultAddMatrices;
}


/*
- Ham tru 2 ma tran.
- Input: truyen vao 2 ma tran la tham chieu hang toi doi tuong matrix.
- Output: tra ve ma tran kieu matrix la ket qua khi tru hai ma tran.
*/
matrix subMatrices(const matrix &mtxA, const matrix &mtxB) {
    int rowsA = mtxA.size();
    int colsA = mtxA[0].size();
    int rowsB = mtxB.size();
    int colsB = mtxB[0].size();

    // Khai bao ma tran ket qua. 
    matrix resultSubMatrices(rowsA, vector<double>(colsA));

    if (checkSameSize(rowsA, colsA, rowsB, colsB) == 0) {
        throw invalid_argument("Khong thuc hien duoc phep tr 2 ma tran do 2 ma tran khong cung cap.");
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            resultSubMatrices[i][j] = mtxA[i][j] - mtxB[i][j];
        }
    }

    return resultSubMatrices;
}


/*
- Ham nhan ma tran dau vao voi mot so thuc cho truoc.
- Input: truyen vao ma tran la tham chieu hang toi doi tuong matrix, so thuc muon nhan vo huong voi ma tran.
- Output: tra ve ma tran kieu matrix la ket qua khi nhan vo huong 1 so thuc voi ma tran.
*/
matrix mulByScalar(const matrix &mtx, double value) {
    matrix result(mtx.size(), vector<double>(mtx[0].size()));

    for (int i = 0; i < mtx.size(); i++) {
        for (int j = 0; j < mtx[0].size(); j++) {
            result[i][j] = mtx[i][j] * value;
        }
    }

    return result;
}


/*
- Ham kiem tra tinh kha thi cua viec nhan ma tran A voi B.
- Input: so cot cua ma tran A, so hang cua ma tran B.
- Output: tra ve gia tri true neu nhan duoc.
*/ 
bool checkMulMatrix(int colsA, int rowsB) {
    if (colsA == rowsB) {
        return true;
    }
    return false;
}


/*
- Ham nhan 2 ma tran su dung don luong de xu li.
- Input: truyen vao 2 ma tran la tham chieu hang toi doi tuong matrix.
- Output: tra ve doi tuong kieu matrix la ket qua cua phep nhan 2 ma tran A, B.
*/
matrix mulMatricesSingleThread(const matrix &mtxA, const matrix &mtxB) {
    int rowsA = mtxA.size();
    int colsA = mtxA[0].size();
    int rowsB = mtxB.size();
    int colsB = mtxB[0].size();

    matrix resultMulMatrices(rowsA, vector<double>(colsB));

    if (checkMulMatrix(colsA, rowsB) == 0) {
        throw invalid_argument("Khong nhan duoc 2 ma tran do vi pham dieu kien nhan ma tran.");
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++)
                resultMulMatrices[i][j] += mtxA[i][k] * mtxB[k][j];
        }
    }

    return resultMulMatrices;
}


/*
- Ham nhan 2 ma tran su dung da luong de xu li.
- Input: truyen vao 2 ma tran la tham chieu hang toi doi tuong matrix.
- Output: tra ve doi tuong kieu matrix la ket qua cua phep nhan 2 ma tran.
*/
matrix mulMatricesMultiThread(const matrix &mtxA, const matrix &mtxB) {
    int rolsA = mtxA.size();
    int colsA = mtxA[0].size();
    int rowsB = mtxB.size();
    int colsB = mtxB[0].size();

    int threadSize;
    cout << "\t\t\tNhap so luong: ";
    cin >> threadSize;
    int rest = rolsA % threadSize;

    matrix resultMulMatrices(rolsA, vector<double>(colsB));
    vector<future<void>> solve;

    if (threadSize < rolsA) {
        for (int i = 0; i < threadSize; i++) {
            solve.push_back(
                async(
                    launch::async, mulMatricesPartially,
                    ref(mtxA), ref(mtxB), ref(resultMulMatrices), 
                    i * floor(rolsA / threadSize), floor(rolsA / threadSize) * (i + 1)
                )
            );
        }
    }
    if (rest != 0) {
        solve.push_back(
            async(
                launch::async, mulMatricesPartially, 
                ref(mtxA), ref(mtxB), ref(resultMulMatrices), 
                threadSize * floor(rolsA / threadSize), rolsA
            )
        );
    }

    for (vector<future<void>>::iterator it = solve.begin(); it != solve.end(); it++) {
        (*it).get();
    }

    return resultMulMatrices;
}


/*
- Ham nhan mot phan cua ma tran A voi toan bo ma tran B.
- Input: 
    +) Truyen vao 2 ma tran la ham chieu hang toi doi tuong matrix,
    +) Truyen vao ma tran ket qua cua phep nhan la tham chieu toi doi tuong matrix,
    +) Truyen vao so hang bat dau va ket thuc de thuc hien phep nhan.
- Output: cap nhat ket qua da thuc hien vao ma tran ket qua cua phep nhan 2 ma tran A, B.
*/
void mulMatricesPartially(const matrix &mtxA, const matrix &mtxB, matrix &result, int startRow, int endRow) {
    int rowsA = mtxA.size();
    int colsA = mtxA[0].size();
    int rowsB = mtxB.size();
    int colsB = mtxB[0].size();

    if (checkMulMatrix(colsA, rowsB) == 0) {
        throw invalid_argument("Nhan ma tran A voi ma tran B khong thanh cong do vi pham dieu kien nhan!");
    }

    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < rowsB; k++) {
                result[i][j] += mtxA[i][k] * mtxB[k][j];
            }
        }
    }
}


/*
- Ham kiem tra ma tran vuong.
- Input: so hang va so cot cua ma tran can kiem tra.
- Output: tra ve kieu boolean la true neu ma tran vuong, nguoc lai.
*/
bool checkSquareMatrix(int rows, int cols) {
    if (rows != cols) {
        return false;
    }
    return true;
}


/*
- Ham nghich dao ma tran.
- Input: truyen vao ma tran la tham chieu hang toi doi tuong matrix.
- Output: tra ve ma tran kieu matrix la ma tran da nghich dao.
*/
matrix inverseMatrix(const matrix &mtx) {
    // Tao ma tran cofactor.
    matrix cofactorMatrix(mtx.size(), vector<double>(mtx[0].size()));
    // Tao ma tran chuyen vi cua ma tran cofactor.
    matrix adjugate(mtx[0].size(), vector<double>(mtx.size()));
    // Tao ma tran nghich dao.
    matrix inverseMtx;

    if (checkSquareMatrix(mtx.size(), mtx[0].size()) == 0) {
        throw invalid_argument("Ma tran khong kha nghich do ma tran khong vuong.");
    }

    // Khoi tao gia tri cho ma tran cofactor.
    for (int i = 0; i < mtx.size(); i++) {
        for (int j = 0; j < mtx[0].size(); j++) {
            cofactorMatrix[i][j] = cofactor(mtx, i, j);
        }
    }

    cout << "\t\tMa tran phan phu dai so la: \n";
    printMatrix(cofactorMatrix);
    
    // Chuyen vi ma tran cofactor.
    adjugate = transposeMatrix(cofactorMatrix);

    if (calculateDeterminant(mtx) == 0) {
        throw invalid_argument("Ma tran khong kha nghich do dinh thuc cua ma tran la: 0");
    }

    // Nghich dao ma tran.
    inverseMtx = mulByScalar(adjugate, 1.0 / calculateDeterminant(mtx));
    
    for (int i = 0; i < inverseMtx.size(); i++) {
        for (int j = 0; j < inverseMtx[0].size(); j++) {
            if (inverseMtx[i][j] == -0) {
                inverseMtx[i][j] = 0;
            }
        }
    }

    return inverseMtx;
}


/*
- Ham tinh dinh thuc cua ma tran.
- Input: truyen vao ma tran la tham chieu hang toi doi tuong matrix.
- Output: tra ve mot gia tri kieu double chinh la dinh thuc cua ma tran truyen vao.
*/ 
double calculateDeterminant(const matrix &mtx) {
    int rowSwapCount; // So lan doi hang.
    double factor, determinant;
    bool foundNonZeroPivot;
    // Tao ma tran tam, copy du lieu cua ma tran matrix.
    matrix tempMatrix(mtx.size(), vector<double>(mtx[0].size()));
    tempMatrix = mtx;

    if (checkSquareMatrix(mtx.size(), mtx[0].size()) == 0) {
        throw invalid_argument("Khong tinh duoc dinh thuc do ma tran khong vuong.");
    }

    rowSwapCount = 0;
    // Vong lap bien doi ma tran matrix thanh ma tran tam giac tren.
    for (int i = 0; i < mtx[0].size(); i++) {
        if (tempMatrix[i][i] == 0) {
            // Tim mot phan tu khac 0 tren cot i.
            foundNonZeroPivot = false;
            for (int j = i + 1; j < mtx.size(); j++) {
                if (tempMatrix[j][i] != 0) {
                    // Doi cho hang i voi hang j.
                    swap(tempMatrix[i], tempMatrix[j]);
                    foundNonZeroPivot = true;
                    rowSwapCount++;
                    break;
                }
            }
            // Neu khong tim duoc phan tu nao khac 0, co nghia la cot i toan 0.
            if (!foundNonZeroPivot) {
                return 0;
            }
        }

        // Loai bo cac phan tu duoi duong cheo chinh.
        for (int k = i + 1; k < mtx.size(); k++) {
            factor = tempMatrix[k][i] / tempMatrix[i][i];
            for (int j = i; j < mtx[0].size(); j++) {
                tempMatrix[k][j] -= factor * tempMatrix[i][j];
            }
        }
    }

    //cout << "\t\t\tMa tran tam giac tren sau khi bien doi ma tran tren la:\n";
    //printMatrix(tempMatrix);

    // Tinh dinh thuc.
    determinant = 1;
    for (int i = 0; i < mtx.size(); i++) {
        determinant *= tempMatrix[i][i];
    }

    // Neu so lan doi cho hang hoac cot la le thi dinh thuc bi doi dau.
    if (rowSwapCount % 2 == 1) {
        determinant = -determinant;
    }

    return determinant;
}


/*
- Ham chuyen vi ma tran.
- Input: truyen vao ma tran la tham chieu hang toi doi tuong matrix.
- Output: ma tran chuyen vi cua ma tran dau vao kieu matrix.
*/
matrix transposeMatrix(const matrix &mtx) {
    int rows = mtx.size();
    int cols = mtx[0].size();

    // Tao ma tran chuyen vi.
    matrix transposedMatrix(cols, vector<double>(rows));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposedMatrix[j][i] = mtx[i][j];
        }
    }

    return transposedMatrix;
}


/*
- Ham tinh phan phu dai so Aij = (-1)^(i + j) * det(Mij).
- Input: tham chieu hang toi doi tuong ma tran dau vao kieu const matrix, index hang i, index cot j.
- Output: tra ve so thuc kieu double la gia tri cua phan phu dai so Aij.
*/
double cofactor(const matrix &mtx, int i, int j) {
    // Khoi tao ma tran con Mij bo di hang i, cot j cua ma tran dau vao.
    matrix minorMatrix(mtx.size() - 1, vector<double>(mtx.size() - 1));

    // Tao ma tran con Mij.
    int rows = 0;
    int cols = 0;
    // Duyet qua cac hang cua ma tran dau vao.
    for (int k = 0; k < mtx.size(); k++) {
        // Khong phai hang can bo, thi thuc hien if block.
        if (k != i) {
            cols = 0;
            for (int l = 0; l < mtx[0].size(); l++) {
                // Khong phai cot can bo, thi thuc hien if block.
                if (l != j) {
                    minorMatrix[rows][cols] = mtx[k][l];
                    cols++;
                }
            }
            rows++;
        }
    }

    return pow(-1, i + j) * calculateDeterminant(minorMatrix);
}


/*
- Ham sinh ma tran ngau nhien.
- Input: so hang va cot cua ma tran muon sinh.
- Output: tra ve doi tuong kieu matrix la ket qua cua viec sinh ma tran ngau nhien.
*/
matrix randMatrix(int rows, int cols) {
    matrix matrix(rows, vector<double>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 1000;
        }
    }
    return matrix;
}