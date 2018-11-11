#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

class MecanismoDeBusca
{
    map<string, set<string>> indice;
    string tokenizarPalavra(const string);
    void inserirEntrada(const string, const string);
  public:
    void indexarArquivo(const string);
    void pesquisar(const string);
};