# Q&A – OOP_Cpp_Part 6.pdf - Objektorientiertes Design (SRP/SOLID) & Einf&uuml;hrung STL

> **Zweck:** Kurze Wiederholung, um nach der Vorlesungspause wieder ins Thema zu kommen.
>
> Themen: Single Responsibility Principle · SOLID-Prinzipien · Vorteile von OOP-Design · STL – Motivation · STL – Aufbau & std-Namespace

---

<!-- markdownlint-disable MD033 -->
## 1. Single Responsibility Principle (SRP)

**F1.1 – Was besagt das Single Responsibility Principle?**
<details><summary>Antwort</summary>

    Jede Klasse sollte für genau einen Teil der Funktionalität eines Programms verantwortlich sein, und diese Funktionalität sollte vollständig in der Klasse gekapselt sein.
    Folge: Es sollte nur einen einzigen Grund geben, warum eine Klasse geändert werden muss.
</details>

**F1.2 – Was ist eine „Gott-Klasse" und welche Probleme bringt sie? (Beispiel Rectangle)**
<details><summary>Antwort</summary>

    Eine Klasse mit mehr als einer Verantwortung. Beispiel: Rectangle macht sowohl area() (Mathematik) als auch render() (Grafik).
    Probleme:
    - Rectangle hat zwei Verantwortungen: grafische Darstellung + mathematische Berechnung.
    - Die Math App wird dadurch von der GUI abhängig (die GUI muss für die Math App mit inkludiert werden).
    - Änderungen in der GUI können zu Fehlern in der Math App führen.
</details>

---

## 2. SOLID-Prinzipien

**F2.1 – Wofür stehen die fünf SOLID-Prinzipien?**
<details><summary>Antwort</summary>

    - S \u2013 Single Responsibility: Jede Klasse nur eine Funktion/Verantwortung.
    - O \u2013 Open/Closed: Offen für Erweiterung, geschlossen für Veränderung.
    - L \u2013 Liskov Substitution: Abgeleitete Klassen sollen sich wie die Basisklasse verwenden lassen.
    - I \u2013 Interface Segregation: Mehrere kleine, spezialisierte Schnittstellen statt einer großen.
    - D \u2013 Dependency Inversion: Abhängigkeit von Abstraktionen, nicht von konkreten Klassen.
</details>

---

## 3. Vorteile von OOP-Design

**F3.1 – Welche weiteren Vorteile bringt gutes OOP-Design?**
<details><summary>Antwort</summary>

    - Abstraktion: Können Dinge gleich behandelt werden, sollte das auch passieren – über Interfaces/Vererbung oder Wiederverwendung.
    - Nähe zur Realität: Je näher am echten Problem, desto weniger muss man umdenken – und desto leichter die Kommunikation mit Kunde/Management.
    - Divide & Conquer: Je kleiner Funktionen und Klassen, desto einfacher wartbar, verständlich und erweiterbar.
    - Kapselung: Je weniger Abhängigkeiten, desto besser. Klassen so schneiden, dass Abhängigkeiten reduziert werden (einer der größten Vorteile gegenüber prozeduraler Programmierung).
</details>

---

## 4. STL – Motivation

**F4.1 – Warum sollte man Bibliotheken wie die STL nutzen, statt selbst zu implementieren?**
<details><summary>Antwort</summary>

    Das Problem hat oft schon jemand anderes gelöst – und zwar häufig schneller, effizienter (RAM- und ROM-schonender), besser getestet und besser portierbar. Außerdem spart es Zeit.
    Bibliotheken sollten immer in Betracht gezogen werden. C++ bietet z. B. die STL.
</details>

---

## 5. STL – Aufbau & std-Namespace

**F5.1 – Aus welchen vier Bausteinen besteht die STL?**
<details><summary>Antwort</summary>

    Container, Iteratoren, Algorithmen und Templates.
</details>

**F5.2 – In welchem Namespace liegen die STL-Elemente, und wie findet man den passenden Header?**
<details><summary>Antwort</summary>

    Alle Elemente der STL liegen im std::-Namespace.
    Welcher Header für eine bestimmte Klasse/Funktion nötig ist, findet man über die Referenz der C++-Standardbibliothek (z. B. cppreference – „C++ Standard Library headers").
</details>

---
*Grundlage: OOP mit C++ – Teil 6 (Kapitel 3: Objektorientiertes Design am Beispiel SRP/SOLID; Kapitel 4: Einführung in die STL).*
