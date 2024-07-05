#pragma once
//
//  constants.h
//  test
//
//  Created by Sergey Snitsaruk on 04.07.2024.
//
#include <string>

namespace dict {
//params
    const std::string p_COMMAND_ = "-m"; //command for execute
    const std::string p_FILE_ =    "-f"; //file name
    const std::string p_WORD_ =    "-v"; //search word

//commands
    const std::string c_WORD_ =     "word"; //return count of word
    const std::string c_CHECKSUM_ = "checksum"; //return checksum
    const std::string c_HELP_ =     "-h"; //return help document


}
