#include "Grafo.h"
#include "Palabra.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// Constructor por defecto
Grafo::Grafo() { nodos = list<Nodo *>(); }

// Destructor
Grafo::~Grafo() { this->nodos.clear(); }

// Verifica si el grafo está vacío
bool Grafo::esVacio() { return this->nodos.empty(); }

// Obtiene la lista de nodos
list<Grafo::Nodo *> Grafo::obtenerNodos() { return this->nodos; }

// Establece el valor de un nodo
void Grafo::addNodo(string val) {
  Nodo *nodo = new Nodo(val);
  nodo->valor = val;
  this->nodos.push_back(nodo);
}

// Establece la conexión entre dos nodos
void Grafo::addConexion(string origen, string destino) {
  Nodo *nodoOrigen = this->buscarNodo(origen);
  Nodo *nodoDestino = this->buscarNodo(destino);
  nodoOrigen->adyacentes.push_back(nodoDestino);
}

Grafo::Nodo *Grafo::buscarNodo(string val) {
  for (Nodo *nodo : this->nodos) {
    if (nodo->valor == val) {
      return nodo;
    }
  }
  return nullptr;
}

void Grafo::verificarConexiones() {

  for (Nodo *a : this->nodos) {
    for (Nodo *b : this->nodos) {
      if (similares(a->valor, b->valor)) {
        if (!esAdyacente(a, b))
          addConexion(a->valor, b->valor);
        if (!esAdyacente(b, a))
          addConexion(b->valor, a->valor);
      }
    }
  }
}

bool Grafo::similares(string a, string b) {

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  const char *palabra1 = a.c_str();
  const char *palabra2 = b.c_str();

  int cont = 0;

  if (a.length() - b.length() > 1 || a.length() - b.length() < -1)
    return false;

  for (int i = 0; i < a.size(); i++) {
    if (palabra1[i] != palabra2[i]) {
      cont++;
    }
  }
  if (cont <= 1) {
    return true;
  } else
    return false;
}

bool Grafo::esAdyacente(Grafo::Nodo *a, Grafo::Nodo *b) {
  for (Nodo *nodo : a->adyacentes) {
    if (nodo == a)
      return true;
  }
  return false;
}

void Grafo::imprimirGrafo() const {
    for (Nodo* nodo : nodos) {
        cout << "Nodo: " << nodo->valor << " -> [ ";
        for (Nodo* adyacente : nodo->adyacentes) {
            cout << adyacente->valor << " ";
        }
        cout << "]" << endl;
    }
}
