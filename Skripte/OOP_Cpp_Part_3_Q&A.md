# Q&A – OOP_Cpp_Part 3.pdf - Pointer/Referenzen & Polymorphismus

> **Zweck:** Kurze Wiederholung, um nach der Vorlesungspause wieder ins Thema zu kommen.
>
> Themen: Speicher, Pointer & Referenzen · Pass by value/reference (C vs. C++) · Polymorphismus · `virtual` & `override` · virtueller Destruktor

---

<!-- markdownlint-disable MD033 -->
## 1. Speicher, Pointer & Referenzen

**F1.1 – Wie ist der Speicher (RAM) grob organisiert?**
<details><summary>Antwort</summary>

    Als Folge von Speicherblöcken. Jeder Block ist ein Byte (= 8 Bit) groß und hat eine eindeutige Adresse.
</details>

**F1.2 – Was speichert ein Pointer, und was bedeutet `float* ptr_x = &x;`?**
<details><summary>Antwort</summary>

    Ein Pointer speichert eine Adresse. `&x` liefert die Adresse von `x`; `ptr_x` enthält danach diese Adresse.
</details>

**F1.3 – Wie groß ist ein `float` und wie groß die Adresse, die auf ihn zeigt (64-Bit-Maschine)?**
<details><summary>Antwort</summary>

    `float`: 4 Byte (32 Bit). Die Adresse: 8 Byte (64 Bit) auf einer 64-Bit-Maschine.
</details>

---

## 2. Pass by value vs. Pass by reference

**F2.1 – Was ist der Unterschied zwischen Pass by value und Pass by reference?**
<details><summary>Antwort</summary>

    - Pass by value: Das Objekt wird kopiert – bei großen Objekten teuer.
    - Pass by reference: Es wird (effektiv) die Adresse übergeben, keine Kopie → Speed-up.
</details>

**F2.2 – Wie sieht Pass by reference in C gegenüber C++ aus?**
<details><summary>Antwort</summary>

    - C: Ein Pointer wird übergeben (`void foo(SomeBigObject* x)`). Vor dem Aufruf referenzieren, in der Funktion dereferenzieren bzw. mit `->` arbeiten. Nicht nullpointer-safe.
    - C++: Eine Referenz mit `&` (`void foo(SomeBigObject& x)`). Vor dem Aufruf nichts, in der Funktion normaler `.`-Zugriff. Nullpointer-safe.
</details>

---

## 3. Polymorphismus

**F3.1 – Was bedeutet Polymorphismus im Kontext der Vererbung?**
<details><summary>Antwort</summary>

    Objekte mit derselben Basisklasse zeigen unterschiedliches Verhalten: Die konkrete Implementierung einer Methode liegt nicht in der Basisklasse, sondern wird in den Kindklassen überschrieben.
</details>

**F3.2 – Welche Vorteile bringt Polymorphismus?**
<details><summary>Antwort</summary>

    - Man kann mit Objekten arbeiten, von denen man nur den Basis-Typ kennt.
    - Ermöglicht Interfaces (was/welche Signatur ist public), ohne das *Wie* der Implementierung festzulegen.
    - Erzeugt eine „Dependency-Firewall": Nutzende sind nur vom Interface abhängig, nicht von der konkreten Implementierung.
    - Schafft eine zusätzliche Abstraktionsebene → Komplexitätsreduktion.
</details>

---

## 4. `virtual` & `override`

**F4.1 – Was bewirkt das Keyword `virtual`?**
<details><summary>Antwort</summary>

    Es ermöglicht Polymorphismus zur Laufzeit über dynamische Bindung: Der Methodenaufruf hängt vom tatsächlichen Objekttyp ab, und die Methode kann in Unterklassen überschrieben werden.
</details>

**F4.2 – Was bedeutet `= 0` bei einer virtuellen Methode?**
<details><summary>Antwort</summary>

    Sie wird zur rein virtuellen Methode, die von Unterklassen implementiert werden muss. Die Klasse selbst wird dadurch zu einer abstrakten Klasse (nicht instanziierbar).

    Beispiel in 231_Einführung_mailHandler erzwingen.
</details>

**F4.3 – Wozu dient `override` (seit C++11)?**
<details><summary>Antwort</summary>

    Es gibt explizit an, dass eine Funktion eine Methode der Basisklasse überschreibt. Vorteile: bessere Lesbarkeit und ein Compiler-Error, falls gar keine Überschreibung stattfindet (z. B. bei Tippfehler in der Signatur).
</details>

---

## 5. Virtueller Destruktor

**F5.1 – Welche Regel gilt für Destruktoren bei Vererbung?**
<details><summary>Antwort</summary>

    Sobald von einer Klasse geerbt wird, muss der Destruktor der Basisklasse `virtual` sein. Am einfachsten: alle Destruktoren virtuell machen.
</details>

**F5.2 – Was passiert, wenn man das vergisst?**
<details><summary>Antwort</summary>

    Der Destruktor der abgeleiteten Klasse wird nicht (korrekt) aufgerufen – das Clean-up läuft nicht wie erhofft. Eine vermeidbare Fehlerquelle (z. B. Ressourcen-/Speicherlecks).
</details>

---
*Grundlage: OOP mit C++ – Teil 3 (Kapitel 2: Polymorphismus, Einschub Pointer & Referenzen).*
