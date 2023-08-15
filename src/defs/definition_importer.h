#ifndef H_MDEF_IMPORTER
#define H_MDEF_IMPORTER

#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include "../structure/mors.h"

class MDefImporter{
public:
    static void ImportDefinitions() { Get().ImportDefinitionsImpl(); }

    static std::map<std::string, std::shared_ptr<MLetter>> getDefinitions() {return Get().Definitions;}
private:
    static MDefImporter& Get(){
        static MDefImporter importer;
        return importer;
    }
    void ImportDefinitionsImpl();
    std::map<std::string, std::shared_ptr<MLetter>> Definitions;
}; 

#endif