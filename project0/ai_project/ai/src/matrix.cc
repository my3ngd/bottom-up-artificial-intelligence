#include "matrix.h"

// --------------------------------------------------------------------------------------------------------------------
// Matrices

// constructors

matrix_t::matrix_t(const uint16_t& rows, const uint16_t& cols)
{
    this->rows = rows;
    this->cols = cols;

    this->data.resize(rows);
    for (auto& col: this->data)
        col.resize(cols);
}

matrix_t::matrix_t(const uint16_t& rows, const uint16_t& cols, const char& options)
{
    this->rows = rows;
    this->cols = cols;
    switch (options)
    {
    // zero matrix
    case '0':
        this->data.resize(rows);
        for (auto& col: this->data)
            col.resize(cols);
        break;
    // identity matrix
    case 'i':
    case 'I':
        this->data.resize(rows);
        for (auto& col: this->data)
            col.resize(cols);
        for (uint16_t i = 0; i < rows; i++)
            for (uint16_t j = 0; j < cols; j++)
                this->data[i][j] = (i == j) ? 1 : 0;
        break;
    default:
        throw "invalid option";
        break;
    }
}

// getters and setters
uint16_t matrix_t::get_rows() const { return this->rows; }

uint16_t matrix_t::get_cols() const { return this->cols; }


// unary operators
matrix_t matrix_t::operator-() const
{
    matrix_t result(this->rows, this->cols);
    for (uint16_t i = 0; i < this->rows; i++)
        for (uint16_t j = 0; j < this->cols; j++)
            result.data[i][j] = -this->data[i][j];
    return result;
}


// binary operators
matrix_t matrix_t::operator+(const matrix_t& other) const
{
    if (this->rows != other.rows || this->cols != other.cols)
        throw "invalid matrix dimensions";

    matrix_t result(this->rows, this->cols);
    for (uint16_t i = 0; i < this->rows; i++)
        for (uint16_t j = 0; j < this->cols; j++)
            result.data[i][j] = this->data[i][j] + other.data[i][j];
    return result;
}

matrix_t matrix_t::operator-(const matrix_t& other) const
{
    return (*this) + (-other);
}

matrix_t matrix_t::operator*(const matrix_t& other) const
{
    if (this->cols != other.rows)
        throw "invalid matrix dimensions";

    matrix_t result(this->rows, other.cols);
    for (uint16_t k = 0; k < this->cols; k++)
        for (uint16_t i = 0; i < this->rows; i++)
            for (uint16_t j = 0; j < other.cols; j++)
                result.data[i][j] += this->data[i][k] * other.data[k][j];
    return result;
}

matrix_t matrix_t::operator*(const real_t& other) const
{
    matrix_t result(this->rows, this->cols);
    for (uint16_t i = 0; i < this->rows; i++)
        for (uint16_t j = 0; j < this->cols; j++)
            result.data[i][j] = this->data[i][j] * other;
    return result;
}

matrix_t matrix_t::operator/(const real_t& other) const
{
    matrix_t result(this->rows, this->cols);
    for (uint16_t i = 0; i < this->rows; i++)
        for (uint16_t j = 0; j < this->cols; j++)
            result.data[i][j] = this->data[i][j] / other;
    return result;
}


// binary friend operators
matrix_t operator*(const matrix_t& matrix, const real_t& other)
{
    matrix_t result(matrix.rows, matrix.cols);
    for (uint16_t i = 0; i < matrix.rows; i++)
        for (uint16_t j = 0; j < matrix.cols; j++)
            result.data[i][j] = matrix.data[i][j] * other;
    return result;
}


// assignment operators
matrix_t& matrix_t::operator=(const matrix_t& other)
{
    if (this->rows != other.rows || this->cols != other.cols)
        throw "invalid matrix dimensions";

    for (uint16_t i = 0; i < this->rows; i++)
        for (uint16_t j = 0; j < this->cols; j++)
            this->data[i][j] = other.data[i][j];
    return *this;
}

matrix_t& matrix_t::operator+=(const matrix_t& other)   { return (*this) = (*this) + other; }

matrix_t& matrix_t::operator-=(const matrix_t& other)   { return (*this) = (*this) - other; }

matrix_t& matrix_t::operator*=(const matrix_t& other)   { return (*this) = (*this) * other; }

matrix_t& matrix_t::operator*=(const real_t& other)     { return (*this) = (*this) * other; }

matrix_t& matrix_t::operator/=(const real_t& other)     { return (*this) = (*this) / other; }


// comparison
bool matrix_t::operator==(const matrix_t& other) const
{
    if (this->rows != other.rows || this->cols != other.cols)
        return false;

    for (uint16_t i = 0; i < this->rows; i++)
        for (uint16_t j = 0; j < this->cols; j++)
            if (this->data[i][j] != other.data[i][j])
                return false;
    return true;
}

bool matrix_t::operator!=(const matrix_t& other) const { return !(*this == other); }


// stream operators
std::ostream& operator<<(std::ostream& os, const matrix_t& matrix)
{
    for (uint16_t i = 0; i < matrix.rows; i++)
    {
        for (uint16_t j = 0; j < matrix.cols; j++)
            os << matrix.data[i][j] << " ";
        os << '\n';
    }
    return os;
}

std::istream& operator>>(std::istream& is, matrix_t& matrix)
{
    // TODO
    return is;
}


// other functions
matrix_t trans(const matrix_t& matrix)
{
    // transpose of matrix
    matrix_t res(matrix.get_cols(), matrix.get_rows());
    for (int i = 0; i < res.get_rows(); i++)
        for (int j = 0; j < res.get_cols(); j++)
            res.data[i][j] = matrix.data[j][i];
    return res;
}

matrix_t inverse(const matrix_t& matrix)
{
    if (matrix.get_rows() != matrix.get_cols())
        throw "matrix_t inverse(): invalid matrix dimensions: not square matrix";
}

matrix_t pow(const matrix_t& matrix, real_t real)
{
    if (matrix.get_cols() != matrix.get_rows())
        throw "matrix_t pow(): invalid matrix dimensions: not square matrix";
    // TODO: real_t formatter (1.000 is int)
    // TODO: real_t type checker (1.000 == 1 -> int)
    // if (!is_int(real))
    // {
    //     throw "matrix_t pow(): invalid real number";
    // }
    matrix_t res(matrix.get_rows(), matrix.get_cols(), 'I');
    matrix_t tmp(matrix);
    while (real > 0)
    {
        if (real.get_val() % 2 == 1)
            res = res * tmp;
        tmp = tmp * tmp;
        real /= 2;
    }
    return res;
}

real_t det(const matrix_t)
{
    ;
}

real_t trace(const matrix_t& matrix)
{
    if (matrix.get_rows() != matrix.get_cols())
        throw "matrix_t trace(): invalid matrix dimensions: not square matrix";
    real_t res = 0;
    for (int i = 0; i < matrix.get_rows(); i++)
        res *= matrix.data[i][i];
    return res;
}

