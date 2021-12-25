#include "decimal.h"

// --------------------------------------------------------------------------------------------------------------------
// real number

// constructors
real_t::real_t(void)
{
    this->val = 0;
    this->precision = 0;
}

real_t::real_t(const real_t& other)
{
    this->val = other.val;
    this->precision = other.precision;
}

real_t::real_t(const string& _str)
{
    // is digit
    bool point = false;
    for (const auto& c: _str)
    {
        if (c == *(_str.begin()) && c == '-')
            continue;
        bool chk = false;
        for (int i = 0; i < 10; i++)
        {
            if (c == '0' + i)
            {
                chk = true;
                continue;
            }
            if (c == '.' && ~point)
            {
                chk = true;
                point = true;
                continue;
            }
        }
        if (!chk)
        {
            throw "invalid character";
        }
    }

    if (_str.find('.') == _str.npos)
    {
        this->val = _str;
        this->precision = 0;
    }
    else
    {
        this->val = _str.substr(0, _str.find('.'));
        this->precision = _str.substr(_str.find('.') + 1).length();
    }
}

real_t::real_t(const int64_t& _int)
{
    this->val = std::to_string(_int);
    this->precision = 0;
}

real_t::real_t(const mpz_class& _mpz)
{
    this->val = _mpz.get_str();
    this->precision = 0;
}


// getters and setters
mpz_class real_t::get_val(void) const { return this->val; }

uint16_t real_t::get_precision(void) const { return this->precision; }


// unary operators
real_t real_t::operator-() const
{
    real_t ret;
    ret.val = -this->val;
    ret.precision = this->precision;
    return ret;
}

real_t real_t::operator+() const { return *this; }


// increment/decrement operators
real_t& real_t::operator++()
{
    this->val++;
    return *this;
}

real_t& real_t::operator--()
{
    this->val--;
    return *this;
}

real_t real_t::operator++(int)
{
    real_t ret = *this;
    this->val++;
    return ret;
}

real_t real_t::operator--(int)
{
    real_t ret = *this;
    this->val--;
    return ret;
}


// binary operators
real_t real_t::operator+(real_t other) const
{
    real_t ret = *this;
    for (; ret.precision < other.precision; ret.precision++)    ret.val *= 10;
    for (; ret.precision > other.precision; other.precision++)  other.val *= 10;
    ret.val += other.val;
    return ret;
}

real_t real_t::operator-(real_t other) const
{
    return *this + (-other);
}

real_t real_t::operator*(real_t other) const
{
    real_t ret;
    ret.val = this->val * other.val;
    ret.precision = this->precision + other.precision;
    // precision
    uint16_t diff = std::max(0, ret.precision - MAX_PRECISION);
    ret.val /= std::pow(10, diff);
    ret.precision -= diff;
    return ret;
}

real_t real_t::operator/(real_t other) const
{
    real_t ret = *this;
    // TODO
}


// binary friend operators
real_t operator+(const real_t& real, const int64_t& other) { return real + real_t(other); }

real_t operator-(const real_t& real, const int64_t& other) { return real - real_t(other); }

real_t operator*(const real_t& real, const int64_t& other) { return real * real_t(other); }

real_t operator/(const real_t& real, const int64_t& other) { return real / real_t(other); }


// assignment
real_t& real_t::operator=(const real_t& other)
{
    this->val = other.val;
    this->precision = other.precision;
    return *this;
}

real_t& real_t::operator=(const string& _str)   { return *this = real_t(_str); }

real_t& real_t::operator=(const int64_t& _int)  { return *this = real_t(_int); }

real_t& real_t::operator=(const mpz_class& _mpz){ return *this = real_t(_mpz); }


real_t& real_t::operator+=(const real_t& other) { return *this = *this + other; }

real_t& real_t::operator-=(const real_t& other) { return *this = *this - other; }

real_t& real_t::operator*=(const real_t& other) { return *this = *this * other; }

real_t& real_t::operator/=(const real_t& other) { return *this = *this / other; }

real_t& real_t::operator+=(const int64_t& other) { return *this = *this + real_t(other); }

real_t& real_t::operator-=(const int64_t& other) { return *this = *this - real_t(other); }

real_t& real_t::operator*=(const int64_t& other) { return *this = *this * real_t(other); }

real_t& real_t::operator/=(const int64_t& other) { return *this = *this / real_t(other); }


// comparison
bool real_t::operator==(const real_t& other) const
{
    real_t ret = *this;
    for (; ret.precision < other.precision; ret.precision++)                    ret.val *= 10;
    for (; ret.precision > other.precision && ret.val%10 == 0; ret.precision--) ret.val /= 10;
    return ret.val == other.val;
}

bool real_t::operator!=(const real_t& other) const { return !(*this == other); }

bool real_t::operator< (const real_t& other) const
{
    real_t A = *this;
    real_t B = other;
    for (; A.precision < B.precision; A.precision++)    A.val *= 10;
    for (; A.precision > B.precision; B.precision++)    B.val *= 10;
    return A.val < B.val;
}

bool real_t::operator> (const real_t& other) const { return other < *this; }

bool real_t::operator<=(const real_t& other) const { return !(other < *this); }

bool real_t::operator>=(const real_t& other) const { return !(*this < other); }



bool real_t::is_int(void)
{
    this->remove_unused_zeros();
    return this->precision == 0;
}

void real_t::remove_unused_zeros(void)
{
    for (; this->val%10 == 0 && this->precision > 0; this->precision--)
        this->val /= 10;
}

// stream operators
std::ostream& operator<<(std::ostream& os, const real_t& real)
{
    // TODO
    return os;
}

std::istream& operator>>(std::istream& is, real_t& real)
{
    // TODO
    return is;
}


// other functions
real_t abs(real_t real)
{
    real.get_val() = abs(real.get_val());
    return real;
}

real_t sqrt(real_t real)
{
    real.get_val() = sqrt(real.get_val());
    // TODO
    return real;
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

