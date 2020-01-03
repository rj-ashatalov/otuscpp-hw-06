#include <vector>
#include <iostream>
#include "matrix.h"
#include <sstream>

static int N = 10;

template <class T>
std::string toString(const T& src)
{
    if (src.size() <= 0) {
        return "[]";
    }

    std::stringstream output;
    output << "[";
    std::copy(src.begin(), std::prev(src.end()), std::ostream_iterator<typename std::remove_reference_t<T>::value_type>(output, ", "));
    output << src.back() << "]";
    return output.str();
}

int main(int, char const* [])
{
//    Matrix<int, 2, -1> matrix;
//    std::cout<<matrix[0][1]<<std::endl;
//    matrix[0][1] = 101;
//    std::cout<<matrix[0][1]<<std::endl;
//    std::cout<<matrix[0][2]<<std::endl;

//    В текущей реализации можно параметризировать только простыми типами
//    Matrix<std::string, 3, "empty"> matrix2;
//    std::cout<<matrix2[0][0][1]<<std::endl;
//    matrix2[0][0][1] = "some text";
//    std::cout<<matrix2[0][0][1]<<std::endl;
//    std::cout<<matrix2[0][1][1]<<std::endl;

    //При запуске программы необходимо создать матрицу с пустым значением 0, заполнить диагонали матрицывыражением
    Matrix<int, 2, 0> matrix;
    for (int i = 0; i < N; ++i)
    {
        matrix[i][i] = i;
        matrix[N - 1 - i][i] = i;
    }

    int count = 0;
    for (int i = 0; i < N * .5f; ++i)
    {
        for (int j = i % 2; j < N; j += 2)
        {
            matrix[i][j] = 0;
            matrix[N - i - 1][N - j - 1] = 0;
            ++count;
        }
    }

    //test print
/*    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }*/
    std::cout << "Iteration count: " << count << std::endl;

    //
    for (int i = 1; i <= 8; ++i)
    {
        for (int j = 1; j <= 8; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Count of filled cells: " << matrix.size() << std::endl;

    for (auto [key, value] : matrix)
    {
        std::cout << "Position:" << toString(key) << "\tValue: " << value <<  std::endl;
    }

    return 0;
}