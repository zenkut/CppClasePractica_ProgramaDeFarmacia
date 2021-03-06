#ifndef __ENTIDADES_TIPO_MEDICAMENTO_HPP__
#define __ENTIDADES_TIPO_MEDICAMENTO_HPP__

#include <string_view>

namespace Farmacia::Entidades 
{
  enum class [[nodiscard]] TipoMedicamento
  {
    Analgesico,
    AntiacidoyAntiulceroso, 
    Antialergico,
    AntidiarreicoyLaxante,
    Antiinflamatorio,
    Antipiretico,
    AntitusivoyMucolitico
  };

  [[nodiscard]] std::string_view to_string(TipoMedicamento tipo_medicamento) noexcept;
}

#endif // !__ENTIDADES_TIPO_MEDICAMENTO_HPP__
