//
//  main.cpp
//  test
//
//  Created by Sergey Snitsaruk on 29.06.2024.
//


#include "headers/commands.h"

int main(int argc, const char * argv[]) {
    
    std::cout << "Test Core!\n";
    
    cmd::Dictionary dict;
   
    //exception help, execute help command
    if (argv[1] == dict::c_HELP_){
        dict.get_c().at(dict::c_HELP_)->execute(dict.get_p());
        std::exit(0);
    }
    //reading params from command line
    for (int i = 1; i< argc; ++i){
        if (argv[i][0] != '-') // if '-' it means not param, skip it
            continue;
        
        //reading params and args
        if (dict.get_p().contains(argv[i])) {
            if ((i+1) < argc && argv[i+1][0] != '-')
                dict.get_p()[argv[i]] = argv[i+1]; //save arg. if param was found
            else
                std::cout << "arg. for param "<< argv[i] << " not found \n";
        }
        else {
            std::cout << "param " << argv[i] << " not found \n";
            std::exit(2);
        }
    }
    
    //if command has found, execute it
    if (dict.get_c().contains(dict.get_p()[dict::p_COMMAND_])) {
        dict.get_c().at(dict.get_p()[dict::p_COMMAND_])->execute(dict.get_p());
    }
    else {
        std::cout << "Command "<< dict.get_p()[dict::p_COMMAND_] << " not found \n";
        std::exit(1);
    }
    
    return 0;
}
