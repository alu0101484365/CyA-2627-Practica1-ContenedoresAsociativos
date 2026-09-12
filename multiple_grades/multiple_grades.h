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
 * Archivo multiple-grades.h: programa donde se declara la clase MultipleGradesAnalyzer.
 * Contiene las definiciones de la clase MultipleGradesAnalyzer con su respectivo contenedor
 * Historial de revisiones:
 *   11/09/2026 - Creación del código
 */

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

class MultipleGradesAnalyzer {
 public:
  // Constructor por defecto
  MultipleGradesAnalyzer();
  // Método para leer el fichero de alumnos
  bool ReadFromFile(const std::string& filename);
  // Setter
  void AddGrade(const std::string& alu, double grade);
  // Getter
  const std::vector<double>& GetGrades(const std::string& alu) const;
  // Mostrar las notas
  void DisplayGrades() const;
 private:
  std::map<std::string, std::vector<double>> student_grades_; 
};