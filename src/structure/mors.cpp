#include "mors.h"



std::string MLetter::rCharacters(){
    std::string morsLetter = "";

    for(auto CH : mChars){
        morsLetter.append(CH->getData());
    }

    return morsLetter;
}