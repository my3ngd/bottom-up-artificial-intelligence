#ifndef __MY3NGD_DECIMAL_H__
#define __MY3NGD_DECIMAL_H__

#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;

#include "gmpxx.h"

// --------------------------------------------------------------------------------------------------------------------
// real number

// under 32 digit
const uint16_t MAX_PRECISION = 32;

class real_t
{
private:
    mpz_class val;
    uint16_t precision;

public:
    // constructors
    real_t(void);
    real_t(const real_t&);
    real_t(const string&);
    real_t(const int64_t&);
    real_t(const mpz_class&);

    // getters and setters
    mpz_class get_val(void) const;
    uint16_t get_precision(void) const;
    void set_val(const mpz_class&);
    void set_precision(const uint16_t&);

    // unary operators
    real_t operator-() const;
    real_t operator+() const;

    // increment/decrement operators
    real_t& operator++();
    real_t& operator--();
    real_t operator++(int);
    real_t operator--(int);

    // binary operators
    real_t operator+(const real_t&) const;
    real_t operator-(const real_t&) const;
    real_t operator*(const real_t&) const;
    real_t operator/(const real_t&) const;

    // binary friend operators
    friend real_t operator+(const real_t&, const int64_t&);
    friend real_t operator-(const real_t&, const int64_t&);
    friend real_t operator*(const real_t&, const int64_t&);
    friend real_t operator/(const real_t&, const int64_t&);

    // assignment
    real_t& operator=(const real_t&);
    real_t& operator=(const string&);
    real_t& operator=(const int64_t&);
    real_t& operator=(const mpz_class&);

    real_t& operator+=(const real_t&);
    real_t& operator-=(const real_t&);
    real_t& operator*=(const real_t&);
    real_t& operator/=(const real_t&);
    real_t& operator+=(const int64_t&);
    real_t& operator-=(const int64_t&);
    real_t& operator*=(const int64_t&);
    real_t& operator/=(const int64_t&);

    // comparison
    bool operator==(const real_t&) const;
    bool operator!=(const real_t&) const;
    bool operator< (const real_t&) const;
    bool operator> (const real_t&) const;
    bool operator<=(const real_t&) const;
    bool operator>=(const real_t&) const;

    // iostream
    friend std::ostream& operator<<(std::ostream&, const real_t&);
    friend std::istream& operator>>(std::istream&, real_t&);
};

// other
real_t abs(const real_t&);
real_t sqrt(const real_t&);
real_t pow(const real_t&, const real_t&);
real_t pow(const real_t&, const int64_t&);
real_t floor(const real_t&);
real_t ceil(const real_t&);
real_t round(const real_t&);
real_t trunc(const real_t&);
real_t frac(const real_t&);
real_t exp(const real_t&);
real_t log(const real_t&);
real_t log10(const real_t&);
real_t sin(const real_t&);
real_t cos(const real_t&);
real_t tan(const real_t&);
real_t asin(const real_t&);
real_t acos(const real_t&);
real_t atan(const real_t&);
/*
real_t sinh(const real_t&);
real_t cosh(const real_t&);
real_t tanh(const real_t&);
real_t asinh(const real_t&);
real_t acosh(const real_t&);
real_t atanh(const real_t&);
// */


#endif  // __MY3NGD_DECIMAL_H__
