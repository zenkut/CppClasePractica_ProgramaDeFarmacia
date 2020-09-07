#ifndef __ENTIDADES_FARMACEUTICO_HPP__
#define __ENTIDADES_FARMACEUTICO_HPP__

#include "Tipos.hpp"
#include "Sexo.hpp"

namespace Farmacia::Entidades 
{
  class Farmaceutico
  {
    public:
      codigo_t        Codigo;
      short_string_t  Identificacion;
      short_string_t  Nombre;
      short_string_t  Apellido;
      short_string_t  Ocupacion;
      Sexo            Sexo;
      long_string_t   Direccion;
      short_string_t  Telefono;
  };
}

#endif //!__ENTIDADES_FARMACEUTICO_HPP__