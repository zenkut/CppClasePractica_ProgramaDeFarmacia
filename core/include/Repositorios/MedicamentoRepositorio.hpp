#ifndef __MEDICAMENTO_REPOSITORIO_HPP__
#define __MEDICAMENTO_REPOSITORIO_HPP__

#include <fstream>
#include <filesystem>
#include <iterator>
#include <cstddef>
#include "../Entidades/Medicamento.hpp"

namespace Farmacia::Repositorios
{
  /*
  difference_type	Iter::difference_type
  value_type	Iter::value_type
  pointer	Iter::pointer
  reference	Iter::reference
  iterator_category	Iter::iterator_category
  */
  class MedicamentoRepositorioIterador
  {
  public:
    using difference_type   = ptrdiff_t;
    using value_type        = Entidades::Medicamento;
    using pointer           = Entidades::Medicamento*;
    using reference         = Entidades::Medicamento&;
    using iterator_category = std::input_iterator_tag;

    MedicamentoRepositorioIterador(std::fstream &repositorio, const size_t indice) noexcept
    : m_indice{ indice }
    , m_repositorio{ &repositorio }
    {
    }

    MedicamentoRepositorioIterador(MedicamentoRepositorioIterador&& it)
    : m_indice{ it.m_indice }
    , m_repositorio{ it.m_repositorio }
    {
      it.m_indice = 0;
      it.m_repositorio = nullptr;
    }

    MedicamentoRepositorioIterador& operator=(MedicamentoRepositorioIterador&& it)
    {
      this->m_indice = std::exchange(it.m_indice, 0);
      this->m_repositorio = std::exchange(it.m_repositorio, nullptr);
      return *this;
    }

    MedicamentoRepositorioIterador(const MedicamentoRepositorioIterador&) = delete;
    MedicamentoRepositorioIterador& operator=(const MedicamentoRepositorioIterador&) = delete;
    ~MedicamentoRepositorioIterador() = default;

    const Entidades::Medicamento& operator*()
    {
      m_repositorio->seekg(m_indice, std::ios::beg);
      m_repositorio->read(reinterpret_cast<char*>(&m_medicamento), sizeof(Entidades::Medicamento));
      return m_medicamento;
    }

    const Entidades::Medicamento* operator->()
    {
      return &this->operator*();
    }

    MedicamentoRepositorioIterador& operator++()
    {
      ++m_indice;
      return *this;
    }

    bool operator!=(const MedicamentoRepositorioIterador &it) noexcept
    {
      return this->m_indice != it.m_indice;
    }

  private:
    size_t                 m_indice;
    std::fstream          *m_repositorio;
    Entidades::Medicamento m_medicamento;
  };

  class MedicamentoRepositorio
  {
    // using namespace Farmacia;
    // using namespace Entidades;

  public:
    MedicamentoRepositorio()
    {
      if (std::filesystem::exists("MedicamentoRepositorio.bin"))
      {
        m_repositorio.open("MedicamentoRepositorio.bin", std::ios::in | std::ios::out | std::ios::binary);
      }
      else 
      {
        // binary|out|in|trunc
        m_repositorio.open("MedicamentoRepositorio.bin", std::ios::in | std::ios::out | std::ios::trunc | std::ios::binary);
      }
    }

    
    bool Guardar(const Entidades::Medicamento& medicamento) noexcept
    {
      EstablecerUltimaPosicion();

      // Escribiendo datos del repositorio en binario.
      m_repositorio.write(reinterpret_cast<const char*>(&medicamento), sizeof(Entidades::Medicamento));
  
      // Verificar que no haya errores al guardar.
      if (m_repositorio.good()) return true;
      
      // Si hubo error, poner Repositorio en un estado "sin error"
      m_repositorio.clear(std::ios::goodbit);

      // Retornar False si hubo error.
      return false;
    }

    MedicamentoRepositorioIterador begin()
    {
      return { m_repositorio, 0 };
    }

    MedicamentoRepositorioIterador end()
    {
      return { m_repositorio, TotalMedicamentos() };
    }

    size_t TotalMedicamentos() const noexcept
    {
      EstablecerUltimaPosicion();
      return m_repositorio.tellg() / sizeof(Entidades::Medicamento);
    }

  private:
    
    inline void EstablecerUltimaPosicion() const
    {
      m_repositorio.seekp(0, std::ios::end);
    }

    mutable std::fstream m_repositorio;
  };
}

#endif // !__MEDICAMENTO_REPOSITORIO_HPP__