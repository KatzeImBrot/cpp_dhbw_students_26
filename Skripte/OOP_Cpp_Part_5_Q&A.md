# Q&A – OOP_Cpp_Part 5.pdf - Weitere C++ Keywords & Namespaces

> **Zweck:** Kurze Wiederholung, um nach der Vorlesungspause wieder ins Thema zu kommen.
>
> Themen: const & constexpr · static · auto · friend class · Namespaces

---

<!-- markdownlint-disable MD033 -->
## 1. const & constexpr

**F1.1 – Was bewirkt das Keyword `const`?**
<details><summary>Antwort</summary>

    Es definiert Variablen, die nicht mehr verändert werden sollen (z. B. Konstanten). Die Variable kann zur Laufzeit nicht mehr geändert werden.
</details>

**F1.2 – Was bedeutet `const` bei Methoden und bei Member-/Argumenten?**
<details><summary>Antwort</summary>

    - Eine const-Methode darf keine Member-Variablen ändern.
    - Ein const-Argument (oder const-Member) darf von der Funktion/Methode nicht geändert werden.
    - const-Membervariablen müssen bei der Objekterzeugung initialisiert werden – über die Initialisierungsliste des Konstruktors oder einen In-Class-Initialisierer im Header. Nachträglich setzen geht nicht.
</details>

**F1.3 – Was ist `constexpr` und worin unterscheidet es sich von `const`?**
<details><summary>Antwort</summary>

    `constexpr` wird bereits zur Compile-Zeit ausgewertet – Wert bzw. Berechnung steht beim Kompilieren fest (Performance-Vorteil, keine Berechnung zur Laufzeit nötig). `constexpr` ist außerdem implizit `const`.
    Unterschied: `const` heißt nur „zur Laufzeit nicht mehr änderbar"; `constexpr` ist zusätzlich schon zur Compile-Zeit bekannt.
</details>

**F1.4 – Wann sollte man `const` / `constexpr` verwenden?**
<details><summary>Antwort</summary>

    Wann immer möglich!
</details>

---

## 2. static

**F2.1 – Was bewirkt `static` bei Variablen/Methoden?**
<details><summary>Antwort</summary>

    Bisher existierten Methoden/Variablen auf Objektebene – man braucht erst ein Objekt, und die Werte können je Objekt unterschiedlich sein.
    Mit `static` lassen sich Variablen/Methoden definieren, die objektlos (ohne Instanz) aufgerufen werden können. Dieser Wert/diese Methode ist in allen Objekten der Klasse gleich, und die Methode hat nie Abhängigkeiten zu den Daten eines spezifischen Objekts.
</details>

---

## 3. auto

**F3.1 – Was macht `auto`, und was ist bei der Nutzung zu beachten?**
<details><summary>Antwort</summary>

    `auto` kann statt des konkreten Typs bei einer Zuweisung stehen, wenn direkt ein Wert zugewiesen wird – der Compiler ermittelt den Typ selbst. Die Typsicherheit bleibt erhalten (der Compiler warnt weiter bei unpassenden Typen).
    C++-Standard: AAA – „Almost Always Auto". Aber Vorsicht: Lesbarkeit kann leiden. Besser nur, wenn der Typ auf der rechten Seite klar ist oder die Lesbarkeit erhöht wird (z. B. bei sehr langen Klassennamen).
</details>

---

## 4. friend class

**F4.1 – Wozu dient eine `friend`-Deklaration?**
<details><summary>Antwort</summary>

    Wenn eine einzelne, spezifische Klasse Zugriff auf eigentlich private Variablen braucht, wäre es unsinnig, diese komplett `public` zu machen. Stattdessen erklärt man die andere Klasse zum `friend` – sie bekommt dann Zugriff auf die privaten Member.
    friend-Beziehungen gelten nur in eine Richtung. Sinnvoll z. B. in Tests.
</details>

---

## 5. Namespaces

**F5.1 – Welches Problem lösen Namespaces?**
<details><summary>Antwort</summary>

    Sie verhindern Namenskollisionen. Beispiel: Man will eine eigene Klasse `Vector` schreiben – die gibt es aber schon (in der STL) → Compiler-Fehler. Da der STL-Vector im Namespace `std` liegt (`std::vector`), ist nur dieser Name belegt, und man kann seine eigene Klasse `Vector` nennen.
    Zusätzlich verbessern sie die Lesbarkeit (z. B. `algebra::vector`). Für große Projekte und wiederverwendeten Code unverzichtbar.
</details>

**F5.2 – Worauf muss man bei `using namespace` achten?**
<details><summary>Antwort</summary>

    Nur mit viel Vorsicht – und niemals in Headern! Auch `using namespace std;` ist heikel: Die STL ist im stetigen Wandel, sodass Namenskollisionen entstehen können, obwohl der eigene Code unverändert bleibt.
    Besser: einzelne, oft genutzte Ausdrücke gezielt „befreien", z. B. `using std::cout;` (geht auch mit eigenen langen Namespaces).
</details>

**F5.3 – Können sich Namespaces über mehrere Dateien erstrecken?**
<details><summary>Antwort</summary>

    Ja. Will man zusätzliche Klassen/Funktionen in einen Namespace einfügen oder die Implementierungen in die `.cpp`-Datei legen, definiert man den Namespace dort einfach erneut.
    Konvention: im Namespace nicht einrücken (sonst werden ganze Files unnötig eingerückt) und das Ende der Klammer kommentieren, wofür sie steht.
</details>

---
*Grundlage: OOP mit C++ – Teil 5 (Kapitel 3: Vertiefung C++ – Weitere C++ Keywords & Namespaces).*
