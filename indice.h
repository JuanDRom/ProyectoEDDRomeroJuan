#ifndef INDICE_H
#define INDICE_H

#include <vector>
#include <string>
#include "Palabra.h" // Incluye la definición de la clase Palabra

class indice {
private:
    char letra;
    std::vector<Palabra> palabras;
    std::vector<Palabra> palabrasInversas;

public:
    char getLetra();
    std::vector<Palabra>getPalabras();
    indice(char letra);
    void agregarPalabra(std::string p);
};

#endif // DICCIONARIOS_H


