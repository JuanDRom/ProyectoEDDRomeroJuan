#include "Palabra.h"
#include <cctype>

Palabra::Palabra(std::string word) {
    this->word=word;
    puntaje = 0;
}
std::string Palabra::getPalabra(){
    return word;
}



int Palabra::getPuntaje(){
    return puntaje;
    
}
int Palabra::calcularPuntaje(){

  for (char c: word){
      c=toupper(c);
    switch (c){
      case 'E':
      case 'A':
      case 'I':
      case 'O':
      case 'N':
      case 'R':
      case 'T':
      case 'L':
      case 'S':
      case 'U':

        puntaje +=1;
        break;
      case 'D':
      case 'G':
        puntaje +=2;
        break; 
      case 'B':
      case 'C':
      case 'M':
      case 'P':
        puntaje +=3;
        break; 
      case 'F':
      case 'H':
      case 'V':
      case 'W':
      case 'Y':
        puntaje +=4;
        break; 
      case 'K':
        puntaje +=5; 
        break; 
      case 'J':
      case 'X':
        puntaje += 8;
        break; 
      case 'Q':
      case 'Z':
        puntaje += 8;
        break; 
      default:
        break; 
      
    }
  }
  return puntaje;
}