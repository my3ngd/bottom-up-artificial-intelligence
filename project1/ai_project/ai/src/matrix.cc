#include "matrix.h"

// --------------------------------------------------------------------------------------------------------------------
// Matrices

// constructors
matrix_t::matrix_t(void)
{
    // code
}

matrix_t::matrix_t(const uint16_t& rows, const uint16_t& cols)
{
    // code
}

matrix_t::matrix_t(const uint16_t& rows, const uint16_t& cols, const char& options)
{
    // code
}

matrix_t::matrix_t(const vector<real_t>& vec)
{
    // code
}

matrix_t::matrix_t(const vector<vector<real_t>>& mat)
{
    // code
}

// getters and setters
uint16_t matrix_t::get_rows(void) const { return this->rows; }

uint16_t matrix_t::get_cols(void) const { return this->cols; }


// unary operators
matrix_t matrix_t::operator-(void) const
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
matrix_t& matrix_t::operator=(const vector<real_t>& other)
{
    // code
}

matrix_t& matrix_t::operator=(const vector<vector<real_t>>& other)
{
    // code
}

matrix_t& matrix_t::operator=(const matrix_t& other)
{
    // code
}

matrix_t& matrix_t::operator+=(const matrix_t& other) { return *this = *this + other; }

matrix_t& matrix_t::operator-=(const matrix_t& other) { return *this = *this - other; }

matrix_t& matrix_t::operator*=(const matrix_t& other) { return *this = *this * other; }

matrix_t& matrix_t::operator*=(const real_t& other) { return *this = *this * other; }

matrix_t& matrix_t::operator/=(const real_t& other) { return *this = *this / other; }


// comparison
bool matrix_t::operator==(const matrix_t& other) const
{
    // code
}

bool matrix_t::operator!=(const matrix_t& other) const { return !(*this == other); }


// indexing
vector<real_t>& matrix_t::operator[](const uint32_t& index)
{
    // code
}

vector<real_t>& matrix_t::operator[](const int32_t& index)  { return this->operator[](static_cast<uint32_t>(index)); }


// broadcast
matrix_t matrix_t::broadcast(const int64_t& _rows, const int64_t& _cols) const
{
    // code
}


// reduce dimension
// [n, m] -> [1, m]
matrix_t matrix_t::sum_rows(void) const
{
    // code
}

// [n, m] -> [n, 1]
matrix_t matrix_t::sum_cols(void) const
{
    // code
}



// stream operators
std::ostream& operator<<(std::ostream& os, matrix_t matrix)
{
    // code
}

std::istream& operator>>(std::istream& is, matrix_t& matrix)
{
    // code
}


// other functions
matrix_t trans(matrix_t& matrix)
{
    // code
}

matrix_t inverse(const matrix_t& matrix)
{
    // code
}

matrix_t pow(const matrix_t& matrix, real_t real)
{
    // code
}

real_t det(matrix_t& matrix)
{
    // code
}

real_t trace(matrix_t& matrix)
{
    // code
}

// derivative
matrix_t df(const func_t& func, matrix_t x)
{
    // code
}

