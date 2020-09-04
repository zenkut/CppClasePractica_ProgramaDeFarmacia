#include "../include/TipoMedicamento.hpp"

namespace Farmacia::Entidades 
{
  [[nodiscard]] std::string_view to_string(TipoMedicamento tipo_medicamento) noexcept
  {
    switch(tipo_medicamento)
    {
      [[likely]] case TipoMedicamento::Analgesico: 
        return "Analgesicos";

      [[likely]] case TipoMedicamento::Vitamina: 
        return "Vitamina";

      [[unlikely]] case TipoMedicamento::Antibiotico:
        return "Antibiotico";

      default:
        return "General";
    }
  }
}

