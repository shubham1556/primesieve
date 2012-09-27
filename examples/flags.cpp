////////////////////////////////////////////////////////////////////
// flags.cpp
// Count prime numbers and twin primes using flags.

#include <primesieve/soe/PrimeSieve.h>
#include <stdint.h>
#include <iostream>

int main()
{
  PrimeSieve ps;
  int flags = ps.COUNT_PRIMES | ps.COUNT_TWINS | ps.PRINT_STATUS;
  uint64_t start = 0;
  uint64_t stop  = (uint64_t) 1E11;
  ps.sieve(start, stop, flags);
  std::cout << "Primes below 10^11: " << ps.getPrimeCount() << std::endl
            << "Twins  below 10^11: " << ps.getTwinCount()  << std::endl;
  return 0;
}