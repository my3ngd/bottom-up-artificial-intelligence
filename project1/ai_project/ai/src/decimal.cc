#include "decimal.h"

// --------------------------------------------------------------------------------------------------------------------
// real number

// constructors
real_t::real_t(void)
{
    // code
}

real_t::real_t(const real_t& other)
{
    // code
}

real_t::real_t(const string& _str)
{
    // code
}

real_t::real_t(const int64_t& _int)
{
    // code
}

real_t::real_t(const mpz_class& _mpz)
{
    // code
}


// getters and setters
mpz_class real_t::get_val(void) const
{
    return this->val;
}

uint16_t real_t::get_precision(void) const
{
    return this->precision;
}


// unary operators
real_t real_t::operator-() const
{
    // code
}

real_t real_t::operator+() const
{
    // code
    return *this;
}


// increment/decrement operators
real_t& real_t::operator++()
{
    // code
    return *this;
}

real_t& real_t::operator--()
{
    // code
    return *this;
}

real_t real_t::operator++(int)
{
    // code
}

real_t real_t::operator--(int)
{
    // code
}


// binary operators
real_t real_t::operator+(real_t other) const
{
    // code
}

real_t real_t::operator-(real_t other) const
{
    // code
}

real_t real_t::operator*(real_t other) const
{
    // code
}

real_t real_t::operator/(real_t other) const
{
    // code
}


// binary friend operators
real_t operator+(const real_t& real, const int64_t& other)
{
    // code
}

real_t operator-(const real_t& real, const int64_t& other)
{
    // code
}

real_t operator*(const real_t& real, const int64_t& other)
{
    // code
}

real_t operator/(const real_t& real, const int64_t& other)
{
    // code
}


// assignment
real_t& real_t::operator=(const real_t& other)
{
    // code
    return *this;
}

real_t& real_t::operator=(const string& _str)
{
    // code
    return *this;
}

real_t& real_t::operator=(const int64_t& _int)
{
    // code
    return *this;
}

real_t& real_t::operator=(const mpz_class& _mpz)
{
    // code
    return *this;
}


real_t& real_t::operator+=(const real_t& other)
{
    // code
    return *this;
}

real_t& real_t::operator-=(const real_t& other)
{
    // code
    return *this;
}

real_t& real_t::operator*=(const real_t& other)
{
    // code
    return *this;
}

real_t& real_t::operator/=(const real_t& other)
{
    // code
    return *this;
}

real_t& real_t::operator+=(const int64_t& other)
{
    // code
    return *this;
}

real_t& real_t::operator-=(const int64_t& other)
{
    // code
    return *this;
}

real_t& real_t::operator*=(const int64_t& other)
{
    // code
    return *this;
}

real_t& real_t::operator/=(const int64_t& other)
{
    // code
    return *this;
}


// comparison
bool real_t::operator==(const real_t& other) const
{
    // code
}

bool real_t::operator!=(const real_t& other) const
{
    // code
}

bool real_t::operator< (const real_t& other) const
{
    // code
}

bool real_t::operator> (const real_t& other) const
{
    // code
}

bool real_t::operator<=(const real_t& other) const
{
    // code
}

bool real_t::operator>=(const real_t& other) const
{
    // code
}


// stream operators
std::ostream& operator<<(std::ostream& os, const real_t& real)
{
    // code
    return os;
}

std::istream& operator>>(std::istream& is, real_t& real)
{
    // code
    return is;
}


// other functions
real_t abs(real_t real)
{
    // code
}

real_t sqrt(real_t real)
{
    // code
}

real_t pow(real_t real, int64_t exp)
{
    // code
}

real_t pow(real_t real, real_t exp)
{
    // code
}

real_t floor(real_t real)
{
    // code
}

real_t ceil(real_t real)
{
    // code
}

real_t round(real_t real)
{
    // code
}

real_t trunc(real_t real)
{
    // code
}

real_t frac(real_t real)
{
    // code
}

real_t exp(real_t real)
{
    // code
}

real_t log(real_t real)
{
    // code
}

real_t log10(real_t real)
{
    // code
}

real_t sin(real_t real)
{
    // code
}

real_t cos(real_t real)
{
    // code
}

real_t tan(real_t real)
{
    // code
}

real_t asin(real_t real)
{
    // code
}

real_t acos(real_t real)
{
    // code
}

real_t atan(real_t real)
{
    // code
}

/*
real_t sinh(real_t real)
{
    // code
}

real_t cosh(real_t real)
{
    // code
}

real_t tanh(real_t real)
{
    // code
}

real_t asinh(real_t real)
{
    // code
}

real_t acosh(real_t real)
{
    // code
}

real_t atanh(real_t real)
{
    // code
}

// */

