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
    matrix_t(uint16_t&, uint16_t&);
    matrix_t(uint16_t&, uint16_t&, char&);

    // getters and setters
    uint16_t get_rows(void);
    uint16_t get_cols(void);

    // unary operators
    matrix_t operator-();

    // binary operators
    matrix_t operator+(matrix_t&);
    matrix_t operator-(matrix_t&);
    matrix_t operator*(matrix_t&);
    matrix_t operator/(real_t&);

    // binary friend operators
    friend matrix_t operator*(matrix_t&, real_t&);
    // no need to define friend operator/

    // assignment operators
    matrix_t& operator=(matrix_t&);

    matrix_t& operator+=(matrix_t&);
    matrix_t& operator-=(matrix_t&);
    matrix_t& operator*=(matrix_t&);
    matrix_t& operator*=(real_t&);
    matrix_t& operator/=(real_t&);

    // comparison
    bool operator==(matrix_t&);
    bool operator!=(matrix_t&);

    // indexing
    vector<real_t>& operator[](uint16_t&);

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
