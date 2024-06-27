#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cctype>
enum class Token{};
int main(int argsc, char **file){
#define SPACE 0x20
#define FILENAME *(file + 1)
    if (argsc > 2 || argsc <= 1){
        std::cout << "incorrect number of arguments\n";
        exit(1);
    };
    std::ifstream f{FILENAME, std::ios::in};
    std::stringstream buffer{};
    std::string filec;
    f.open(FILENAME);
    buffer << f.rdbuf();
    filec = buffer.str();
    int i = 0;
    while (filec.c_str()[i]){
        char current_char = filec.c_str()[i];
        if (current_char == (char)SPACE){
            std::cout << "space\n";
        }
        i++;
        std::cout << current_char;
    };
    f.close();
};