#include "Rational.hpp"
#include <assert.h>
int main()
{
    // To do:
    //   
    //  Rational operator + (int lhs, Ratinal const& rhs) noexcept;
    //  Rational operator - (int lhs, Rational const& rhs) noexcept; 
    //  
    
    Rational a{ 62, 16 }, b{ 1,2 }, c{ 1, 3};
    
    /* Rational d{ 2, 0}; // Throw exception!!! */
 
    std::cout << std::boolalpha;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << ( a * b ).toDecimal() + 1 << std::endl;
    
    assert(b.toDecimal() == 0.5f);
    assert(c.toDecimal() == 0.33333333f);

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