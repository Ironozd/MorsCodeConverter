#ifndef H_MORS_IMPL
#define H_MORS_IMPL

#include <iostream>
#include <vector>
#include <memory>

class MChar
{
public:
    MChar() {}
    MChar(std::string data) { Data = data; }
    std::string getData() { return Data; }

private:
    std::string Data;
};

class MLetter
{
public:
    MLetter() {}
    MLetter(std::vector<std::shared_ptr<MChar>> chars) { mChars = chars; }
    std::vector<std::shared_ptr<MChar>> getCharacters() { return mChars; }

    std::string rCharacters();

    static bool isEqualTo(const std::shared_ptr<MLetter> &a, const std::shared_ptr<MLetter> &b)
    {
        if (a->getCharacters().size() != b->getCharacters().size()) return false;
        int count = 0;
        for (int i = 0; i < a->getCharacters().size(); i++)
        {
            if (a->getCharacters().at(i)->getData() == b->getCharacters().at(i)->getData()) count++;
        }
        if (count == a->getCharacters().size()) return true;
        return false;
    }

private:
    std::vector<std::shared_ptr<MChar>> mChars;
};

#endif