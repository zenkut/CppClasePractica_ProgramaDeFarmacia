#ifndef __RECIBO_HPP__
#define __RECIBO_HPP__

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

#endif //!__RECIBO_HPP__