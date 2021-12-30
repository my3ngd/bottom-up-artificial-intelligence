#include "matrix.h"

vector<vector<real_t>> mat = {
    {1, 2, 3},
    {4, real_t(5), 6},
    {7, 8, 9},
    {10, 11, 12},
};

int main(int argc, char const *argv[])
{
    real_t a(1);
    for (int i = 0; i < 10; i++)
    {
        cout << i << " >> " << exp(a*i) << endl;
    }

    return 0;
}
