#ifndef ALPHABET_H
#define ALPHABET_H

#include <set>
#include <iostream>

class Alphabet {
 private:
  std::set<char> symbols_;

 public:
  // Constructores
  Alphabet() = default;
  Alphabet(const std::set<char>& symbols);

  // Getters
  std::set<char> GetSymbols() const;

  // Métodos
  bool Contains(char c) const;

  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);
  friend std::istream& operator>>(std::istream& is, Alphabet& alphabet);
};

#endif
