#ifndef CHECK_SUM_H
#define CHECK_SUM_H
#include<iostream>
#include<fstream>
#include <unistd.h>
#include<Poco/File.h>
#include<Poco/Path.h>
#include<Poco/Zip/Decompress.h>
#include<Poco/Zip/Compress.h>

void integrity_check (std::string file_name_zip);
static void Decompress_Directory(std::string file_name);

#endif
