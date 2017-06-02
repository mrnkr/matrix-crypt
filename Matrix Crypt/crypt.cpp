//
//  crypt.cpp
//  Matrix Crypt
//
//  Created by Alvaro Nicoli on 6/2/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#include "crypt.hpp"

namespace crypt {
    std::vector<double> str_to_vec(std::string str)
    {
        std::vector<double> ret_val;
        std::locale loc;
        
        for (int i = 0; i < 20; ++i)
        {
            if (i < str.length())
            {
                if (str[i] != ' ')
                {
                    // Get ASCII representation of the character and substract 64 to it so A will be represented as 01
                    int code = static_cast<int>(std::toupper(str[i], loc));
                    code -= 64;
                    
                    // Divides the code into its separate digits and pushes them to the vector
                    ret_val.push_back(static_cast<double>(code / 10 % 10));
                    ret_val.push_back(static_cast<double>(code % 10));
                }
                else
                {
                    // Pushes the designated code for a blank space
                    ret_val.push_back(2);
                    ret_val.push_back(7);
                }
            }
            else
            {
                // Pushes the code that represents the end of a message
                ret_val.push_back(2);
                ret_val.push_back(8);
            }
        }
        
        return ret_val;
    }
    
    std::string vec_to_str(std::vector<double> vec)
    {
        std::string ret_val;
        
        for (int i = 0; i < vec.size(); i += 2)
        {
            int code = static_cast<int>(vec[i] * 10 + vec[i+1]);
            
            if (code < 27)
            {
                char c = static_cast<char>(code + 64);
                ret_val += c;
            }
            
            if (code == 27)
            {
                ret_val += ' ';
            }
        }
        
        return ret_val;
    }
    
    std::vector<double> encrypt(std::string msg, std::vector<std::vector<double>> matrix)
    {
        std::vector<double> ret_val = str_to_vec(msg);
        ret_val = matrix::multiply_by_vector(matrix, ret_val);
        
        return ret_val;
    }
    
    std::string decrypt(std::vector<double> msg, std::vector<std::vector<double>> matrix)
    {
        std::string ret_val;
        matrix = matrix::invert(matrix);
        msg = matrix::multiply_by_vector(matrix, msg);
        ret_val = vec_to_str(msg);
        
        return ret_val;
    }
}
