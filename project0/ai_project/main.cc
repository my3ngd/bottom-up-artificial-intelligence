#include "matrix.h"

int main(int argc, char const *argv[])
{
    matrix_t m1(2, 2, 'i');
    matrix_t m2(2, 2, '0');
    m2[0][0] = 1;
    return 0;
}
