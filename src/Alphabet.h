/**
 * @file Alphabet.h
 * @brief Definición de la clase Alphabet para representar alfabetos finitos
 * @author Hector Luis Mariño Fernandez
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
// Archivo Alphabet.h: definición de la clase Alphabet.
// Contiene la clase Alphabet que representa un alfabeto finito
// para operaciones con cadenas y lenguajes formales
// Referencias:
// https://en.wikipedia.org/wiki/Alphabet_(formal_languages)
//
// Historial de revisiones
// 21/09/2025 - Creación (primera versión) del código

#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <set>

/**
 * @brief Clase que representa un alfabeto finito
 *
 * Un alfabeto es un conjunto finito de símbolos que se usan para formar
 * cadenas. Esta clase implementa las operaciones básicas sobre alfabetos
 * utilizadas en teoría de autómatas y lenguajes formales.
 */
class Alphabet {
 private:
  std::set<char> symbols_;  ///< Conjunto de símbolos que conforman el alfabeto

 public:
  // ==================== CONSTRUCTORES ====================

  /**
   * @brief Constructor por defecto que crea un alfabeto vacío
   */
  Alphabet() = default;

  /**
   * @brief Constructor que inicializa el alfabeto con un conjunto de símbolos
   * @param symbols Conjunto de símbolos para inicializar el alfabeto
   */
  Alphabet(const std::set<char>& symbols);

  // ==================== MÉTODOS DE ACCESO ====================

  /**
   * @brief Obtiene una copia del conjunto de símbolos del alfabeto
   * @return std::set<char> Conjunto de símbolos del alfabeto
   */
  std::set<char> GetSymbols() const;

  // ==================== MÉTODOS DE CONSULTA ====================

  /**
   * @brief Verifica si un símbolo pertenece al alfabeto
   * @param c Símbolo a verificar
   * @return true si el símbolo está en el alfabeto, false en caso contrario
   */
  bool Contains(char c) const;

  // ==================== SOBRECARGA DE OPERADORES ====================

  /**
   * @brief Operador de salida para imprimir el alfabeto
   * @param os Flujo de salida
   * @param alphabet Alfabeto a imprimir
   * @return std::ostream& Referencia al flujo de salida
   */
  friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

  /**
   * @brief Operador de entrada para leer un alfabeto desde un flujo
   * @param is Flujo de entrada
   * @param alphabet Alfabeto donde almacenar los símbolos leídos
   * @return std::istream& Referencia al flujo de entrada
   */
  friend std::istream& operator>>(std::istream& is, Alphabet& alphabet);
};

#endif
