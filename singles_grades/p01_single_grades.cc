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
 *   15/09/2026 - Revisión código (pulir)
 */

#include "single_grades.h"

#include <iostream>
#include <string>



void PrintUsage(const std::string& program_name) {
  std::cout << "Modo de empleo: " << program_name << " <fichero_entrada.txt>\n";
  std::cout << "Pruebe '" << program_name << " --help' para más información.\n";
}



int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::string parameter = argv[1];
    if (parameter == "--help" || parameter == "-h") {
      std::cout << "Uso: " << argv[0] << " <fichero_entrada.txt>\n";
      std::cout << "Procesa un fichero con identificadores de alumno y notas.\n";
      return 0;
    }
  }
  if (argc != 2) {
    PrintUsage(argv[0]);
    return 1;
  }
  std::string filename = argv[1];
  SingleGradesAnalyzer analyzer;
  // Lectura y procesamiento del archivo txt
  if (!analyzer.ReadFromFile(filename)) {
    std::cerr << "Error al procesar el archivo " << filename << std::endl;
    return 1;
  }
  char option;
  std::cout << "\n¿Desea insertar una nueva calificación individualmente? (s/n): ";
  while (std::cin >> option && (option == 's' || option == 'S')) {
    std::string alu;
    double grade;
    std::cout << "Introduzca alu y nota (ej. aluXXXXXXXXXX 8.5): ";
    if (std::cin >> alu >> grade) {
      analyzer.SetGrade(alu, grade);
      std::cout << "Calificación registrada correctamente.\n";
    }
    std::cout << "¿Desea insertar otra calificación? (s/n): ";
  }
  // Mostrar resultados
  std::cout << "---| LISTADO DE NOTAS MÁXIMAS |---" << std::endl;
  analyzer.DisplayGrades();
  return 0;
}