/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo2 
 Fichier     : main.cpp
 Auteur(s)   : Doran Kayoumi , Soulaymane Lamrani , Wènes Limem
 Date        : 09.10.2018

 But         : Convertisseur de entier/décimale vers n'importe quelle base

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
   
   long double givenRealNumber;
   unsigned basis;
   unsigned precision;

   // ask for user input. 
   // number to convert, base to convert to and the wanted precision
   cout << "Entrez un nombre réel" << endl; 
   cin >> givenRealNumber;
   
   cout << "Entrez une base" << endl; 
   cin >> basis;
   
   cout << "Entrez une precision" << endl; 
   cin >> precision; 
   
   // get absolute value
   long double realNumber = trunc(fabs(givenRealNumber));


   int power = 0;
   
   // find basis highest possible power within the given number
   // another solution we found was to use logarithms to find the highest power
   //    (int)trunc(log(realNumber)/log(basis));   
   //
   // the while condition is performed on the next power 
   //    since we know that the previous one is within the range. 
   //    Otherwise we'll be one over the max.
   while (pow(basis, power + 1) < realNumber) {
      power++;
   }
   
   // extract integer part of the given number
   long double quotient;
   string convertedNumber;
   
   // convert given number into the chosen basis
   //    to do this, we start by dividing the the chosen number with 
   //    with the basis highest power then we go done utile we reach a power of 0.
   //    e.g.: realNumber     = 4
   //          basis          = 2
   //          power          = 2
   //          4 / 2^2
   while (power >= 0) {
     quotient = trunc(realNumber / pow(basis, power));
     // find the equivalent digit.
     convertedNumber += DIGITS[(char)quotient];
     realNumber = realNumber - (quotient * pow(basis, power));
     power--;
   }
   // check if a precision is wanted
   if (precision > 0)
      convertedNumber += '.';

   // extract the decimal portion of the number
   long double decimal = givenRealNumber - trunc(givenRealNumber);
   
   for (unsigned i = 0; i < precision ; i++) {
     decimal *= basis;
     
     // extract integer part of decimal
     int numberToConvert = (int)decimal;
     
     decimal -= numberToConvert;

     convertedNumber += DIGITS[numberToConvert];
   }
   
   convertedNumber = givenRealNumber < 0 ? "-" + convertedNumber : convertedNumber;
   // display results
   cout << givenRealNumber << " en base " << basis;
   cout << " s'ecrit " << convertedNumber << " avec "<< precision << " chiffres"
     << " apres la virgule" << endl; 

  
   return EXIT_SUCCESS;
}