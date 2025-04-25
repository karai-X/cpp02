#include "Fixed.hpp"

Fixed::Fixed() {
  _value = 0;
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  _value = value << _fractional_bits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;

  _value = roundf(value * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  _value = other.getRawBits();
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

std::ostream &operator<<(std::ostream& os, const Fixed &other) {
	os << other.toFloat();
	return os;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->_value = other.getRawBits();
  }
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _value;
}

void Fixed::setRawBits(int const raw) {

  std::cout << "setRawBits member function called" << std::endl;
  _value = raw;
}

float Fixed::toFloat(void) const {
  return (static_cast<float>(_value)) / (1 << _fractional_bits);
}

int Fixed::toInt(void) const { return _value >> _fractional_bits; }

