#ifndef PACKING_H
#define PACKING_H


#include <fstream>
#include <vector>
#include <iterator>
#include <assert.h>
#include <unistd.h>
#include <iostream>


			typedef unsigned char BYTE;
			using ByteVectorType = std::vector<BYTE>;

			ByteVectorType packedfile(const char* filename);
			void unpackedfile(const char* filename, ByteVectorType & byteVector);

#endif
