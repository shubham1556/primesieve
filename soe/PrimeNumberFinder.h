//
// Copyright (c) 2011 Kim Walisch, <kim.walisch@gmail.com>.
// All rights reserved.
//
// This file is part of primesieve.
// Visit: http://primesieve.googlecode.com
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above
//     copyright notice, this list of conditions and the following
//     disclaimer in the documentation and/or other materials provided
//     with the distribution.
//   * Neither the name of the author nor the names of its
//     contributors may be used to endorse or promote products derived
//     from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef PRIMENUMBERFINDER_H
#define PRIMENUMBERFINDER_H

#include "SieveOfEratosthenes.h"
#include "defs.h"

class PrimeSieve;

/**
 * PrimeNumberFinder is a SieveOfEratosthenes class that is used to
 * count, print and generate the prime numbers and prime k-tuplets
 * (twin primes, prime triplets, ...) within the interval
 * [startNumber_, stopNumber_].
 * The prime numbers up to stopNumber_^0.5 needed for sieving are
 * provided by PrimeNumberGenerator.
 * @see PrimeNumberGenerator::generate(const uint8_t*, uint32_t)
 */
class PrimeNumberFinder: public SieveOfEratosthenes {
public:
  PrimeNumberFinder(PrimeSieve&);
  ~PrimeNumberFinder();
private:
  static const uint32_t nextBitValues_[30];
  /** Used to recognize the last bit value in kTupletBitValues_. */
  enum { END = 1 << 8 };
  /** Reference to the parent PrimeSieve object. */
  PrimeSieve& ps_;
  /**
   * Lookup tables that give the count of prime k-tuplets (twin
   * primes, prime triplets, ...) per byte.
   */
  uint32_t** kTupletByteCounts_;
  /**
   * Lookup table used to reconstruct prime k-tuplets from bitmasks
   * of the sieve array.
   */
  uint32_t** kTupletBitValues_;
  void initLookupTables();
  virtual void analyseSieve(const uint8_t*, uint32_t);
  void count(const uint8_t*, uint32_t);
  void generate(const uint8_t*, uint32_t);
  void callbackOOP(uint64_t);
  void printPrime(uint64_t) const;
};

#endif /* PRIMENUMBERFINDER_H */
