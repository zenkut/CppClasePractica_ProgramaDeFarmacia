#ifndef __RECIBO_REPOSITORIO_HPP__
#define __RECIBO_REPOSITORIO_HPP__

#include <fstream>
#include <filesystem>
#include <cstddef>
#include "../Iteradores/Recibo.hpp"
#include "Repositorio.hpp"

namespace Farmacia::Repositorios
{
  template<>
  class Repositorio<Entidades::Recibo>
  {
  public:

    using value_type      = Entidades::Recibo;
    using size_type       = size_t;
    using difference_type = ptrdiff_t;
    using reference       = Entidades::Recibo&;
    using const_reference = const Entidades::Recibo&;
    using pointer         = Entidades::Recibo*;
    using const_pointer   = const Entidades::Recibo*;
    using iterator        = Iteradores::Iterador<Entidades::Recibo>;
    using const_iterator  = const Iteradores::Iterador<Entidades::Recibo>;

    Repositorio()
    {
      std::ios::openmode mode = std::ios::in | std::ios::out | std::ios::binary;
      
      if (!std::filesystem::exists("ReciboRepositorio.bin"))
        mode |= std::ios::trunc;
      
      m_repositorio.open("ReciboRepositorio.bin", mode);
    }

    
    bool push_back(const_reference Recibo) noexcept
    {
      m_repositorio.seekp(0, std::ios::end);

      // Escribiendo datos del repositorio en binario.
      m_repositorio.write(reinterpret_cast<const char*>(&Recibo), sizeof(value_type));

      // Verificar que no haya errores al guardar.
      if (m_repositorio.good())
      {
        m_repositorio.flush();
        return true;
      }

      // Si hubo error, poner Repositorio en un estado "sin error"
      m_repositorio.clear(std::ios::goodbit);

      // Retornar False si hubo error.
      return false;
    }

    iterator begin() noexcept
    {
      return { m_repositorio, 0 };
    }

    iterator end() noexcept
    {
      return { m_repositorio, size() };
    }

    const_iterator cbegin() const noexcept
    {
      return { m_repositorio, 0 };
    }

    const_iterator cend() const noexcept
    {
      return { m_repositorio, size() };
    }

    size_t size() const noexcept
    {
      return std::filesystem::file_size("ReciboRepositorio.bin") / sizeof(Entidades::Recibo);
    }

  private:
    mutable std::fstream m_repositorio;
  };
}

#endif // !__Recibo_REPOSITORIO_HPP__