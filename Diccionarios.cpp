#include "Diccionarios.h"
#include "Palabra.h"
#include "indice.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <stack>
#include <string> 
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

void Diccionarios::inicializarDiccionario(std::string rutaArchivo) {
  std::ifstream myfile(rutaArchivo);
  std::string linea;
  int contador = 0;

  if (!myfile.is_open()) {
    cout << "El archivo no existe" << endl;

  } else if (diccionarioInicializado) {
    cout << "El archivo ya fue ejecutado" << endl;
  }

  if (myfile.is_open() && !diccionarioInicializado) {
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

        list<indice>::iterator it;
        for (it = indices.begin(); it != indices.end(); it++) {
          linea[0] = toupper(linea[0]);
          if (linea[0] == it->getLetra()) { // toupper

            it->agregarPalabra(linea);
            encontro++;
          }
        }
        if (encontro == 0) {
          linea[0] = toupper(linea[0]);
          indice i(linea[0]); // toupper se maneja desde el constructor
          i.agregarPalabra(linea);
          indices.push_back(i);
        }

        diccionarioInicializado = true;
      }
    }
    cout << "El diccionario se ha inicializado correctamente." << endl;

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
bool Diccionarios::puntajePalabra(std::string palabra) {

  for (char c : palabra) {
    // 65-90,97-122
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    } else {
      cout << "La palabra contiene símbolos inválidos." << endl;
      return true;
    }
  }

  palabra[0] = toupper(palabra[0]);
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

bool Diccionarios::getDiccionarioInicializado() {
  return diccionarioInicializado;
}

bool Diccionarios::getArbolInicializado() { return arbolInicializado; }

// Muestra al usuario los comandos disponibles y los explica
void Diccionarios::ayuda(string x) {

  if (x == "") {
    cout << endl << endl << " Los comandos disponibles son: " << endl << endl;
    cout << "\tinicializar" << endl;
    cout << "\tiniciar_inverso" << endl;
    cout << "\tpuntaje" << endl;
    cout << "\tiniciar_arbol" << endl;
    cout << "\tiniciar_arbol_inverso" << endl;
    cout << "\tpalabras_por_prefijo" << endl;
    cout << "\tpalabras_por_sufijo" << endl;
    cout << "\tgrafo_de_palabras" << endl;
    cout << "\tposibles_palabras" << endl;
    cout << "\tayuda" << endl;
    cout << "\tsalir" << endl;
  }

  else if (x == "inicializar")
    cout << "Inicializa el sistema a partir del archivo de texto que contiene "
            "el diccionario en idioma ingles. Ejemplo: inicializar "
            "diccionario.txt "
         << endl;

  else if (x == "iniciar_inverso")
    cout << "Inicializa el sistema a partir del archivo de texto que contiene "
            "el diccionario en idioma ingles pero con las palabras invertidas. "
            "Ejemplo: iniciar_inverso diccionario.txt "
         << endl;

  else if (x == "puntaje")
    cout << "Retorna el puntaje de una palabra. Ejemplo: puntaje palabra"
         << endl;

  else if (x == "iniciar_arbol")
    cout << "Inicializa el sistema a partir del archivo de texto que contiene "
            "el diccionario en idioma ingles y lo almacena en forma de arbol. "
            "Ejemlo: iniciar_arbol diccionario.txt"
         << endl;

  else if (x == "iniciar_arbol_inverso")
    cout << "Inicializa el sistema a partir del archivo de texto que contiene "
            "el diccionario en idioma ingles pero con las palabras invertidas "
            "y lo almacena en forma de arbol. Ejemlo: iniciar_arbol_inverso "
            "diccionario.txt"
         << endl;

  else if (x == "palabras_por_prefijo")
    cout << "Presenta una lista de todas las palabras que empiezan con un "
            "determinado prefijo. Ejemplo: palabras_por_prefijo pre"
         << endl;

  else if (x == "palabras_por_sufijo")
    cout << "Presenta una lista de todas las palabras que terminan con un "
            "determinado sufijo. Ejemplo: palabras_por_sufijo ing"
         << endl;

  else if (x == "grafo_de_palabras")
    cout << "Construye un grafo con las palabras en el arbol en dodne cada "
            "palabra se conecta a las demas si y solo si difieren en una unica "
            "letra"
         << endl;

  else if (x == "posibles_palabras")
    cout << "Presenta una lista de todas las palabras que pueden ser "
            "construidas a partir de una cadena de caracteres. Ademas se "
            "permite el uso de un comodin (?) que representa una lestra "
            "desconocida para generar mayores posibilidades de palabras. "
            "Ejemplo: posibles_palabras ho?l"
         << endl;

  else if (x == "ayuda")
    cout << "Muestra la lista de comandos disponibles. Si se especifica un "
            "comando, muestra la descripcion de este. Ejemplo: ayuda puntaje"
         << endl;

  else if (x == "salir")
    cout << "Termina la ejecucion del programa." << endl;

  else
    cout << "El comando no existe." << endl;
}

// funciones de arbol
bool Diccionarios::llenarArbol(std::string file) {
  std::ifstream myfile(file);
  std::string linea;
  int sirve = 0;

  if (!myfile.is_open()) {
    cout << "El archivo " << file << " no existe o no puede ser leido " << endl;

  } else if (arbolInicializado) {
    cout << "El árbol del diccionario ya ha sido inicializado." << endl;
  }

  if (myfile.is_open() && !arbolInicializado) {

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
        linea = minuscula(linea);
        string aux;
        char inicial = linea[0];
        aux += inicial;
        arb.insertarNodo(aux, linea);
      }
    }
    myfile.close();
    arbolInicializado = true;
    cout << "El árbol del diccionario se ha inicializado correctamente" << endl;
    return true;
  }
  return false;
}
void Diccionarios::llenarArbol() {
  for (int i = 0; i < 26; i++) {
    string letra;
    char p = 97 + i;
    letra += p;
    arb.insertarNodo("#", letra);
  }
}
bool Diccionarios::arbolLleno() {
  if (arb.subArbol().size() == 0)
    return false;
  else
    return true;
}
void Diccionarios::imprimirArbol() { arb.preOrden(); }
string Diccionarios::minuscula(string pal) {
  char aux;
  string auxi;
  for (char c : pal) {
    aux = tolower(c);
    auxi += aux;
  }
  return auxi;
}
string Diccionarios::invertirPalabra(std::string pal) {
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
bool Diccionarios::sufijo(string suf) {
  bool bandera = false;
  suf = invertirPalabra(suf);
  list<string> aux;
  arb.presufijo(suf, aux);
  for (string p : aux) {
    p = invertirPalabra(p);
    cout << "palabra: " << p << " puntaje: " << puntaje(p)
         << " tamano: " << p.size() << endl;
    bandera = true;
  }
  if (bandera) {
    return true;
  } else {
    return false;
  }
}

bool Diccionarios::prefijo(string pre) {
  bool bandera = false;
  list<string> aux;
  arb.presufijo(pre, aux);
  for (string p : aux) {
    cout << "palabra: " << p << " puntaje: " << puntaje(p)
         << " tamano: " << p.size() << endl;
    bandera = true;
  }
  if (bandera) {
    return true;
  } else {
    return false;
  }
}
int Diccionarios::puntaje(string pal) {
  Palabra p(pal);

  return p.calcularPuntaje();
}

bool Diccionarios::llenarGrafo(std::string file) {
  std::ifstream myfile(file);
  std::string linea;
  int sirve = 0;

  if (!myfile.is_open()) {
    cout << "El archivo " << file << " no existe o no puede ser leido " << endl;

  } else if (arbolInicializado) {
    cout << "El grafo del diccionario ya ha sido inicializado." << endl;
  }

  if (myfile.is_open() && !grafoInicializado) {

    sirve = 0;
    while (getline(myfile, linea)) {

      for (char c : linea) {
        // 65-90,97-122
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        } else {
          sirve++;
        }
      }

      if (sirve == 0) {
        linea = minuscula(linea);
        string aux;
        char inicial = linea[0];
        aux += inicial;
        grafo.addNodo(linea);
      }
    }
    myfile.close();
    grafo.verificarConexiones();
    grafoInicializado = true;
    cout << "El Grafo del diccionario se ha inicializado correctamente" << endl;
    return true;
  }
  
  return false;
}

bool Diccionarios:: letrasValidas(const std::string &letras) {
  for (char c : letras) {
      if (!std::isalpha(c) && c != '?') {
          return false;
      }
  }
  return true;
}

bool Diccionarios:: es_palabra_valida(const std::string &palabra) {
  for (auto nodo : grafo.obtenerNodos()) {
      if (nodo->valor == palabra) {
        cout<<nodo->valor<<endl;
          return true;
      }
  }
  return false;
}

/*void Diccionarios:: generar_combinaciones(const std::string &letras, std::vector<std::string> &combinaciones, std::string current ="", size_t pos = 0) {
  if (pos == letras.size()) {
      if (!current.empty()) {
          combinaciones.push_back(current);
      }
      return;
  }

  if (letras[pos] == '?') {
      for (char c = 'a'; c <= 'z'; ++c) {
          generar_combinaciones(letras, combinaciones, current + c, pos + 1);
      }
  } else {
      generar_combinaciones(letras, combinaciones, current + letras[pos], pos + 1);
  }

  generar_combinaciones(letras, combinaciones, current, pos + 1); // Skip the current letter
}
*/

/*void Diccionarios::encontrar_palabras(const std::string &letras) {
  std::vector<std::string> combinaciones;
  generar_combinaciones(letras, combinaciones);

  std::unordered_set<std::string> palabras_encontradas;

  for (const std::string &combinacion : combinaciones) {
      std::string sorted_comb = combinacion;
      std::sort(sorted_comb.begin(), sorted_comb.end());

      do {
          if (es_palabra_valida(sorted_comb)== true && palabras_encontradas.find(sorted_comb) == palabras_encontradas.end()) {
              Palabra palabra(sorted_comb);
              int puntuacion = palabra.calcularPuntaje();
              palabras_encontradas.insert(sorted_comb);
              std::cout << "Palabra: " << sorted_comb << ", Longitud: " << sorted_comb.length() << ", Puntuación: " << puntuacion << std::endl;
          }
      } while (std::next_permutation(sorted_comb.begin(), sorted_comb.end()));
  }
}*/
void Diccionarios::encontrar_palabras(const std::string& letras) {
    std::unordered_set<std::string> palabras_encontradas;

    // Lambda recursiva para generar todas las combinaciones de letras
    auto generar_combinaciones = [&](const std::string& palabra, const std::string& letras_restantes, auto& ref) -> void {
        if (!palabra.empty() && es_palabra_valida(palabra)) {
            palabras_encontradas.insert(palabra);
        }
        for (size_t i = 0; i < letras_restantes.size(); ++i) {
            std::string nueva_palabra = palabra + letras_restantes[i];
            std::string nuevas_letras_restantes = letras_restantes.substr(0, i) + letras_restantes.substr(i + 1);
            ref(nueva_palabra, nuevas_letras_restantes, ref);
        }
    };

    generar_combinaciones("", letras, generar_combinaciones);

    // Imprimir las palabras encontradas con su puntuación
    for (const auto& palabra : palabras_encontradas) {
        Palabra palabra2 = Palabra(palabra);
        int puntuacion = palabra2.calcularPuntaje();
        std::cout << "Palabra: " << palabra << ", Longitud: " << palabra.length() << ", Puntuación: " << puntuacion << std::endl;
    }
}
