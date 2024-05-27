#include "DiccionarioInverso.h"
#include "Diccionarios.h"
#include "Palabra.h"
#include "indice.h"
#include <iostream>
#include <sstream>

using namespace std;
int main() {

  Diccionarios sistema1; // aqui se crea la instancia sistema
  DiccionarioInverso sistema2;
  string linea; // donde se guarda las lineas
  string comando;
  string argumento;
  string otro = "";

  cout << ":'######:::'######::'########:::::'###::::'########::'########::'##:"
          "::::::'########:"
       << endl;
  cout << "'##... ##:'##... ##: ##.... ##:::'## ##::: ##.... ##: ##.... ##: "
          "##::::::: ##.....::"
       << endl;
  cout << " ##:::..:: ##:::..:: ##:::: ##::'##:. ##:: ##:::: ##: ##:::: ##: "
          "##::::::: ##:::::::"
       << endl;
  cout << ". ######:: ##::::::: ########::'##:::. ##: ########:: ########:: "
          "##::::::: ######:::"
       << endl;
  cout << ":..... ##: ##::::::: ##.. ##::: #########: ##.... ##: ##.... ##: "
          "##::::::: ##...::::"
       << endl;
  cout << "'##::: ##: ##::: ##: ##::. ##:: ##.... ##: ##:::: ##: ##:::: ##: "
          "##::::::: ##:::::::"
       << endl;
  cout << ". ######::. ######:: ##:::. ##: ##:::: ##: ########:: ########:: "
          "########: ########:"
       << endl;
  cout << ":......::::......:::..:::::..::..:::::..::........:::........:::...."
          "....::........::"
       << endl;

  cout << "\n\nBienvenido al sistema de apoyo para Scrabble" << endl << endl;
  cout << "Escriba ayuda para ver la lista de comandos disponibles o ingrese "
          "ayuda seguido del nombre del comando para obtener informacion sobre "
          "el"
       << endl;

  while (true) {
    cout << "\n$";
    getline(cin, linea);
    istringstream stream(linea);
    stream >> comando;

    // no se puede usar un switch case con string entonces toca con if or else
    // if

    if (comando == "salir") {
      break;
    }
    stream >> argumento;
    stream >> otro;
    if (otro != "") {
      cout << "El comando " << comando
           << " solo puede llevar maximo un argumento " << endl;
      otro = "";
    } else if (comando == "ayuda") {
      sistema1.ayuda(argumento);
    } else if (comando == "inicializar") {
      sistema1.inicializarDiccionario(argumento);
    } else if (comando == "iniciar_inverso") {
      sistema2.inicializarInverso(argumento);
    } else if (comando == "puntaje") {
      if (sistema1.getDiccionarioInicializado() &&
          sistema2.getDiccionarioInversoInicializado()) {
        if (!sistema1.puntajePalabra(argumento)) {
          if (!sistema2.puntajePalabra(argumento)) {
            cout << "la palabra no existe en el diccionario" << endl;
          }
        }
      } else {
        if (!sistema1.getDiccionarioInicializado())
          cout << "El diccionario no ha sido inicializado" << endl;
        if (!sistema2.getDiccionarioInversoInicializado())
          cout << "El diccionario inverso no ha sido inicializado" << endl;
      }
    } else if (comando == "iniciar_arbol") {
      sistema1.llenarArbol(argumento);
      // sistema1.imprimirArbol();

    } else if (comando == "iniciar_arbol_inverso") {
      sistema2.llenarArbol(argumento);
      // sistema2.imprimirArbol();
    } else if (comando == "palabras_por_sufijo") {
      bool b1 = false;
      bool b2 = false;

      if (sistema1.getArbolInicializado()) {
        b1 = sistema1.sufijo(argumento);
      }
      if (sistema2.getArbolInverso()) {
        b2 = sistema2.sufijo(argumento);
      }
      if (b1 == false && b2 == false) {
        cout << "Sufijo " << argumento
             << " no pudo encontrarse en el diccionario" << endl;
      }

    } else if (comando == "palabras_por_prefijo") {
      bool bandera1 = true;
      bool bandera2 = false;
      if (sistema1.getArbolInicializado()) {
        bandera1 = sistema1.prefijo(argumento);
      }
      if (sistema2.getArbolInverso()) {
        bandera2 = sistema2.prefijo(argumento);
      }
      if (bandera1 == false && bandera2 == false) {
        cout << "Prefijo " << argumento
             << " no pudo encontrarse en el diccionario" << endl;
      }
      bandera1 = true;

    } else if (comando == "grafo_de_palabras") {
      sistema1.llenarGrafo(argumento);
    } else if (comando == "posibles_palabras") {
      sistema1.encontrar_palabras(argumento);
    } else {
      cout << "Comando no reconocido." << endl;
    }
    argumento = "";
    otro = "";
  }

  return 0;
}
