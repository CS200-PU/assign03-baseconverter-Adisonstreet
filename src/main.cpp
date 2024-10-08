//******************************************************************************
// File name:   main.cpp
// Author:      Adison Street
// Date:        9/22/2024 (Replace xx/xx/xxxx with month/day/year)
// Class:       CS200 
// Assignment:  BASECONVERTER
// Purpose:     convert different strings to different forms
// Hours:       10+
//******************************************************************************

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;
const string BIN = "0b";
const string HEX = "0x";
const string TITLE = "HEX-DECIMAL-BINARY CONVERTER";
const string PROMPT = "Enter your string to convert (q to quit): ";
const string BIN_CONV = "The binary conversion is: ";
const string DEC_CONV = "The decimal conversion is: ";
const string HEX_CONV = "The hexadecimal conversion is: ";

int hexCharToInt (char hexDigit);
char getBase (const string& strNumber);
string getNumber (const string& prompt); 
void printTitle (const string& myTitle); 
string binaryToDecimal (const string& strNumber); 
string decimalToBinary (const string& strNumber);
string decimalToHex (const string& strNumber);
string hexToDecimal (const string& strNumber);
string hexToBinary (const string& strNumber);
string binaryToHex (const string& strNumber);

int main () {
  string decimal, userInput;
  char base = ' ';
  printTitle(TITLE);
  userInput = getNumber(PROMPT);
  while(userInput != "q"){
    base = getBase(userInput);
    if(base == 'd'){
      cout << BIN_CONV << BIN << decimalToBinary(userInput) << endl;
      cout << HEX_CONV << HEX << decimalToHex(userInput) << endl;
    }else if(base == 'h'){
      cout << DEC_CONV << hexToDecimal(userInput) << endl;
      cout << BIN_CONV << BIN << hexToBinary(userInput) << endl;
    }else if(base == 'b'){
      cout << DEC_CONV << binaryToDecimal(userInput) << endl;
      cout << HEX_CONV << HEX << binaryToHex(userInput) << endl;
    }
    userInput = getNumber(PROMPT);
  }
  return EXIT_SUCCESS;
}
/*/////////////////////////////////////////////////////////////////

    function: hexCharToInt

    Purpose: change the char from the hex into an int

    parameters: hexDiigit 

    return int from hex 

/*/////////////////////////////////////////////////////////////////

int hexCharToInt (char hexDigit){
  int decimal = 0;
  if(hexDigit <= '9' && hexDigit >= '0'){
    decimal = static_cast<int>(hexDigit - '0');
  }else{
    decimal = static_cast<int>(hexDigit - '7');
  }
  return decimal;
}
/*/////////////////////////////////////////////////////////////////

    function: getBase

    Purpose: determine whether the string is Bin, hex, or decimal

    parameters: strNumber- the string from the user

    return char to represent what form the string is 

/*/////////////////////////////////////////////////////////////////

char getBase (const string& strNumber){
  char base = '\0';
  if(strNumber[0] == BIN[0] && strNumber[1] == BIN[1]){
    base = 'b';
  }else if(strNumber[0] == HEX[0] && strNumber[1] == HEX[1]){
    base = 'h';
  }else{
    base = 'd';
  }
  return base;
}
/*/////////////////////////////////////////////////////////////////

    function: getNumber

    Purpose: recieve a numbered string from the user or hex or binary yk

    parameters: prompt - displayed to the user to recieve data

    return: the users string

/*/////////////////////////////////////////////////////////////////

string getNumber (const string& prompt){
  string userString;
  cout << prompt;
  cin >> userString;
  return userString;
}
/*/////////////////////////////////////////////////////////////////

    function: printTitle

    Purpose: print the title to the screen

    parameters: myTitle

    return void

/*/////////////////////////////////////////////////////////////////

 void printTitle (const string& myTitle){
  cout << setfill('*') << setw(38) << "*" << endl;
  cout << setfill('*') << setw(5) << "*" << myTitle << 
          setfill('*') << setw(5) << "*" << endl;
  cout << setfill('*') << setw(38) << "*" << endl;
 }
/*/////////////////////////////////////////////////////////////////

    function: binaryToDecimal

    Purpose: convert the string from a binary to a decimal

    parameters: strNumber- the users string

    return: converted string

/*/////////////////////////////////////////////////////////////////

 string binaryToDecimal (const string& strNumber){
  int decimal = 0;
  int exponent = 0;
  int base = 2;
  int constant = 0;
  for(int i = strNumber.length()-1; i >= 2; i--){
    constant = strNumber[i] - '0';
    decimal += constant * static_cast<int>(pow(base, exponent));  
    exponent++;
    }
    return to_string(decimal);
 }
/*/////////////////////////////////////////////////////////////////

    function: decimalToBinary

    Purpose: convert the string from a decimal to a binary

    parameters: strNumber- the users string

    return: converted string

/*/////////////////////////////////////////////////////////////////

  string decimalToBinary (const string& strNumber){
    int number = stoi(strNumber);
    string binaryString;
    int binaryDigit;
    if(0 == number){
      binaryString = "0";
    }
    while(number != 0){
      binaryDigit = number % 2;
      number = number / 2;
      binaryString += to_string(binaryDigit);
    }
    reverse(binaryString.begin(), binaryString.end());
    return binaryString;
  }
 /*/////////////////////////////////////////////////////////////////

    function: decimalToHex

    Purpose: convert the string from a decimal to a hexadecimal

    parameters: strNumber- the users string

    return: converted string

/*/////////////////////////////////////////////////////////////////

  string decimalToHex (const string& strNumber){
    int length = stoi(strNumber);
    string hexString;
    char hexChar;
    int hexInt;

    if(length == 0){
      hexString = "0";
    }

    while(length != 0){
      hexInt = length % 16;
      if(hexInt <= 9){

        hexChar = hexInt + '0';
      }else{
        hexChar = hexInt + '7';
      }
      hexString += hexChar;
      length = length / 16;
    }
    reverse(hexString.begin(), hexString.end());
    return hexString;
  }
/*/////////////////////////////////////////////////////////////////

    function: hexToDecimal

    Purpose: convert the string from a hex to a decimal

    parameters: strNumber- the users string

    return: converted string

/*/////////////////////////////////////////////////////////////////

  string hexToDecimal (const string& strNumber){
    int decimal = 0;
    int constant;
    int exp = 0;

    for(int i = strNumber.size() - 1; i >= 2; i--){
      constant = hexCharToInt(strNumber[i]);

      decimal += constant * static_cast<int>(pow(16, exp));
      exp++;
    }
    return to_string(decimal);

  }
/*/////////////////////////////////////////////////////////////////

    function: hexToBinary

    Purpose: convert the string from a hex to a binary

    parameters: strNumber- the users string

    return: converted string

/*/////////////////////////////////////////////////////////////////

string hexToBinary (const string& strNumber){
  return decimalToBinary(hexToDecimal(strNumber));
}
/*/////////////////////////////////////////////////////////////////

    function: binaryToHex

    Purpose: convert the string from a binary to a hex

    parameters: strNumber- the users string

    return: converted string

/*/////////////////////////////////////////////////////////////////

 string binaryToHex (const string& strNumber){
  return decimalToHex(binaryToDecimal(strNumber));
 }