#ifndef H_TRANSLATE
#define H_TRANSLATE

#include <vector>
#include <iostream>
#include <memory>
#include "../structure/mors.h"
#include "../defs/definition_importer.h"

class translate{
public:
    /* 
    TO BE IMPLEMENTED / INEFFICIENT
    Large amounts of morse code will take a long time and/or crash.
    */
    static std::string MLetterToString(const std::vector<std::shared_ptr<MLetter>>& Letters);
};

#endif