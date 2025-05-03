#include <iostream>
#include <string>

int main() {
    // 1) Dichiaro una std::string inizializzata
    std::string str = "HI THIS IS BRAIN";

    // 2) Creo un puntatore che punta a str
    std::string* stringPTR = &str;

    // 3) Creo un riferimento alla stessa str
    std::string& stringREF = str;

    // 4) print: indirizzi
    //    &str         → indirizzo di str
    //    stringPTR    → indirizzo memorizzato dal puntatore
    //    &stringREF   → indirizzo referenziato da stringREF (stessa di str)
    
    std::cout << "Address of str:        " << &str << std::endl;
    std::cout << "Address held by PTR:   " << stringPTR << std::endl;
    std::cout << "Address held by REF:   " << &stringREF << std::endl;

    // 5) Stampiamo i valori
    //    str           → il contenuto di str
    //    *stringPTR   → il contenuto a cui punta il puntatore (str)
    //    stringREF    → il valore referenziato (stessa str)
    std::cout << "Value of str:          " << str << std::endl;
    std::cout << "Value pointed by PTR:  " << *stringPTR << std::endl;
    std::cout << "Value referenced by REF: " << stringREF << std::endl;

    return 0;
}
