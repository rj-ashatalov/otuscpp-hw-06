#include <vector>
#include <iostream>
#include "matrix.h"

int main(int, char const *[])
{
    Matrix<int, 2, -1> matrix;
    std::cout<<matrix[0][1]<<std::endl;
    matrix[0][1] = 101;
    std::cout<<matrix[0][1]<<std::endl;
    return 0;
}