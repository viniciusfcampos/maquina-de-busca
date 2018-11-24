#include "mecanismo-de-busca.h"

using namespace std;

void ExibirResultado(set<string> resultados)
{
	// Verifica se algum resultado foi encontrado antes de imprimir
	if (resultados.size() > 0)
	{
		for (string caminhoArquivo : resultados)
		{
			cout << " " << caminhoArquivo << endl;
		}
	}
	else
	{
		cout << "Nenhum resultado foi encontrado para sua busca." << endl;
	}
}

int main()
{
	// Lista de livros a serem indexados. Um deles nao-existe e foi colocado nesta lista para testar o tratamento de exceções
	string arquivos[] = {
		"./livros/othello.txt",
		"./livros/kinglear.txt",
		"./livros/romeoandjuliet.txt",
		"./livros/hamlet.txt",
		"./livros/macbeth.txt",
		"./livros/nao-existe.txt"};

	MecanismoDeBusca mecanismo;
	cout << "~ Shakespeare Search ~" << endl
		 << endl;

	// Indexa cada um dos arquivos informados anteriormente
	for (string arquivo : arquivos)
	{
		// Este try foi colocado para tratar a abertura, leitura e fechamento de arquivos
		try
		{
			cout << "Indexando o  arquivo: " << arquivo << "..." << endl;
			mecanismo.IndexarArquivo(arquivo);
		}
		catch (system_error &e)
		{
			// Caso alguma exceção tenha sido lançada no processamento do arquivo, a mensagem de erro é exibido na tela, mas o programa não é interrompido
			cerr << e.what() << endl;
		}
	}

	// Após indexar, a máquina de busca fica disponível para consultas.
	while (1)
	{
		string termo;
		cout << endl
			 << "Pesquisar: ";
		cin >> termo;
		ExibirResultado(mecanismo.Pesquisar(termo));
	}

	return 0;
}
