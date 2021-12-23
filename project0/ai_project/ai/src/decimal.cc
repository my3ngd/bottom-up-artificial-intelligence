#include "decimal.h"


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
real_t real_t::operator+(const real_t& other) const
{
    // code
}

real_t real_t::operator-(const real_t& other) const
{
    // code
}

real_t real_t::operator*(const real_t& other) const
{
    // code
}

real_t real_t::operator/(const real_t& other) const
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
real_t abs(const real_t& real)
{
    // code
}

real_t sqrt(const real_t& real)
{
    // code
}

real_t pow(const real_t& real, const int64_t& exp)
{
    // code
}

real_t pow(const real_t& real, const real_t& exp)
{
    // code
}

real_t floor(const real_t& real)
{
    // code
}

real_t ceil(const real_t& real)
{
    // code
}

real_t round(const real_t& real)
{
    // code
}

real_t trunc(const real_t& real)
{
    // code
}

real_t frac(const real_t& real)
{
    // code
}

real_t exp(const real_t& real)
{
    // code
}

real_t log(const real_t& real)
{
    // code
}

real_t log10(const real_t& real)
{
    // code
}

real_t sin(const real_t& real)
{
    // code
}

real_t cos(const real_t& real)
{
    // code
}

real_t tan(const real_t& real)
{
    // code
}

real_t asin(const real_t& real)
{
    // code
}

real_t acos(const real_t& real)
{
    // code
}

real_t atan(const real_t& real)
{
    // code
}

/*
real_t sinh(const real_t& real)
{
    // code
}

real_t cosh(const real_t& real)
{
    // code
}

real_t tanh(const real_t& real)
{
    // code
}

real_t asinh(const real_t& real)
{
    // code
}

real_t acosh(const real_t& real)
{
    // code
}

real_t atanh(const real_t& real)
{
    // code
}

// */
