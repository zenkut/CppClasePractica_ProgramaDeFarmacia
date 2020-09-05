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
  src/Entidades/Sexo.cpp
  include/Entidades/TipoMedicamento.hpp
  src/Entidades/TipoMedicamento.cpp
  include/Repositorios/MedicamentoRepositorio.hpp)
