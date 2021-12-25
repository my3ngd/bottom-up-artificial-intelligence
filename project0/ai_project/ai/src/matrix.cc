#include "matrix.h"

// --------------------------------------------------------------------------------------------------------------------
// Matrices

// constructors

matrix_t::matrix_t(const uint16_t& rows, const uint16_t& cols)
{
    // code
}

matrix_t::matrix_t(const uint16_t& rows, const uint16_t& cols, const char& options)
{
    // code
}

// getters and setters
uint16_t matrix_t::get_rows() const
{
    // code
}

uint16_t matrix_t::get_cols() const
{
    // code
}


// unary operators
matrix_t matrix_t::operator-() const
{
    // code
}


// binary operators
matrix_t matrix_t::operator+(const matrix_t& other) const
{
    // code
}

matrix_t matrix_t::operator-(const matrix_t& other) const
{
    // code
}

matrix_t matrix_t::operator*(const matrix_t& other) const
{
    // code
}

matrix_t matrix_t::operator*(const real_t& other) const
{
    // code
}

matrix_t matrix_t::operator/(const real_t& other) const
{
    // code
}


// binary friend operators
matrix_t operator*(const matrix_t& matrix, const real_t& other)
{
    // code
}


// assignment operators
matrix_t& matrix_t::operator=(const matrix_t& other)
{
    // code
}

matrix_t& matrix_t::operator+=(const matrix_t& other)
{
    // code
}

matrix_t& matrix_t::operator-=(const matrix_t& other)
{
    // code
}

matrix_t& matrix_t::operator*=(const matrix_t& other)
{
    // code
}

matrix_t& matrix_t::operator*=(const real_t& other)
{
    // code
}

matrix_t& matrix_t::operator/=(const real_t& other)
{
    // code
}


// comparison
bool matrix_t::operator==(const matrix_t& other) const
{
    // code
}

bool matrix_t::operator!=(const matrix_t& other) const
{
    // code
}


// stream operators
std::ostream& operator<<(std::ostream& os, const matrix_t& matrix)
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
matrix_t trans(const matrix_t& matrix)
{
    // code
}

matrix_t inverse(const matrix_t& matrix)
{
    // code
}

matrix_t pow(const matrix_t& matrix, real_t real)
{
    ;
}

real_t det(const matrix_t)
{
    ;
}

real_t trace(const matrix_t& matrix)
{
    ;
}

