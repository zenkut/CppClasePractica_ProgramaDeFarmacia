#include <iostream>
#include "include/TipoMedicamento.hpp"

using namespace Farmacia;
using namespace Entidades;

int main()
{
    std::cout << to_string(TipoMedicamento::Vitamina)    << "\n";
    std::cout << to_string(TipoMedicamento::Analgesico) << "\n";
    std::cout << to_string(TipoMedicamento::Antibiotico) << "\n";
    return 0;
}
