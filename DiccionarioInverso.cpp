#include "DiccionarioInverso.h"
#include "Palabra.h"
#include "indice.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

void DiccionarioInverso::inicializarInverso(std::string rutaArchivo) {
  std::ifstream myfile(rutaArchivo);
  std::string linea;
  int contador = 0;

  if (!myfile.is_open()) {
    cout << "El archivo no existe" << endl;

  } else if (diccionarioInversoInicializado) {
    cout << "El archivo inverso ya fue ejecutado" << endl;
  }

  if (myfile.is_open() && !diccionarioInversoInicializado) {
    contador = 0;

    while (getline(myfile, linea)) {

      for (char c : linea) {
        // 65-90,97-122
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        } else {
          contador++;
        }
      }
      int encontro = 0;

      if (contador == 0) {
        // aqui se invierte

        linea = invertirPalabra(linea);

        list<indice>::iterator it;
        for (it = indices.begin(); it != indices.end(); it++) {

          if (linea[0] == it->getLetra()) { // toupper

            it->agregarPalabra(linea);
            encontro++;
          }
        }
        if (encontro == 0) {
          indice i(linea[0]); // toupper se maneja desde el constructor
          i.agregarPalabra(linea);
          indices.push_back(i);
        }

        diccionarioInversoInicializado = true;
      }
    }
    cout << "El diccionario inverso se ha inicializado correctamente." << endl;
    myfile.close();
    // impresion:
    /*
    list<indice>::iterator it;
    for(it=indices.begin();it!=indices.end();it++){
        cout<<"\n indice: "<<it->getLetra()<<endl;
        vector<Palabra>aux = it->getPalabras();
        for(Palabra p: aux){
            cout<<p.getPalabra()<<endl;
        }
    }
    */
  }
}
string DiccionarioInverso::invertirPalabra(std::string pal) {
  stack<char> pila;
  for (char c : pal) {
    pila.push(c);
  }
  string lineaAux = "";
  string aux;
  while (!pila.empty()) {
    aux = pila.top();
    lineaAux = lineaAux + aux;
    pila.pop();
  }
  return lineaAux;
}

bool DiccionarioInverso::puntajePalabra(std::string palabra) {
  list<indice>::iterator it;
  for (it = indices.begin(); it != indices.end(); it++) {
    vector<Palabra> aux = it->getPalabras();
    for (Palabra p : aux) {
      if (p.getPalabra() == palabra) {
        cout << "la palabra contien un valor de ";
        cout << p.calcularPuntaje() << endl;
        return true;
      }
    }
  }
  return false;
}

bool DiccionarioInverso::getDiccionarioInversoInicializado() {
  return diccionarioInversoInicializado;
}

bool DiccionarioInverso::getArbolInverso () {
  return arbolInverso;
}

 
// funciones de arbol
bool DiccionarioInverso::llenarArbol(std::string file) {
  std::ifstream myfile(file);
  std::string linea;
  int sirve = 0;

 
  if(!myfile.is_open()){
      cout<<"El archivo "<<file<<" no existe o no puede ser leido "<<endl;

  }else if (arbolInverso){
      cout<<"El árbol del diccionario inverso ya ha sido inicializado."<<endl;

  } 
 

  if (myfile.is_open() && !arbolInverso) {
    
    sirve = 0;
    llenarArbol();
    while (getline(myfile, linea)) {

      for (char c : linea) {
        // 65-90,97-122
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        } else {
            sirve++;
        }
      }
      

      if (sirve == 0) {
        // aqui se invierte
        linea = invertirPalabra(linea);
        linea = minuscula(linea);
        string aux;
        char inicial=linea[0];
        aux+=inicial;
        arb.insertarNodo(aux, linea);
      }
    }
    myfile.close();
    arbolInverso = true;
    cout<<"El árbol del diccionario inverso se ha inicializado correctamente."<<endl;
    return true;
  }
  return false;
}
void DiccionarioInverso::llenarArbol() {
  for (int i = 0; i < 26; i++) {
    string letra;
    char p = 97 + i;
    letra += p;
    arb.insertarNodo("#", letra);
  }
}
bool DiccionarioInverso::arbolLleno(){
  if(arb.subArbol().size()==0)
    return false;
  else
    return true;
}
void DiccionarioInverso::imprimirArbol(){
  arb.preOrden();
}
string DiccionarioInverso::minuscula(string pal){
  char aux;
  string auxi;
  for(char c:pal){
    aux=tolower(c);
    auxi+=aux;
  }
  return auxi;
}



bool  DiccionarioInverso::sufijo(string suf){
  bool bandera = false; 
  suf=invertirPalabra(suf);
  list<string>aux;
  arb.presufijo(suf,aux);
  for(string p:aux){
    p=invertirPalabra(p);
    cout<<"palabra: "<<p<<" puntaje: "<<puntaje(p)<<" tamano: "<<p.size()<<endl;
    bandera = true; 
  }
  if (bandera){
    return true; 
  }else{
    return false;
  }
}
bool DiccionarioInverso::prefijo(string pre){
  bool bandera = false; 
  list<string>aux;
  arb.presufijo(pre,aux);
  for(string p:aux){
    
    cout<<"palabra: "<<p<<" puntaje: "<<puntaje(p)<<" tamano: "<<p.size()<<endl;
    bandera = true; 
  }
  if (bandera){
    return true; 
  }else{
    return false;
  }
}


int DiccionarioInverso::puntaje(string pal){
  Palabra p(pal);
  
  return p.calcularPuntaje();
}