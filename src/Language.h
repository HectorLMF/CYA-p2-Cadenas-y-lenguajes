/**
 * @file Language.h
 * @brief Definición de la clase Language para representar lenguajes formales
 * @author [Tu nombre]
 * @date 21 de septiembre de 2025
 */

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "String.h"
#include <set>
#include <vector>
#include <iostream>
#include <cstddef>
#include <algorithm>

/**
 * @brief Clase que representa un lenguaje formal como conjunto de cadenas
 * 
 * Un lenguaje formal es un conjunto de cadenas (finito o infinito) sobre un
 * alfabeto dado. Esta clase implementa las operaciones básicas sobre lenguajes
 * utilizadas en teoría de autómatas y lenguajes formales.
 */
class Language {
 private:
  std::set<String> strings_;  ///< Conjunto de cadenas que forman el lenguaje

 public:
  // ==================== CONSTRUCTORES ====================
  
  /**
   * @brief Constructor por defecto que crea un lenguaje vacío
   */
  Language() = default;

  // ==================== MÉTODOS DE MODIFICACIÓN ====================
  
  /**
   * @brief Añade una cadena al lenguaje
   * @param str Cadena a añadir al lenguaje
   */
  void AddString(const String& str);
  
  // ==================== MÉTODOS DE ACCESO ====================
  
  /**
   * @brief Obtiene una copia del conjunto de cadenas del lenguaje
   * @return std::set<String> Conjunto de cadenas que forman el lenguaje
   */
  std::set<String> GetStrings() const;
  
  /**
   * @brief Obtiene las cadenas del lenguaje ordenadas por longitud
   * @return std::vector<String> Vector de cadenas ordenadas por longitud
   */
  std::vector<String> GetStringsByLength() const;

  // ==================== SOBRECARGA DE OPERADORES ====================
  
  /**
   * @brief Operador de salida para imprimir el lenguaje
   * @param os Flujo de salida
   * @param lang Lenguaje a imprimir
   * @return std::ostream& Referencia al flujo de salida
   */
  friend std::ostream& operator<<(std::ostream& os, const Language& lang);
  
  /**
   * @brief Operador de entrada para leer un lenguaje desde un flujo
   * @param is Flujo de entrada
   * @param lang Lenguaje donde almacenar las cadenas leídas
   * @return std::istream& Referencia al flujo de entrada
   */
  friend std::istream& operator>>(std::istream& is, Language& lang);
};

#endif
