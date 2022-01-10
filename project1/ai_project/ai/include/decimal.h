#ifndef __MY3NGD_DECIMAL_H__
#define __MY3NGD_DECIMAL_H__

/* print precision digits:
 * -1: flexible
 *  0: no under point
 *  1: 1 digit under point
 * ...
 */
extern int print_precision;

#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;

#include "gmpxx.h"
const uint16_t TAYLOR_LOOPS = 32;
const uint16_t RAND_MAX_DIGIT = 10;

// --------------------------------------------------------------------------------------------------------------------
// real number

// under 32 digit
const uint16_t MAX_PRECISION = 8;

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

    bool is_int(void);
    void remove_unused_zeros(void);

    // iostream
    friend std::ostream& operator<<(std::ostream&, real_t);
    friend std::istream& operator>>(std::istream&, real_t);
};

// basic functions
real_t abs(real_t);
real_t sqrt(real_t);
real_t pow(real_t, real_t);
real_t pow(real_t, int64_t);
real_t floor(real_t);
real_t ceil(real_t);
real_t round(real_t);

real_t realrand(real_t, real_t);

real_t exp(real_t);
real_t ln(real_t);
real_t sin(real_t);
real_t cos(real_t);
real_t tan(real_t);

// activation functionq
real_t sigmoid(real_t);
real_t tanh(real_t);
real_t relu(real_t);
real_t leaky_relu(real_t);
real_t exp_lu(real_t);
real_t linear(real_t);

// scalar functions
enum func_t
{
    EXP,    // 0
    LN,     // 1
    SQRT,   // 2
    SIN,    // 3
    COS,    // 4
    TAN,    // 5
    SIGMOID,// 6
    TANH,   // 7
    RELU,   // 8
    LRELU,  // 9
    ELU,    // 10
    LINEAR, // 11
};

// derivative real_t by function f(x)
real_t df(const func_t&, real_t);

extern real_t PI;
extern real_t E;

#endif  // __MY3NGD_DECIMAL_H__
