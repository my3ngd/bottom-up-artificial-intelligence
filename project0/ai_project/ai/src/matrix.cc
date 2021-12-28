#include "matrix.h"

// --------------------------------------------------------------------------------------------------------------------
// Matrices

// constructors

matrix_t::matrix_t(uint16_t& rows, uint16_t& cols)
{
    // code
}

matrix_t::matrix_t(uint16_t& rows, uint16_t& cols, char& options)
{
    // code
}

// getters and setters
uint16_t matrix_t::get_rows()
{
    // code
}

uint16_t matrix_t::get_cols()
{
    // code
}


// unary operators
matrix_t matrix_t::operator-()
{
    // code
}


// binary operators
matrix_t matrix_t::operator+(matrix_t& other)
{
    // code
}

matrix_t matrix_t::operator-(matrix_t& other)
{
    // code
}

matrix_t matrix_t::operator*(matrix_t& other)
{
    // code
}

matrix_t matrix_t::operator/(real_t& other)
{
    // code
}


// binary friend operators
matrix_t operator*(matrix_t& matrix, real_t& other)
{
    // code
}


// assignment operators
matrix_t& matrix_t::operator=(matrix_t& other)
{
    // code
}

matrix_t& matrix_t::operator+=(matrix_t& other)
{
    // code
}

matrix_t& matrix_t::operator-=(matrix_t& other)
{
    // code
}

matrix_t& matrix_t::operator*=(matrix_t& other)
{
    // code
}

matrix_t& matrix_t::operator*=(real_t& other)
{
    // code
}

matrix_t& matrix_t::operator/=(real_t& other)
{
    // code
}


// comparison
bool matrix_t::operator==(matrix_t& other)
{
    // code
}

bool matrix_t::operator!=(matrix_t& other)
{
    // code
}


// indexing
vector<real_t>& matrix_t::operator[](uint16_t& index)
{
    // code
}


// stream operators
std::ostream& operator<<(std::ostream& os, matrix_t& matrix)
{
    // code
    return os;
}

std::istream& operator>>(std::istream& is, matrix_t& matrix)
{
    // code
    return is;
}


// other functions
matrix_t trans(matrix_t& matrix)
{
    // code
}

matrix_t inverse(matrix_t& matrix)
{
    // code
}

matrix_t pow(matrix_t& matrix, real_t real)
{
    // code
}

real_t det(matrix_t)
{
    // code
}

real_t trace(matrix_t& matrix)
{
    // code
}

