
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <cfloat>
#include <chrono>
#include <future>
#include "readMatrix.hpp"
#include "writeMatrix.hpp"
#include "matrix.hpp"


using namespace std;
using matrix = vector<vector<double>>;

int main() {
    int option;
    system("clear");
    printf("\t******************************************************************************************************\n");
    printf("\t*         Chao mung den voi chuong trinh tinh toan ma tran, lap trinh boi Nguyen Nhat Phong.         *\n");
    printf("\t******************************************************************************************************\n\n\n");
    printf("\t+------------+----------------+-----------+----------------+-----------+----------------+------------+\n");
    printf("\t|                                               OPTION                                               |\n");
    printf("\t+------------+----------------+-----------+----------------+-----------+----------------+------------+\n");
    printf("\t|    1. Cong hai ma tran.                                                                            |\n");
    printf("\t|    2. Tru hai ma tran.                                                                             |\n");
    printf("\t|    3. Nhan ma tran voi mot so.                                                                     |\n");
    printf("\t|    4. Nhan hai ma tran.                                                                            |\n");
    printf("\t|    5. Chuyen vi ma tran.                                                                           |\n");
    printf("\t|    6. Tinh dinh thuc cua ma tran.                                                                  |\n");
    printf("\t|    7. Nghich dao ma tran.                                                                          |\n");
    printf("\t|    8. Sinh ma tran ngau nhien.                                                                     |\n");
    printf("\t|    9. Thoat chuong trinh.                                                                          |\n");
    printf("\t+------------+----------------+-----------+----------------+-----------+----------------+------------+\n\n\n");
    cout << "\tLua chon bai toan: ";
    cin >> option;
    cout << "\t\t\t\t\t\t--Thuc hien bai toan--" << endl;

    while(option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6 || option == 7 || option == 8 || option == 9) {
        if (option == 1) {
            try {
                cout << "\t\tDoc ma tran A tu file: matrixA1.txt." << endl;
                matrix matrixA = readMatrixFromFile("matrixA1.txt");
                cout << "\t\t\tMa tran doc duoc tu file la:\n";
                printMatrix(matrixA);
                cout << "\t\tDoc ma tran B tu file: matrixB1.txt." << endl;
                matrix matrixB = readMatrixFromFile("matrixB1.txt");
                cout << "\t\t\tMa tran doc duoc tu file la:\n";
                printMatrix(matrixB);

                matrix result = addMatrices(matrixA, matrixB);

                // Thuc hien cong ma tran va ghi ket qua vao file result1.txt.
                writeMatrixToFile(result, "result1.txt");
                cout << "\t\tThuc hien cong 2 ma tran thanh cong va luu ket qua vao file: result1.txt." << endl;
                cout << "\t\t\tMa tran doc duoc tu file ket qua la:\n";
                printMatrix(readMatrixFromFile("result1.txt"));
            } catch(const exception &err) {
                cerr << "\t\tLoi: " << err.what() << endl;
            }
        }
        else if(option == 2) {
            try {
                cout << "\t\tDoc ma tran A tu file: marixA2.txt." << endl;
                matrix matrixA = readMatrixFromFile("matrixA2.txt");
                cout << "\t\t\tMa tran doc duoc tu file la:\n";
                printMatrix(matrixA);
                cout << "\t\tDoc ma tran B tu file: matrixB2.txt." << endl;
                matrix matrixB = readMatrixFromFile("matrixB2.txt");
                cout << "\t\t\tMa tran doc duoc tu file la:\n";
                printMatrix(matrixB);

                matrix result = subMatrices(matrixA, matrixB);

                // Thuc hien tru 2 ma tran roi ghi ket qua ra file result2.txt.
                writeMatrixToFile(result, "result2.txt");
                cout << "\t\tThuc hien tru 2 ma tran thanh cong va luu ket qua vao file: result2.txt." << endl;
                cout << "\t\t\tMa tran doc duoc tu file ket qua la:\n";
                printMatrix(readMatrixFromFile("result2.txt"));
            } catch(const exception &err) {
                cerr << "\t\tLoi: " << err.what() << endl;
            }
        }
        else if(option == 3) {
            try {
                int value;
                cout << "\t\tDoc ma tran A tu file: matrixA3.txt." << endl;
                matrix matrixA = readMatrixFromFile("matrixA3.txt");
                cout << "\t\t\tMa tran doc duoc tu file la:\n";
                printMatrix(matrixA);
                cout << "\t\tNhap gia tri muon nhan cho ma tran: ";
                cin >> value;
                matrix result = mulByScalar(matrixA, value);
                writeMatrixToFile(result, "result3.txt");
                cout << "\t\tThuc hien nhan vo huong ma tran thanh cong va luu ket qua vao file: result3.txt." << endl;
                cout << "\t\t\tMa tran doc duoc tu file ket qua la:\n";
                printMatrix(readMatrixFromFile("result3.txt"));
            } catch(const exception &err) {
                cerr << "\t\tLoi: " << err.what() << endl;
            }
        }
        else if(option == 4) {
            int choose;
            printf("\t+------------+----------------+-----------+----------------+-----------+----------------+------------+\n");
            printf("\t|                                          OPTION MULTIPLY.                                          |\n");
            printf("\t+------------+----------------+-----------+----------------+-----------+----------------+------------+\n");
            printf("\t|            1. Nhan ma tran su dung don luong.                                                      |\n");
            printf("\t|            2. Nhan ma tran su dung da luong.                                                       |\n");
            printf("\t|            3. Sinh cac ma tran ngau nhien voi kich thuoc cho truoc,                                |\n");
            printf("\t|               So sanh thoi gian nhan cac ma tran nay khi su dung da luong va don luong,            |\n");
            printf("\t|               Thoat chuong trinh nhan ma tran.                                                     |\n");
            printf("\t|            4. Thoat chuong trinh nhan ma tran.                                                     |\n");
            printf("\t+------------+----------------+-----------+----------------+-----------+----------------+------------+\n\n\n");
            cout << "\t\tLua chon bai toan nhan: ";
            cin >> choose;
            cout << "\t\t\t\t\t\t--Thuc hien bai toan--" << endl;
            while(choose == 1 || choose == 2 || choose == 3 || choose == 4) {
                if (choose == 1) {
                    try {
                        cout << "\t\t\tDoc ma tran A tu file: matrixA4.txt." << endl;
                        matrix matrixA = readMatrixFromFile("matrixA4.txt");
                        cout << "\t\t\tMa tran doc duoc tu file la:\n";
                        printMatrix(matrixA);
                        cout << "\t\t\tDoc ma tran B tu file: matrixB4.txt." << endl;
                        matrix matrixB = readMatrixFromFile("matrixB4.txt");
                        cout << "\t\t\tMa tran doc duoc tu file la:\n";
                        printMatrix(matrixB);
                        matrix result1 = mulMatricesSingleThread(matrixA, matrixB);

                        writeMatrixToFile(result1, "result4_1.txt");
                        cout << "\t\t\tNhan 2 ma tran thanh cong su dung don luong va luu ket qua vao file: result4_1.txt." << endl;
                        cout << "\t\t\tMa tran doc duoc tu file ket qua la:\n";
                        printMatrix(readMatrixFromFile("result4_1.txt"));
                    } catch(const exception &err) {
                        cerr << "\t\t\tLoi: " << err.what() << endl;
                    }
                }
                else if(choose == 2) {
                    try {
                        cout << "\t\t\tDoc ma tran A tu file: matrixA4.txt." << endl;
                        matrix matrixA = readMatrixFromFile("matrixA4.txt");
                        cout << "\t\t\tMa tran doc duoc tu file la:\n";
                        printMatrix(matrixA);
                        cout << "\t\t\tDoc ma tran B tu file: matrixB4.txt." << endl;
                        matrix matrixB = readMatrixFromFile("matrixB4.txt");
                        cout << "\t\t\tMa tran doc duoc tu file la:\n";
                        printMatrix(matrixB);
                        matrix result2 = mulMatricesMultiThread(matrixA, matrixB);

                        writeMatrixToFile(result2, "result4_2.txt");
                        cout << "\t\t\tNhan 2 ma tran thanh cong su dung da luong va luu ket qua vao file: result4_2.txt." << endl;
                        cout << "\t\t\tMa tran doc duoc tu file ket qua la:\n";
                        printMatrix(readMatrixFromFile("result4_2.txt"));
                    } catch(const exception &err) {
                        cerr << "\t\t\tLoi: " << err.what() << endl;
                    }
                }
                else if(choose == 3) {
                    srand(time(0));

                    vector<pair<int, int>> sizes = {
                        {100, 200}, {200, 500}, {500, 700}, {500, 1000}, {700, 1000}
                    };

                    for (auto size : sizes) {
                        int rows = size.first;
                        int cols = size.second;
                        cout << "\t\t\tSinh ngau nhien ma tran A co co: "  << rows << "x" << cols << endl;
                        matrix A = randMatrix(rows, cols);
                        cout << "\t\t\tSinh ngau nhien ma tran B co co: "  << cols << "x" << cols<< endl;
                        matrix B = randMatrix(cols, cols);

                        auto start = chrono::high_resolution_clock::now();
                        matrix resultSingleThread = mulMatricesSingleThread(A, B);
                        auto end = chrono::high_resolution_clock::now();
                        chrono::duration<double> durationSingleThread = end - start;
                        cout << "\t\t\tNhan 2 ma tran thanh cong bang phuong phap xu li don luong." << endl;
                        cout << "\t\t\t\tKich thuoc cua ma tran ket qua: " << rows << "x" << cols << ", SingleThread time: " << durationSingleThread.count() << "s" << endl;

                        start = chrono::high_resolution_clock::now();
                        matrix resultMultiThread = mulMatricesMultiThread(A, B);
                        end = chrono::high_resolution_clock::now();
                        chrono::duration<double> durationMultiThread = end - start;
                        cout << "\t\t\tNhan 2 ma tran thanh cong bang phuong phap xu li da luong." << endl;
                        cout << "\t\t\t\tKich thuoc cua ma tran ket qua: " << rows << "x" << cols << ", MultiThread time: " << durationMultiThread.count() << "s" << endl;
                        cout << endl;
                    }
                    break;
                }
                else {
                    cout << "\t\t\tThoat chuong trinh nhan ma tran." << endl;
                    break;
                }
                cout << "\n\n\t\tLua chon bai toan nhan: ";
                cin >> choose;
                cout << "\t\t\t\t\t\t--Thuc hien bai toan--" << endl;
            }
        }
        else if(option == 5) {
            try {
                cout << "\t\tDoc ma tran A tu file: matrixA5.txt." << endl;
                matrix matrixA = readMatrixFromFile("matrixA5.txt");
                cout << "\t\t\tMa tran doc duoc tu file la:\n";
                printMatrix(matrixA);

                matrix transposedMatrix = transposeMatrix(matrixA);

                writeMatrixToFile(transposedMatrix, "result5.txt");
                cout << "\t\tThuc hien chuyen vi ma tran thanh cong va luu ket qua vao file: result5.txt." << endl;
                cout << "\t\t\tMa tran doc duoc tu file ket qua la:\n";
                printMatrix(readMatrixFromFile("result5.txt"));
            } catch(const exception &err) {
                cerr << "\t\tLoi: " << err.what() << endl;
            }
        }
        else if(option == 6) {
            try {
                cout << "\t\tDoc ma tran A tu file: matrixA6.txt." << endl;
                matrix matrixA = readMatrixFromFile("matrixA6.txt");
                
                cout << "\t\t\tMa tran doc duoc tu file la:\n";
                printMatrix(matrixA);
                double determinant = calculateDeterminant(matrixA);
                cout << "\t\tDinh thuc cua ma tran la: " << determinant << endl;
            } catch(const exception &err) {
                cerr << "\t\tLoi: " << err.what() << endl;
            }
        }
        else if(option == 7) {
            try {
                cout << "\t\tDoc ma tran A tu file: matrixA7.txt." << endl;
                matrix matrixA = readMatrixFromFile("matrixA7.txt");
                cout << "\t\t\tMa tran doc duoc tu file la:\n";
                printMatrix(matrixA);
                matrix inverseA = inverseMatrix(matrixA);
                writeMatrixToFile(inverseA, "result7.txt");
                cout << "\t\tThuc hien nghich dao ma tran thanh cong va luu ket qua vao file: result7.txt." << endl;
                cout << "\t\t\tMa tran doc duoc tu file la:\n";
                printMatrix(readMatrixFromFile("result7.txt"));
            } catch(const exception &err) {
                cerr << "\t\tLoi: " << err.what() << endl;
            }
        }
        else if(option == 8) {
            try {
                int rows, cols;
                cout << "\t\tNhap so hang cua ma tran muon sinh: ";
                cin >> rows;
                cout << "\t\tNhap so cot cua ma tran muon sinh: ";
                cin >> cols;
                cout << "\t\tThuc hien sinh ma tran.\n";
                cout << "\t\tMa tran duoc sinh la. \n";
                printMatrix(randMatrix(rows, cols));
            } catch(const exception &err) {
                cerr << "\t\tLoi: " << err.what() << endl;
            }
        }
        else if(option == 9) {
            cout << "\t\tThoat chuong trinh tinh toan ma tran." << endl;
            break;
        }
        cout << "\n\n\tLua chon bai toan: ";
        cin >> option;
        cout << "\t\t\t\t\t\t--Thuc hien bai toan--" << endl;
    }
    return 0;
}
