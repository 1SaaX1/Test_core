//
//  resources.cpp
//  test
//
//  Created by Sergey Snitsaruk on 05.07.2024.
//
#include "resources.h"

using namespace res;
//return handle to file
fileHandle::fileHandle (std::string fileName) {
    //std::cout << "File opening\n";
    fs.open(fileName, std::ios::binary);
    
    if (!fs.is_open())  {
        std::cout << "File wasn't opened!\nProgramm terminated!\n";
        std::exit(1);
    }
}

    fileHandle::~fileHandle(){
        //std::cout << "File close\n";
        fs.close();
    }

        std::ifstream&  fileHandle::operator()(){
        //get handle for file
        return fs;
    }
