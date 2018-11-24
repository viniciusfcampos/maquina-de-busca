#include "mecanismo-de-busca.h"
#include <sstream>
#include <locale>

using namespace std;

// Este método érecebe o caminho relativo de um arquivo e indexa as palavras deste arquivo
void MecanismoDeBusca::IndexarArquivo(const string caminhoArquivo)
{
    ifstream arquivo;
    // Configura o tratamento de exceções do ifstream
    arquivo.exceptions(ifstream::badbit);

    arquivo.open(caminhoArquivo);

    // Caso a abertura do arquivo não tenha ocorrido com sucesso, uma exceção é lançada contando uma mensagem pré-definida
    if (!arquivo)
    {
        throw system_error(errno, system_category(), "Nao foi possivel abrir o arquivo: " + caminhoArquivo);
    }

    // Enquanto o arquivo não chegar ao fim, o processamento continua
    while (!arquivo.eof())
    {
        string palavra;
        arquivo >> palavra;

        // Gera token obedecendo as regras de apenas letras minúsculas e números
        string token = TokenizarPalavra(palavra);

        // Grava o token no indice e a referência do arquivo
        InserirEntrada(token, caminhoArquivo);
    }

    arquivo.close();
}

string MecanismoDeBusca::TokenizarPalavra(const string palavra)
{
    ostringstream token;

    // Cada carcter da palavra é tratado separadamente
    for (int i = 0; i < palavra.length(); i++)
    {
        // Um caracter só permanecerar no token se for uma letra ou um número
        if ((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z') || (palavra[i] >= '0' && palavra[i] <= '9'))
        {
            // O token é gerado apenas com caracteres minúsculos
            token << tolower(palavra[i], locale());
        }
    }

    return token.str();
}

void MecanismoDeBusca::InserirEntrada(const string token, const string caminhoArquivo)
{
    // Se o token estiver vazio, ele não é inserido
    if (token.length() == 0)
    {
        return;
    }

    // Se o token não for encontrado no indice, um novo set é criado para ele
    if (Indice.count(token) == 0)
    {
        set<string> novoSet;
        Indice[token] = novoSet;
    }

    // O caminho do arquivo é associado ao token.
    // O set grava apenas uma vez a informação. Assim, não é necessário verificar se o caminho já existe antes de inseri-lo no set
    Indice[token].insert(caminhoArquivo);
}

set<string> MecanismoDeBusca::Pesquisar(const string termo)
{
    // E gerado um token para o termo pesquisado com as mesmas regras da inserção
    string token = TokenizarPalavra(termo);
    set<string> resultadoBusca;

    // Antes de acessar o indice, verifica se há uma entrada para o token antes de tentar acessá-la. Caso contrário, uma nova entrada seria gerada para cada termo pesquisado
    // Caso não seja encontrado, será retornado um set vazio
    if (Indice.count(token) > 0)
    {
        resultadoBusca = Indice[token];
    }

    // O set já retorna a lista em ordem crescentes
    return resultadoBusca;
}