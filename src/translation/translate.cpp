#include "translate.h"

std::string translate::MLetterToString(const std::vector<std::shared_ptr<MLetter>>& Letters){
    std::string result = "";
    for(auto letter : Letters){
        int i = 0;
        for(auto def : MDefImporter::getDefinitions()){
            if(MLetter::isEqualTo(letter, def.second)){
                result.append(def.first);
            }else{
                i++;
            }
        }
        if(i == MDefImporter::getDefinitions().size()) result.append("*");
    }
    return result;
}