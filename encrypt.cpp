#include "encrypt.h"

std::string encrypt::Encrypt::plain() const{
    return _plain;
}

std::string encrypt::Encrypt::cipher() const{
    return _cipher;
}

void encrypt::Encrypt::read(){
    std::fstream file;
    std::string line="";
    _plain = "";
    file.open("plain.txt",std::ios::in);
    if(file.is_open()){
        while(std::getline(file,line)){
            _plain = _plain + line;
        }
    }
    file.close();
}

void encrypt::Encrypt::wrtie(){
    std::fstream file;
    file.open("cipher.txt", std::ios::out);
    if(file.is_open()){
        file << _cipher + "\n";
    }
    file.close();
}