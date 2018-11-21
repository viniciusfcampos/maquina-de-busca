#include "mecanismo-de-busca.h"
#include <sstream>
#include <locale>

using namespace std;

string MecanismoDeBusca::tokenizarPalavra(const string palavra)
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

void MecanismoDeBusca::inserirEntrada(const string token, const string caminhoArquivo)
{
    if (token.length() == 0)
    {
        return;
    }

    if (indice.count(token) == 0)
    {
        set<string> novoSet;
        indice[token] = novoSet;
    }

    indice[token].insert(caminhoArquivo);
}

void MecanismoDeBusca::indexarArquivo(const string caminhoArquivo)
{
    ifstream arquivo;
    arquivo.open(caminhoArquivo);

    while (!arquivo.eof())
    {
        string palavra;
        arquivo >> palavra;
        string token = tokenizarPalavra(palavra);
        inserirEntrada(token, caminhoArquivo);
    }
}

void MecanismoDeBusca::pesquisar(const string termo)
{
    string token = tokenizarPalavra(termo);

    if (indice.count(token) > 0)
    {
        for (string caminhoArquivo : indice[token])
        {
            cout << " " << caminhoArquivo << endl;
        }

        cout << endl << endl;
    }
    else
    {
        cout << "Nenhum resultado foi encontrado para sua busca." << endl;
    }
}