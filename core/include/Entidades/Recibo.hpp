#ifndef __ENTIDADES_RECIBO_HPP__
#define __ENTIDADES_RECIBO_HPP__

#include "Tipos.hpp"
#include "Medicamento.hpp"

namespace Farmacia::Entidades 
{
  class Recibo
  {
    public:
      short_string_t NumeroRecibo;
      short_string_t NombreCliente;
      // vector<Medicamento>   Medicamentos;
      double long    PrecioTotal;
  };
}

#endif //!__ENTIDADES_RECIBO_HPP__