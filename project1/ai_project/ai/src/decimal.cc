#include "decimal.h"

real_t e("2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274");
real_t PI("3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");

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

void real_t::set_val(const mpz_class& _val)
{
    this->val = _val;
}

uint16_t real_t::get_precision(void) const
{
    return this->precision;
}

void real_t::set_precision(const uint16_t& _precision)
{
    this->precision = _precision;
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

void real_t::remove_unused_zeros(void)
{
    // code
}

// stream operators
std::ostream& operator<<(std::ostream& os, real_t real)
{
    // code
    return os;
}

std::istream& operator>>(std::istream& is, real_t real)
{
    // TODO
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

real_t realrand(real_t _min, real_t _max)
{
    // code
}


real_t exp(real_t real)
{
    // code
}

real_t ln(real_t real)
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


// activation functions
real_t sigmoid(real_t real)
{
    // code
}

real_t tanh(real_t real)
{
    // code
}

real_t relu(real_t real)
{
    // code
}

real_t leaky_relu(real_t real)
{
    // code
}

real_t exp_lu(real_t real)
{
    // code
}

real_t linear(real_t real)
{
    // code
}



// derivative real_t by function f(x)
real_t df(const func_t& func, real_t x)
{
    // code
}

