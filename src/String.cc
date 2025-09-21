/**
 * @file String.cc
 * @brief Implementación de la clase String
 * @author [Tu nombre]
 * @date 21 de septiembre de 2025
 */

#include "String.h"

#include <algorithm>
#include <cstddef>

#include "Language.h"

/**
 * @brief Constructor que inicializa la cadena con contenido y alfabeto
 * específicos
 * @param content Contenido de la cadena como std::string
 * @param alphabet Alfabeto sobre el cual está definida la cadena
 */
String::String(const std::string& content, const Alphabet& alphabet)
    : content_(content), alphabet_(alphabet) {}

/**
 * @brief Obtiene el contenido de la cadena
 * @return std::string Contenido de la cadena
 */
std::string String::GetContent() const { return content_; }

/**
 * @brief Obtiene el alfabeto sobre el cual está definida la cadena
 * @return Alphabet Alfabeto de la cadena
 */
Alphabet String::GetAlphabet() const { return alphabet_; }

/**
 * @brief Calcula la longitud de la cadena
 * @return size_t Número de símbolos en la cadena
 */
size_t String::Length() const { return content_.size(); }

/**
 * @brief Verifica si la cadena es válida respecto a su alfabeto
 * Comprueba que todos los caracteres de la cadena estén en el alfabeto
 * @return true si todos los caracteres de la cadena están en el alfabeto
 */
bool String::IsValid() const {
  for (char c : content_) {
    if (!alphabet_.Contains(c)) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Verifica si la cadena está vacía
 * @return true si la cadena no contiene símbolos
 */
bool String::IsEmpty() const { return content_.empty(); }

/**
 * @brief Genera la cadena inversa (reversa)
 * Crea una nueva cadena con los símbolos en orden inverso
 * @return String Nueva cadena con los símbolos en orden inverso
 */
String String::Reverse() const {
  return String(std::string(content_.rbegin(), content_.rend()), alphabet_);
}

/**
 * @brief Genera el lenguaje de todos los prefijos de la cadena
 * Un prefijo es una subcadena que comienza desde el inicio
 * @return Language Lenguaje que contiene todos los prefijos
 */
Language String::Prefixes() const {
  Language prefixes_lang;

  // Añadir la cadena vacía como prefijo
  String empty_string("", alphabet_);
  prefixes_lang.AddString(empty_string);

  // Añadir todos los prefijos de la cadena
  for (size_t i = 1; i <= content_.length(); ++i) {
    String prefix(content_.substr(0, i), alphabet_);
    prefixes_lang.AddString(prefix);
  }

  return prefixes_lang;
}

/**
 * @brief Genera el lenguaje de todos los sufijos de la cadena
 * Un sufijo es una subcadena que termina al final
 * @return Language Lenguaje que contiene todos los sufijos
 */
Language String::Suffixes() const {
  Language suffixes_lang;

  // Añadir la cadena vacía como sufijo
  String empty_string("", alphabet_);

  suffixes_lang.AddString(empty_string);

  // Añadir todos los sufijos de la cadena
  for (size_t i = 1; i <= content_.length(); ++i) {
    String suffix(content_.substr(content_.length() - i), alphabet_);
    suffixes_lang.AddString(suffix);
  }

  return suffixes_lang;
}

/**
 * @brief Operador de igualdad para comparar dos cadenas
 * Compara únicamente el contenido de las cadenas, no sus alfabetos
 * @param other Cadena a comparar
 * @return true si las cadenas tienen el mismo contenido, false en caso
 * contrario
 */
bool String::operator==(const String& other) const {
  return content_ == other.content_;
}

/**
 * @brief Operador de comparación lexicográfica
 * Utiliza el orden lexicográfico estándar de std::string
 * @param other Cadena a comparar
 * @return true si esta cadena es lexicográficamente menor que other
 */
bool String::operator<(const String& other) const {
  return content_ < other.content_;
}

/**
 * @brief Operador de salida para imprimir la cadena
 * Imprime únicamente el contenido de la cadena, o & si está vacía
 * @param os Flujo de salida
 * @param str Cadena a imprimir
 * @return std::ostream& Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream& os, const String& str) {
  if (str.content_.empty()) {
    os << "&";
  } else {
    os << str.content_;
  }
  return os;
}

/**
 * @brief Operador de entrada para leer una cadena desde un flujo
 * Lee el contenido de la cadena, pero no modifica el alfabeto
 * @param is Flujo de entrada
 * @param str Cadena donde almacenar el contenido leído
 * @return std::istream& Referencia al flujo de entrada
 */
std::istream& operator>>(std::istream& is, String& str) {
  is >> str.content_;
  return is;
}
