/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo2 
 Fichier     : main.cpp
 Auteur(s)   : Doran Kayoumi , Soulaymane Lamrani , Wènes Limem
 Date        : 09.10.2018

 But         : Convertisseur d'entier vers n'importe quelle base. [1-36]

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