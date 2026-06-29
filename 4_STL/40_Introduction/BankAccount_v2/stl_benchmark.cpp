// ============================================================================
//  STL-Benchmark - auf Basis des BankAccount / IBANGen Beispiels
//  Vergleicht drei Ansaetze fuer "N IBANs verwalten: einfuegen + nachschlagen"
//    1) Selbst gebaut : std::vector + bubbleSort + (korrigierte) binaere Suche
//    2) STL-Algorithmen: std::vector + std::sort + std::find
//    3) STL-Container  : std::set / std::unordered_set
// ============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <chrono>

using Clock = std::chrono::steady_clock;
static double msd(Clock::time_point a, Clock::time_point b) {   // Millisekunden als double
    return std::chrono::duration_cast<std::chrono::microseconds>(b - a).count() / 1000.0;
}
static void line(const char* name, double insertMs, double lookupMs) {
    std::cout << "  " << std::left << std::setw(34) << name
              << "einfuegen: " << std::right << std::setw(10) << std::fixed << std::setprecision(3) << insertMs << " ms"
              << "   |   nachschlagen: " << std::setw(9) << lookupMs << " ms\n";
}

// ---------------------------------------------------------------------------
//  1) Selbst gebaut: bubbleSort + binaere Suche
// ---------------------------------------------------------------------------
void bubbleSort(std::vector<int> &v) {
    bool swapped = true;
    for (std::size_t i = 0; i + 1 < v.size() && swapped; ++i) {
        swapped = false;
        for (std::size_t j = 0; j + 1 < v.size() - i; ++j) {
            if (v[j + 1] < v[j]) { std::swap(v[j], v[j + 1]); swapped = true; }
        }
    }
}
bool manualIsUsed(const std::vector<int> &v, int x) {
    int low = 0, high = (int)v.size() - 1;          // korrekt: size()-1
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if      (x < v[mid]) high = mid - 1;
        else if (x > v[mid]) low  = mid + 1;
        else return true;
    }
    return false;
}

int main() {
    const int N = 2500;     // Anzahl einzufuegender Werte
    const int R = 100;      // Wiederholungen der Suchphase (damit messbar)

    std::mt19937 gen(42);
    std::uniform_int_distribution<int> dist(100000, 999999);
    std::vector<int> input(N);
    for (int &x : input) x = dist(gen);

    std::cout << "Benchmark: " << N << " Werte einfuegen (inkl. Sortieren) + "
              << N << " x " << R << " mal nachschlagen\n";
    std::cout << "============================================================================\n";
    volatile long long sink = 0;   // verhindert Wegoptimieren der Suche

    // ----- 1) Selbst gebaut -------------------------------------------------
    {
        std::vector<int> v;
        auto t0 = Clock::now();
        for (int x : input) { v.push_back(x); bubbleSort(v); }
        auto t1 = Clock::now();
        for (int r = 0; r < R; ++r) for (int x : input) sink += manualIsUsed(v, x);
        auto t2 = Clock::now();
        line("1) Selbst gebaut (bubble+binaer)", msd(t0, t1), msd(t1, t2));
    }
    // ----- 2) STL-Algorithmen ----------------------------------------------
    {
        std::vector<int> v;
        auto t0 = Clock::now();
        for (int x : input) { v.push_back(x); std::sort(v.begin(), v.end()); }
        auto t1 = Clock::now();
        for (int r = 0; r < R; ++r) for (int x : input) sink += (std::find(v.begin(), v.end(), x) != v.end());
        auto t2 = Clock::now();
        line("2) STL-Algorithmen (sort+find)", msd(t0, t1), msd(t1, t2));
    }
    // ----- 3) STL-Container: std::set --------------------------------------
    {
        std::set<int> s;
        auto t0 = Clock::now();
        for (int x : input) s.insert(x);
        auto t1 = Clock::now();
        for (int r = 0; r < R; ++r) for (int x : input) sink += s.count(x);
        auto t2 = Clock::now();
        line("3) STL-Container (std::set)", msd(t0, t1), msd(t1, t2));
    }
    // ----- 3b) STL-Container: std::unordered_set ---------------------------
    {
        std::unordered_set<int> s;
        auto t0 = Clock::now();
        for (int x : input) s.insert(x);
        auto t1 = Clock::now();
        for (int r = 0; r < R; ++r) for (int x : input) sink += s.count(x);
        auto t2 = Clock::now();
        line("3b) STL-Container (unordered_set)", msd(t0, t1), msd(t1, t2));
    }

    std::cout << "============================================================================\n";
    std::cout << "(Suchphase gesamt: " << (long long)N * R << " Lookups pro Ansatz)\n";
    return 0;
}
