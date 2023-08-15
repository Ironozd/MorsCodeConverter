#include "definition_importer.h"

void MDefImporter::ImportDefinitionsImpl(){
    std::ifstream defFile("D:\\GitRepos\\mors\\src\\defs\\defs.txt");
    if(!defFile.is_open())
    {
        std::cout << "MDefImporter::ImportDefinition:: Failed to load definition.\n";
    }

    std::string str;
    std::string token;

    while(std::getline(defFile, str))
    {
        std::istringstream iss(str);
        while(std::getline(iss, token, '|')) {
            std::string Character = token;
            std::getline(iss, token, '|');
            std::vector<std::shared_ptr<MChar>> chars;
            for(char CH : token){
                chars.emplace_back(std::make_shared<MChar>(std::string(1,CH)));
            }
            std::shared_ptr<MLetter> letter;
            letter.reset(new MLetter(chars));
            Definitions.insert({Character, letter});
        }
    }
    defFile.clear();
    defFile.close();
    std::cout << "Imported " << Definitions.size() << " mors definitions.\n";
}
