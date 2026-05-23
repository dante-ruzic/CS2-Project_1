#ifndef bigint_HPP
#define bigint_HPP

#include <iostream>

const int CAPACITY = 400;

class bigint {
public:

  void initialize();

  bigint();
  
  bigint(int);
  
  bigint(const char[]);
  
  void debugPrint(std::ostream&) const;
  
  friend std::ostream& operator<<(std::ostream&, const bigint&);
  
 
  bool operator==(const bigint&);
  
  
  friend std::istream& operator>>(std::istream&, bigint&);
  
  
  bigint operator+(bigint) const;
  
  bigint timesDigit(int) const;
  
  bigint times10(int) const;
  
  bigint operator*(bigint) const;
  
  int operator[](int) const;
  
  bigint factorial(int x);

private:
  int numArray[CAPACITY];
};
#endif