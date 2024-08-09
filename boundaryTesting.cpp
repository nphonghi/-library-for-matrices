
#include <iostream>
#include <vector>
#include <cfloat>
#include <cmath>

using namespace std;
using matrix = vector<vector<double>>;

void createTestMatrix(matrix &mtx) {
    mtx = {
        {-DBL_MAX, -1.0, 0.0},
        {1.0, DBL_MAX, -DBL_MAX},
        {INFINITY, 0.0, -1.0} // Su dung INFINITY de dai dien cho DBL_MAX + 1
    };
}

void testMatrixValues(const matrix &mtx) {
    // Kiem tra cac phan tu co nam trong khoang [-DBL_MAX, DBL_MAX] hay khong.
    for (int i = 0; i < mtx.size(); i++) {
        for (int j = 0; j < mtx[i].size(); j++) {
            if (mtx[i][j] == INFINITY) {
                cout << "Ma tran co phan tu nam ngoai khoang: [-DBL_MAX, DBL_MAX] nam tai vi tri: [" << i << "][" << j << "]" << endl;
                return;
            }
        }
    }
    cout << "Tat ca cac phan tu deu nam trong khoang: [-DBL_MAX, DBL_MAX]" << endl;
}

int main() {
    matrix mtx;
    createTestMatrix(mtx);
    testMatrixValues(mtx);
    return 0;
}
