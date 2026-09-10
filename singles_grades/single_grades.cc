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
 * Archivo single-grades.cc: programa donde se definen los métodos la clase SingleGradesAnalyzer.
 * Contiene las definiciones de los métodos la clase SingleGradesAnalyzer con su respectivo contenedor
 * Historial de revisiones:
 *   10/09/2026 - Creación del código
 */ 

#include "single_grades.h"

#include <fstream>

/**
 * @brief Constructor por defecto
 */
SingleGradesAnalyzer::SingleGradesAnalyzer() {}

/**
 * @brief Método encargado de insertar o actualizar la nota de un alumno
 * @param alu: identificador del alumno
 * @param grade: nota del alumno
 */
void SingleGradesAnalyzer::SetGrade(const std::string& alu, double grade) {
  // Iterador del mapa
  auto it = student_grades_.find(alu); // std::map<std::string, double>::iterator it = student_grades_.find(alu);
  if (it == student_grades_.end()) {
    // No existe, ya que it apunta al marcador de fin del mapa (end())
    student_grades_[alu] = grade;
  } else {
    // Como existe, actualizamos solo si la nueva nota es mayor
    if (grade > it->second) {
      it->second = grade;
    }
  }
}

/**
 * @brief Método encargado de obtener la nota de un alumno
 * @param alu: identificador del alumno
 * @return nota del alumno
 */
double SingleGradesAnalyzer::GetGrade(const std::string& alu) const {
  auto it = student_grades_.find(alu); // std::map<std::string, double>::iterator it = student_grades_.find(alu);
  if (it == student_grades_.end()) {
    // No existe, ya que it apunta al marcador de fin del mapa (end())
    std::cerr << "El alumno no existe..." << std::endl;
    return -1.0;
  } else {
    // Como existe, devolvemos la nota
    return it->second;
  }
}

/**
 * @brief Método encargado de mostrar todas las notas de los alumnos
 */
void SingleGradesAnalyzer::DisplayGrades() const {
  for (const auto& student : student_grades_) {
    std::cout << student.first << ": " << student.second << std::endl;
  }
}

#include <fstream>
#include <iostream>
#include "single_grades.h"

/**
 * @brief Método encargado de leer el fichero de alumnos y procesar sus notas
 * @param filename: nombre o ruta del fichero de texto
 * @return true si se procesó correctamente, false en caso de error
 */
bool SingleGradesAnalyzer::ReadFromFile(const std::string& filename) {
  // Abrimos el fichero en modo lectura
  std::ifstream file(filename);
  // Comprobamos si el fichero no se pudo abrir
  if (!file.is_open()) {
    std::cerr << "Error: No se pudo abrir el fichero " << filename << std::endl;
    return false;
  }
  std::string alu;
  double grade;
  // Leemos mientras sigan existiendo pares (alu, nota) en el archivo
  while (file >> alu >> grade) {
    SetGrade(alu, grade);  // Usamos la lógica de guardar solo la nota más alta
  }
  // Cerramos el fichero y devolvemos éxito
  file.close();
  return true;
}