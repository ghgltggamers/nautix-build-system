/*

 * Copyright (c) ghgltggamer 2024
 * Nautix build system
 * Written by ghgltggamer
 * Protected under the MIT License
 * Checkout the LICENSE file for more information
 * Checkout the README.md file for more information about the project
 * Checkout the GitHub repository for latest available source code
 * Contributing? So checkout the .md file according to that
 * The source code comes with absolutely no warranty
 * Modifications are allowed for any use purpose until it's ethical

*/

// Source starts from here
// Including the headerfiles for project

// define the project if not defines
#ifndef NAUTIX
#define NAUTIX 11101 // define nautic with a unique key

// STL
#include <iostream>
#include  <fstream>
#include   <string>
#include    <cmath>

// Custom
#include "nautix_rt_init.hpp"

// main function
int main(int argc, char* argv[]){
    if (argc > 1){
        std::string argument = argv[1];
        // version check
        if (argument == "--version"){
            std::cout<<"SCNN NAUTIX 1.0\n";
        }
        else if (argument == "--doc"){
            std::cout<<R"(----------------------doc nautix------------------------
             1.) --version : Tell you the version of NAUTIX
             2.) --doc     : Shows you the documentation via your CLI
             3.) --new     : Create a new project with project name and path by "--new [your project name] [path to your project]"
             4.) build[bin]: Build your project with path to it self by using "--build [path to your project]"
             
             ---------------------doc nautix ends here--------------------
             )";
        }
        else if (argument == "--new"){
            if (argc > 1){
                std::string project_name = argv[2], project_path = argv[3];
                std::cout<<"Checking if the project can be created or not!";
                std::string project_file_path = project_path+"/project.nautix";
                std::ofstream project_file(project_file_path);
                std::ifstream project_file_input(project_file_path);
                std::string bin = "mkdir " + project_path + "/bin\n"
                                  "mkdir " + project_path + "/nautix-rt/";
                std::system(bin.c_str());

                if (project_file_input.is_open()){ // Project can be created here
                    std::cout<<"Your project can be created here.\n"
                               "Initalising yout nautix file\n";
                    project_file<<"# This is the nautix file for " + project_name + 
                                  "\n# Better to refer the documentation for writting nautix file if you need, Othervise leave this file to be default it will work more\n"
                                  "project-name="+project_name+"\n"
                                  "project-version=1.0\n"
                                  "project-compiler=gcc\n"
                                  "project-main-file=main.cpp\n"
                                  "project-bin-directory=bin\n"
                                  "project-main-output-file=main\n"
                                  "# temprorary binaries are those who will be deleted after program is being executed and perm binaries are those which will exist ever after project is done, So play with the setting bellow accordingly\n"
                                  "project-bin-type=temp\n"
                                  "# Uncomment the line bellow if want to parse any arguments for compiler, these will be placed in between file name and -o flag by nautix\n"
                                  "# project-compiler-arguments="
                                  "# Uncomment the line bellow if want to parse any additional file for linking\n"
                                  "# project-link-cpp=\n"
                                  "execute-project=true\n";
                    std::ofstream main_cpp(project_path+"/main.cpp");
                    std::ofstream header_hpp(project_path+"/"+project_name+".h");
                    std::ofstream configure_nautix_rt(project_path+"/configure-nautix-rt");
                    main_cpp<<"/*\n"
                              " * Copyright (c) " + project_name + " 2024\n"
                              " * Written by [authorname]\n"
                              " * Check the LICENSE file for Licensing info\n"
                              " * Check out the README.md file for more information\n"
                              " */\n"
                              "// Source\n"
                              "#ifndef MAIN\n"
                              "#define MAIN 101010111\n"
                              "#include \""+project_name+".h\"\n\n"
                              "int main(int argc, char* argv[]){\n"
                              "   std::cout<<\"Example program is running\";\n"
                              "   return 0;\n"
                              "}\n"
                              "#endif";
                    header_hpp<<"/*\n"
                              " * Copyright (c) " + project_name + " 2024\n"
                              " * Written by [authorname]\n"
                              " * Check the LICENSE file for Licensing info\n"
                              " * Check out the README.md file for more information\n"
                              " */\n"
                              "// Source starts from here\n"
                              "#ifndef MAIN_HEADER\n"
                              "#define MAIN_HEADER 11110101\n"
                              "#include <iostream>\n"
                              "#include   <string>\n"
                              "#include  <fstream>\n"
                              "#include   <vector>\n"
                              "#include    <cmath>\n"
                              "#endif";
                    std::ofstream nautix_rt(project_path + "/nautix-rt/build.cpp");
                    nautix_rt<<build_cpp;
                    configure_nautix_rt<<"g++ -o build nautix-rt/build.cpp";

                              std::cout<<"Successfully created a new project!\n";
                }   
                else {
                    std::cout<<"The path for project creation is wrong, So the project can't be created here\n";
                }
            }
            else {
                std::cout<<"NAUTIX Err -----> Required arguments for --new can't be set to empty\n";
            }
        }
    }
    else {
        std::cout<<"NAUTIX Requires at least 1 CLI argument use '--doc' for checking argument docs\n";
    }
    return 0;
}

#endif