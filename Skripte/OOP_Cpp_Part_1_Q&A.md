# Q&A – OOP_Cpp_Part 1.pdf - Einführung & OOP-Grundlagen

> **Zweck:** Kurze Wiederholung, um nach der Vorlesungspause wieder ins Thema zu kommen.
>
> Themen: Setup & C-Wiederholung · Paradigmen & die 4 Säulen der OOP · Klassen & Objekte · Kapselung · Konstruktoren & Destruktoren

---

<!-- markdownlint-disable MD033 -->
## 1. Setup & Wiederholung C

**F1.1 – Welche Werkzeuge brauchst du, um ein C++-Programm zu kompilieren und auszuführen?**
<details><summary>Antwort</summary>

    Einen Editor/eine IDE (z. B. VS Code), einen Compiler (z. B. `g++` aus MinGW) und – auf Windows – den Pfad zu `…\mingw64\bin` in der `PATH`-Umgebungsvariable, damit `g++` von der Konsole aus gefunden wird. Prüfen lässt sich das mit `g++ --version`.
</details>

**F1.2 – Wie liest man in C++ einen Wert von der Konsole ein und wie gibt man ihn aus?**
<details><summary>Antwort</summary>

    Einlesen mit `std::cin >> variable;`, Ausgeben mit `std::cout << variable;`. Beides aus `<iostream>`.
</details>

**F1.3 – Was für ein Datentyp ist `bool` und welche Werte kann er annehmen?**
<details><summary>Antwort</summary>

    Ein elementarer Datentyp mit genau zwei möglichen Werten: `true` und `false`.
    "Elementarer Datentyp" heißt: ein eingebauter Grundtyp von C++ – wie int, double oder char. Man muss ihn nicht selbst definieren, er ist Teil der Sprache.
</details>

---

## 2. Paradigmen & die 4 Säulen der OOP

**F2.1 – Worin unterscheiden sich prozedurale und objektorientierte Programmierung grundlegend?**
<details><summary>Antwort</summary>

    Prozedural orientiert sich an der Funktionsweise des Rechners (Anweisungen/Funktionen), trennt Daten und Funktionalität, Daten sind nur lokal oder global verfügbar → schwierig wartbar bei großen Programmen.

    Objektorientiert orientiert sich an der „echten Welt", führt Daten und Funktionalität zusammen (in Objekten) und steuert deren Verfügbarkeit über Kapselung.
</details>

**F2.2 – Nenne die vier Säulen der objektorientierten Programmierung.**
<details><summary>Antwort</summary>

    1. Abstraktion
    2. (Daten-)Kapselung
    3. Vererbung
    4. Polymorphie

</details>

---

## 3. Klassen & Objekte

**F3.1 – Was ist der Unterschied zwischen einer Klasse und einem Objekt?**
<details><summary>Antwort</summary>

    Eine Klasse ist der „Bauplan": eine Erweiterung von structs, die Daten und Funktionalität enthält und Zugriffe einschränken kann (Kapselung).
    Ein Objekt ist eine konkrete Instanz dieser Klasse mit den drei Bestandteilen...
</details>

**F3.2 – Aus welchen drei Bestandteilen besteht ein Objekt?**
<details><summary>Antwort</summary>

    Zustand (Daten / Member-Variablen), Verhalten (Methoden) und Identität (eindeutig, z. B. über die Speicheradresse).
</details>

---

## 4. Kapselung

**F4.1 – Was bewirken `public`, `private` und `protected`?**
<details><summary>Antwort</summary>

    - public: von außen aufrufbar (über eine Instanz).
    - private: kein Zugriff von außen – auch Kinderklassen kommen nicht heran.
    - protected: von außen nicht erreichbar, aber Kinderklassen kommen heran (quasi „public für Kinder").

</details>

**F4.2 – Wozu dient Kapselung überhaupt?**
<details><summary>Antwort</summary>

    Sie kontrolliert, welche Daten und Methoden von außen sichtbar/veränderbar sind. So lässt sich der interne Zustand schützen und ein definiertes Interface nach außen anbieten. Member-Variablen sind deshalb fast immer privat.
</details>

---

## 5. Konstruktoren & Destruktoren

**F5.1 – Was ist und was macht ein Konstruktor?**
<details><summary>Antwort</summary>

    Konstruktoren sind spezielle Methoden, die beim Erstellen eines Objektes aufgerufen werden.

    Ein Konstruktor allokiert Speicher und initialisiert die Werte eines Objekts beim Erstellen.
    Typischerweise gibt es mehrere Konstruktoren – je nachdem, welche Argumente übergeben werden.
</details>

**F5.2 – Was ist eine Initialisierungsliste und warum gilt sie als guter Stil?**
<details><summary>Antwort</summary>

    Eine Initialisierungsliste initialisiert Member-Variablen direkt (`: m_name(name), m_speed(speed)`), ohne eine zusätzliche Kopie über eine Zuweisung im Konstruktorrumpf. Daher also effizienter und guter Stil.
</details>

**F5.3 – Wann wird der Destruktor aufgerufen?**
<details><summary>Antwort</summary>

    Wenn das Objekt gelöscht wird – z. B. wenn die Funktion, in der es lebt, verlassen wird (das Objekt seinen Gültigkeitsbereich verlässt).
</details>

---
*Grundlage: OOP mit C++ – Teil 1 (Kapitel 1 Einführung + Beginn Kapitel 2 Objektorientierung).*
