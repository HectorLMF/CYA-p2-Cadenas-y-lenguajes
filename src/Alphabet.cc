/**
 * @file Alphabet.cc
 * @brief Implementación de la clase Alphabet
 * @author [Tu nombre]
 * @date 21 de septiembre de 2025
 */

#include "Alphabet.h"

/**
 * @brief Constructor que inicializa el alfabeto con un conjunto de símbolos
 * @param symbols Conjunto de caracteres que formarán el alfabeto
 */
Alphabet::Alphabet(const std::set<char>& symbols) : symbols_(symbols) {}

/**
 * @brief Obtiene una copia del conjunto de símbolos del alfabeto
 * @return std::set<char> Conjunto de símbolos del alfabeto
 */
std::set<char> Alphabet::GetSymbols() const {
  return symbols_;
}

/**
 * @brief Verifica si un carácter pertenece al alfabeto
 * @param c Carácter a verificar
 * @return true si el carácter está en el alfabeto, false en caso contrario
 */
bool Alphabet::Contains(char c) const {
  return symbols_.find(c) != symbols_.end();
}

/**
 * @brief Operador de salida para imprimir el alfabeto
 * Imprime todos los símbolos del alfabeto en formato {a, b, c}
 * @param os Flujo de salida
 * @param alphabet Alfabeto a imprimir
 * @return std::ostream& Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "{";
  bool first = true;
  for (char c : alphabet.symbols_) {
    if (!first) {
      os << ", ";
    }
    os << c;
    first = false;
  }
  os << "}";
  return os;
}

/**
 * @brief Operador de entrada para leer un alfabeto desde un flujo
 * Lee una línea completa y añade cada carácter único al alfabeto
 * Ignora espacios, comas y caracteres de puntuación comunes
 * @param is Flujo de entrada
 * @param alphabet Alfabeto donde almacenar los símbolos leídos
 * @return std::istream& Referencia al flujo de entrada
 */
std::istream& operator>>(std::istream& is, Alphabet& alphabet) {
  std::string input;
  std::getline(is, input);
  
  alphabet.symbols_.clear();
  
  // Parsear la entrada (asumiendo formato: a b c o abc o {a,b,c})
  for (char c : input) {
    if (std::isalnum(c) || (std::ispunct(c) && c != '{' && c != '}' && c != ',' && c != ' ')) {
      alphabet.symbols_.insert(c);
    }
  }
  
  return is;
}
