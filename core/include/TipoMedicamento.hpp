#ifndef __TIPO_MEDICAMENTO_HPP__
#define __TIPO_MEDICAMENTO_HPP__

#include <string_view>

namespace Farmacia::Entidades 
{
  enum class [[nodiscard]] TipoMedicamento
  {
    Analgesico,
    Vitamina, 
    Antibiotico,
  };

  [[nodiscard]] std::string_view to_string(TipoMedicamento tipo_medicamento) noexcept;
}

#endif // !__TIPO_MEDICAMENTO_HPP__
