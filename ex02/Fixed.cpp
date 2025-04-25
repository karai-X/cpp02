#include "Fixed.hpp"

Fixed::Fixed() {
  _value = 0;
  //   std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
  //   std::cout << "Int constructor called" << std::endl;
  _value = value << _fractional_bits;
}

Fixed::Fixed(const float value) {
  //   std::cout << "Float constructor called" << std::endl;

  _value = roundf(value * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &other) {
  //   std::cout << "Copy constructor called" << std::endl;
  _value = other.getRawBits();
}

Fixed::~Fixed(void) {
  // std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Fixed &other) {
  os << other.toFloat();
  return os;
}

Fixed &Fixed::operator=(const Fixed &other) {
  //   std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->_value = other.getRawBits();
  }
  return *this;
}

bool Fixed::operator==(const Fixed &other) const {
  return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const {
  return (this->_value != other._value);
}

bool Fixed::operator<(const Fixed &other) const {
  return this->_value < other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
  return this->_value <= other._value;
}

bool Fixed::operator>(const Fixed &other) const {
  return this->_value > other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
  return this->_value >= other._value;
}

Fixed Fixed::operator+(const Fixed &other) const {
  int raw = this->_value + other._value;
  Fixed ret;
  ret.setRawBits(raw);
  return ret;
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed ret;
  ret.setRawBits(this->_value - other._value);
  return ret;
}

Fixed Fixed::operator*(const Fixed &other) const {
  int64_t raw = this->_value * other._value;
  raw = raw >> _fractional_bits;
  Fixed ret;
  ret.setRawBits((int)raw);
  return ret;
}

Fixed Fixed::operator/(const Fixed &other) const {
  int64_t numerator = (int64_t)this->_value << _fractional_bits;
  int64_t raw = numerator / (int64_t)other._value;
  Fixed ret;
  ret.setRawBits((int)raw);
  return ret;
}

Fixed &Fixed::operator++() {
  ++this->_value;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  ++_value;
  return temp;
}

Fixed &Fixed::operator--() {
  --this->_value;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  --_value;
  return temp;
}

int Fixed::getRawBits(void) const {
  //   std::cout << "getRawBits member function called" << std::endl;
  return _value;
}

void Fixed::setRawBits(int const raw) {

  //   std::cout << "setRawBits member function called" << std::endl;
  _value = raw;
}

float Fixed::toFloat(void) const {
  return (static_cast<float>(_value)) / (1 << _fractional_bits);
}

int Fixed::toInt(void) const { return _value >> _fractional_bits; }

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
  if (f1.getRawBits() <= f2.getRawBits())
    return f1;
  else
    return f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
  if (f1.getRawBits() <= f2.getRawBits())
    return f1;
  else
    return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
  if (f1.getRawBits() >= f2.getRawBits())
    return f1;
  else
    return f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
  if (f1.getRawBits() >= f2.getRawBits())
    return f1;
  else
    return f2;
}
