#ifndef __CLIENTE_HPP__
#define __CLIENTE_HPP__

#include "Tipos.hpp"
#include "Sexo.hpp"

namespace Farmacia::Entidades 
{
  class Cliente
  {
    public:
      codigo_t        Codigo;
      short_string_t  Identificacion;
      short_string_t  Nombre;
      short_string_t  Apellido;
      Sexo            Sexo;
      long_string_t   Direccion;
      short_string_t  Telefono;
  };
}

#endif //!__CLIENTE_HPP__