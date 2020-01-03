#define BOOST_TEST_MODULE app_test_module

#include "../lib.h"
#include <boost/test/unit_test.hpp>
#include <matrix.h>

BOOST_AUTO_TEST_SUITE(app_test_suite)

BOOST_AUTO_TEST_CASE(test_version)
{
    BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_CASE(test_сode)
{
    Matrix<int, 2, -1> matrix;
    BOOST_CHECK(matrix.size() == 0);

    auto a = matrix[0][0];
    BOOST_CHECK(a == -1);
    BOOST_CHECK(matrix.size() ==0);

    matrix[100][100] = 314;
    BOOST_CHECK(matrix[100][100] == 314);
    BOOST_CHECK(matrix.size() ==1);
}
BOOST_AUTO_TEST_SUITE_END()
