#pragma once
#include <iostream>

//
//  Great Common Divisor algorithm...
//
int findGCD(int a, int b);

class Rational
{
public:
    Rational() noexcept = default;
    
    Rational(int numerator, int denominator) noexcept;
    Rational(const Rational& rhs) noexcept;
    Rational(Rational const&& rhs) noexcept;

    constexpr const float toDecimal() const noexcept
    {
        return { (float)m_numerator / m_denominator };
    }

    constexpr void operator = (const Rational& rhs) noexcept;

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

    inline const int& getNumerator() const noexcept
    {
        return m_numerator;
    }

    inline const int& getDenominator() const noexcept
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