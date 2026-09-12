/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 1: Contenedores asociativos
 * Autor: Raúl Navarro Cobos
 * Correo: alu0101484365@ull.edu.es
 * Fecha: 11/09/2026
 * Archivo multiple-grades.cc: programa donde se definen los métodos la clase MultipleGradesAnalyzer.
 * Contiene las definiciones de los métodos la clase MultipleGradesAnalyzer con su respectivo contenedor
 * Historial de revisiones:
 *   11/09/2026 - Creación del código
 */

#include "multiple_grades.h"

#include <fstream>

/**
 * @brief Constructor por defecto
 */
MultipleGradesAnalyzer::MultipleGradesAnalyzer() {}

/**
 * @brief Método encargado de añadir una nueva nota a un alumno
 * @param alu: identificador del alumno
 * @param grade: nota a añadir
 */
void MultipleGradesAnalyzer::AddGrade(const std::string& alu, double grade) {
  student_grades_[alu].push_back(grade);
}

/**
 * @brief Método encargado de obtener todas las notas de un alumno
 * @param alu: identificador del alumno
 * @return referencia al vector con sus notas (o un vector vacío si no existe)
 */
const std::vector<double>& MultipleGradesAnalyzer::GetGrades(const std::string& alu) const {
  static const std::vector<double> emptyVector{}; // Vector vacío para devolver si no existe
  auto it = student_grades_.find(alu);
  if (it == student_grades_.end()) {
    std::cerr << "El alumno " << alu << " no existe." << std::endl;
    return emptyVector;
  }
  return it->second; // Devolvemos directamente la referencia al vector de notas que está dentro del mapa
}


/**
 * @brief Método encargado de mostrar todas las notas de los alumnos
 */
void MultipleGradesAnalyzer::DisplayGrades() const {
  for (const auto& student : student_grades_) {
    std::cout << student.first << ": ";
      for (const auto& grade : student.second) {
        std::cout << " " << grade;
      }
    std::cout << std::endl;
  }
}

/**
 * @brief Método encargado de leer el fichero de alumnos y procesar sus notas
 * @param filename: nombre o ruta del fichero de texto
 * @return true si se procesó correctamente, false en caso de error
 */
bool MultipleGradesAnalyzer::ReadFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: No se pudo abrir el fichero " << filename << std::endl;
    return false;
  }
  std::string alu;
  double grade;
  while (file >> alu >> grade) {
    AddGrade(alu, grade);  // Llamamos a AddGrade para añadir cada nota al vector
  }
  file.close();
  return true;
}
