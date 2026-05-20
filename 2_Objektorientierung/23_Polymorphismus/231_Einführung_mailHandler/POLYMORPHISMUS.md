# Polymorphismus – MailHandler Beispiel

## Was ist Polymorphismus?

Polymorphismus (griech. „Vielgestaltigkeit") ermöglicht es, dass ein Zeiger oder eine Referenz auf eine Basisklasse zur Laufzeit das Verhalten der tatsächlichen abgeleiteten Klasse aufruft – nicht das der Basisklasse.

Das Schlüsselwort `virtual` in der Basisklasse aktiviert diesen Mechanismus (sog. **Late Binding** / dynamische Bindung).

---

## Klassenhierarchie

```
Person  (Basisklasse)
├── Professor  (abgeleitet)
└── Student    (abgeleitet)
```

---

## Wie ist es hier eingebaut?

### 1. Virtuelle Methode in der Basisklasse (`Person.hpp`)

```cpp
virtual std::string printSignature();
```

Durch `virtual` wird die Methode für Late Binding markiert. Subklassen können sie überschreiben.

### 2. Überschreiben in den Subklassen (`override`)

```cpp
// Professor.cpp
std::string Professor::printSignature() {
    return "Mit freundlichen Gruessen, " + getName();
}

// Student.cpp
std::string Student::printSignature() {
    return "Hau rein, " + getName();
}
```

Das Schlüsselwort `override` (in den `.hpp`-Dateien) stellt sicher, dass die Methode tatsächlich eine virtuelle Methode der Basisklasse überschreibt – der Compiler meldet einen Fehler, falls nicht.

### 3. Polymorphe Nutzung via Zeiger (`MailHandler.cpp`)

```cpp
void MailHandler::writeMail(Person receiver, Person* sender, std::string mailText)
{
    std::cout << sender->printSignature() << std::endl;
}
```

`sender` ist ein `Person*`. Wird ein `Professor*` oder `Student*` übergeben, ruft `sender->printSignature()` automatisch die **richtige Implementierung** der jeweiligen Klasse auf – das ist Polymorphismus.

### 4. Aufruf in `main.cpp`

```cpp
myMailHandler.writeMail(Frank, &Nina, "Hallo Frank, wie geht es dir?");
```

`&Nina` ist vom Typ `Professor*`, wird aber als `Person*` übergeben. Dennoch wird `Professor::printSignature()` aufgerufen.

---

## Virtueller Destruktor

```cpp
virtual ~Person();
```

Wichtig bei Vererbung mit Zeigern: Ohne `virtual` würde beim Löschen eines `Person*`-Zeigers auf ein `Professor`-Objekt nur der `Person`-Destruktor aufgerufen – der `Professor`-Destruktor würde übersprungen → **Speicherleck**.

---

## Zusammenfassung

| Konzept | Wo im Code |
|---|---|
| `virtual` Methode | `Person.hpp` – `printSignature()` |
| `override` | `Professor.hpp`, `Student.hpp` |
| Polymorphie via Zeiger | `MailHandler.cpp` – `Person* sender` |
| Virtueller Destruktor | `Person.hpp` – `~Person()` |
