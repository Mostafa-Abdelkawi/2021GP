#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <assert.h>
#include <string.h>
#include "Packing_Unpacking.h"
ByteVectorType packedfile(const char* filename)
{
                // open the file:
                std::ifstream file(filename, std::ios::binary);

                // Stop eating new lines in binary mode!!!
                file.unsetf(std::ios::skipws);

                // get its size:
                std::streampos fileSize;

                file.seekg(0, std::ios::end);
                fileSize = file.tellg();
                file.seekg(0, std::ios::beg);

                // reserve capacity
                ByteVectorType vec;
                vec.reserve(fileSize);

                // read the data:
                vec.insert(vec.begin(),
                    std::istream_iterator<BYTE>(file),
                    std::istream_iterator<BYTE>());

                return vec;
}



void unpackedfile(const char* filename, ByteVectorType& byteVector)
{

                std::ofstream outfile(filename, std::ios::out | std::ios::binary| std::ofstream::app);
                outfile.write((const char*)&byteVector[0], byteVector.size());

                outfile.close();

}


