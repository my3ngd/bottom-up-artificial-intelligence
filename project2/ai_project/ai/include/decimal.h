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
    real_t operator+(real_t) const;
    real_t operator-(real_t) const;
    real_t operator*(real_t) const;
    real_t operator/(real_t) const;

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
real_t abs(real_t);
real_t sqrt(real_t);
real_t pow(real_t, real_t);
real_t pow(real_t, int64_t);
real_t floor(real_t);
real_t ceil(real_t);
real_t round(real_t);
real_t trunc(real_t);
real_t frac(real_t);
real_t exp(real_t);
real_t log(real_t);
real_t log10(real_t);
real_t sin(real_t);
real_t cos(real_t);
real_t tan(real_t);
real_t asin(real_t);
real_t acos(real_t);
real_t atan(real_t);
/*
real_t sinh(real_t);
real_t cosh(real_t);
real_t tanh(real_t);
real_t asinh(real_t);
real_t acosh(real_t);
real_t atanh(real_t);
// */


#endif  // __MY3NGD_DECIMAL_H__
