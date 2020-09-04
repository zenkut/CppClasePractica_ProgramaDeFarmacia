#ifndef __MEDICAMENTO_HPP__
#define __MEDICAMENTO_HPP__

#include "Tipos.hpp"
#include "TipoMedicamento.hpp"

namespace Farmacia::Entidades 
{
  class Medicamento
  {
  public:
    short_string_t  Codigo;
    short_string_t  Nombre;
    long double     Precio;
    size_t          Stock;
    TipoMedicamento Tipo;
  };
}

#endif // !__MEDICAMENTO_HPP__