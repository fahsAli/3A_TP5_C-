#include "enigma.h"

enigma::Enigma::Enigma(std::string key1,std::string txt){
    _key1 = key1;
    _plain = txt;
    std::srand(time(0));
}

bool enigma::duplicatedChar(std::string str,char c){
    for(int i=0;i<str.length();i++){
        if(str[i]==c){
            return true;
        }
    }
    return false;
}

std::string enigma::generateKey(){
    int let=0;
    char carc = 'a';
    std::string key="";
    for(int i=0;i<26;i++){
        let = std::rand()%26;
        carc = char(let+'a');
        
        while(enigma::duplicatedChar(key,carc)){
            let = std::rand()%26;
            carc = char(let+'a');
        }

        key = key + carc;
    }
    return key;
}

void enigma::moveKey(std::string& key){
    char front = key.front();
    key.erase(0,1);
    key = key + front;
}

std::string enigma::moveBackKey(std::string key,int shift){
    char back;
    for(int i=0;i<shift;i++){
        back = key.back();
        key.erase(key.length()-1);
        key = back + key;
    }
    return key;
}

std::string enigma::Enigma::key() const{
    return _key1;
}

void enigma::Enigma::encode(){
    char c;
    int pos=0;
    _cipher = "";
    for(int i=0;i<_plain.length();i++){
        if(std::isalpha(_plain[i])){
            c = std::tolower(_plain[i]);
            pos = c - 'a';
            _cipher = _cipher + _key1[pos];
            enigma::moveKey(_key1);
        }else{
            _cipher = _cipher + _plain[i];
        }
    }
}

void enigma::Enigma::decode(){
    char c;
    int pos=0,cpt=1;
    std::string key;
    _plain = "";
    for(int i=0;i<_cipher.length();i++){
        if(std::isalpha(_cipher[_cipher.length()-1-i])){
            key = enigma::moveBackKey(_key1,cpt);
            pos = key.find(_cipher[_cipher.length()-1-i]);
            pos = pos + 'a';
            _plain = char(pos) + _plain;
            pos = 0;
            cpt++;
        }else{
            _plain = _cipher[_cipher.length()-1-i] + _plain;
        }
    }
}
