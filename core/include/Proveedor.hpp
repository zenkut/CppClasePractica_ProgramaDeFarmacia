#ifndef __PROVEEDOR_HPP__
#define __PROVEEDOR_HPP__
#include "Tipos.hpp"

namespace Farmacia::Entidades 
{
  class Proveedor
  {
  public:
    codigo_t       Codigo;
    short_string_t Nombre;
    short_string_t Ciudad;
    long_string_t  Direccion;
    short_string_t Telefono;
  };
}

#endif //!____PROVEEDOR_HPP