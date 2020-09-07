#ifndef __ENTIDADES_SEXO_HPP__
#define __ENTIDADES_SEXO_HPP__

#include <string_view>

namespace Farmacia::Entidades 
{
  enum class [[nodiscard]] Sexo
  {
    Hombre,
    Mujer
  };

  [[nodiscard]] std::string_view to_string(Sexo sexo) noexcept;
}

#endif // !__ENTIDADES_SEXO_HPP__
