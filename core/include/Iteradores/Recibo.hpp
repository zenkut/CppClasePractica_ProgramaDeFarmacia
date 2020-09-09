#ifndef __ITERADORES_RECIBO_HPP__
#define __ITERADORES_RECIBO_HPP__

#include <fstream>
#include "Iterador.hpp"
#include "../Entidades/Recibo.hpp"

namespace Farmacia::Iteradores
{
  template<>
  class Iterador<Entidades::Recibo>
  {
  public:
    using difference_type   = ptrdiff_t;
    using value_type        = Entidades::Recibo;
    using pointer           = Entidades::Recibo*;
    using const_pointer     = const Entidades::Recibo*;
    using reference         = Entidades::Recibo&;
    using const_reference   = const Entidades::Recibo&;
    using iterator_category = std::input_iterator_tag;

    Iterador(std::fstream &repositorio, const size_t indice) noexcept
    : m_indice{ indice }
    , m_repositorio{ &repositorio }
    {
    }

    Iterador(Iterador&& it)
    : m_indice{ std::exchange(it.m_indice, 0) }
    , m_repositorio{ std::exchange(it.m_repositorio, nullptr) }
    {
    }

    Iterador& operator=(Iterador&& it)
    {
      this->m_indice = std::exchange(it.m_indice, 0);
      this->m_repositorio = std::exchange(it.m_repositorio, nullptr);
      return *this;
    }

    Iterador(const Iterador&) = delete;
    Iterador& operator=(const Iterador&) = delete;
    ~Iterador() = default;

    reference operator*() noexcept
    {
      m_repositorio->seekg(m_indice * sizeof(value_type), std::ios::beg);
      m_repositorio->read(reinterpret_cast<char*>(&m_recibo), sizeof(value_type));
      return m_recibo;
    }

    pointer operator->() noexcept
    {
      return &this->operator*();
    }

    const_reference operator*() const noexcept
    {
      m_repositorio->seekg(m_indice * sizeof(value_type), std::ios::beg);
      m_repositorio->read(reinterpret_cast<char*>(&m_recibo), sizeof(value_type));
      return m_recibo;
    }

    const_pointer operator->() const noexcept
    {
      return &this->operator*();
    }

    Iterador& operator++() noexcept
    {
      ++m_indice;
      return *this;
    }

    const Iterador& operator++() const noexcept
    {
      ++m_indice;
      return *this;
    }
    
    Iterador operator++(int) noexcept
    {
      return { *m_repositorio, m_indice++ };
    }

    const Iterador operator++(int) const noexcept
    {
      return { *m_repositorio, m_indice++ };
    }

    Iterador& operator--() noexcept
    {
      --m_indice;
      return *this;
    }

    const Iterador& operator--() const noexcept
    {
      --m_indice;
      return *this;
    }
    
    Iterador operator--(int) noexcept
    {
      return { *m_repositorio, m_indice-- };
    }

    const Iterador operator--(int) const noexcept
    {
      return { *m_repositorio, m_indice-- };
    }

    value_type operator[](const int32_t index) const noexcept
    {
      m_repositorio->seekg(index * sizeof(value_type), std::ios::beg);
      m_repositorio->read(reinterpret_cast<char*>(&m_recibo), sizeof(value_type));
      return m_recibo;
    }

    bool operator!=(const Iterador &it) const noexcept
    {
      return this->m_indice != it.m_indice;
    }

    friend Iterador operator+(const Iterador& it, const int32_t index);
    friend Iterador operator+(const int32_t index, const Iterador& it);
    friend Iterador operator-(const Iterador& it, const int32_t index);
    friend Iterador operator-(const int32_t index, const Iterador& it);

  private:
    mutable size_t      m_indice;
    std::fstream       *m_repositorio;
    mutable value_type  m_recibo;
  };


  Iterador<Entidades::Recibo> operator+(const Iterador<Entidades::Recibo>& it, const int32_t index)
  {
    return { *it.m_repositorio, it.m_indice + index };
  }

  Iterador<Entidades::Recibo> operator+(const int32_t index, const Iterador<Entidades::Recibo>& it)
  {
    return { *it.m_repositorio, it.m_indice + index };
  }

  Iterador<Entidades::Recibo> operator-(const Iterador<Entidades::Recibo>& it, const int32_t index)
  {
    return { *it.m_repositorio, it.m_indice - index };
  }

  Iterador<Entidades::Recibo> operator-(const int32_t index, const Iterador<Entidades::Recibo>& it)
  {
    return { *it.m_repositorio, it.m_indice - index };
  }
}

#endif // !__ITERADORES_RECIBO_HPP__