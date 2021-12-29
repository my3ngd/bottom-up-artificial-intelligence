#include "matrix.h"

vector<vector<real_t>> mat = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12},
};

int main(int argc, char const *argv[])
{
    matrix_t A = mat;
    matrix_t I(4, 4, 'i');

    cout << A.get_rows() << "|" << A.get_cols() << endl;
    for (int i = 0; i < A.get_rows(); i++, cout << endl)
        for (int j = 0; j < A.get_cols(); j++)
            cout << A[i][j] << " ";
    cout << endl;

    cout << I.get_rows() << "|" << I.get_cols() << endl;
    for (int i = 0; i < I.get_rows(); i++, cout << endl)
        for (int j = 0; j < I.get_cols(); j++)
            cout << I[i][j] << " ";
    cout << endl;

    return 0;
}
