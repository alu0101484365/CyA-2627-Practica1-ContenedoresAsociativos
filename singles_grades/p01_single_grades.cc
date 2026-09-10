/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 1: Contenedores asociativos
 * Autor: Raúl Navarro Cobos
 * Correo: alu0101484365@ull.edu.es
 * Fecha: 10/09/2026
 * Archivo p01_single_grades.cc: Programa cliente.
 * Contiene la función main para ejecutar el análisis de calificaciones únicas.
 * Historial de revisiones:
 *   10/09/2026 - Creación del código
 */

#include "single_grades.h"

#include <iostream>
#include <string>

// Función auxiliar para mostrar la ayuda del programa
void Usage(int argc, char* argv[]) {
  if (argc == 2) {
    std::string parameter = argv[1];
    if (parameter == "--help" || parameter == "-h") {
      std::cout << "Uso: " << argv[0] << " <fichero_entrada.txt>\n";
      std::cout << "Procesa un fichero con identificadores de alumno y notas, almacenando únicamente la calificación más alta de cada estudiante.\n";
      exit(EXIT_SUCCESS);
    }
  }
  if (argc != 2) {
    std::cout << "Error en los argumentos. Pruebe '" << argv[0] << " --help' para más información.\n";
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char* argv[]) {
  //Verificación de argumentos
  Usage(argc, argv);
  std::string filename = argv[1];
  SingleGradesAnalyzer analyzer;
  // Lectura y procesamiento del archivo txt
  if (!analyzer.ReadFromFile(filename)) {
    std::cerr << "Error al procesar el archivo " << filename << std::endl;
    return 1;
  }
  // Mostrar resultados
  std::cout << "---| LISTADO DE NOTAS MÁXIMAS |---" << std::endl;
  analyzer.DisplayGrades();
  return 0;
}