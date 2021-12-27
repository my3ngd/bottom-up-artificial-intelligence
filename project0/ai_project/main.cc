#include "matrix.h"

int main(int argc, char const *argv[])
{
    real_t a("123.456");
    real_t b("-789.012");

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    return 0;
}
