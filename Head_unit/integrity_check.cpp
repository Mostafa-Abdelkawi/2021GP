#include"integrity_check.h"


void integrity_check (std::string file_name_zip)
{
    Decompress_Directory(file_name_zip);


    std::size_t found = file_name_zip.find_last_of(".");
    std::string DIR_NAME =file_name_zip.substr(0,found);
    std::string comand="rm -r "+DIR_NAME;

    std::string md = "md5sum -c md.cs >file2.txt";

    std::string md_1;

    md_1=system(md.c_str());
    std::fstream file;
    file.open("file2.txt",std::ios::in);
    if(file.is_open())
    {
        while(getline(file,md))
        {
            if(md.substr(md.length()-2 )=="OK")
            {

            }
            else
            {
                std::cout<<"integrity filed"<<std::endl;
                /*
                    to do:
                        get the name of the corrupted file and send its name to the server
                        then server reply with that file and then put it in the package
                */
                exit(1);
            }

        }
        std::cout<<"integrity ok"<<std::endl;
        file.close();
        md_1=system("rm file2.txt");
        md_1=system("rm md.cs");
        system(comand.c_str());
    }
}



static void Decompress_Directory(std::string file_name)
{
    std::string md_1;
    std::string in_file =file_name;
    std::ifstream f (in_file,std::ios::binary);
    Poco::File f1("./");
    Poco::Path p1 =f1.path();
    Poco::Zip::Decompress decompressor(f, p1);
    decompressor.decompressAllFiles();
    std::cout <<std::endl<< "Decompression Done!" <<std::endl;
    f.close();
}


