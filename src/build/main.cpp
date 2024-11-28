/*
 * Copyright (c) build 2024
 * Written by ghgltggamer
 * Check the LICENSE file for Licensing info
 * Check out the README.md file for more information
 */
// Source starts from here
#include <iostream>
#include <fstream>
#include <string>

#define UNIDEF "unidef-23192192838912245578234347856"

class Parser {
public:
    std::string line;

    std::string parse(const std::string& key, const std::string& spacer = "=") {
        std::string value;
        std::string search_key = key + spacer;
        size_t key_pos = line.find(search_key);

        if (key_pos != std::string::npos) {
            value = line.substr(key_pos + search_key.length());
        } else {
            value = UNIDEF;
        }

        return value;
    }
};

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "Error: Path to build directory not provided.\n";
        return 1;
    }

    std::string path_to_build = argv[1];
    std::ifstream project_nautix(path_to_build + "/project.nautix");

    if (!project_nautix.is_open()) {
        std::cerr << "Error: File '" << path_to_build + "/project.nautix"
                  << "' not found or could not be opened.\n";
        return 1;
    }

    std::cout << "Parsing your project...\n";

    Parser parser;
    std::string temp;

    // Variables to store parsed values
    std::string COMMENT = UNIDEF, PROJECT_NAME = UNIDEF, PROJECT_VERSION = UNIDEF,
                PROJECT_COMPILER = UNIDEF, PROJECT_MAIN_FILE = UNIDEF,
                PROJECT_BIN_DIR = UNIDEF, PROJECT_MAIN_FILE_OUTPUT = UNIDEF,
                PROJECT_COMPILER_ARGS, PROJECT_LINK_FILES, EXECUTE_PROJECT=UNIDEF, BIN_TYPE = UNIDEF;

    while (std::getline(project_nautix, temp)) {
        parser.line = temp;

        // Update tokens only if the parsed value is not UNIDEF
        std::string value;

        value = parser.parse("#");
        if (value != UNIDEF) {COMMENT = value;continue;}

        value = parser.parse("project-name");
        if (value != UNIDEF) {PROJECT_NAME = value;continue;}

        value = parser.parse("project-version");
        if (value != UNIDEF) {PROJECT_VERSION = value;continue;}

        value = parser.parse("project-compiler");
        if (value != UNIDEF) {PROJECT_COMPILER = value;continue;}

        value = parser.parse("project-bin-directory");
        if (value != UNIDEF) {PROJECT_BIN_DIR = value;continue;}

        value = parser.parse("project-compiler-arguments");
        if (value != UNIDEF) {PROJECT_COMPILER_ARGS = value;continue;}

        value = parser.parse("project-main-file");
        if (value != UNIDEF) {PROJECT_MAIN_FILE = value;continue;}

        value = parser.parse("project-main-output-file");
        if (value != UNIDEF) {PROJECT_MAIN_FILE_OUTPUT = value;continue;}

        value = parser.parse("project-link-cpp");
        if (value != UNIDEF) {PROJECT_LINK_FILES = value;continue;}

        value = parser.parse("execute-project");
        if (value != UNIDEF) {EXECUTE_PROJECT = value;continue;}

        value = parser.parse("project-bin-type");
        if (value != UNIDEF) {BIN_TYPE = value;continue;}
    }

    // Display parsed values
   //  std::cout << "Project Name: " << PROJECT_NAME << "\n";
   //  std::cout << "Version: " << PROJECT_VERSION << "\n";
   //  std::cout << "Compiler: " << PROJECT_COMPILER << "\n";
   //  std::cout << "Compiler Args: " << PROJECT_COMPILER_ARGS << "\n";
   //  std::cout << "Binary Directory: " << PROJECT_BIN_DIR << "\n";
   //  std::cout << "Main File: " << PROJECT_MAIN_FILE << "\n";
   //  std::cout << "Main Output File: " << PROJECT_MAIN_FILE_OUTPUT << "\n";
   if (PROJECT_COMPILER == "gcc" || PROJECT_COMPILER == "g++"){
    PROJECT_COMPILER = "g++";
   }
   else if (PROJECT_COMPILER == "clang" || PROJECT_COMPILER == "clang++"){
    PROJECT_COMPILER = "clang++";
   }
   else {
    std::cout<<"A valid project compiler must be given use clang or gcc instead\n";
   }

   // build
    std::string command = "mkdir " + PROJECT_BIN_DIR + "\n"
                          "clear\n"
                          "echo compiling...\n"
                          "echo \"\"\n"
                          + PROJECT_COMPILER + " " + PROJECT_MAIN_FILE + " " + PROJECT_LINK_FILES + " -o " + PROJECT_BIN_DIR + "/" + PROJECT_MAIN_FILE_OUTPUT + " " + PROJECT_COMPILER_ARGS + "\n"
                          ;
    if (EXECUTE_PROJECT == "true"){
      command += "echo Attempting to run the project\n./" + PROJECT_BIN_DIR + "/" + PROJECT_MAIN_FILE_OUTPUT + "\n";
    }
    else if (EXECUTE_PROJECT == "false"){

    }
    else {
      std::cout<<"Error: execute-project can be only set to true or false\n";
    }


    if (BIN_TYPE == "temp"){
      if (EXECUTE_PROJECT == "true"){
         command += "rm -rf " + PROJECT_BIN_DIR + "/" + PROJECT_MAIN_FILE_OUTPUT + "\n";
      }
      else {
         std::cout<<"Error: Temp binaries can be only created if execute project is true\n";
      }
    }
    else if (BIN_TYPE == "perm"){

    }
    else {
      std::cout<<"Error: binary type can only be temp or perm\n";
    }

    std::system(command.c_str());
   //  std::cout<<command;
    std::cout<<"\n[program finished]\n";

    

    return 0;
}
