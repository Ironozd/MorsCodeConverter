#include <sstream>
#include <iostream>
#include <fstream>
#include "defs/definition_importer.h"
#include "translation/translate.h"


class FileToMors{
public:
    static std::vector<std::shared_ptr<MLetter>> ConvertFileToMors(std::string filePath);
};