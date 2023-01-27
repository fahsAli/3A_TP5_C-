#include <iostream>
#include <string>
#include "encrypt.h"
#include "enigma.h"
#include "enigma2.h"


int main(){
    std::srand(time(0));
    // std::string key = enigma::generateKey();
    // std::string txt = "ali fahs";
    // enigma::Enigma e(key,txt);

    // std::cout << "key : " << key << std::endl;
    // e.encode();
    // std::cout << "cod : " << e.cipher() << std::endl;
    // std::cout << "key : " << e.key() << std::endl;
    // e.decode();
    // std::cout << "txt : " <<  e.plain() << std::endl;

    std::cout << "===============================================================\n\n";
    std::string key1 = enigma::generateKey();
    std::string key2 = enigma::generateKey();
    std::string txt = "hello i'm Ali from Esirem groupe tp 3";
    enigma2::Enigma2 e2(key1,key2,txt);
    std::cout << "key1 : " << key1 << std::endl;
    std::cout << "key2 : " << key2 << std::endl;
    e2.encode();
    std::cout << "txt : " << e2.plain() << std::endl;
    std::cout << "cod : " << e2.cipher() << std::endl;
    e2.decode();
    std::cout << "txt : " << e2.plain() << std::endl;
    std::cout << "===============================================================\n\n";
    e2.read();
    e2.encode();
    e2.wrtie();
    std::cout << "txt : " << e2.plain() << std::endl;
    std::cout << "cod : " << e2.cipher() << std::endl;
    e2.decode();
    std::cout << "txt : " << e2.plain() << std::endl;
    std::cout << "===============================================================\n\n";
    return 0;
}