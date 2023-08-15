#include "mors_file.h"

std::vector<std::shared_ptr<MLetter>> FileToMors::ConvertFileToMors(std::string filePath){
    std::vector<std::shared_ptr<MLetter>> letters;
    std::ifstream mFile(filePath);

    std::string line;
    std::string token;
    
    while(std::getline(mFile, line)){
        std::istringstream iss(line);
        while(std::getline(iss, token, ' ')){
            std::vector<std::shared_ptr<MChar>> chars;
            for(auto CH : token){
                chars.emplace_back(std::make_shared<MChar>(std::string(1, CH)));
            }
            letters.emplace_back(std::make_shared<MLetter>(chars));
        }
    }
    mFile.clear();
    mFile.close();

    return letters;
}

int main(int argc, char* argv[]){
    MDefImporter::ImportDefinitions();
    std::string filePath = "";
#ifndef MDEBUG
    if(argc == 1){
        std::cout << "Please enter a file path!\nUsage: .\\mors_file <file_path>";
        return 1;
    }
    filePath = argv[1];
#else
    filePath = "D:\\GitRepos\\mors\\ConvertMe.txt";
#endif
    auto letters = FileToMors::ConvertFileToMors(filePath);
    std::cout << "Loaded " << letters.size() << " letters from file.\n";
    std::cout << "-------------------[ RESULT ]-----------------------\n";
    std::cout << translate::MLetterToString(letters) << std::endl;
    return 0;
}