#include <vector>
#include <iostream>
#include "matrix.h"

int main(int, char const *[])
{
    Matrix<int, 2, -1> matrix;
    std::cout<<matrix[0][1]<<std::endl;
    matrix[0][1] = 101;
    std::cout<<matrix[0][1]<<std::endl;
    std::cout<<matrix[0][2]<<std::endl;

//    Matrix<std::string, 3, "empty"> matrix2;
//    std::cout<<matrix2[0][0][1]<<std::endl;
//    matrix2[0][0][1] = "some text";
//    std::cout<<matrix2[0][0][1]<<std::endl;
//    std::cout<<matrix2[0][1][1]<<std::endl;


    return 0;
}