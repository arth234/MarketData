#include <cstdlib>
#include <ctime>
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
 
  size_t limit; 

  capital = 10000;
  while(true)
  {
    srand(time(0));  

    loadCandles();
    engolfoAlta = RisingEngulfing(3);
  
    limit = rand() % 10;

    size_t a = limit;    

    engolfoBaixa = DownEngulfing(3);

    for(size_t x = 0; x < a; x++)
    {
      if(i.Volatility(x) == i.Volatility(x))
      {
        retorno = 0;   
      }
    }
    if(engolfoAlta)
    {
      retorno = Return(3);
      balance++;

      networth = capital + (100000* (retorno));
        
      cout << "volatilidade:" << i.Volatility(10) << 
      " engolfo resultado financeiro << " << networth << endl;
    }

    if(engolfoBaixa)
    {
      retorno = Return(3);
      
      if(retorno < 0)
      {
        retorno = abs(Return(3));
        balance++; 

        networth = capital + (100000* (retorno));
        
        cout << "volatilidade:" << i.Volatility(10) << 
        " engolfo resultado financeiro << " << networth << endl;
      }

      if(retorno > 0)
      {
        retorno = -(Return(3));

        networth = capital + (100000* (retorno));
        
        cout << "volatilidade:" << i.Volatility(10) << 
        " engolfo resultado financeiro << " << networth << endl;
      }
    }      
  }

  return 0;
}
