//	Copyright 2023 Kevin Daniel Taylor (frixtaylor1)
//	Contact: kevinmusic123@gmail.com
//	for more information about the license, see the end of the file.

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

// MIT License
// 
// Copyright (c) 2023 Kevin Daniel Taylor (frixtaylor1)
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