/**
 * @file String.h
 * @brief Definición de la clase String para representar cadenas sobre un alfabeto
 * @author [Tu nombre]
 * @date 21 de septiembre de 2025
 */

#ifndef STRING_H
#define STRING_H

#include "Alphabet.h"
#include <string>
#include <vector>
#include <iostream>

class Language;  // forward declaration

/**
 * @brief Clase que representa una cadena (string) sobre un alfabeto específico
 * 
 * Una cadena es una secuencia finita de símbolos de un alfabeto. Esta clase
 * implementa las operaciones básicas sobre cadenas utilizadas en teoría de
 * autómatas y lenguajes formales, como obtener prefijos, sufijos, inversas, etc.
 */
class String {
 private:
  std::string content_;  ///< Contenido de la cadena como secuencia de caracteres
  Alphabet alphabet_;    ///< Alfabeto sobre el cual está definida la cadena

 public:
  // ==================== CONSTRUCTORES ====================
  
  /**
   * @brief Constructor por defecto que crea una cadena vacía
   */
  String() = default;
  
  /**
   * @brief Constructor que inicializa la cadena con contenido y alfabeto específicos
   * @param content Contenido de la cadena como std::string
   * @param alphabet Alfabeto sobre el cual está definida la cadena
   */
  String(const std::string& content, const Alphabet& alphabet);

  // ==================== MÉTODOS DE ACCESO ====================
  
  /**
   * @brief Obtiene el contenido de la cadena
   * @return std::string Contenido de la cadena
   */
  std::string GetContent() const;
  
  /**
   * @brief Obtiene el alfabeto sobre el cual está definida la cadena
   * @return Alphabet Alfabeto de la cadena
   */
  Alphabet GetAlphabet() const;

  // ==================== MÉTODOS DE ANÁLISIS ====================
  
  /**
   * @brief Calcula la longitud de la cadena
   * @return size_t Número de símbolos en la cadena
   */
  size_t Length() const;
  
  /**
   * @brief Verifica si la cadena es válida respecto a su alfabeto
   * @return true si todos los caracteres de la cadena están en el alfabeto
   */
  bool IsValid() const;
  
  /**
   * @brief Verifica si la cadena está vacía
   * @return true si la cadena no contiene símbolos
   */
  bool IsEmpty() const;
  
  /**
   * @brief Genera la cadena inversa (reversa)
   * @return String Nueva cadena con los símbolos en orden inverso
   */
  String Reverse() const;
  
  /**
   * @brief Genera el lenguaje de todos los prefijos de la cadena
   * @return Language Lenguaje que contiene todos los prefijos
   */
  Language Prefixes() const;
  
  /**
   * @brief Genera el lenguaje de todos los sufijos de la cadena
   * @return Language Lenguaje que contiene todos los sufijos
   */
  Language Suffixes() const;

  // ==================== SOBRECARGA DE OPERADORES ====================
  
  /**
   * @brief Operador de igualdad para comparar dos cadenas
   * @param other Cadena a comparar
   * @return true si las cadenas tienen el mismo contenido, false en caso contrario
   */
  bool operator==(const String& other) const;
  
  /**
   * @brief Operador de comparación lexicográfica
   * @param other Cadena a comparar
   * @return true si esta cadena es lexicográficamente menor que other
   */
  bool operator<(const String& other) const;

  /**
   * @brief Operador de salida para imprimir la cadena
   * @param os Flujo de salida
   * @param str Cadena a imprimir
   * @return std::ostream& Referencia al flujo de salida
   */
  friend std::ostream& operator<<(std::ostream& os, const String& str);
  
  /**
   * @brief Operador de entrada para leer una cadena desde un flujo
   * @param is Flujo de entrada
   * @param str Cadena donde almacenar el contenido leído
   * @return std::istream& Referencia al flujo de entrada
   */
  friend std::istream& operator>>(std::istream& is, String& str);
};

#endif
