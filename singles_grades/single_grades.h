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
 * Archivo single-grades.h: programa donde se declara la clase SingleGradesAnalyzer.
 * Contiene las definiciones de la clase SingleGradesAnalyzer con su respectivo contenedor
 * Historial de revisiones:
 *   10/09/2026 - Creación del código
 */ 

#pragma once

#include <iostream>
#include <map>
#include <string>

class SingleGradesAnalyzer {
 public:
  // Constructor por defecto
  SingleGradesAnalyzer();
  // Método para leer el fichero de alumnos
  bool ReadFromFile(const std::string& filename);
  // Setter
  void SetGrade(const std::string& alu, double grade);
  // Getter
  double GetGrade(const std::string& alu) const;
  // Mostrar las notas
  void DisplayGrades() const;
 private:
  std::map<std::string, double> student_grades_; 
};