#ifndef __ENTIDADES_TIPOS_HPP__
#define __ENTIDADES_TIPOS_HPP__

#include <array>

namespace Farmacia
{
  using codigo_t       = std::array<char, 20>;
  using short_string_t = std::array<char, 30>;
  using long_string_t  = std::array<char, 150>;

} // namespace Farmacia

#endif // !__ENTIDADES_TIPOS_HPP__
