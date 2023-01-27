#include "enigma2.h"

enigma2::Enigma2::Enigma2(std::string key1,std::string key2,std::string txt){
    _key1 = key1;
    _key2 = key2;
    _plain = txt;
}

bool enigma2::duplicatedChar(std::string str,char c){
    for(int i=0;i<str.length();i++){
        if(str[i]==c){
            return true;
        }
    }
    return false;
}

std::string enigma2::generateKey(){
    int let=0;
    char carc = 'a';
    std::string key="";
    for(int i=0;i<26;i++){
        let = std::rand()%26;
        carc = char(let+'a');
        
        while(enigma2::duplicatedChar(key,carc)){
            let = std::rand()%26;
            carc = char(let+'a');
        }

        key = key + carc;
    }
    return key;
}

void enigma2::moveKey(std::string& key){
    char front = key.front();
    key.erase(0,1);
    key = key + front;
}

std::string enigma2::moveBackKey(std::string key,int shift){
    char back;
    for(int i=0;i<shift;i++){
        back = key.back();
        key.erase(key.length()-1);
        key = back + key;
    }
    return key;
}

int enigma2::realLength(std::string str){
    int cpt=1;
    for(int i=0;i<str.length();i++){
        if(std::isalpha(str[i])){
            cpt++;
        }
    }
    return cpt;
}

std::string enigma2::Enigma2::key1() const{
    return _key1;
}

std::string enigma2::Enigma2::key2() const{
    return _key2;
}

void enigma2::Enigma2::encode(){
    char c;
    int pos=0,cpt=1;
    std::string rotor1="";
    _cipher = "";
    for(int i=0;i<_plain.length();i++){
        if(std::isalpha(_plain[i])){
            c = std::tolower(_plain[i]);
            pos = c - 'a';
            rotor1 = rotor1 + _key1[pos];
            enigma2::moveKey(_key1);
        }else{
            rotor1 = rotor1 + _plain[i];
        }
    }

    for(int i=0;i<rotor1.length();i++){
        if(std::isalpha(rotor1[i])){
            c = std::tolower(rotor1[i]);
            pos = _key2.find(rotor1[i]);
            pos = pos + 'a';
            _cipher = _cipher + char(pos);
            cpt++;
            if(cpt==26){
                enigma2::moveKey(_key2);
                cpt=1;
            }
        }else{
            _cipher = _cipher + rotor1[i];
        }
    }
}

void enigma2::Enigma2::decode(){
    char c;
    int pos=0,cpt=1,rpos=0;
    std::string key1="",key2="",rotor2="";
    _plain = "";

    key2=enigma2::moveBackKey(_key2,enigma2::realLength(_cipher)/26);
    //key2 = _key2;

    for(int i=0;i<_cipher.length();i++){
        if(std::isalpha(_cipher[i])){
            pos = _cipher[i]-'a';
            rotor2 = rotor2 + key2[pos];
            cpt++;
            if(cpt%26==0){
                enigma2::moveKey(key2);
            }
        }else{
            rotor2 = rotor2 + _cipher[i];
        }
    }

    cpt = 1;
    pos = 0;

    for(int i=0;i<rotor2.length();i++){
        if(std::isalpha(rotor2[rotor2.length()-1-i])){
            key1 = enigma2::moveBackKey(_key1,cpt);
            pos = key1.find(rotor2[rotor2.length()-1-i]);
            pos = pos + 'a';
            _plain = char(pos) + _plain;
            pos = 0;
            cpt++;
        }else{
            _plain = rotor2[rotor2.length()-1-i] + _plain;
        }
    }
}