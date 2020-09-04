#include "../include/Sexo.hpp"

namespace Farmacia::Entidades 
{
  [[nodiscard]] std::string_view to_string(Sexo sexo) noexcept
  {
    switch(sexo)
    {
      [[unlikely]] case Sexo::Hombre: 
        return "Hombre";

      [[likely]] case Sexo::Mujer: 
        return "Mujer";

      default:
        return "Desconocido";
    }
  }
}

