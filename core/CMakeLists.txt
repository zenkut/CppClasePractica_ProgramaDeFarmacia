cmake_minimum_required (VERSION 3.16)

project (FarmaciaSA)

add_executable (FarmaciaSA
  main.cpp
  include/Entidades/Cliente.hpp
  include/Entidades/Medicamento.hpp
  include/Entidades/Proveedor.hpp
  include/Entidades/Sexo.hpp
  include/Entidades/Receta.hpp
  include/Entidades/Recibo.hpp
  include/Entidades/Farmaceutico.hpp
  include/Entidades/TipoMedicamento.hpp
  src/Entidades/Sexo.cpp
  src/Entidades/TipoMedicamento.cpp
  include/Repositorios/Medicamento.hpp
  include/Repositorios/Repositorio.hpp
  include/Iteradores/Iterador.hpp
  include/Iteradores/Medicamento.hpp)

