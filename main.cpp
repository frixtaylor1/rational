#include "Rational.hpp"

int main()
{
    // To do:
    //   
    //  Rational operator + (int lhs, Ratinal const& rhs) noexcept;
    //  Rational operator - (int lhs, Rational const& rhs) noexcept; 
    //  
    
    Rational a{ 62, 16 }, b{ 1,2 };
    
    /* Rational c{ 0, 2}; // Throw exception fail!!! */
 
    std::cout << std::boolalpha;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << ( a * b ).toDecimal() + 1 << std::endl;
    std::cout << ( a / b ) << std::endl;
    std::cout << ( a + b ) << std::endl;

    std::cout << ( a < b ) << std::endl;
    std::cout << ( a > b ) << std::endl;
    std::cout << ( Rational{ 1, 3 } == Rational{ 1, 3 } ) << std::endl;
    std::cout << ( 1.0f < Rational{ 1, 3 } ) << std::endl;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}