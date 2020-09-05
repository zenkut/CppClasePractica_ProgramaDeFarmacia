#include "../../include/Entidades/TipoMedicamento.hpp"

namespace Farmacia::Entidades 
{
  [[nodiscard]] std::string_view to_string(TipoMedicamento tipo_medicamento) noexcept
  {
    switch(tipo_medicamento)
    {
      [[likely]] case TipoMedicamento::Analgesico: 
        return "Analgesico";

      case TipoMedicamento::AntiacidoyAntiulceroso:
        return "Antiacido y Antiulceroso";

      case TipoMedicamento::Antialergico:
        return "Antialergico";
      
      case TipoMedicamento::Antiinflamatorio:
        return "Antiinflamatorio";

      case TipoMedicamento::AntidiarreicoyLaxante:
        return "Antidiarreico y Laxante";
      
      case TipoMedicamento::AntitusivoyMucolitico:
        return "Antitusivo y Mucolitico";
      
      [[unlikely]] case TipoMedicamento::Antipiretico:
        return "Antipiretico";

      default:
        return "General";
    }
  }
}

