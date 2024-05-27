#include "Arbol.h"
#include <iostream>
using namespace std;
// Constructor por defecto
Arbol::Arbol() { raiz = new Nodo("#"); }

// Constructor con valor inicial para la raíz
Arbol::Arbol(string val) { raiz = new Nodo(val); }

// Constructor de copia
Arbol::Arbol(const Arbol&arbol) {
  copiar(arbol.raiz, raiz);
}

// Destructor
Arbol::~Arbol() { destruir(raiz); }

// Devuelve una lista de subárboles
std::list<Arbol> Arbol::subArbol() {
  std::list<Arbol
> subarboles;
  if (raiz != nullptr) {
    for (auto hijo : raiz->hijos) {
      Arbol
    subarbol;
      subarbol.raiz = hijo;
      subarboles.push_back(subarbol);
    }
  }
  return subarboles;
}

// Verifica si el árbol está vacío
bool Arbol::esVacio() { return raiz == nullptr; }

// Obtiene el valor de la raíz
string Arbol::obtenerRaiz() {
  if (raiz != nullptr)
    return raiz->valor;
  else
    throw std::runtime_error("El árbol está vacío");
}

// Establece el valor de la raíz
void Arbol::fijarRaiz(string val) {
  if (raiz != nullptr)
    raiz->valor = val;
  else
    raiz = new Nodo(val);
}

// Sobrecarga del operador de asignación
Arbol&Arbol::operator=(const Arbol&arbol) {
  if (this != &arbol) {
    destruir(raiz);
    raiz = nullptr;
    copiar(arbol.raiz, raiz);
  }
  return *this;
}
// Busca un valor en el árbol
bool Arbol::buscar(string n) { return buscarNodo(n, raiz) != nullptr; }

// Calcula la altura del árbol
unsigned int Arbol::altura() { return altura(raiz); }

// Calcula el tamaño del árbol
unsigned int Arbol::tamano() { return tamano(raiz); }

// Devuelve el orden del árbol
unsigned int Arbol::orden() {
  return raiz != nullptr ? raiz->hijos.size() : 0;
}

// Recorrido en preorden
void Arbol::preOrden() { preOrden(raiz); }

// Recorrido en postorden
void Arbol::posOrden() { posOrden(raiz); }

// Recorrido por niveles
void Arbol::nivelOrden() { nivelOrden(raiz); }

// Función privada para copiar un árbol
void Arbol::copiar(const Nodo *nodo, Nodo *&nuevo) {
  if (nodo == nullptr)
    nuevo = nullptr;
  else {
    nuevo = new Nodo(nodo->valor);
    for (auto hijo : nodo->hijos) {
      Nodo *nuevoHijo = nullptr;
      copiar(hijo, nuevoHijo);
      nuevo->hijos.push_back(nuevoHijo);
    }
  }
}
// Función privada para destruir un árbol
void Arbol::destruir(Nodo *&nodo) {
  if (nodo != nullptr) {
    for (auto hijo : nodo->hijos) {
      destruir(hijo);
    }
    delete nodo;
    nodo=nullptr;
  }
}
// Función privada para calcular la altura del árbol
unsigned int Arbol::altura(Nodo *nodo) {
  if (nodo == nullptr)
    return 0;
  unsigned int maxAltura = 0;
  // Función privada para calcular la altura del árbol (continuación)
  for (auto hijo : nodo->hijos) {
    unsigned int alturaHijo = altura(hijo);
    if (alturaHijo > maxAltura)
      maxAltura = alturaHijo;
  }
  return maxAltura + 1;
}

// Función privada para calcular el tamaño del árbol
unsigned int Arbol::tamano(Nodo *nodo) {
  if (nodo == nullptr)
    return 0;
  unsigned int totalNodos = 1;
  for (auto hijo : nodo->hijos) {
    totalNodos += tamano(hijo);
  }
  return totalNodos;
}

// Función privada para realizar un recorrido en preorden
void Arbol::preOrden(Nodo *nodo) {
  if (nodo != nullptr) {
    std::cout << nodo->valor << " ";
    for (auto hijo : nodo->hijos) {
      preOrden(hijo);
    }
  }
}

// Función privada para realizar un recorrido en postorden
void Arbol::posOrden(Nodo *nodo) {
  if (nodo != nullptr) {
    for (auto hijo : nodo->hijos) {
      posOrden(hijo);
    }
    std::cout << nodo->valor << " ";
  }
}

// Función privada para realizar un recorrido por niveles
void Arbol::nivelOrden(Nodo *nodo) {
  if (nodo == nullptr)
    return;
  std::list<Nodo *> nivelActual, siguienteNivel;
  nivelActual.push_back(nodo);
  while (!nivelActual.empty()) {
    for (auto nodo : nivelActual) {
      std::cout << nodo->valor << " ";
      for (auto hijo : nodo->hijos) {
        siguienteNivel.push_back(hijo);
      }
    }
    std::cout << std::endl;
    nivelActual = std::move(siguienteNivel);
  }
}
// Función privada para buscar un nodo con valor n en el árbol y devuelve un
// puntero a dicho nodo
Arbol::Nodo *Arbol::buscarNodo(string n, Nodo *nodo) {
  if (nodo == nullptr)
    return nullptr;
  if (nodo->valor == n)
    return nodo;
  for (auto hijo : nodo->hijos) {
    Nodo *encontrado = buscarNodo(n, hijo);
    if (encontrado != nullptr)
      return encontrado;
  }
  return nullptr;
}
// Inserta un nodo en el árbol
bool Arbol::insertarNodo(string padre, string n) {
  Nodo *nodoPadre = buscarNodo(padre, raiz);
  if (nodoPadre != nullptr) {
    nodoPadre->hijos.push_back(new Nodo(n));
    return true;
  }
  return false;
}

// Funcion que busca el presufijo en el arbol 
 void Arbol::presufijo(std::string presuf,list<string>&pal){
  string p;
   
  p+=presuf[0];
  Nodo *nodoPadre=buscarNodo(p, raiz);
  list<Nodo*>retorno = nodoPadre->hijos;
  for(Nodo* n:retorno){
    int contador=0;
    for(int i=0;i<presuf.size();i++){
      if(n->valor[i]==presuf[i]){
        contador++;
      }
    }
    if(contador==presuf.size()){
      pal.push_back(n->valor);
    }
  }
}