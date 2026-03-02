#pragma once
#include <vector>
#include <cstdint>
#include <mutex>
#include <string>

// Estrutura para armazenar os dados de um candle
struct Candle {
    std::string symbol;
    double open;
    double high;
    double low;
    double close;
};

// Declarando variáveis globais para serem definidas em um .cpp
extern std::vector<Candle> period;
extern std::mutex mtx;

// Função para iniciar o servidor
void candleServer(uint16_t Port);
