#ifndef DICCIONARIOINVERSO_H
#define DICCIONARIOINVERSO_H

#include <list>
#include <vector>
#include <string>
#include"indice.h"
#include"Arbol.h"

class DiccionarioInverso {
private:

    bool diccionarioInversoInicializado = false;
    bool arbolInverso = false; 
    std::list<indice>indices;
    Arbol arb;

public:
    void inicializarInverso(std::string rutaArchivo);// punto 1 Eduardo
    bool puntajePalabra( std::string palabra);//punto 3 Harry
    bool getDiccionarioInversoInicializado();
    //funciones de arbol
    bool getArbolInverso ();
    void llenarArbol();
    std::string invertirPalabra(std::string pal);
    bool llenarArbol(std::string file);
    bool arbolLleno();
    void imprimirArbol();
    string minuscula(string pal);
    bool sufijo(string suf);
    bool prefijo(string pre);
    int puntaje(string pal);
};

#endif // DICCIONARIOSINVERSO_H

