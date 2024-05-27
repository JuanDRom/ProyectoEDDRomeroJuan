#ifndef PALABRA_H
#define PALABRA_H

#include <string>
#include <map>

class Palabra {
private:
    std::string word; // Guarda la palabra
    int puntaje; 

public:
    std::string getPalabra();
    Palabra(std::string word);
    int calcularPuntaje();
    int getPuntaje();
    
};

#endif // PALABRA_H


