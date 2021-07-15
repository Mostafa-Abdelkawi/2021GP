#ifndef GET_SWC_H
#define GET_SWC_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <bits/stdc++.h>
#include <dirent.h>
#include <sys/stat.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace pt = boost::property_tree;


void Get_Swc(std::string path, std::vector<std::string> &dirs_inside_parent, std::vector<std::string> &files_inside_parent, 
		std::vector<std::string> &swc_names, std::vector<std::string> &version);


#endif 
