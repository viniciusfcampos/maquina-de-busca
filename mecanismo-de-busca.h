#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

class MecanismoDeBusca
{
    map<string, set<string>> Indice;
  public:
    string TokenizarPalavra(const string);
    void IndexarArquivo(const string);
    void InserirEntrada(const string, const string);
    set<string> Pesquisar(const string);
};