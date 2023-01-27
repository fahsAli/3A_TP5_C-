#pragma once
#ifndef ENIGMA_HEADER
#define ENIGMA_HEADER
#include <string>
#include <cctype>
#include "encrypt.h"

namespace enigma{
    class Enigma : public encrypt::Encrypt{
        public:
            Enigma(std::string key1,std::string txt);

            std::string key() const;

            void encode() override;
            void decode() override;


        private:
            std::string _key1;
    };
    void moveKey(std::string& key);
    std::string moveBackKey(std::string key,int shift);
    std::string generateKey();
    bool duplicatedChar(std::string str,char c);
}

#endif