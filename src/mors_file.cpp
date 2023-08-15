#include "mors_file.h"

LoadFile::LoadFile(std::string filePath){
    FilePath = filePath;
    std::ifstream cFile(filePath);
}


int main(int argc, char* argv[]){
    MDefImporter::ImportDefinitions();
    std::string filePath = "";
#ifndef MDEBUG
    if(argc == 0){
        std::cout << "Please enter a file path!\nUsage: .\\mors_file <file_path>";
        return 1;
    }

    filePath = argv[0];
#else
    filePath = "D:\\GitRepos\\mors\\ConvertMe.txt";
#endif
    return 0;
}