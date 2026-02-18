
#include <iostream>
#include <chrono>
#include <thread>
#include "OpenDB.h"
#include "INDEX.h"
#include "engulfing.h"
#include "return.h"
#include "ConstConcepts.h"

using namespace std;

int main()
{
  Concepts i;

  bool engolfoAlta;
  bool engolfoBaixa;  

  double capital;
  double networth;
  double balance;
  double retorno;

  capital = 10000.000000000;
  while(true)
  {
    loadCandles();
    engolfoAlta = RisingEngulfing(3);

    engolfoBaixa = DownEngulfing(3);

    if(engolfoAlta)
    {
      retorno = Return(3);
      balance++;
    }

    if(engolfoBaixa)
    {
      retorno = Return(3);
      
      if(retorno < 0)
      {
        retorno = abs(Return(3));
        balance++; 
      }

      if(retorno > 0)
      {
        retorno = -(Return(3));
      }
    }
    networth = capital + (100000* (retorno));

    cout << "engolfo " << "saldo:"
    << networth << endl; 
  }

  return 0;
}
