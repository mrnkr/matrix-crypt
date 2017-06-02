//
//  matrix.hpp
//  Matrix Crypt
//
//  Created by Alvaro Nicoli on 6/1/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include <string>
#include <vector>

const std::vector<double> TEST_VECTOR = {0, 8, 1, 6, 1, 2, 0, 1, 2, 9, 2, 9, 2, 9, 2, 9, 2, 9, 2, 9, 2, 9, 2, 9, 2, 9, 2, 9, 2, 9, 2, 9, 2, 9, 2, 9, 2, 9, 2, 9};

namespace matrix {
    std::vector<std::vector<double>> gen();
    bool is_invertible(std::vector<std::vector<double>> matrix);
    double det(std::vector<std::vector<double>> matrix);
    std::vector<std::vector<double>> adj(std::vector<std::vector<double>> matrix, int x, int y);
    double dot_prod_vector(std::vector<double> vector1, std::vector<double> vector2);
    std::vector<double> multiply_by_vector(std::vector<std::vector<double>> matrix, std::vector<double> vector);
    std::vector<std::vector<double>> scalar_prod(std::vector<std::vector<double>> matrix, double num);
    std::vector<std::vector<double>> trans(std::vector<std::vector<double>> matrix);
    std::vector<std::vector<double>> cof(std::vector<std::vector<double>> matrix);
    std::vector<std::vector<double>> invert(std::vector<std::vector<double>> matrix);
}

#endif /* matrix_hpp */
