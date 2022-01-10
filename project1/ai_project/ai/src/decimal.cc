#include "decimal.h"

/* TODO list
 * output formmating
 * power function
 */

real_t e("2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274");
real_t PI("3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679");

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
            cout << "invalid character exists at" << __FILE__ << ", line " << __LINE__ << endl;
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
        this->precision = _str.substr(_str.find('.') + 1).length();
        this->val = _str.substr(0, _str.find('.')) + _str.substr(_str.find('.') + 1);
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

void real_t::set_val(const mpz_class& _val) { this->val = _val; }

uint16_t real_t::get_precision(void) const { return this->precision; }

void real_t::set_precision(const uint16_t& _precision) { this->precision = _precision; }

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
    const uint16_t DEVIDE_PRECISION = 100;
    real_t ret = *this;
    /* 나눗셈 연산
     * 1. ret 자리수를 엄청 크게 설정함
     * 2. other로 나눔
     * 3. precision 조정
     * 
     * [ex] 123/4567
     * 1. 123 -> 1230...0 (몇 개를 추가?)
     * 2. 1230...0 / 4567 = ???
     * 3. ??? -> precision 조정
     */
    for (int i = 0; i < DEVIDE_PRECISION; i++)
        ret.val *= 10;

    ret.val /= other.val;
    ret.precision = DEVIDE_PRECISION + ret.precision - other.precision;
    for (; ret.precision > MAX_PRECISION; ret.precision--)
        ret.val /= 10;
    ret.remove_unused_zeros();
    return ret;
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
std::ostream& operator<<(std::ostream& os, real_t real)
{
    // remove leading zeros
    while (real.get_val()%10 == 0 && real.get_precision() > 0)
    {
        real.set_val(real.get_val()/10);
        real.set_precision(real.get_precision()-1);
    }

    if (real.get_val() == 0)
        return os << "0";
    if (real.get_precision() == 0)
        return os << real.get_val();

    string output_string = real.val.get_str();
    bool is_signed = output_string[0] == '-';
    if (is_signed)
    {
        os << '-';
        output_string.erase(0, 1);
    }

    if (real.precision < output_string.size())
    {
        output_string.insert(output_string.begin() + (output_string.size() - real.precision), '.');
        return os << output_string;
    }
    // under 1
    os << "0.";
    for (int i = 0; i < real.get_precision() - output_string.size(); i++)
        os << "0";
    return os << output_string;
}

std::istream& operator>>(std::istream& is, real_t real)
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
    if (real.get_val() < 0)
    {
        cout << "sqrt(real_t) : error : sqrt(-x) is undefined" << endl;
        throw std::runtime_error("sqrt(real_t): negative number");
    }
    // TODO
}

real_t pow(real_t real, int64_t exp)
{
    return pow(real, real_t(exp));
}

real_t pow(real_t real, real_t exp)
{
    if (exp.is_int())
    {
        real_t res = 1;
        while (exp > 0)
        {
            if (exp.get_val() % 2 == 1)
                res *= real;
            exp = floor(exp/2);
            real *= real;
        }
        return res;
    }
    // TODO: implement non-integer exponents
    // like power(2, 3.14)
}

real_t floor(real_t real)
{
    uint16_t precision = real.get_precision();
    for (int i = 0; i < precision; i++)
        real.set_val(real.get_val() / 10);
    real.set_precision(0);
    return real;
}

real_t ceil(real_t real)
{
    if (real.is_int())
        return real;
    real_t res = floor(real);
    res.set_val(res.get_val() + 1);
    return res;
}

real_t round(real_t real)
{
    if (real.is_int())
        return real;
    real_t res = floor(real);
    if (real.get_val() % 10 >= 5)
        res.set_val(res.get_val() + 1);
    return res;
}

real_t realrand(real_t _min, real_t _max)
{
    string st = "";
    for (int i = 0; i < RAND_MAX_DIGIT; i++)
        st += '9';
    real_t _MAX(st);
    // get random number in [0, 1]
    string res_str = "";
    for (int i = 0; i < RAND_MAX_DIGIT; i++)
        res_str += std::to_string(rand()%10);
    // remove leading zeros
    while (res_str[0] == '0')
        res_str.erase(0, 1);

    real_t res(res_str);
    return _min + res * (_max - _min) / _MAX;
}


real_t exp(real_t real)
{
    if (real.is_int() && real >= 0)
        return pow(e, real);
    /* taylor series for exp(x)
     * exp(x) = 1 + x + x^2/2! + x^3/3! + ...
     */
    real_t res = 1;
    real_t x = real;
    real_t f = 1;
    for (real_t i = 1; i < TAYLOR_LOOPS; i++)
    {
        f *= i;
        res += x / f;
        x *= real;
    }
    return res;
}

real_t ln(real_t real)
{
    if (real.get_val() <= 0)
    {
        cout << "ln(real_t) : error : ln(0) is undefined" << endl;
        throw std::runtime_error("ln(real_t): negative number");
    }
    const uint16_t LN_LOOP_COUNT = TAYLOR_LOOPS;
    // ln(1+x) = Sum(n=1...inf, (-1)^(n+1)*x^n/n)
    // TODO
}

real_t sin(real_t real)
{
    const uint16_t SIN_LOOP_COUNT = 10;
    // get sin(real) in radians using the Taylor series
    // sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
    real_t x = real;
    real_t res = x;
    real_t f = 1;
    real_t sign = 1;
    for (uint16_t i = 1; i < SIN_LOOP_COUNT; i++)
    {
        x *= -real*real / f;
        res += x * sign;
        sign *= -1;
        f /= (i<<1|0)*(i<<1|1);
    }
    return res;
}

real_t cos(real_t real)
{
    const uint16_t COS_LOOP_COUNT = TAYLOR_LOOPS;
    // get cos(real) in radians using the Taylor series
    // cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...
    real_t x = real;
    real_t res = 1;
    real_t f = 1;
    real_t sign = 1;
    for (uint16_t i = 1; i < COS_LOOP_COUNT; i++)
    {
        x *= -real*real / f;
        res += x * sign;
        sign *= -1;
        f *= (i*2-1)*(i*2);
    }
    return res;
}

real_t tan(real_t real)
{
    // not easy to implement
    return sin(real) / cos(real);
}


// activation functions
real_t sigmoid(real_t real)
{
    return real_t(1) / (real_t(1) + exp(-real));
}

real_t tanh(real_t real)
{
    return sigmoid(real) * 2 - real_t(1);
}

real_t relu(real_t real)
{
    return real > 0 ? real : real_t(0);
}

real_t leaky_relu(real_t real)
{
    return real > 0 ? real : real_t("0.01") * real;
}

real_t exp_lu(real_t real)
{
    if (real >= 0)   return real;
    return exp(real) - 1;
}

real_t linear(real_t real)
{
    return real;
}



// derivative real_t by function f(x)
real_t df(const func_t& func, real_t x)
{
    switch (func)
    {
    case EXP:
        return exp(x);
    case LN:
        return real_t(1) / x;
    case SQRT:
        return real_t(1) / (real_t(2) * sqrt(x));
    case SIN:
        return cos(x);
    case COS:
        return -sin(x);
    case TAN:
        return real_t(1) + tan(x) * tan(x);
    case SIGMOID:
    {
        real_t sig = sigmoid(x);
        return sig * (real_t(1) - sig);
    }
    case TANH:
    {
        real_t _tanh = tanh(x);
        return real_t(1) - _tanh * _tanh;
    }
    case RELU:
        return x > 0 ? real_t(1) : real_t(0);
    case LRELU:
        return x > 0 ? real_t("1") : real_t("0.01");
    case ELU:
        return x > 0 ? real_t(1) : exp(x);
    case LINEAR:
        return real_t(1);
    default:
        cout << "df(real_t) : error : unknown activation function" << endl;
        throw std::runtime_error("df(real_t): unknown activation function");
    }
}

