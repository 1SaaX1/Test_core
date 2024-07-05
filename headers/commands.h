#pragma once
//  commands.h
//  test
//
//  Created by Sergey Snitsaruk on 05.07.2024.
//
#ifndef commands_h
#define commands_h


#include <map>
#include "resources.h"
#include "constants.h"

namespace cmd{

    class Icommands {
    public:
        using list_params = std::unordered_map<std::string, std::string>;
        virtual void execute(list_params& params) = 0;
        virtual ~Icommands(){};
    };
    class find_word final : public Icommands {
    public:
        void execute(list_params& params) override;
        size_t search (std::ifstream& fs, const std::string& word);
    };
    class checksum final : public Icommands {
    public:
        void execute(list_params& params) override;
        size_t calc_checkSum (std::ifstream& fs);
    };
    struct help final : Icommands{
        void execute(list_params& params) override;
    };




    class Dictionary final {
    private:
        using u_map_c = const std::unordered_map<std::string, Icommands*>;
        //commands buffer
       static const std::unordered_map<std::string, Icommands*> command_buf;
       static std::unordered_map<std::string,std::string> param_buf;
        
    public:
        Dictionary(){}
        Dictionary(const Dictionary&) = delete;
        Dictionary& operator=(const Dictionary&) = delete;
        ~Dictionary(){
        }

        const   std::unordered_map<std::string, Icommands*>& get_c();
                std::unordered_map<std::string,std::string>& get_p();
    };
} //end namespace
#endif
