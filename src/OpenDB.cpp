#include "OpenDB.h"
#include <sqlite3.h>
#include <cstddef> 

std::vector<Candle>period;

void loadCandles()
{
    period.clear();

    sqlite3* db;
    sqlite3_stmt* stmt;

    sqlite3_open(R"(/home/arthur/.wine/drive_c/Program Files/MetaTrader 5/MQL5/Files/home/arthur/DatabaseOHLC/market_data.db)", &db);
   

    const char* sql = "SELECT time,open,high,low,close,"
                      "tick_volume,real_volume,technical_volume "
                      "FROM candles ORDER BY time ASC;";

    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        Candle c;

        c.time             = sqlite3_column_int(stmt, 0);
        c.open             = sqlite3_column_double(stmt, 1);
        c.high             = sqlite3_column_double(stmt, 2);
        c.low              = sqlite3_column_double(stmt, 3);
        c.close            = sqlite3_column_double(stmt, 4);
        c.tick_volume      = sqlite3_column_int(stmt, 5);
        c.real_volume      = sqlite3_column_int(stmt, 6);
        c.technical_volume = sqlite3_column_double(stmt, 7);

        period.push_back(c);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
