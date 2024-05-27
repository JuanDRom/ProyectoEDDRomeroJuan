#include "indice.h"
#include "Palabra.h"
indice::indice(char letra){
    this->letra=letra;
}
void indice::agregarPalabra(std::string p){
    Palabra pl(p);
    palabras.push_back(pl);
}
char indice::getLetra(){
    return letra;
}
std::vector<Palabra> indice::getPalabras(){
    return palabras;
}