#pragma once

//
//  resources.h
//  test
//
//  Created by Sergey Snitsaruk on 05.07.2024.
//
#include <iostream>
#include <fstream>

namespace res {
    //return handle to file
    class fileHandle final {
    private:
        std::ifstream fs;
        
        fileHandle(const fileHandle&) = delete;
        //fileHandle(fileHandle&&) = delete;
        fileHandle& operator=(const fileHandle&) = delete;
        //fileHandle& operator=(const fileHandle&&) = delete;
    public:
        fileHandle (std::string fileName);
        ~fileHandle();
        std::ifstream&  operator()();
    };
}
