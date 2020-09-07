#ifndef __ENTIDADES_RECETA_HPP__
#define __ENTIDADES_RECETA_HPP__

#include "Tipos.hpp"
#include "TipoMedicamento.hpp"

namespace Farmacia::Entidades 
{
  class Receta
  {
    public:
      short_string_t  NombreCliente;
      TipoMedicamento TipoMedicamento;
      long_string_t   Descripcion;
      short_string_t  Fecha;
  };
}

#endif //!__ENTIDADES_RECETA_HPP__