#ifndef ARBOL_GENERAL_H
#define ARBOL_GENERAL_H

#include <list>
#include <stdexcept>
using namespace std;
class Arbol {
private:
  struct Nodo {
    string valor;
    std::list<Nodo *> hijos;
    Nodo(string val) : valor(val) {}
  };

  Nodo *raiz;
  void copiar(const Nodo *nodo, Nodo *&nuevo);
  void destruir(Nodo *&nodo);
  Nodo *buscarNodo(string n, Nodo *nodo);
  unsigned int altura(Nodo *nodo);
  unsigned int tamano(Nodo *nodo);
  void preOrden(Nodo *nodo);
  void posOrden(Nodo *nodo);
  void nivelOrden(Nodo *nodo);
public:
  Arbol();
  Arbol(string val);
  Arbol(const Arbol &arbol);
  ~Arbol();
  std::list<Arbol> subArbol();
  bool esVacio();
string obtenerRaiz();
  void fijarRaiz(string val);
  Arbol &operator=(const Arbol &arbol);
  bool insertarNodo(string padre, string n);
  bool buscar(string n);
  unsigned int altura();
  unsigned int tamano();
  unsigned int orden();
  void preOrden();
  void posOrden();
  void nivelOrden();
  void presufijo(string presuf,list<string>&pal);
};
#endif // ARBOL_GENERAL_H