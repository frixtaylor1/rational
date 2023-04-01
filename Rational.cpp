#include "Rational.hpp"

int findGCD(int a, int b)
{
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

Rational::Rational(int numerator, int denominator)
    : m_numerator(numerator), m_denominator(denominator)
{
    if( m_numerator == 0 ) std::__throw_invalid_argument("Numerator must be greater or lower than 0");

    reduce();
}

Rational::Rational(const Rational& rhs)
    : m_numerator(rhs.m_numerator), m_denominator(rhs.m_denominator)
{
    reduce();
}

Rational::Rational(Rational const&& rhs)
    : m_numerator(rhs.m_numerator), m_denominator(rhs.m_denominator)
{
    reduce();
}

constexpr void Rational::operator = (const Rational& rhs ) noexcept
{
    m_numerator = rhs.m_numerator;
    m_denominator = rhs.m_numerator;
}

bool Rational::operator < (Rational const& rhs) const noexcept
{
    return toDecimal() < rhs.toDecimal();
}

bool Rational::operator > (Rational const& rhs) const noexcept
{
    return !( *this < rhs );
}

bool Rational::operator == (Rational const& rhs) const noexcept
{
    return toDecimal() == rhs.toDecimal();
}

bool Rational::operator != (Rational const& rhs) const noexcept
{
    return !( *this == rhs );
}

Rational Rational::operator + (Rational const& rhs) const noexcept
{
    int commonDenominator = m_denominator * rhs.m_denominator;
    int numerator = ( m_numerator * rhs.m_denominator ) + ( m_denominator * rhs.m_numerator );
    return { numerator, commonDenominator };
}

Rational Rational::operator - (Rational const& rhs) const noexcept
{
    int commonDenominator = m_denominator * rhs.m_denominator;
    int numerator = ( m_numerator * rhs.m_denominator ) - ( m_denominator * rhs.m_numerator );
    return { numerator, commonDenominator };
}

Rational Rational::operator * (Rational const& rhs) const noexcept
{
    return { m_numerator * rhs.m_numerator, m_denominator * rhs.m_denominator };
}

Rational Rational::operator / (Rational const& rhs) const noexcept
{
    return { m_numerator * rhs.m_denominator, m_denominator * rhs.m_numerator };
}

constexpr bool Rational::operator < (float rhs) const noexcept
{
    return { toDecimal() < rhs };
}

constexpr bool Rational::operator > (float rhs) const noexcept
{
    return { !(toDecimal() < rhs) };
}

bool operator < (float lhs, Rational const& rhs) noexcept
{
    return { lhs < rhs.toDecimal() };
}

bool operator > (float lhs, Rational const& rhs) noexcept
{
    return { !(lhs < rhs.toDecimal()) };
}

Rational operator * (int lhs, Rational const& rhs) noexcept
{
    int numerator = rhs.getNumerator() * lhs;
    return { numerator, rhs.getDenominator()};
}

Rational operator / (int lhs, Rational const& rhs) noexcept
{
    int numerator = lhs * rhs.getDenominator();
    return { numerator, rhs.getNumerator() };
}

std::ostream& operator << (std::ostream& stream, const Rational& rational)
{
    stream << rational.getNumerator() << "/" << rational.getDenominator(); 
    return stream;
}

void Rational::reduce()
{
    int gcd = findGCD(m_numerator, m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
}