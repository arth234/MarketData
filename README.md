<h1 align="center">⚡ MarketData</h1>

<p align="center">
High-Performance Market Data Ingestion Engine written in C++
</p>

<p align="center">
Designed for <b>low latency</b>, <b>predictable memory usage</b> and
<b>high-throughput real-time market data processing</b>.
</p>

<hr>

<h2>🚀 Overview</h2>

<p>
<b>MarketData</b> is a lightweight C++ engine built to ingest and process
real-time OHLC candle data with minimal latency.
</p>

<p>
Unlike traditional data ingestion pipelines that rely on dynamic containers and
heavy synchronization mechanisms, MarketData focuses on:
</p>

<ul>
<li>Deterministic memory usage</li>
<li>Lock-free concurrency</li>
<li>Cache-friendly data structures</li>
<li>High-throughput ingestion pipelines</li>
</ul>

<p>
The project is designed with the same architectural philosophy used in
<strong>low-latency trading infrastructure</strong>.
</p>

<hr>

<h2>⚙ Core Architecture</h2>

<p>
The system uses a <b>fixed-size ring buffer</b> for storing candle data.
</p>

<p>
Instead of using dynamic containers like <code>std::vector</code>, the system
relies on a preallocated circular structure with a maximum capacity of
<b>1024 periods</b>.
</p>

<pre>
Client
   │
HTTP POST (JSON candles)
   │
Socket Layer
   │
CandleServer
   │
Atomic synchronization
   │
Ring Buffer (1024 periods)
   │
Pattern / Index analysis
</pre>

<p>
This design ensures minimal memory allocations and predictable performance.
</p>

<hr>

<h2>⚡ Latest Performance Improvements</h2>

<h3>🔄 Ring Buffer Implementation</h3>

<p>
Previous versions relied on dynamic containers:
</p>

<pre><code>std::vector&lt;Candle&gt;</code></pre>

<p>
Problems with this approach:
</p>

<ul>
<li>Memory reallocations</li>
<li>Cache inefficiencies</li>
<li>Unpredictable latency spikes</li>
</ul>

<p>
The system now uses:
</p>

<pre>
Fixed Ring Buffer
Capacity: 1024 periods
</pre>

<p>
Advantages:
</p>

<ul>
<li>O(1) insertion</li>
<li>No memory reallocations</li>
<li>Constant memory footprint</li>
<li>Better CPU cache locality</li>
</ul>

<hr>

<h3>⚛ Atomic Concurrency</h3>

<p>
The engine now leverages the <code>&lt;atomic&gt;</code> library from C++ for
thread-safe operations without heavy locking mechanisms.
</p>

<p>
Atomic operations are used for:
</p>

<ul>
<li>Buffer indexing</li>
<li>Thread synchronization</li>
<li>Concurrent data access</li>
</ul>

<p>
Benefits:
</p>

<ul>
<li>Reduced thread contention</li>
<li>Higher ingestion throughput</li>
<li>Lower synchronization overhead</li>
</ul>

<hr>

<h3>📦 Library Modularization</h3>

<p>
The project architecture was modularized to improve maintainability and
reusability.
</p>

<p>
Core modules currently include:
</p>

<pre>
CandleServer
Index
Pattern
ConstConcepts
Socket utilities
</pre>

<p>
Advantages:
</p>

<ul>
<li>Cleaner project structure</li>
<li>Easier testing</li>
<li>Better extensibility</li>
</ul>

<hr>

<h3>🗄 DuckDB Removal (Temporary)</h3>

<p>
The embedded <code>DuckDB.hpp</code> dependency was removed from the current
version.
</p>

<p>
The goal is to fork DuckDB and adapt it for a
<b>multithreaded ingestion architecture</b> specifically optimized for this
engine.
</p>

<p>
Future integration may include:
</p>

<ul>
<li>Parallel query execution</li>
<li>Optimized ingestion pipelines</li>
<li>Tighter integration with MarketData's concurrency model</li>
</ul>

<hr>

<h2>📊 Example Candle Payload</h2>

<p>
Example JSON request sent by a client:
</p>

<pre><code>{
  "symbol": "EURUSD",
  "open": 1.0845,
  "high": 1.0852,
  "low": 1.0838,
  "close": 1.0849,
  "volume": 1200
}
</code></pre>

<hr>

<h2>🛠 Build Instructions</h2>

<h3>Requirements</h3>

<ul>
<li>C++17 or newer</li>
<li>CMake</li>
<li>Linux / POSIX environment</li>
</ul>

<h3>Build</h3>

<pre><code>git clone https://github.com/arth234/MarketData

cd MarketData

mkdir build
cd build

cmake ..
make
</code></pre>

<h3>Run</h3>

<pre><code>./MarketData</code></pre>

<hr>

<h2>📈 Future Development</h2>

<p>
Planned improvements include:
</p>

<ul>
<li>Lock-free multi-producer ingestion</li>
<li>Custom memory allocators</li>
<li>SIMD optimizations</li>
<li>Multithreaded database integration</li>
<li>Real-time analytics modules</li>
</ul>

<p>
The long-term goal is to evolve MarketData into a
<strong>high-performance market data engine for quantitative trading
systems</strong>.
</p>

<hr>

<h2>👨‍💻 Author</h2>

<p>
Arthur Vieira
</p>

<p>
Interests:
</p>

<ul>
<li>Low-latency systems</li>
<li>High-performance C++</li>
<li>Trading infrastructure</li>
<li>Real-time data pipelines</li>
</ul>

<hr>

<h2>📜 License</h2>

<p>
MIT License
</p>
