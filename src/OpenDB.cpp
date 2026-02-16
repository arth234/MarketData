#include <iostream>
#include <vector>
#include <sqlite3.h>
#include <ctime>
#include <string>
#include "OpenDB.h"

// Função para carregar candles do banco SQLite
std::vector<Candle> loadCandles() {
    std::string db_path;
  
    db_path = "/home/arthur/.wine/drive_c/Program Files/MetaTrader 5/MQL5/Files/home/arthur/DatabaseOHLC/market_data.db";

    
    sqlite3* db;
    sqlite3_stmt* stmt;

    if (sqlite3_open(db_path.c_str(), &db)) {
        std::cerr << "Erro ao abrir banco: " << sqlite3_errmsg(db) << std::endl;
        return period;
    }

    const char* sql = 
        "SELECT time, open, high, low, close, tick_volume, real_volume, technical_volume "
        "FROM candles ORDER BY time ASC;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erro ao preparar query: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return period;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Candle c;
        c.time              = sqlite3_column_int(stmt, 0);
        c.open              = sqlite3_column_double(stmt, 1);
        c.high              = sqlite3_column_double(stmt, 2);
        c.low               = sqlite3_column_double(stmt, 3);
        c.close             = sqlite3_column_double(stmt, 4);
        c.tick_volume       = sqlite3_column_int(stmt, 5);
        c.real_volume       = sqlite3_column_int(stmt, 6);
        c.technical_volume  = sqlite3_column_double(stmt, 7);

        period.push_back(c); // adiciona ao vector
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return period;
}

// Função auxiliar para imprimir candle (opcional)
void printCandle(const Candle& c) {
    std::time_t t = c.time;
    std::cout << std::ctime(&t) // converte timestamp para string legível
              << " O:" << c.open
              << " H:" << c.high
              << " L:" << c.low
              << " C:" << c.close
              << " TV:" << c.tick_volume
              << " RV:" << c.real_volume
              << " Tech:" << c.technical_volume
              << "\n";
}
	
