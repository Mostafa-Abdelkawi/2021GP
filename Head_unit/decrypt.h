#ifndef DECRYPT_H
#define DECRYPT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ios>
#include <vector>

#include "cryptopp/modes.h"
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"
#include <iterator>


typedef unsigned char BYTE;



std::vector<BYTE> readFile(std::string filename);
void aes_decrypt(std::string path);



#endif 
