#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
private:
  int _value;
  static const int _fractional_bits = 8;

public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed &other);
  ~Fixed();
  Fixed &operator=(const Fixed &other);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
  std::string getFixed(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &other);

#endif
