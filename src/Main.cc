/**
 * @file Main.cc
 * @brief Programa principal para operaciones con cadenas y lenguajes
 * @author Hector Luis Mariño Fernandez
 * @date 21 de septiembre de 2025
 *
 * Este programa lee cadenas y sus alfabetos desde un archivo de entrada
 * y permite realizar diversas operaciones sobre ellas como obtener alfabetos,
 * longitudes, inversas, prefijos y sufijos.
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
// Archivo Main.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases Alphabet,
// String y Language para realizar operaciones sobre cadenas y lenguajes
// Referencias:
// https://google.github.io/styleguide/cppguide.html
//
// Historial de revisiones
// 21/09/2025 - Creación (primera versión) del código

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Alphabet.h"
#include "Language.h"
#include "String.h"

/**
 * @brief Lee los datos de entrada desde un archivo
 * @param filename Nombre del archivo de entrada
 * @return std::vector<String> Vector de cadenas leídas con sus alfabetos
 * @throws std::runtime_error si no se puede abrir el archivo
 *
 * Formato esperado del archivo:
 * Cada línea: cadena alfabeto
 * Ejemplo:
 * abbab ab
 * 6793836 123456789
 * hola ahlo
 */
std::vector<String> ReadInputFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("No se pudo abrir el archivo: " + filename);
  }

  std::vector<String> strings;
  std::string line;

  // Leer cada línea del archivo
  while (std::getline(file, line)) {
    if (line.empty()) continue;  // Saltar líneas vacías

    std::istringstream iss(line);
    std::string cadena_str, alfabeto_str;

    // Leer cadena y alfabeto de la línea
    if (iss >> cadena_str >> alfabeto_str) {
      // Crear alfabeto a partir de la cadena de símbolos
      std::set<char> symbols;
      for (char c : alfabeto_str) {
        symbols.insert(c);
      }
      Alphabet alphabet(symbols);

      // Crear la cadena con su alfabeto
      String str(cadena_str, alphabet);

      // Verificar que la cadena sea válida
      if (!str.IsValid()) {
        std::cerr << "Advertencia: La cadena '" << cadena_str
                  << "' contiene símbolos no presentes en el alfabeto '"
                  << alfabeto_str << "'" << std::endl;
      }

      strings.push_back(str);
    } else {
      std::cerr << "Advertencia: Línea con formato incorrecto: " << line
                << std::endl;
    }
  }

  file.close();
  return strings;
}

/**
 * @brief Muestra el modo de uso correcto del programa
 * @param program_name Nombre del programa (argv[0])
 */
void Usage(const std::string& program_name) {
  std::cout << "Usage: " << program_name << " input.txt output.txt opcode\n";
  std::cout << "Opcodes:\n";
  std::cout << " 1: alfabeto\n";
  std::cout << " 2: longitud\n";
  std::cout << " 3: inversa\n";
  std::cout << " 4: prefijos\n";
  std::cout << " 5: sufijos\n";
}

/**
 * @brief Función principal del programa
 * @param argc Número de argumentos de línea de comandos
 * @param argv Array de argumentos de línea de comandos
 * @return int Código de salida (0 si éxito, 1 si error)
 */
int main(int argc, char* argv[]) {
  // Verificar número correcto de argumentos
  if (argc != 4) {
    Usage(argv[0]);
    return 1;
  }

  std::string input_filename = argv[1];
  std::string output_filename = argv[2];
  int opcode = std::stoi(argv[3]);  // Código de operación a realizar

  try {
    // Leer datos del archivo de entrada
    std::vector<String> strings = ReadInputFile(input_filename);

    // Abrir archivo de salida
    std::ofstream output(output_filename);
    if (!output.is_open()) {
      std::cerr << "Error: No se pudo abrir el archivo de salida: "
                << output_filename << std::endl;
      return 1;
    }

    // Mostrar información de las cadenas leídas
    std::cout << "Número de cadenas leídas: " << strings.size() << std::endl;

    // Procesar cada cadena según el código de operación
    for (size_t i = 0; i < strings.size(); ++i) {
      const String& str = strings[i];

      switch (opcode) {
        case 1:
          // Mostrar alfabeto de la cadena
          output << (i + 1) << " " << str.GetAlphabet() << std::endl;
          break;
        case 2:
          // Mostrar longitud de la cadena
          output << (i + 1) << " " << str.Length() << std::endl;
          break;
        case 3:
          // Mostrar cadena inversa
          output << (i + 1) << " " << str.Reverse() << std::endl;
          break;
        case 4:
          // Mostrar prefijos de la cadena
          output << (i + 1) << " " << str.Prefixes() << std::endl;
          break;
        case 5:
          // Mostrar sufijos de la cadena
          output << (i + 1) << " " << str.Suffixes() << std::endl;
          break;
        default:
          // Código de operación inválido
          Usage(argv[0]);
          return 1;
      }
    }

    output.close();
    std::cout << "Procesamiento completado. Resultados guardados en: "
              << output_filename << std::endl;

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
