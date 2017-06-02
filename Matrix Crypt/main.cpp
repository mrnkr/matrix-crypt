//
//  main.cpp
//  Matrix Crypt
//
//  Created by Alvaro Nicoli on 6/1/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <vector>
#include "matrix.hpp"
#include "crypt.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    string message = "Hello World";
    vector<vector<double>> matrix = matrix::gen();
    
    cout << "Encryption matrix generated!" << endl;
    cout << "Message set as: " << message << endl;
    cout << "Beginning encryption..." << endl;
    
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    vector<double> encrypted_message = crypt::encrypt(message, matrix);
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    
    auto duration = chrono::duration_cast<chrono::milliseconds>( t2 - t1 ).count();
    cout << "Encryption completed in: " << duration << " milliseconds" << endl;
    
    cout << "Message encrypted as the following vector:" << endl;
    
    for (int i = 0; i < encrypted_message.size(); ++i)
    {
        cout << encrypted_message[i] << " ";
    }
    
    cout << "" << endl;
    
    cout << "Beginning decryption..." << endl;
    
    t1 = chrono::high_resolution_clock::now();
    message = crypt::decrypt(encrypted_message, matrix);
    t2 = chrono::high_resolution_clock::now();
    
    duration = chrono::duration_cast<chrono::minutes>( t2 - t1 ).count();
    cout << "Decryption completed in: " << duration << " minutes" << endl;
    
    cout << "Message decrypted as the following string: " << message << endl;
    
    cout << "Mission accomplished" << endl;
    
    return 0;
}
