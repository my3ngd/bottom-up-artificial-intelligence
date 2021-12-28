#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "decimal.h"


// --------------------------------------------------------------------------------------------------------------------
// Matrices

class matrix_t
{
private:
    uint16_t rows;
    uint16_t cols;
    vector<vector<real_t>> data;

public:
    // constructors
    matrix_t(const uint16_t&, const uint16_t&);
    matrix_t(const uint16_t&, const uint16_t&, const char&);

    // getters and setters
    uint16_t get_rows(void) const;
    uint16_t get_cols(void) const;

    // unary operators
    matrix_t operator-(void) const;

    // binary operators
    matrix_t operator+(const matrix_t&) const;
    matrix_t operator-(const matrix_t&) const;
    matrix_t operator*(const matrix_t&) const;
    matrix_t operator/(const real_t&)   const;

    // binary friend operators
    friend matrix_t operator*(const matrix_t&, const real_t&);
    // no need to define friend operator/

    // assignment operators
    matrix_t& operator=(const matrix_t&);

    matrix_t& operator+=(const matrix_t&);
    matrix_t& operator-=(const matrix_t&);
    matrix_t& operator*=(const matrix_t&);
    matrix_t& operator*=(const real_t&);
    matrix_t& operator/=(const real_t&);

    // comparison
    bool operator==(const matrix_t&) const;
    bool operator!=(const matrix_t&) const;

    // indexing
    vector<real_t>& operator[](const uint32_t&);
    vector<real_t>& operator[](const int32_t&);

    // iostream
    friend std::ostream& operator<<(std::ostream&, matrix_t&);
    friend std::istream& operator>>(std::istream&, matrix_t&);
};

// matrix operations
matrix_t trans(matrix_t&);
matrix_t inverse(matrix_t&);
matrix_t pow(matrix_t&, real_t);
real_t det(matrix_t&);
real_t trace(matrix_t&);

#endif  // __MATRIX_H__
