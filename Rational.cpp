//	Copyright 2023 Kevin Daniel Taylor (frixtaylor1)
//	Contact: kevinmusic123@gmail.com
//	for more information about the license, see the end of the file.

#include "Rational.hpp"
#include <assert.h>

int findGCD(int a, int b)
{
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

Rational::Rational(int numerator, int denominator) noexcept
    : m_numerator(numerator), m_denominator(denominator)
{
    assert( m_denominator != 0 );
    if(m_numerator == 0) m_denominator = 1;
    reduce();
}

Rational::Rational(const Rational& rhs) noexcept
    : m_numerator(rhs.m_numerator), m_denominator(rhs.m_denominator)
{
    reduce();
}

Rational::Rational(Rational const&& rhs) noexcept
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
{   // the following is the same as return !(operator < (rhs));
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

// MIT License
// 
// Copyright (c) 2023 Kevin Daniel Taylor frixtaylor1
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.