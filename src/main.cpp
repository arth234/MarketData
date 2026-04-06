#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include "ConstConcepts.h"
#include "CandleServer.h"
#include "duckdb.hpp"

using namespace duckdb;
using Lock = std::lock_guard<std::mutex>;
int main(int argc, char *argv[])
{
  int port = std::stol(argv[1]);
  
  std::thread t(candleServer, port); 
  t.detach();

  std::string path;

  std::cout << "Where can i write the data:";
  std::cin >> path;  

  DuckDB dataFinance(path);
  Connection connect(dataFinance);

  connect.Query("CREATE TABLE a "
  "(id INTEGER PRIMARY KEY, value" 
  " DOUBLE PRECISION);"); 

  connect.Query("ALTER TABLE a ADD"
  "COLUMN volatility DOUBLE PRECISION;");
  connect.Query("ALTER TABLE a ADD"
  "COLUMN net DOUBLE PRECISION;");
  connect.Query("ALTER TABLE a ADD"
  "COLUMN netProfit DOUBLE PRECISION;");

  Concepts i;

  size_t a;
  size_t shift;

  std::cin >> shift;
  while(true)
  {    
    auto prepareData = 
    connect.Prepare("INSERT INTO a (volatility, net, netProfit)"
    "VALUES (?,?,?)");
    {
      Lock lock(mtx);
      prepareData->Execute(period.size(), i.Volatility(shift),
      i.Net(period.size()), i.Return(1));
    }

    {      
      Lock lock(mtx);
      if(period.size() >= 100)
      {
        period.clear();
      }
    }
  
    auto volatilidade = connect.Query("SELECT volatility FROM a;");
    auto liquido = connect.Query("SELECT net FROM a;");
    auto lucrLiqdo = connect.Query("SELECT netProfit FROM a;");

    {
      Lock lock(mtx);
      for(size_t x = 0; x < period.size(); x++)
      {
        double vol = 
        volatilidade->GetValue(0, x).GetValue<double>();
        double liquid =
        liquido->GetValue(0, x).GetValue<double>();
        double lucroLiqdo = 
        lucrLiqdo->GetValue(0, x).GetValue<double>();

        if(vol == vol  && liquid < 0)
        {
          std::cout << " retorno de " << lucroLiqdo << 
          std::endl;
        }
      }
    }
  } 

  return 0;
}
