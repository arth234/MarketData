#pragma once
#include <vector>
#include <cstdint>
#include <mutex>
#include <string>
#include <atomic>

// Estrutura para armazenar os dados de um candle
struct Candle {
    char symbol[16];
    long double open;
    long double high;
    long double low;
    long double close;
};

// Declarando variáveis globais para serem definidas em um .cpp

extern std::mutex mtx;
extern Candle period[1024];

// Função para iniciar o servidor
void candleServer(int port, std::atomic<size_t>* indice);
