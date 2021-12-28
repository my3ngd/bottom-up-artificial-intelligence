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
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                this->data[i][j] = (i == j) ? 1 : 0;
        break;
    default:
        cout << "Invalid option for matrix constructor: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "invalid option";
        break;
    }
}

matrix_t::matrix_t(const vector<real_t>& vec)
{
    this->rows = vec.size();
    this->cols = 1;
    this->data.resize(rows);
    for (auto& col: this->data)
        col.resize(cols);
    for (int i = 0; i < rows; i++)
        this->data[i][0] = vec[i];
}

matrix_t::matrix_t(const vector<vector<real_t>>& mat)
{
    this->rows = mat.size();
    this->cols = mat[0].size();
    this->data.resize(rows);
    for (auto& col: this->data)
        col.resize(cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            this->data[i][j] = mat[i][j];
}

// getters and setters
uint16_t matrix_t::get_rows(void) const { return this->rows; }

uint16_t matrix_t::get_cols(void) const { return this->cols; }


// unary operators
matrix_t matrix_t::operator-(void) const
{
    matrix_t result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            result[i][j] = -this->data[i][j];
    return result;
}


// binary operators
matrix_t matrix_t::operator+(const matrix_t& other) const
{
    if (this->rows != other.rows || this->cols != other.cols)
    {
        cout << "Invalid matrix dimensions: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "invalid matrix dimensions";
    }

    matrix_t result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            result[i][j] = this->data[i][j] + other.data[i][j];
    return result;
}

matrix_t matrix_t::operator-(const matrix_t& other) const
{
    return (*this) + (-other);
}

matrix_t matrix_t::operator*(const matrix_t& other) const
{
    if (this->cols != other.rows)
    {
        cout << "Invalid matrix dimensions: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "invalid matrix dimensions";
    }

    matrix_t result(this->rows, other.cols);
    for (int k = 0; k < this->cols; k++)
        for (int i = 0; i < this->rows; i++)
            for (int j = 0; j < other.cols; j++)
                result[i][j] += this->data[i][k] * other.data[k][j];
    return result;
}

matrix_t matrix_t::operator/(const real_t& other) const
{
    matrix_t result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            result[i][j] = this->data[i][j] / other;
    return result;
}


// binary friend operators
matrix_t operator*(const matrix_t& matrix, const real_t& other)
{
    matrix_t result(matrix.rows, matrix.cols);
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.cols; j++)
            result[i][j] = matrix.data[i][j] * other;
    return result;
}


// assignment operators
matrix_t& matrix_t::operator=(const vector<real_t>& other)
{
    // [n, 1] matrix
    this->rows = other.size();
    this->cols = 1;
    this->data.resize(this->rows);
    for (auto& col: this->data)
        col.resize(this->cols);

    for (int i = 0; i < this->rows; i++)
        this->data[i][0] = other[i];
    return *this;
}

matrix_t& matrix_t::operator=(const vector<vector<real_t>>& other)
{
    this->rows = other.size();
    this->cols = other[0].size();
    this->data.resize(this->rows);
    for (auto& col: this->data)
        col.resize(this->cols);

    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            this->data[i][j] = other[i][j];
    return *this;
}

matrix_t& matrix_t::operator=(const matrix_t& other)
{
    if (this->rows != other.rows || this->cols != other.cols)
    {
        cout << "Invalid matrix dimensions: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "invalid matrix dimensions";
    }
    return *this = other.data;
}

matrix_t& matrix_t::operator+=(const matrix_t& other)
{
    if (this->rows != other.rows || this->cols != other.cols)
    {
        cout << "Invalid matrix dimensions: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "invalid matrix dimensions";
    }
    return *this = *this + other;
}

matrix_t& matrix_t::operator-=(const matrix_t& other)
{
    if (this->rows != other.rows || this->cols != other.cols)
    {
        cout << "Invalid matrix dimensions: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "invalid matrix dimensions";
    }
    return *this = *this - other;
}

matrix_t& matrix_t::operator*=(const matrix_t& other)
{
    if (this->cols != other.rows)
    {
        cout << "Invalid matrix dimensions: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "invalid matrix dimensions";
    }
    return *this = *this * other;
}

matrix_t& matrix_t::operator*=(const real_t& other)
{
    return *this = *this * other;
}

matrix_t& matrix_t::operator/=(const real_t& other)
{
    return *this = *this / other;
}


// comparison
bool matrix_t::operator==(const matrix_t& other) const
{
    if (this->rows != other.rows || this->cols != other.cols)
        return false;

    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            if (this->data[i][j] != other.data[i][j])
                return false;
    return true;
}

bool matrix_t::operator!=(const matrix_t& other) const
{
    return !(*this == other);
}


// indexing
vector<real_t>& matrix_t::operator[](const uint32_t& index)
{
    if (index >= this->rows)
    {
        cout << "Invalid index: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "invalid index";
    }
    return this->data[index];
}

vector<real_t>& matrix_t::operator[](const int32_t& index)
{
    if (index < 0 || index >= this->rows)
    {
        cout << "Invalid index: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "invalid index";
    }
    return this->data[index];
}


// stream operators
std::ostream& operator<<(std::ostream& os, matrix_t& matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
            os << matrix[i][j] << " ";
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
matrix_t trans(matrix_t& matrix)
{
    // transpose of matrix
    matrix_t res(matrix.get_cols(), matrix.get_rows());
    for (int i = 0; i < res.get_rows(); i++)
        for (int j = 0; j < res.get_cols(); j++)
            res[i][j] = matrix[j][i];
    return res;
}

matrix_t inverse(const matrix_t& matrix)
{
    if (matrix.get_rows() != matrix.get_cols())
    {
        cout << "Invalid matrix dimensions: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "matrix_t inverse(): invalid matrix dimensions: not square matrix";
    }
    // TODO: inverse matrix
}

matrix_t pow(const matrix_t& matrix, real_t real)
{
    if (matrix.get_cols() != matrix.get_rows())
    {
        cout << "Invalid matrix dimensions: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "matrix_t pow(): invalid matrix dimensions: not square matrix";
    }

    if (!real.is_int())  // real is formated value now
    {
        cout << "Invalid real value: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "matrix_t pow(): invalid real number";
    }

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

real_t det(matrix_t& matrix)
{
    // get determinant of matrix using LU-factorization
    if (matrix.get_rows() != matrix.get_cols())
    {
        cout << "Invalid matrix dimensions: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "matrix_t det(): invalid matrix dimensions: not square matrix";
    }

    // copy matrix
    matrix_t tmp(matrix);

    // LU-factorization (copilot coded)
    for (int i = 0; i < tmp.get_rows(); i++)
    {
        // find pivot
        uint16_t pivot = i;
        for (int j = i + 1; j < tmp.get_rows(); j++)
            if (abs(tmp[j][i]) > abs(tmp[pivot][i]))
                pivot = j;

        // swap rows
        if (pivot != i)
            for (int j = 0; j < tmp.get_cols(); j++)
                std::swap(tmp[i][j], tmp[pivot][j]);

        // check if matrix is singular
        if (tmp[i][i] == 0)
            return 0;

        // divide row by pivot
        for (int j = 0; j < tmp.get_cols(); j++)
            tmp[i][j] /= tmp[i][i];;
        // real_t pivot_inv = real_t(1) / tmp[i][i];
        // for (int j = 0; j < tmp.get_cols(); j++)
        //     tmp[i][j] *= pivot_inv;

        // subtract multiple of row from other rows
        for (int j = 0; j < tmp.get_rows(); j++)
            if (j != i)
            {
                real_t multiple = tmp[j][i];
                for (int k = 0; k < tmp.get_cols(); k++)
                    tmp[j][k] -= multiple * tmp[i][k];
            }
    }

    // calculate determinant
    real_t det = 1;
    for (int i = 0; i < tmp.get_rows(); i++)
        det *= tmp[i][i];
    return det;
}

real_t trace(matrix_t& matrix)
{
    if (matrix.get_rows() != matrix.get_cols())
    {
        cout << "Invalid matrix dimensions: " << __FILE__ << " -> function " << __func__ << ", line " << __LINE__ << endl;
        throw "matrix_t trace(): invalid matrix dimensions: not square matrix";
    }
    real_t res = 0;
    for (int i = 0; i < matrix.get_rows(); i++)
        res *= matrix[i][i];
    return res;
}

