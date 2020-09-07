#include <iostream>
#include <iomanip>
#include "include/Entidades/TipoMedicamento.hpp"
#include "include/Repositorios/Medicamento.hpp"
#include "include/Entidades/Medicamento.hpp"

using namespace Farmacia;
using namespace Entidades;
using namespace Repositorios;

int main()
{
    using ctraits = std::char_traits<char>;
    Repositorio<Medicamento> repositorio;

    Medicamento medicamento;
    ctraits::copy(medicamento.Codigo.data(), "123456", 6);
    ctraits::copy(medicamento.Nombre.data(), "Denis", 5);
    medicamento.Precio = 1'000'000;
    medicamento.Stock  = 1;
    medicamento.Tipo   = TipoMedicamento::Antialergico;

    repositorio.push_back(medicamento);

    for (const auto &m : repositorio)
    {
        std::cout << "Codigo: " << m.Codigo.data() << "\n";
        std::cout << "Nombre: " << m.Nombre.data() << "\n";
        std::cout << "Precio: " << std::fixed << std::setprecision(2) << m.Precio << "\n";
        std::cout << "Stock:  " << m.Stock << "\n";
        std::cout << "Tipo:   " << to_string(m.Tipo) << "\n";
        std::cout << "------------------------------------\n\n";
    }

    return 0;
}
