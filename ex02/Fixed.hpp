#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <string>

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
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator>(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
  static Fixed &min(Fixed &f1, Fixed &f2);
  static const Fixed &min(Fixed const &f1, Fixed const &f2);
  static Fixed &max(Fixed &f1, Fixed &f2);
  static const Fixed &max(Fixed const &f1, Fixed const &f2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &other);

#endif
