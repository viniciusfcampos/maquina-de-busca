#include "../mecanismo-de-busca.h"
#define BOOST_TEST_MODULE MecanismoDeBuscaTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testa_se_indexacao_de_arquivos_nao_existentes_lanca_excecao)
{
    MecanismoDeBusca mecanismo;
    // Testa lançamento de exceções caso o arquivo não seja aberto com sucesso
    BOOST_CHECK_THROW(mecanismo.IndexarArquivo(""));
    BOOST_CHECK_THROW(mecanismo.IndexarArquivo(".////caminho-que-nao-existe"));
}

BOOST_AUTO_TEST_CASE(testa_regras_para_tokenizacao)
{
    MecanismoDeBusca mecanismo;
    // Testa as regras de transformar palavras em tokens contendo apenas letras minúsculas e números
    BOOST_REQUIRE_EQUAL(mecanismo.TokenizarPalavra("guardachuva"), "guardachuva");
    BOOST_REQUIRE_EQUAL(mecanismo.TokenizarPalavra("GUARDACHUVA"), "guardachuva");
    BOOST_REQUIRE_EQUAL(mecanismo.TokenizarPalavra("Guarda-chuva"), "guardachuva");
    BOOST_REQUIRE_EQUAL(mecanismo.TokenizarPalavra("Guarda chuva"), "guardachuva");
    BOOST_REQUIRE_EQUAL(mecanismo.TokenizarPalavra("Guarda Chuva 123"), "guardachuva123");
    BOOST_REQUIRE_EQUAL(mecanismo.TokenizarPalavra("Guarda-chuva,.!?;"), "guardachuva");
}

BOOST_AUTO_TEST_CASE(testa_se_pesquisa_pesquisa_sem_ter_indexado_nenhum_nao_lanca_excecao)
{
    MecanismoDeBusca mecanismo;
    // Testa se não lança exceção se não tiver indexado nenhum arquivo
    set<string> resultados = mescanismo.Pesquisar("Termo não inserido");
    BOOST_REQUIRE_EQUAL(resultados.size(), 0);
}

BOOST_AUTO_TEST_CASE(testa_se_pesquisa_pesquisa_sem_ter_indexado_nenhum_arquivo_retorna_vazio)
{
    MecanismoDeBusca mecanismo;
    // Testa se retorna vazio para termos não inseridos
    set<string> resultados = mescanismo.Pesquisar("Termo não inserido");
    BOOST_REQUIRE_EQUAL(resultados.size(), 0);
}

BOOST_AUTO_TEST_CASE(testa_se_nao_grava_quantidade_duplicada_de_arquivos)
{
    MecanismoDeBusca mecanismo;
    // Testa se não grava quantidade duplicada de arquivos
    mecanismo.InserirEntrada("Guarda chuva", "Arquivo 1");
    mecanismo.InserirEntrada("Guarda chuva", "Arquivo 1");
    mecanismo.InserirEntrada("Guarda chuva", "Arquivo 1");
    set<string> resultados = mescanismo.Pesquisar("Guarda chuva");
    BOOST_REQUIRE_EQUAL(resultados.size(), 1);
}

BOOST_AUTO_TEST_CASE(testa_insercao_e_pesquisa_por_termos_contidos_em_mais_de_um_arquivo)
{
    MecanismoDeBusca mecanismo;
    // Testa se grava mais de um arquivo corretamente
    mecanismo.InserirEntrada("Guarda chuva", "Arquivo 1");
    mecanismo.InserirEntrada("Guarda chuva", "Arquivo 2");
    mecanismo.InserirEntrada("Guarda chuva", "Arquivo 3");
    set<string> resultados = mescanismo.Pesquisar("Guarda chuva");
    BOOST_REQUIRE_EQUAL(resultados.size(), 3);
    BOOST_REQUIRE_EQUAL(resultados.contains("Arquivo 1"), true);
    BOOST_REQUIRE_EQUAL(resultados.contains("Arquivo 2"), true);
    BOOST_REQUIRE_EQUAL(resultados.contains("Arquivo 3"), true);
}

BOOST_AUTO_TEST_CASE(testa_se_retorno_ja_esta_em_ordem_crescente)
{
    MecanismoDeBusca mecanismo;
    // Testa se retorno da pesquisa é em ordem crescente
    mecanismo.InserirEntrada("Guarda chuva", "Arquivo 4");
    mecanismo.InserirEntrada("Guarda chuva", "Arquivo 2");
    mecanismo.InserirEntrada("Guarda chuva", "Arquivo 1");
    mecanismo.InserirEntrada("Guarda chuva", "Arquivo 3");
    set<string> resultados = mescanismo.Pesquisar("Guarda chuva");

    int arquivoId = 1
    for (string resultado : resultados)
    {
        BOOST_REQUIRE_EQUAL(resultado, "Arquivo " + arquivoId);
        arquivoId++;
    }
}