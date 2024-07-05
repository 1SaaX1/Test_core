//
//  commands.cpp
//  test
//
//  Created by Sergey Snitsaruk on 05.07.2024.
//
#include "commands.h"

using namespace cmd;

void find_word::execute(list_params& params) {
    //res::fileHandle fh(("/Users/saax/TestApp/C++/test/test/Test.tst"));
    res::fileHandle fh(params[dict::p_FILE_]);
    std::cout   << "count of word '" << params[dict::p_WORD_] <<"' = "
                <<find_word::search(fh(),params[dict::p_WORD_]) <<"\n";
}
    
size_t find_word::search (std::ifstream& fs, const std::string& word){
    
    using it = std::istream_iterator<std::string>; //define short type
    //expression for skip dot and comma, if word will be ending at these punctuation mark
    auto is_correct = [word](std::string s_word) {
        return s_word == word || s_word == (word + ".") || s_word == (word + ",");
    };
    int word_count = 0; // count of reiteration words
    
    if (fs.fail()) fs.clear(); //check stream for I/O Error and clear it
        
    fs.seekg(0, std::ios::beg); //set the position at the begin

    //looking for word in the file
    while(std::find_if(it(fs), it(), is_correct) != it()) word_count++;

    return word_count;
}

void checksum::execute( list_params& params) {
    //res::fileHandle fh("/Users/saax/TestApp/C++/test/test/Test.tst");
    res::fileHandle fh(params[dict::p_FILE_]);
    std::cout << "checksum = " << checksum::calc_checkSum(fh()) <<"\n";
    
}
    size_t checksum::calc_checkSum (std::ifstream& fs){
        const int BYTES = 4; //32x bit
        size_t size = 0; //count of 32x bit words
        
        if (fs.fail()) fs.clear(); //check stream for I/O Error and clear it
            
        fs.seekg(0,std::ios::end); //set the position at the end
        size = fs.tellg(); // reading file size
        
        if (size == 0) return 0;
            
        if  (size % BYTES != 0)   size = (size / BYTES) + 1; //calculate count of 32x bit words
        else size /= BYTES;
        
        return size;
    }


void help::execute(list_params& params) {
    std::cout <<"Allow parameters:\n"
    << "-m : command for execution, ex.  -m word\n"
    << "-f : file name, ex. -f Test.tst\n"
    << "-v : search word, ex. -v hello\n\n"
    << "Allow commands:\n"
    << "word : return count of word [-v] in file, ex. -m word -f Test.tst -v hello\n"
    << "checksum : return checksum of 32bit words in file, ex. -m checksum, -f Test.tst\n\n";
}

using u_map_c = const std::unordered_map<std::string, cmd::Icommands*>;
//commands buffer
u_map_c Dictionary::command_buf {
    {dict::c_WORD_,new(find_word)},
    {dict::c_CHECKSUM_,new(checksum)},
    {dict::c_HELP_,new(help)}
};

using u_map_p = std::unordered_map<std::string,std::string>;
// params buffer
u_map_p Dictionary::param_buf {
    {dict::p_FILE_,""}, //file name
    {dict::p_WORD_,""}, //search word
    {dict::p_COMMAND_,""} //command for execute
};

const   u_map_c& Dictionary::get_c(){return Dictionary::command_buf;}
        u_map_p& Dictionary::get_p(){return Dictionary::param_buf;}


