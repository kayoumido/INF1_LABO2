/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo2 
 Fichier     : main.cpp
 Auteur(s)   : Doran Kayoumi , Soulaymane Lamrani , Wènes Limem
 Date        : 09.10.2018

 But         : Réaliser un programme permettant à un utilisateur de saisir 
               un nombre en base 10 
               ainsi qu'une autre base (allant jusqu'à la base 36) 
               et d'obtenir en retour son nombre converti dans la base fournie.

 Remarque(s) : On suppose la saisie utilisateur correcte.

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
   const string DIGITS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   
   long long givenIntegerNumber;
   unsigned basis;

   // ask for user input. 
   // number to convert, base to convert to.
   cout << "Entrez un nombre entier" << endl; 
   cin >> givenIntegerNumber;
   
   cout << "Entrez une base" << endl; 
   cin >> basis;
   
   // get absolute value
   long long integerNumber = (int)trunc(abs(givenIntegerNumber));
   
   int remainder;
   string convertedInteger;
   
   while (integerNumber != 0) {
      remainder = (int)integerNumber % basis;

      convertedInteger = DIGITS[(char)remainder] + convertedInteger;
      integerNumber /= basis;  
   }
   // check if the given integer was negative.
   // if so, a "-" is added before the converted number.
   convertedInteger = givenIntegerNumber < 0 
           ? "-" + convertedInteger : convertedInteger;
   
   cout << givenIntegerNumber << " en base " << basis 
        << " s'ecrit " << convertedInteger << endl;

   return EXIT_SUCCESS;
}
