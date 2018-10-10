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
   long double realNumber = fabs(givenRealNumber);
   
   // extract integer part of the given number
   long long integerPart = trunc(realNumber);   
   double rest;
   string valueToDisplay;
   
   while (integerPart != 0) {
     rest = double(integerPart % basis);
     
     valueToDisplay = DIGITS[(char)rest] + valueToDisplay;
     integerPart /= basis;  
   }
   valueToDisplay += '.';

   //Conversion de la partie decimale ; 
   //Extraction de la partie decimale ; 

   long double decimal = realNumber - trunc(realNumber);
   
   for (unsigned i = 0; i < precision ; i++){
     decimal *= basis; 
     //Extraction de la partie Enitere apres chaques mulitplication 
     int numberToConvert = (int)decimal;
     
     decimal -= numberToConvert;

     valueToDisplay += DIGITS[numberToConvert];
   }
   
   valueToDisplay = givenRealNumber < 0 ? "-" + valueToDisplay : valueToDisplay;
   //affichage 
   cout << givenRealNumber << " en base " << basis;
   cout << " s'ecrit " << valueToDisplay << " avec "<< precision << " chiffres"
     << " apres la virgule" << endl; 

  
   return EXIT_SUCCESS;
}