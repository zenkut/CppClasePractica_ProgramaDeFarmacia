cmake_minimum_required (VERSION 3.16)

project (FarmaciaSA)

add_executable (FarmaciaSA
  main.cpp
  include/Cliente.hpp
  include/Medicamento.hpp
  include/Proveedor.hpp
  include/Sexo.hpp
  include/Receta.hpp
  include/Recibo.hpp
  include/Farmaceutico.hpp
  src/Sexo.cpp
  include/TipoMedicamento.hpp
  src/TipoMedicamento.cpp)
