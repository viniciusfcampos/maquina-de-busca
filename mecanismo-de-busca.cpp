#include "mecanismo-de-busca.h"
#include <sstream>
#include <locale>

using namespace std;

string MecanismoDeBusca::TokenizarPalavra(const string palavra)
{
    ostringstream token;

    for (int i = 0; i < palavra.length(); i++)
    {
        if ((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z'))
        {
            token << tolower(palavra[i], locale());
        }
    }

    return token.str();
}

void MecanismoDeBusca::InserirEntrada(const string token, const string caminhoArquivo)
{
    if (token.length() == 0)
    {
        return;
    }

    if (Indice.count(token) == 0)
    {
        set<string> novoSet;
        Indice[token] = novoSet;
    }

    Indice[token].insert(caminhoArquivo);
}

void MecanismoDeBusca::IndexarArquivo(const string caminhoArquivo)
{
    ifstream arquivo;
    arquivo.open(caminhoArquivo);

    while (!arquivo.eof())
    {
        string palavra;
        arquivo >> palavra;
        string token = TokenizarPalavra(palavra);
        InserirEntrada(token, caminhoArquivo);
    }
}

set<string> MecanismoDeBusca::Pesquisar(const string termo)
{
    string token = TokenizarPalavra(termo);
    set<string> resultadoBusca;

    if (Indice.count(token) > 0)
    {
        resultadoBusca = Indice[token];
    }
    
    return resultadoBusca;
}