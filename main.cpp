/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo2 
 Fichier     : main.cpp
 Auteur(s)   : Doran Kayoumi , Soulaymane Lamrani , Wènes Limem
 Date        : 09.10.2018

 But         : Réaliser un programme permettant à un utilisateur de saisir 
               un nombre en base 10 
               d'une autre base (allant jusqu'à 36) 
               ainsi qu'une valeur pour la précision
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
   
   string convertedDecimal;
   // extract the decimal portion of the number
   long double decimal = givenRealNumber - trunc(givenRealNumber);
   long double numberToConvert;
   
   for (unsigned i = 0; i < precision ; i++) {
        decimal *= basis;

        // extract integer part
        numberToConvert = trunc(decimal);
        decimal -= numberToConvert;
        
        // check if we're at the last iteration and the round is equal to 1
        // this is done so we can round up the number.
        //
        // There's a big(ish) issue with this method is that values like :
        //     1.999 with a wanted precision of 2 converts the number to 2.90 which 
        //     is incorrect. 
        if(i == precision - 1 && round(decimal) == 1){
            numberToConvert += 1;
            
            // if the round is higher than the basis, then the number needs to be 
            // increased and not the decimal
            if (numberToConvert >= basis) {
                givenRealNumber++;
                numberToConvert = 0;
            }
        }

        convertedDecimal += DIGITS[(char)numberToConvert];
   }
   
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
   
   long double quotient = 0;
   string convertedNumber;
   // convert given number into the chosen basis
   //    to do this, we start by dividing the the chosen number with 
   //    the basis highest power, then we decrement until we reach a power of 0.
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
   
   convertedNumber = givenRealNumber < 0 ? "-" + convertedNumber : convertedNumber;   
   // display results
   cout << givenRealNumber << " en base " << basis;
   cout << " s'ecrit " << convertedNumber << convertedDecimal
        << " avec "<< precision << " chiffre"
        << (precision > 1 ? "s" : "") << " apres la virgule" << endl; 

  
   return EXIT_SUCCESS;
}