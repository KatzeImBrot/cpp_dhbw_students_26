# Aufgabe: Bankkonto-Verwaltung mit verschiedenen Kontotypen

## Beschreibung

Entwickeln Sie ein Verwaltungssystem für Bankkonten. Das System soll verschiedene Arten von Konten mit unterschiedlichen Regeln unterstützen und dabei zeigen, wie klassenweite Daten für die Verfolgung von Instanzen genutzt werden können.

## Kontotypen

Ihr System soll folgende drei Kontotypen unterstützen:
- **Girokonto**
- **Tagesgeldkonto**
- **Bausparvertrag**

## Grundlegende Anforderungen

### Eigenschaften aller Konten

Jedes Konto hat:
- **Kontonummer**: 6-stellig, automatisch bei Erstellung zufällig generiert (100000 - 999999)
- **BLZ** (Bankleitzahl): Wird bei Erstellung festgelegt und kann nicht mehr geändert werden
- **Guthaben**: Aktueller Kontostand, startet bei 0

**Hinweis zur Zufallszahl-Generierung:** Nutzen Sie `std::mt19937` aus `<random>` zur Erzeugung der Kontonummer.

### Grundfunktionalität

Jedes Konto muss folgende Operationen unterstützen:
- **Geld einzahlen/auszahlen**: Eine Methode, die sowohl positive (Einzahlung) als auch negative (Auszahlung) Beträge verarbeitet
- **Informationen ausgeben**: Zeigt alle relevanten Kontoinformationen an

### Statistik-Anforderung

Das System soll **automatisch zählen**, wie viele Konten jedes Typs insgesamt erstellt wurden:
- Anzahl der Girokonten
- Anzahl der Tagesgeldkonten  
- Anzahl der Bausparverträge

Es soll eine Möglichkeit geben, diese Zähler jederzeit abzufragen.

## Kontotyp-spezifische Anforderungen

### Girokonto

**Besonderheit: Dispokredit**
- Das Girokonto darf ins Negative gehen
- Auszahlungen sind auch möglich, wenn das Guthaben negativ wird
- Keine Beschränkung nach unten

### Tagesgeldkonto

**Zusätzliche Eigenschaft:**
- **Mindestlaufzeit**: Wird bei Erstellung festgelegt und kann nicht mehr geändert werden

**Besonderheit: Kein Negativsaldo**
- Das Konto **darf nicht** ins Negative gehen
- Auszahlungen, die das Guthaben unter 0 bringen würden, werden abgelehnt
- Bei abgelehnten Operationen: Ausgabe einer Fehlermeldung

### Bausparvertrag

**Zusätzliche Eigenschaft:**
- **Bausparsumme**: Maximalbetrag, der angespart werden kann (unveränderlich)

**Besonderheit: Nur Einzahlungen**
- **Nur Einzahlungen** sind erlaubt (keine Auszahlungen)
- Einzahlungen nur möglich, solange die Bausparsumme nicht erreicht ist
- Wenn eine Einzahlung die Bausparsumme überschreiten würde:
  - Nur der Betrag bis zur Bausparsumme wird eingezahlt
  - Der Rest wird abgelehnt
  - Ausgabe einer entsprechenden Meldung

## Technische Anforderungen

- **Keine Code-Duplikation**: Gemeinsame Funktionalität soll wiederverwendet werden
- **Gekapselter Zugriff**: Werte dürfen nur über Methoden geändert werden (keine public Member-Variablen)
- **Sinnvolle Klassenstruktur**: Überlegen Sie, welche Eigenschaften und Methoden gemeinsam sind und welche spezifisch
- **Unterschiedliches Verhalten**: Die deposit-Methode muss für jeden Kontotyp unterschiedlich funktionieren

## Vorgehen

1. Überlegen Sie sich eine Klassenstruktur
   - Was ist allen Konten gemeinsam?
   - Was unterscheidet die Kontotypen?
2. Implementieren Sie die Zufallszahl-Generierung für Kontonummern
3. Implementieren Sie die Grundfunktionen (einzahlen/auszahlen, Info ausgeben)
4. Implementieren Sie die typ-spezifischen Regeln
5. Fügen Sie die Zählfunktionalität hinzu
6. Testen Sie ausgiebig

## Test-Szenario

Testen Sie Ihr System mit:
- Mindestens 2 Konten pro Typ
- Verschiedenen Ein- und Auszahlungen
- Grenzfällen:
  - Girokonto: Negativer Kontostand
  - Tagesgeldkonto: Versuch, mehr abzuheben als vorhanden
  - Bausparvertrag: Bausparsumme erreichen/überschreiten, Auszahlungsversuch
- Ausgabe der Kontostände nach jeder Operation
- Ausgabe der Zähler zu verschiedenen Zeitpunkten

**Beispiel aus der main.cpp:**
```cpp
Giro myGiro1(12342);
myGiro1.deposit(-1011.1);  // Auszahlung ins Negative
myGiro1.printInfo();

Tagesgeld myTagesgeld(41422, 100);  // BLZ, Mindestlaufzeit
myTagesgeld.deposit(10);
myTagesgeld.deposit(-100);  // Sollte abgelehnt werden

Bausparvertrag myBausparvertrag(3242, 100);  // BLZ, Bausparsumme
myBausparvertrag.deposit(10);
myBausparvertrag.deposit(100);  // Überschreitung der Bausparsumme

BankAccount::printAccountCounts(); //Ausgabe der Zähler
```

---

## Tipps

- Beginnen Sie mit einer Basisklasse für gemeinsame Eigenschaften
- Nutzen Sie Vererbung für die spezifischen Kontotypen
- Überlegen Sie, welche Methoden in den Unterklassen anders implementiert werden müssen
- Die Zähler sollten klassenübergreifend sein - welches Keyword hilft dabei?
- Virtuelle Methoden ermöglichen unterschiedliches Verhalten in Unterklassen
- `const` bei Member-Variablen verhindert spätere Änderungen (BLZ, Mindestlaufzeit, Bausparsumme)
- Eine pure virtual Methode in der Basisklasse erzwingt Implementierung in allen Unterklassen
