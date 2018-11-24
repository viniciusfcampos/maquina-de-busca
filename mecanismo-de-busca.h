#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

class MecanismoDeBusca
{
    map<string, set<string>> Indice;
    string TokenizarPalavra(const string);
    void InserirEntrada(const string, const string);
  public:
    void IndexarArquivo(const string);
    set<string> Pesquisar(const string);
};