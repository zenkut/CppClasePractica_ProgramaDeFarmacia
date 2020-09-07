#ifndef __MEDICAMENTO_REPOSITORIO_HPP__
#define __MEDICAMENTO_REPOSITORIO_HPP__

#include <fstream>
#include <filesystem>
#include <cstddef>
#include "../Iteradores/Medicamento.hpp"
#include "Repositorio.hpp"

namespace Farmacia::Repositorios
{
  template<>
  class Repositorio<Entidades::Medicamento>
  {
  public:

    using value_type      = Entidades::Medicamento;
    using size_type       = size_t;
    using difference_type = ptrdiff_t;
    using reference       = Entidades::Medicamento&;
    using const_reference = const Entidades::Medicamento&;
    using pointer         = Entidades::Medicamento*;
    using const_pointer   = const Entidades::Medicamento*;
    using iterator        = Iteradores::Iterador<Entidades::Medicamento>;
    using const_iterator  = const Iteradores::Iterador<Entidades::Medicamento>;

    Repositorio()
    {
      std::ios::openmode mode = std::ios::in | std::ios::out | std::ios::binary;
      
      if (!std::filesystem::exists("MedicamentoRepositorio.bin"))
        mode |= std::ios::trunc;
      
      m_repositorio.open("MedicamentoRepositorio.bin", mode);
    }

    
    bool push_back(const_reference medicamento) noexcept
    {
      m_repositorio.seekp(0, std::ios::end);

      // Escribiendo datos del repositorio en binario.
      m_repositorio.write(reinterpret_cast<const char*>(&medicamento), sizeof(value_type));

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
      return std::filesystem::file_size("MedicamentoRepositorio.bin") / sizeof(Entidades::Medicamento);
    }

  private:
    mutable std::fstream m_repositorio;
  };
}

#endif // !__MEDICAMENTO_REPOSITORIO_HPP__