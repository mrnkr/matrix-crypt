//
//  matrix.cpp
//  Matrix Crypt
//
//  Created by Alvaro Nicoli on 6/1/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "matrix.hpp"

namespace matrix {
    // Generates a test matrix to work with
    std::vector<std::vector<double>> gen()
    {
        std::vector<std::vector<double>> ret_val;
        
        for (int i = 0; i < 40; ++i)
        {
            std::vector<double> vec;
            
            for (int j = 0; j < 40; ++j)
            {
                // Difference between i & j has to be less than 2
                // On even rows, positions different from 0 will be greater than the number of the previous row
                // and less than the next one
                // Inverse logic applied to when the row index is odd
                if (abs(i - j) < 2 && ((i % 2 == 0 && j > i-1 && j <= i+1) || (i % 2 != 0 && j >= i-1 && j < i+1)))
                {
                    // The row index has to be equal to the column index and they both have to be odd numbers
                    // for the element to be -1
                    if (i == j && i % 2 != 0)
                    {
                        vec.push_back(-1);
                    }
                    else {
                        vec.push_back(1);
                    }
                }
                else
                {
                    vec.push_back(0);
                }
            }
            
            ret_val.push_back(vec);
        }
        
        return ret_val;
    }
    
    bool is_invertible(std::vector<std::vector<double>> matrix)
    {
        // Checks whether the determinant is different from 0
        return det(matrix) != 0;
    }
    
    double det(std::vector<std::vector<double>> matrix)
    {
        double ret_val = 0;
        
        // If the matrix isnt square then the determinant cant be calculated
        if (matrix.size() == matrix[0].size())
        {
            // If the dimension is greater than one calculate by adjoint - else return the number
            if (matrix.size() > 1)
            {
                for (int i = 0; i < matrix[0].size(); ++i)
                {
                    if (matrix[0][i] != 0)
                    {
                        ret_val += pow(-1, (i+2)) * matrix[0][i] * det(adj(matrix, i, 0));
                    }
                }
            }
            else
            {
                ret_val = matrix[0][0];
            }
        }
        else
        {
            ret_val = -90807060203058204;
        }
        
        return ret_val;
    }
    
    std::vector<std::vector<double>> adj(std::vector<std::vector<double>> matrix, int x, int y)
    {
        // Remove the row that has to go away
        matrix.erase(matrix.begin() + y);
        
        // Removes the column that has to be removed
        for (int i = 0; i < matrix.size(); ++i)
        {
            matrix[i].erase(matrix[i].begin() + x);
        }
        
        return matrix;
    }
    
    double dot_prod_vector(std::vector<double> vector1, std::vector<double> vector2)
    {
        double ret_val = 0;
        
        if (vector1.size() == vector2.size())
        {
            for (int i = 0; i < vector1.size(); ++i)
            {
                ret_val += vector1[i] * vector2[i];
            }
        }
        else
        {
            ret_val = -90807060203058204;
        }
        
        return ret_val;
    }

    std::vector<double> multiply_by_vector(std::vector<std::vector<double>> matrix, std::vector<double> vector)
    {
        std::vector<double> ret_val;
        
        for (int i = 0; i < matrix.size(); ++i)
        {
            ret_val.push_back(dot_prod_vector(matrix[i], vector));
        }
        
        return ret_val;
    }
    
    std::vector<std::vector<double>> scalar_prod(std::vector<std::vector<double>> matrix, double num)
    {
        std::vector<std::vector<double>> ret_val;
        
        for (int i = 0; i < matrix.size(); ++i)
        {
            std::vector<double> vec;
            
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                vec.push_back(matrix[i][j] * num);
            }
            
            ret_val.push_back(vec);
        }
        
        return ret_val;
    }
    
    std::vector<std::vector<double>> trans(std::vector<std::vector<double>> matrix)
    {
        // Transformation can only be made to square matrices
        if (matrix.size() == matrix[0].size())
        {
            for (int i = 0; i < matrix.size(); ++i)
            {
                for (int j = i+1; j < matrix[i].size(); ++j)
                {
                    // a = a + b
                    // b = a - b
                    // a = a - b
                    
                    matrix[i][j] = matrix[i][j] + matrix[j][i];
                    matrix[j][i] = matrix[i][j] - matrix[j][i];
                    matrix[i][j] = matrix[i][j] - matrix[j][i];
                }
            }
        }
        
        return matrix;
    }
    
    std::vector<std::vector<double>> cof(std::vector<std::vector<double>> matrix)
    {
        std::vector<std::vector<double>> ret_val;
        
        for (int i = 0; i < matrix.size(); ++i)
        {
            std::vector<double> vec;
            
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                vec.push_back(pow(-1, i + 1 + j + 1) * det(adj(matrix, j, i)));
            }
            
            ret_val.push_back(vec);
        }
        
        return ret_val;
    }
    
    std::vector<std::vector<double>> invert(std::vector<std::vector<double>> matrix)
    {
        std::vector<std::vector<double>> ret_val;
        
        ret_val = scalar_prod(trans(cof(matrix)), (1/det(matrix)));
        
        return ret_val;
    }
}
