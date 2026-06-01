# Mehrfachvererbung in C++

## Was ist Mehrfachvererbung?

C++ erlaubt es, dass eine Klasse von **mehreren Basisklassen** gleichzeitig erbt. Die abgeleitete Klasse erhält dadurch alle Member und Methoden aller Elternklassen.

```cpp
class MultiFunctionDevice : public Printer, public Scanner { ... };
```

`MultiFunctionDevice` kann damit sowohl `print()` als auch `scan()` aufrufen.

Beispiel: `mehrfachvererbung_tools.cpp`

---

## Das Problem: Ambiguität

Haben mehrere Basisklassen Methoden oder Member mit **demselben Namen**, weiß der Compiler nicht, welche Version gemeint ist:

```cpp
mfd.turnOn();        // FEHLER: Printer::turnOn() oder Scanner::turnOn()?
mfd.m_isCalibrated;  // FEHLER: Printer::m_isCalibrated oder Scanner::m_isCalibrated?
```

Der Compiler verweigert die Übersetzung – das Programm lässt sich nicht bauen.

---

## Scheinlösung: Explizite Qualifizierung

Die Ambiguität kann durch explizite Angabe der Klasse aufgelöst werden:

```cpp
mfd.Printer::turnOn();  // explizit: Printer-Version (Nicht optimal)
mfd.Scanner::turnOn();  // explizit: Scanner-Version (Nicht optimal)
```

### Nachteile dieser Lösung

| Problem | Erklärung |
|---|---|
| **Enge Kopplung** | Der aufrufende Code muss wissen, von welcher Basisklasse die Methode stammt |
| **Fehleranfällig** | Wird eine Basisklasse umbenannt oder entfernt, bricht jede explizite Referenz |
| **Keine klare Semantik** | Ein `MultiFunctionDevice` soll einfach `turnOn()` können – nicht zwei separate Geräte einschalten |
| **Doppelte Datenhaltung** | `m_isCalibrated` existiert zweifach im Objekt, obwohl logisch nur ein Zustand gemeint ist |

Kurz: Der Code funktioniert zwar, ist aber schwer wartbar und fehleranfällig.

---

## Warum Ambiguität generell vermieden werden sollte

Ambiguität ist ein Zeichen, dass das Klassenmodell **nicht klar genug strukturiert** ist. In größeren Codebases führt sie zu:

- schwer lesbarem Code durch ständige Scope-Auflösung (`Printer::`)
- versteckten Bugs, wenn versehentlich die falsche Implementierung aufgerufen wird
- erhöhtem Wartungsaufwand bei Änderungen an Basisklassen

---

## Lösung: Interfaces (abstrakte Klassen)

In C++ gibt es kein eigenes `interface`-Schlüsselwort wie in Java oder C#. Der gleiche Effekt wird durch **abstrakte Klassen** erreicht: Klassen, die ausschließlich rein virtuelle Methoden und **keine Member-Variablen** enthalten.

Beispiel: `mehrfachvererbung_tools_interface.cpp`

```cpp
class IPrinter {
public:
    virtual void print() = 0;
    virtual void turnOn() = 0;
    virtual bool isCalibrated() = 0;
    virtual ~IPrinter() = default;
};

class IScanner {
public:
    virtual void scan() = 0;
    virtual void turnOn() = 0;
    virtual bool isCalibrated() = 0;
    virtual ~IScanner() = default;
};

class MultiFunctionDevice : public IPrinter, public IScanner {
public:
    void print() override { /* ... */ }
    void scan() override  { /* ... */ }
    void turnOn() override { /* ... */ }        // eine Implementierung für beide Interfaces
    bool isCalibrated() override { /* ... */ }  // eine Implementierung für beide Interfaces

private:
    bool m_isCalibrated = true; // Member-Variable nur einmal, in der konkreten Klasse
};
```

### Warum funktioniert das?

- Interfaces definieren nur was eine Klasse kann, keine **Implementierung** (wie sie es tut)
- Es gibt keine doppelten Member-Variablen → kein Datenduplikat
- `MultiFunctionDevice` stellt **eine** `turnOn()`-Implementierung bereit, die beide Interfaces erfüllt
- Der aufrufende Code arbeitet sauber gegen das Interface: `IPrinter& p = mfd; p.turnOn();`

### Vergleich

| | Mehrfachvererbung mit Implementierung | Interfaces (abstrakte Klassen) |
|---|---|---|
| Ambiguität bei gleichen Methoden | Ja | Nein – eine Override-Implementierung |
| Datenduplikate | Möglich (`m_isCalibrated` 2×) | Nein – keine Member-Variablen |
| Kopplung | Eng (Scope-Auflösung nötig) | Lose (nur gegen Interface programmiert) |
| Wartbarkeit | Gering | Hoch |

---

## Exkurs: Diamond-Problem & virtual inheritance

Wird eine gemeinsame Basisklasse (`IDevice`) über mehrere Pfade geerbt, entsteht das sog. **Diamond-Problem**:

```
      IDevice
     /       \
 Printer   Scanner
     \       /
  MultiFunctionDevice
```

Ohne Gegenmaßnahme existiert `IDevice` zweimal in `MultiFunctionDevice`. C++ löst das mit **virtual inheritance**:

```cpp
class Printer : public virtual IDevice { ... };
class Scanner : public virtual IDevice { ... };
```

`IDevice` existiert dann nur noch **einmal** im Objekt. Wichtig: Implementieren sowohl `Printer` als auch `Scanner` dieselbe virtuelle Methode (z. B. `turnOn()`), entsteht dennoch Ambiguität – der Compiler kann nicht entscheiden, welche Implementierung für den einen vtable-Slot genutzt wird. `MultiFunctionDevice` muss die Methode dann explizit überschreiben und beide Elternimplementierungen ggf. manuell aufrufen:

```cpp
void turnOn() override
{
    Printer::turnOn();
    Scanner::turnOn();
}
```

> Virtual inheritance löst das **Subobject-Problem**, nicht das **Override-Konflikt-Problem**.
