#ifndef DICCIONARIOS_H
#define DICCIONARIOS_H

#include "Arbol.h"
#include "Grafo.h"
#include "indice.h"
#include <list>
#include <string>
#include <vector>

class Diccionarios {
private:
  bool diccionarioInicializado = false;
  bool arbolInicializado = false;
  bool grafoInicializado = false;
  std::list<indice> indices;
  Arbol arb;
  Grafo grafo;

public:
  void inicializarDiccionario(std::string rutaArchivo);
  bool puntajePalabra(std::string palabra);
  bool getDiccionarioInicializado();
  void ayuda(std::string x);
  // funciones de arbol
  bool getArbolInicializado();
  void llenarArbol();
  bool llenarArbol(std::string file);
  bool arbolLleno();
  void imprimirArbol();
  string minuscula(string pal);
  bool prefijo(string pre);
  bool sufijo(string suf);
  string invertirPalabra(string pal);
  int puntaje(string pal);
  // funciones del grafo
  bool getGrafoIncializado();
  bool llenarGrafo(string file);
  bool es_palabra_valida(const std::string &palabra);
  void encontrar_palabras(const std::string &letras);
 

 
};

#endif // DICCIONARIOS_H
