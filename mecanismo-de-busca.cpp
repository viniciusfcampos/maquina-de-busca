#include "mecanismo-de-busca.h"
#include <sstream>
#include <locale>

using namespace std;

void MecanismoDeBusca::IndexarArquivo(const string caminhoArquivo)
{
    ifstream arquivo;
    arquivo.exceptions(ifstream::badbit);

    try
    {
        arquivo.open(caminhoArquivo);

        if (!arquivo)
        {
            throw system_error(errno, system_category(), "Nao foi possivel abrir o arquivo: " + caminhoArquivo);
        }

        while (!arquivo.eof())
        {
            string palavra;
            arquivo >> palavra;
            string token = TokenizarPalavra(palavra);
            InserirEntrada(token, caminhoArquivo);
        }

        arquivo.close();
    }
    catch (system_error& e)
    {
        cerr << e.what() << endl;
    }
}

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