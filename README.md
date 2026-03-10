<div id="top">

<!-- HEADER STYLE: CLASSIC -->

<div align="center">

<img src="readmeai/assets/logos/purple.svg" width="30%" style="position: relative; top: 0; right: 0;" alt="Project Logo"/>

# MARKETDATA

<em>Lightweight C++ Market Data Ingestion Server for Real-Time OHLC Data</em>

<!-- BADGES -->

<img src="https://img.shields.io/github/license/arth234/MarketData?style=default&logo=opensourceinitiative&logoColor=white&color=0080ff" alt="license">
<img src="https://img.shields.io/github/last-commit/arth234/MarketData?style=default&logo=git&logoColor=white&color=0080ff" alt="last-commit">
<img src="https://img.shields.io/github/languages/top/arth234/MarketData?style=default&color=0080ff" alt="repo-top-language">
<img src="https://img.shields.io/github/languages/count/arth234/MarketData?style=default&color=0080ff" alt="repo-language-count">

</div>
<br>

---

## Table of Contents

* [Overview](#overview)
* [Features](#features)
* [Project Structure](#project-structure)
* [Getting Started](#getting-started)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)

---

## Overview

**MarketData** is a lightweight **C++ HTTP server** designed to ingest **real-time OHLC candle data** from trading platforms such as MetaTrader.

The system receives **HTTP POST requests containing JSON candle data**, parses the payload, and stores the information in memory for further processing.

The project focuses on:

* performance and low-latency networking
* minimal dependencies
* simple and modular architecture
* real-time market data ingestion

Typical use cases include:

* algorithmic trading infrastructure
* market data collection pipelines
* quantitative research systems
* real-time analytics platforms

---

## Features

| Feature                       | Description                                   |
| ----------------------------- | --------------------------------------------- |
| ⚡ Lightweight HTTP Server     | Implemented using native C++ sockets          |
| 📈 Real-Time Candle Ingestion | Receives OHLC data via HTTP                   |
| 🔒 Thread-Safe Storage        | Uses mutex synchronization                    |
| 🧩 Modular Architecture       | Clear separation of networking and data logic |
| 📦 Minimal Dependencies       | No heavy frameworks required                  |
| 🛠 CMake Build System         | Portable build configuration                  |

---

## Project Structure

```sh
└── MarketData/
    ├── CMakeLists.txt
    ├── include
    │   ├── CandleServer.h
    │   ├── ConstConcepts.h
    │   ├── Index.h
    │   ├── Pattern.h
    │   └── socket.h
    └── src
        ├── CandleServer.cpp
        ├── ConstConcepts.cpp
        ├── Index.cpp
        └── main.cpp
```

### Project Index

<details open>
<summary><b><code>MARKETDATA/</code></b></summary>

<details>
<summary><b>__root__</b></summary>

| File               | Description                                                           |
| ------------------ | --------------------------------------------------------------------- |
| **CMakeLists.txt** | Defines the build configuration and compilation settings using CMake. |

</details>

<details>
<summary><b>include</b></summary>

| File                | Description                                                          |
| ------------------- | -------------------------------------------------------------------- |
| **CandleServer.h**  | Interface for the candle ingestion server and request handling logic |
| **ConstConcepts.h** | Compile-time constraints and constant utilities                      |
| **Index.h**         | Indexing structures for market data organization                     |
| **Pattern.h**       | Utility functions for pattern-related processing                     |
| **socket.h**        | Minimal HTTP socket server implementation                            |

</details>

<details>
<summary><b>src</b></summary>

| File                  | Description                                             |
| --------------------- | ------------------------------------------------------- |
| **CandleServer.cpp**  | Implementation of candle ingestion and request handling |
| **ConstConcepts.cpp** | Implementation of compile-time and constant utilities   |
| **Index.cpp**         | Indexing logic for market data access                   |
| **main.cpp**          | Entry point that starts the HTTP server                 |

</details>

</details>

---

## Getting Started

### Prerequisites

This project requires:

* **Programming Language:** C++17
* **Build System:** CMake
* **Operating System:** Linux or POSIX environment

### Installation

Clone the repository:

```sh
git clone https://github.com/arth234/MarketData
cd MarketData
```

Build the project:

```sh
mkdir build
cd build

cmake ..
make
```

### Usage

Run the server:

```sh
./MarketData
```

Expected output

```
Server running on 5000
```

### Testing

You can test the API using curl:

```sh
curl -X POST http://127.0.0.1:5000/ohlc \
-H "Content-Type: application/json" \
-d '{"symbol":"EURUSD","open":1.08,"high":1.09,"low":1.07,"close":1.085}'
```

---

## Roadmap

* [x] HTTP candle ingestion server
* [x] JSON request parsing
* [x] Thread-safe candle storage
* [ ] Persistent database storage
* [ ] WebSocket streaming
* [ ] Historical candle API
* [ ] Performance benchmarking

---

## Contributing

* **💬 Discussions:** https://github.com/arth234/MarketData/discussions
* **🐛 Issues:** https://github.com/arth234/MarketData/issues

Pull requests are welcome.

---

## License

Distributed under the **MIT License**.

---

<div align="right">

<a href="#top">⬆ Back to top</a>

</div>
