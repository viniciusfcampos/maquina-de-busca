#include "mecanismo-de-busca.h"

using namespace std;

void ExibirResultado(set<string> resultados)
{
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

	for (string arquivo : arquivos)
	{
		cout << "Indexando o  arquivo: " << arquivo << "..." << endl;
		mecanismo.IndexarArquivo(arquivo);
	}

	while (1)
	{
		string termo;
		cout << endl << "Pesquisar: ";
		cin >> termo;
		ExibirResultado(mecanismo.Pesquisar(termo));
	}

	return 0;
}
