/**
 * @file Language.cc
 * @brief Implementación de la clase Language
 * @author [Tu nombre]
 * @date 21 de septiembre de 2025
 */

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Hector Luis Mariño Fernandez
// Correo: alu0100595604@ull.edu.es
// Fecha: 21/09/2025
// Archivo Language.cc: implementación de la clase Language.
// Contiene la implementación de métodos de la clase Language
// para manejo de lenguajes formales ordenados por longitud
// Referencias:
// https://en.wikipedia.org/wiki/Formal_language
//
// Historial de revisiones
// 21/09/2025 - Creación (primera versión) del código

#include "Language.h"

#include <algorithm>
#include <vector>

/**
 * @brief Añade una cadena al lenguaje
 * Utiliza std::set para garantizar que no haya duplicados
 * @param str Cadena a añadir al lenguaje
 */
void Language::AddString(const String& str) { strings_.insert(str); }

/**
 * @brief Obtiene una copia del conjunto de cadenas del lenguaje
 * @return std::set<String> Conjunto de cadenas que forman el lenguaje
 */
std::set<String> Language::GetStrings() const { return strings_; }

/**
 * @brief Operador de salida para imprimir el lenguaje
 * Imprime el lenguaje en formato de conjunto: {cadena1, cadena2, ...}
 * Las cadenas se ordenan por longitud (y lexicográficamente para misma
 * longitud)
 * @param os Flujo de salida
 * @param lang Lenguaje a imprimir
 * @return std::ostream& Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream& os, const Language& lang) {
  // Convertir el set a vector para poder ordenarlo por longitud
  std::vector<String> sorted_strings(lang.strings_.begin(),
                                     lang.strings_.end());

  // Ordenar por longitud primero, luego lexicográficamente
  std::sort(
      sorted_strings.begin(), sorted_strings.end(),
      [](const String& a, const String& b) {
        if (a.Length() != b.Length()) {
          return a.Length() < b.Length();  // Ordenar por longitud
        }
        return a <
               b;  // Si tienen la misma longitud, ordenar lexicográficamente
      });

  os << "{";
  bool first = true;
  for (const auto& str : sorted_strings) {
    if (!first) {
      os << ", ";
    }
    os << str;
    first = false;
  }
  os << "}";
  return os;
}

/**
 * @brief Operador de entrada para leer un lenguaje desde un flujo
 * Lee primero el número de cadenas, luego lee cada cadena individualmente
 * @param is Flujo de entrada
 * @param lang Lenguaje donde almacenar las cadenas leídas
 * @return std::istream& Referencia al flujo de entrada
 */
std::istream& operator>>(std::istream& is, Language& lang) {
  int n;
  is >> n;  // cantidad de cadenas
  for (int i = 0; i < n; ++i) {
    String s;
    is >> s;
    lang.AddString(s);
  }
  return is;
}
