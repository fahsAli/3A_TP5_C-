#pragma once
#ifndef ENIGMA2_HEADER
#define ENIGMA2_HEADER

#include <string>
#include <cctype>
#include "encrypt.h"

namespace enigma2{
    class Enigma2 : public encrypt::Encrypt{
        public:
            Enigma2(std::string key1,std::string key2,std::string txt);

            std::string key1() const;
            std::string key2() const;

            void encode();
            void decode();

        private:
            std::string _key1;
            std::string _key2;
    };
    int realLength(std::string str);
    void moveKey(std::string& key);
    std::string moveBackKey(std::string key,int shift);
    std::string generateKey();
    bool duplicatedChar(std::string str,char c);
}

#endif