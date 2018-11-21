#include "./mecanismo-de-busca.h"
#define BOOST_TEST_MODULE MecanismoDeBuscaTeste
#include <boost/test/unit_test.hpp>
using namespace std;

BOOST_AUTO_TEST_CASE(DoisMaisDois)
{
    BOOST_CHECK_EQUAL(2+2, 4);
}