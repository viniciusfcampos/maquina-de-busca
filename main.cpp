#include "mecanismo-de-busca.h"

using namespace std;

int main()
{
	string arquivos[] = {
		"./livros/othello.txt",
		"./livros/kinglear.txt",
		"./livros/romeoandjuliet.txt",
		"./livros/hamlet.txt",
		"./livros/macbeth.txt"
		};

	MecanismoDeBusca mecanismo;
	cout << "~ Shakespeare Search ~" << endl
		 << endl;

	for (string arquivo : arquivos)
	{
		cout << "Indexando o  arquivo: " << arquivo << "..." << endl;
		mecanismo.indexarArquivo(arquivo);
	}

	while (1)
	{
		string termo;
		cout<< endl << "Pesquisar: ";
		cin >>  termo;
		mecanismo.pesquisar(termo);
	}
	
	return 0;
}
