# Q&A – OOP_Cpp_Part 2.pdf - Header Files, UML & Vererbung

> **Zweck:** Kurze Wiederholung, um nach der Vorlesungspause wieder ins Thema zu kommen.
>
> Themen: Header Files (.hpp/.cpp) · UML-Klassendiagramme · Vererbung · Zugriffsmodifikationen bei Vererbung · Konstruktoren bei Vererbung

---

<!-- markdownlint-disable MD033 -->
## 1. Header Files

**F1.1 – Was gehört in die `.hpp` und was in die `.cpp`?**
<details><summary>Antwort</summary>

    - `.hpp` (Interface): Include guard gegen doppel-Inkludierung, Deklarationen von Konstruktoren, Destruktoren, Methoden, Member-Variablen (fast immer privat) sowie die Sichtbarkeitsmodifikatoren – Reihenfolge: erst `public`, dann `private`.
    - `.cpp` (Implementierung): die eigentlichen Definitionen der Methoden; inkludiert die `.hpp` und alles Weitere, was gebraucht wird.
</details>

**F1.2 – Wozu dient ein Include Guard?**
<details><summary>Antwort</summary>

    Er verhindert die doppelte Inkludierung derselben Header-Datei (z. B. über mehrere `#include`-Pfade), die sonst zu Fehlern führen würde.
    (Die Header-Datei soll pro Übersetzungseinheit nur einmal eingebunden werden.)
</details>

**F1.3 – Warum muss die `main` nur die `.hpp` kennen?**
<details><summary>Antwort</summary>

    Die `main` braucht nur das Interface (Deklarationen aus der `.hpp`). Die Implementierung aus der `.cpp` wird später über den **Linker** zusammengeführt.
</details>

---

## 2. UML-Klassendiagramme

**F2.1 – Wofür stehen die Zeichen `+`, `-` und `#` im UML-Klassendiagramm?**
<details><summary>Antwort</summary>

    - `+` → public
    - `-` → private
    - `#` → protected
</details>

**F2.2 – Wie modelliert man eine has-a- bzw. eine is-a-Beziehung in UML?**
<details><summary>Antwort</summary>

    - has-a → über Member-Variablen (z. B. „eine Person *hat* einen Namen").
    - is-a → über Vererbung (z. B. „ein Golf *ist ein* Auto", „ein Student *ist eine* Person").
</details>

**F2.3 – Welche drei Bereiche hat ein UML-Klassendiagramm einer Klasse?**
<details><summary>Antwort</summary>

    Klassenname, Attribute (Member-Variablen) und Operationen (das Interface / die Methoden).
</details>

---

## 3. Vererbung

**F3.1 – Welche Vorteile bietet Vererbung?**
<details><summary>Antwort</summary>

    - Vermeidet Code-Duplizierung (gemeinsame Funktionalität in eine Basisklasse auslagern).
    - Reduziert Komplexität durch kleinere Klassen und eine neue Abstraktionsebene.
    - Ermöglicht ein gemeinsames Interface mehrerer Klassen.
</details>

**F3.2 – Welche Regel gilt, BEVOR man Vererbung einsetzt?**
<details><summary>Antwort</summary>

    Vererbung nur bei einer echten is-a-Beziehung nutzen. Ansonsten zurückhaltend einsetzen, denn verschachtelte Vererbung kann Übersichtlichkeit und Wartbarkeit verschlechtern (Elternklasse beeinflusst Kinderklassen). Leitgedanke: KISS – „Keep it stupid simple".
</details>

---

## 4. Zugriffsmodifikationen bei Vererbung

**F4.1 – Was passiert bei *public inheritance* mit `public`, `protected` und `private` Membern der Basisklasse?**
<details><summary>Antwort</summary>

    - `public` → bleibt `public`
    - `protected` → bleibt `protected`
    - `private` → nie in der abgeleiteten Klasse verfügbar
</details>

**F4.2 – Werden Konstruktoren und Destruktoren mitvererbt?**
<details><summary>Antwort</summary>

    Nein. Konstruktoren und Destruktoren werden bei Vererbung nicht übertragen.
</details>

---

## 5. Konstruktoren bei Vererbung

**F5.1 – Welcher Konstruktor wird beim Erzeugen eines abgeleiteten Objekts zuerst aufgerufen?**
<details><summary>Antwort</summary>

    Konstruktoren rufen immer zuerst den Konstruktor ihrer Basisklasse auf.
</details>

**F5.2 – Was passiert, wenn man den Basisklassen-Konstruktor nicht explizit aufruft?**
<details><summary>Antwort</summary>

    Dann wird automatisch der Default-Konstruktor der Basisklasse aufgerufen.
</details>

**F5.3 – Warum ist das so in C++?**
<details><summary>Antwort</summary>

    Die Grundidee: Ein abgeleitetes Objekt enthält das Basisobjekt

    Wenn Student von Person erbt, dann besteht ein Student-Objekt im Speicher physisch aus zwei Teilen: einem Person-Teil (der die Attribute und Methoden der Person-Klasse enthält) und einem Student-Teil (der die zusätzlichen Attribute und Methoden der Student-Klasse enthält).

    Die abgeleitete Klasse (Student) ist also eine Erweiterung der Basisklasse (Person) und kann auf Attribute und Methoden der Basisklasse zugreifen. Damit das funktioniert, muss der Konstruktor der Basisklasse zuerst aufgerufen werden, um den Person-Teil des Student-Objekts zu initialisieren.
</details>

---
*Grundlage: OOP mit C++ – Teil 2 (Kapitel 2 Objektorientierung: Header Files & Vererbung).*
