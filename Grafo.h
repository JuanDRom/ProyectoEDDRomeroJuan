#ifndef GRAFO_H
#define GRAFO_H

#include <algorithm>
#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Grafo {
private:
  struct Nodo {
    string valor;
    std::list<Nodo *> adyacentes;
    Nodo(string val) : valor(val) {}
  };

  list<Nodo *> nodos;
  void destruir(Nodo *&nodo);
  unsigned int altura(Nodo *nodo);
  unsigned int tamano(Nodo *nodo);
  void preOrden(Nodo *nodo);
  void posOrden(Nodo *nodo);
  void nivelOrden(Nodo *nodo);

public:
  Grafo();
  Grafo(string val);
  Grafo(const Grafo &arbol);
  ~Grafo();
  bool esVacio();
  list<Nodo *> obtenerNodos();
  void addNodo(string val);
  Grafo &operator=(const Grafo &arbol);
  Nodo *buscarNodo(string val);
  void addConexion(string origen, string destino);
  void verificarConexiones();
  bool similares(string a, string b);
  bool esAdyacente(Nodo *a, Nodo *b);
  void imprimirGrafo() const ;

};
#endif // GRAFO_H