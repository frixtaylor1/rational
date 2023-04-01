#pragma once
#include <iostream>

//
//  Great Common Divisor algorithm...
//
int findGCD(int a, int b);

class Rational
{
public:
    Rational() = default;
    
    Rational(int numerator, int denominator);
    Rational(const Rational& rhs);
    Rational(Rational const&& rhs);

    constexpr const double toDecimal() const noexcept
    {
        return { (double)m_numerator / m_denominator };
    }

    constexpr void operator = (const Rational& rhs ) noexcept;

    bool operator < (Rational const& rhs) const noexcept;
    bool operator > (Rational const& rhs) const noexcept;
    bool operator == (Rational const& rhs) const noexcept;
    bool operator != (Rational const& rhs) const noexcept;

    Rational operator + (Rational const& rhs) const noexcept;
    Rational operator - (Rational const& rhs) const noexcept;
    Rational operator * (Rational const& rhs) const noexcept;
    Rational operator / (Rational const& rhs) const noexcept;

    constexpr bool operator < (float rhs) const noexcept;
    constexpr bool operator > (float rhs) const noexcept;


    const int& getNumerator() const
    {
        return m_numerator;
    }

    const int& getDenominator() const
    {
        return m_denominator;
    }

private:
    void reduce();

    int m_numerator, m_denominator;
};
/* 
Rational operator + (int lhs, Ratinal const& rhs) noexcept;
Rational operator - (int lhs, Rational const& rhs) noexcept; 
*/
Rational operator * (int lhs, Rational const& rhs) noexcept;
Rational operator / (int lhs, Rational const& rhs) noexcept;

bool operator < (float lhs, Rational const& rhs) noexcept;
bool operator > (float lhs, Rational const& rhs) noexcept;

std::ostream& operator << (std::ostream& stream, const Rational& rational);
