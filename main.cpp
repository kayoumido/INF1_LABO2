/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo2 
 Fichier     : main.cpp
 Auteur(s)   : Doran Kayoumi , Soulaymane Lamrani , Wènes Limem
 Date        : 09.10.2018

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main() {
   // Déclaration des variables 
   long long entierAConvertir;
   long long entierAConvertirCopy;
   
   int base;
   int reste;
   
   string strReste;
   string strEntier;
   
   cout << "Entrez un nombre entier" << endl;
   cin >> entierAConvertir;
   cout << "Entrez une base" << endl; 
   cin >> base; 
   entierAConvertirCopy = entierAConvertir;
   while (entierAConvertirCopy != 0) {
      reste = entierAConvertirCopy % base;

      if (reste < 10) { //Pour les bases inférieurs a 10 
         strReste = '0' + reste;
      }
      else {
         strReste = reste - 10 + 'A';
      }
      strEntier = strReste + strEntier;

      entierAConvertirCopy /= base;  
   }
   cout << entierAConvertir << " en base " << base << " s'ecrit " << strEntier << endl;
   return EXIT_SUCCESS;
}