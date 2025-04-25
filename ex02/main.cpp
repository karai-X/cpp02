#include "Fixed.h"
#include "Fixed.hpp"

int main(void) {
  {
    Fixed a(10.5f);
    Fixed b(21.0f);
    Fixed c = a + b;
    std::cout << a << " + " << b << " = " << c << std::endl;
    c = a - b;
    std::cout << a << " - " << b << " = " << c << std::endl;
    c = a * b;
    std::cout << a << " * " << b << " = " << c << std::endl;
    c = a / b;
    std::cout << a << " / " << b << " = " << c << std::endl;
  }
  {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
  }
}
