#include <iostream>
#include "Interador.h"
#include "Conjunto.h"

Interador::Interador()
{
}
Interador::~Interador()
{
}
Interador Interador::Inicio(Conjunto conjunto)
{
    Interador interadorNovo;
    interadorNovo.point = conjunto.estrutura;
    return interadorNovo;
}
Interador Interador::Fim(Conjunto conjunto)
{
    Interador interadorNovo;
    interadorNovo.point = conjunto.estrutura + conjunto.n;
    return interadorNovo;
}
void Interador::avancar(Interador inicio)
{
    inicio.point++;
}
TipoItem Interador::acessar_elemento(Interador it)
{
    return *it.point;
}
bool Interador::sao_diferentes(Interador inicio, Interador fim)
{
    return inicio.point != fim.point;
}