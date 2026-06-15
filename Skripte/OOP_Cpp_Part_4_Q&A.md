# Q&A – OOP_Cpp_Part 4.pdf - Speicherverwaltung, enum class & std::vector

> **Zweck:** Kurze Wiederholung, um nach der Vorlesungspause wieder ins Thema zu kommen.
>
> Themen: Stack & Funktionsaufruf · Heap & new/delete · Stack vs. Heap & RAII · enum class & switch · std::vector & moderne for-Schleifen

---

<!-- markdownlint-disable MD033 -->
## 1. Stack & Funktionsaufruf

**F1.1 – Was passiert auf dem Stack bei einem Funktionsaufruf?**
<details><summary>Antwort</summary>

    Jeder Funktionsaufruf legt einen Stack-Frame oben drauf. Darin liegen: die Rücksprungadresse (ret), die Argumente (args) und die lokalen Variablen (locals).
    Der Stack-Pointer (sp) zeigt immer auf das aktuelle „oben" und wandert mit. Nach return wird der ganze Frame abgeräumt und sp wandert zurück (LIFO – wie ein Stapel Teller).
</details>

**F1.2 – Warum werden lokale (Stack-)Variablen automatisch freigegeben?**
<details><summary>Antwort</summary>

    Weil sie im Frame ihrer Funktion liegen. Sobald die Funktion verlassen wird, wird der Frame abgeräumt – die Locals verschwinden automatisch mit ihm. Kein manuelles Aufräumen nötig.
</details>

**F1.3 – Was zeigt der Call Stack, und was bedeutet „Variablen nur lokal verfügbar"?**
<details><summary>Antwort</summary>

    Der Call Stack zeigt alle gerade auf dem Stack liegenden (offenen) Funktionen. Lokale Variablen sind nur im eigenen Frame sichtbar – eine aufgerufene Funktion sieht die Locals der aufrufenden nicht.
</details>

**F1.4 – Was passiert bei einer Endlosrekursion bzw. einem Infinite-Loop? (Trickfrage)**
<details><summary>Antwort</summary>

    Endlosrekursion: Jeder Aufruf legt einen neuen Frame an, der nie abgeräumt wird → der Stack wächst unbegrenzt → Stack Overflow (Absturz).
    Infinite-Loop: Eine Schleife ruft keine Funktion auf, legt also keine neuen Frames an → kein Overflow, das Programm läuft nur ewig weiter.
</details>

---

## 2. Heap & new/delete

**F2.1 – Wofür stehen `new` und `delete`, und welche Regel gilt?**
<details><summary>Antwort</summary>

    `new` reserviert (allokiert) Speicher auf dem Heap, `delete` gibt ihn wieder frei. Regel: Für jedes `new` ein `delete` – sonst entsteht ein Memory Leak.
    `new double(7.0)` reserviert und initialisiert direkt mit 7.0. Auf den Heap kommt man nur über einen Pointer.
</details>

**F2.2 – Warum setzt man den Pointer nach dem `delete` auf `nullptr`?**
<details><summary>Antwort</summary>

    Nach dem `delete` hält der Pointer noch die alte Adresse – ein „dangling pointer", der auf bereits freigegebenen Speicher zeigt. Ein Zugriff darauf ist ein gefährlicher Bug. `ptr = nullptr;` setzt ihn bewusst auf „nichts". (Ein `delete` auf `nullptr` ist harmlos.)
</details>

---

## 3. Stack vs. Heap & RAII

**F3.1 – Nenne die wichtigsten Unterschiede zwischen Stack und Heap.**
<details><summary>Antwort</summary>

    - Verwaltung: Stack automatisch (Sprache/OS), Heap manuell durch den Entwickler.
    - Freigabe: Stack automatisch am Scope-Ende, Heap manuell per `delete`.
    - Größe: Stack bei Programmstart festgelegt, Heap manuell vergrößerbar.
    - Zugriff: Stack ohne Pointer nutzbar, Heap nur über Pointer.

    Faustregel: Stack ist Standard, Heap die Ausnahme. C++ hat keinen Garbage Collector.
</details>

**F3.2 – Was ist ein Memory Leak und wie entsteht er?**
<details><summary>Antwort</summary>

    Heap-Speicher, der reserviert wurde, aber nicht freigegeben wird (vergessenes `delete`). Wenn kein Pointer mehr darauf zeigt, ist er belegt, aber unerreichbar – er wird erst beim Programmende vom OS zurückgeholt. In langlaufenden Programmen sammelt sich so immer mehr Müll an.
</details>

**F3.3 – Was sind Smart Pointer und was bedeutet RAII?**
<details><summary>Antwort</summary>

    Smart Pointer (`std::unique_ptr`, `std::shared_ptr`) sind Objekte auf dem Stack, die Heap-Speicher besitzen und ihn in ihrem Destruktor automatisch freigeben – für jedes `new` also automatisch ein `delete`.
    RAII (Resource Acquisition Is Initialization): Ressourcen sind an die Objektlebensdauer gekoppelt, der Destruktor läuft deterministisch am Scope-Ende. Genau deshalb braucht C++ keinen Garbage Collector.
</details>

---

## 4. enum class & switch

**F4.1 – Was ist eine `enum class` und welchen Vorteil hat sie gegenüber einem einfachen `enum`?**
<details><summary>Antwort</summary>

    Eine `enum class` ist ein eigener, typsicherer Aufzählungstyp (nicht nur Integer 0, 1, 2, …). Werte werden scoped angesprochen (`Color::red`).
    Ein `enum` ohne `class` ist dagegen quasi äquivalent zu Integern – mit impliziter Umwandlung und möglichen Namenskonflikten, also fehleranfällig. Generell besser als „Magic Numbers".
</details>

**F4.2 – Was braucht ein `switch`, und worauf muss man achten?**
<details><summary>Antwort</summary>

    Ein `switch` braucht einen `int` oder `char` – diese können aus einer `enum class` kommen (`case Color::red:`). Wichtig: `break` nicht vergessen (sonst „fall-through"), und einen `default`-Zweig für die übrigen Fälle.
</details>

**F4.3 – Warum lässt sich `Color::blue + Color::red` nicht einfach rechnen? (Trickfrage)**
<details><summary>Antwort</summary>

    Weil `enum class` typsicher ist: keine Arithmetik und keine implizite Umwandlung in `int`. Das ergibt einen Compiler-Fehler. Will man die Zahl wirklich, braucht es ein explizites `static_cast<int>(...)`. Genau das ist der Schutz, den das `class` bietet.
</details>

---

## 5. std::vector & moderne for-Schleifen

**F5.1 – Was ist `std::vector` und welche Methoden kennst du?**
<details><summary>Antwort</summary>

    Ein dynamisches Array aus der Standardbibliothek (`#include <vector>`), das mitwächst und seinen Speicher selbst verwaltet (RAII – kein manuelles `new[]`/`delete[]`).
    Wichtige Methoden: `push_back()`, `pop_back()`, `size()`, `capacity()`, `empty()`, Zugriff per `vec[i]`.
</details>

**F5.2 – Was bewirkt das `&` in einer range-based for-Schleife?**
<details><summary>Antwort</summary>

    `for (std::string &element : vec)`: Das `&` macht element zu einer Referenz – keine Kopie, und Änderungen wirken direkt auf den Vektor. Ohne `&` wird jedes Element kopiert, Änderungen betreffen nur die Kopie. Nur-lesend am besten `const auto&`.
</details>

**F5.3 – Was ist der Unterschied zwischen `size()` und `capacity()`?**
<details><summary>Antwort</summary>

    `size()` ist die aktuelle Anzahl der Elemente. `capacity()` ist der aktuell reservierte Platz – er kann größer sein als size, damit nicht bei jedem `push_back` neu allokiert werden muss.
</details>

---
*Grundlage: OOP mit C++ – Teil 4 (Kapitel 2: C++ Basics – Speicherverwaltung, enum class, std::vector).*
