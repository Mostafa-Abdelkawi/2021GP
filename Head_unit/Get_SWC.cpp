#include "Get_SWC.h"



void Get_Swc(std::string path, std::vector<std::string> &dirs_inside_parent, std::vector<std::string> &files_inside_parent, 
																		std::vector<std::string> &swc_names, std::vector<std::string> &version)
{
	std::string cluster_path ;
	std::string cluster_path_1 ;
	int a1 =::chdir(path.c_str());
	
	//std::vector<std::pair<std::string,std::int>> inside_directory;
	DIR* dirp = opendir(path.c_str());
    struct dirent * dp;
    //looping through the directory
    while ((dp = readdir(dirp)) != NULL)
    {
        if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") )
        {
             // do nothing (straight logic)
        }
        else
        {
            //fill the vector with names and types of each item
			if(dp->d_type == 4)
			{
				dirs_inside_parent.push_back(dp->d_name);
				cluster_path=path+"/"+dp->d_name;
				DIR* dirp_1 = opendir(cluster_path.c_str());
				struct dirent * dp_1;
				while ((dp_1 = readdir(dirp_1)) != NULL)
				{
					if ( !strcmp(dp_1->d_name, ".") || !strcmp(dp_1->d_name, "..") )
					{	
						// do nothing (straight logic)
					}
					else
					{
						if(dp_1->d_type == 4)
						{
							swc_names.push_back(dp_1->d_name);
							cluster_path_1=cluster_path+"/"+dp_1->d_name;
							DIR* dirp_2 = opendir(cluster_path_1.c_str());
							struct dirent* dp_2;
							while((dp_2=readdir(dirp_2)) != NULL)
							{
								if ( !strcmp(dp_2->d_name, ".") || !strcmp(dp_2->d_name, "..") )
								{	
									// do nothing (straight logic)
								}
								else 
								{
									if(dp_2->d_type == 4)
									{
										
									}
									else
									{
										std::string software_cluster ;
										std::string manifest_json ;
										manifest_json="_Manifest.json";
										software_cluster = dp_1->d_name+manifest_json;
										std::string manifest_path;
										if(dp_2->d_name == software_cluster)
										{
											manifest_path=cluster_path_1+"/"+software_cluster;
											pt::ptree root;
											pt::read_json(manifest_path , root);
											version.push_back(root.get<std::string>("version"));
										}
											
									}
								}
							}
							closedir(dirp_2);
							
						}

                        else
                        {
                            swc_names.push_back(dp->d_name);

                            std::string software_cluster ;
                            std::string manifest_json ;
                            manifest_json="_Manifest.json";
                            software_cluster = dp->d_name+manifest_json;
                            std::string manifest_path;
                            if(dp_1->d_name == software_cluster)
                            {
                                manifest_path=cluster_path+"/"+software_cluster;
                                pt::ptree root;
                                pt::read_json(manifest_path , root);
                                version.push_back(root.get<std::string>("version"));
                            }
                        }
                    }
				}
				closedir(dirp_1);
			}				
			else
			{
				files_inside_parent.push_back(dp->d_name);
			}
        }

    }
    //close the directory
    closedir(dirp);

	
	
}
