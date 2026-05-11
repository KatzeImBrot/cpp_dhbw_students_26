# Build-Kommando erklärt: Compiler & Linker

Das Bauen eines C++-Projekts mit mehreren Dateien läuft in **zwei Phasen** ab:
1. **Kompilierung** – jede `.cpp`-Datei wird einzeln in eine Objektdatei (`.o`) übersetzt
2. **Linking** – alle Objektdateien werden zu einer ausführbaren Datei zusammengeführt

---

## Das vollständige Kommando (vereinfacht dargestellt)

```
[Schritt 1] g++ <flags> -c main.cpp      -o build/main.o
[Schritt 2] g++ <flags> -c Rectangle.cpp -o build/Rectangle.o
[Schritt 3] g++          build/main.o build/Rectangle.o -o build/outDebug.exe
```

Die drei Schritte werden mit `&&` verkettet – d.h. der nächste Schritt startet nur, wenn der vorherige erfolgreich war.

---

## Phase 1 & 2: Compiler

```
g++ ... -c main.cpp -o .\build\Debug\main.o
g++ ... -c Rectangle.cpp -o .\build\Debug\Rectangle.o
```

| Teil | Bedeutung |
|---|---|
| `g++` | Der C++-Compiler (GNU Compiler Collection) |
| `-c` | **Nur kompilieren**, nicht linken → erzeugt eine Objektdatei (`.o`) |
| `main.cpp` / `Rectangle.cpp` | Die Quelldatei, die übersetzt wird |
| `-o .\build\Debug\main.o` | Name der Ausgabedatei (Objektdatei) |

Der Compiler übersetzt jede `.cpp`-Datei **unabhängig** in Maschinencode. Er prüft Syntax, Typen und löst `#include`-Direktiven auf. Er weiß noch **nicht**, wo z. B. `calcArea()` aus `Rectangle.cpp` im Speicher liegt – das ist Aufgabe des Linkers.

### Compiler-Flags (Warnungen)

| Flag | Bedeutung |
|---|---|
| `-Wall` | Alle Standard-Warnungen aktivieren |
| `-Wextra` | Zusätzliche Warnungen (über `-Wall` hinaus) |
| `-Wpedantic` | Strikte Einhaltung des C++-Standards erzwingen |
| `-Wshadow` | Warnung, wenn eine Variable eine äußere Variable verdeckt |
| `-Wformat=2` | Strenge Prüfung von `printf`/`scanf`-Formatstrings |
| `-Wcast-align` | Warnung bei potenziell falsch ausgerichtetem Cast |
| `-Wconversion` | Warnung bei impliziten Typumwandlungen (z. B. `double` → `int`) |
| `-Wsign-conversion` | Warnung bei Vorzeichenwechsel (signed ↔ unsigned) |
| `-Wnull-dereference` | Warnung bei möglichem Null-Pointer-Zugriff |

### Debug-Flags

| Flag | Bedeutung |
|---|---|
| `-g3` | Maximale Debug-Informationen in die Objektdatei einbetten (für Debugger wie GDB) |
| `-O0` | **Keine Optimierung** – der Compiler übersetzt den Code genau so, wie er geschrieben wurde (wichtig beim Debuggen) |

---

## Phase 3: Linker

```
g++ .\build\Debug\main.o .\build\Debug\Rectangle.o -o .\build\Debug\outDebug.exe
```

| Teil | Bedeutung |
|---|---|
| `g++` | Ruft hier intern den Linker (`ld`) auf |
| `main.o Rectangle.o` | Die Objektdateien, die zusammengeführt werden |
| `-o outDebug.exe` | Name der fertigen ausführbaren Datei |

Der Linker **verknüpft** alle Objektdateien miteinander. Er löst sogenannte *unresolved references* auf: `main.o` ruft `calcArea()` auf, weiß aber nicht wo es liegt. Der Linker findet die Implementierung in `Rectangle.o` und trägt die korrekte Speicheradresse ein.

---

## Zusammenspiel: Compiler und Linker

```
main.cpp        ──[Compiler]──►  main.o       ─┐
Rectangle.cpp   ──[Compiler]──►  Rectangle.o  ─┤─[Linker]──► outDebug.exe
                    (+ stdlib, runtime)       ─┘
                                 
```

### Warum zwei separate Schritte?

- **Separate Kompilierung**: Große Projekte müssen bei einer Änderung nicht komplett neu gebaut werden – nur die geänderte `.cpp`-Datei wird neu kompiliert, der Rest bleibt.
- **Wiederverwendbarkeit**: Objektdateien oder Bibliotheken (`.lib`, `.a`) können in mehreren Projekten gelinkt werden, ohne den Quellcode neu zu übersetzen.
- **Klare Trennung**: Der Compiler prüft die Korrektheit einzelner Übersetzungseinheiten; der Linker prüft, ob alle Abhängigkeiten zwischen den Einheiten erfüllt sind.

---

## Rollen von Header- und Quelldateien

| Datei | Rolle beim Compiler |
|---|---|
| `Rectangle.hpp` | Wird per `#include` in `main.cpp` und `Rectangle.cpp` eingefügt – enthält nur **Deklarationen** (was gibt es?) |
| `Rectangle.cpp` | Enthält die **Definitionen** (wie funktioniert es?) – wird separat kompiliert |
| `main.cpp` | Nutzt die Deklarationen aus dem Header; der Compiler vertraut darauf, dass die Definitionen beim Linken vorhanden sind |
