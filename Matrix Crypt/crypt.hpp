//
//  crypt.hpp
//  Matrix Crypt
//
//  Created by Alvaro Nicoli on 6/2/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#ifndef crypt_hpp
#define crypt_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <locale>
#include <iostream>
#include "matrix.hpp"

namespace crypt {
    std::vector<double> str_to_vec(std::string str);
    std::string vec_to_str(std::vector<double> vec);
    std::vector<double> encrypt(std::string msg, std::vector<std::vector<double>> matrix);
    std::string decrypt(std::vector<double> msg, std::vector<std::vector<double>> matrix);
}

#endif /* crypt_hpp */
