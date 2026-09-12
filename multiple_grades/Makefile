# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Práctica 1: Contenedores asociativos
# Autor: Raúl Navarro Cobos
# Correo: alu0101484365@ull.edu.es

# Variables de compilación
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g

# Archivos del proyecto
TARGET = p01_multiple_grades
OBJS = p01_multiple_grades.o multiple_grades.o

# Regla principal
all: $(TARGET)

# Regla de enlazado del ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Reglas de compilación de módulos individuales
p01_multiple_grades.o: p01_multiple_grades.cc multiple_grades.h
	$(CXX) $(CXXFLAGS) -c p01_multiple_grades.cc

multiple_grades.o: multiple_grades.cc multiple_grades.h
	$(CXX) $(CXXFLAGS) -c multiple_grades.cc

# Regla de limpieza (obligatoria)
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) *~