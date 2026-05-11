# Grundlagen C++: Vererbung am Beispiel Shape, Rectangle und Triangle

Dieses Beispiel demonstriert die Grundlagen der Vererbung in C++ anhand einer einfachen Klassenhierarchie mit einer Basisklasse `Shape` und den abgeleiteten Klassen `Rectangle` und `Triangle`.

---

## Code-Übersicht

### Der Code

```cpp
#include <iostream>

// Base class
class Shape
{
public:
   Shape(double width, double height)
       : m_width(width), m_height(height)
   {
   }

   ~Shape()
   {
   }

   void setWidth(double width)
   {
      m_width = width;
   }

   void setHeight(double height)
   {
      m_height = height;
   }

   // Can be changed only by child classes (not by any other)
protected:
   double m_width;
   double m_height;
};

// Derived class
class Rectangle : public Shape // Inheritance from Shape class (base class)
{
public:
   Rectangle(double width, double height)
       : Shape(width, height) // Call the constructor of the base class
   {
   }

   ~Rectangle()
   {
   }

   double getArea()
   {
      return m_width * m_height;
   }
};

// Derived class
class Triangle : public Shape // Inheritance from Shape class (base class)
{
public:
   Triangle(double base, double height)
       : Shape(base, height) // Call the constructor of the base class (base -> m_width)
   {
   }

   ~Triangle()
   {
   }

   double getArea()
   {
      return m_width * m_height / 2.0;
   }
};

int main()
{
   Rectangle rect(10, 20);

   std::cout << "--- Call getArea() from Rectangle class ---" << std::endl;
   std::cout << "Area: " << rect.getArea() << std::endl;

   Triangle tri(10, 20);
   std::cout << "--- Call getArea() from Triangle class ---" << std::endl;
   std::cout << "Area: " << tri.getArea() << std::endl;

   return 0;
}

// Was passiert wenn Sie die Methode setWidth() in der Klasse Shape als private deklarieren?
// Was passiert wenn Sie die protected Sektion in der Klasse Shape als private deklarieren?
```

---

## Aufbau des Programms

### 1. Basisklasse `Shape`

- Stellt die gemeinsamen Eigenschaften `m_width` und `m_height` bereit (geschützt, also für abgeleitete Klassen sichtbar).
- Konstruktor initialisiert Breite und Höhe.
- Methoden `setWidth` und `setHeight` erlauben das Setzen der Werte.
- Destruktor vorhanden (hier leer, aber für spätere Erweiterungen nützlich).

### 2. Abgeleitete Klasse `Rectangle`

- Erbt öffentlich von `Shape`.
- Konstruktor ruft den Basisklassen-Konstruktor auf.
- Methode `getArea()` berechnet die Fläche des Rechtecks (`m_width * m_height`).
- Eigener Destruktor (hier leer).

### 3. Abgeleitete Klasse `Triangle`

- Erbt öffentlich von `Shape`.
- Konstruktor übergibt `base` als `m_width` und `height` als `m_height` an die Basisklasse.
- Methode `getArea()` berechnet die Fläche des Dreiecks (`m_width * m_height / 2.0`).
- Eigener Destruktor (hier leer).

### 4. `main()`

- Erstellt ein `Rectangle`-Objekt und gibt dessen Fläche aus.
- Erstellt ein `Triangle`-Objekt und gibt dessen Fläche aus.
- Der Zugriff auf die geschützten Member-Variablen ist außerhalb der Klasse nicht möglich.

---

## Die Ausgabe

### Beispielausgabe

```bash
--- Call getArea() from Rectangle class ---
Area: 200
--- Call getArea() from Triangle class ---
Area: 100
```

- Die Fläche des Rechtecks (10 × 20 = 200) wird berechnet und ausgegeben.
- Die Fläche des Dreiecks (10 × 20 / 2 = 100) wird berechnet und ausgegeben.

---

## Hinweise

- **Vererbung** ermöglicht es, gemeinsame Funktionalität in einer Basisklasse zu definieren und in abgeleiteten Klassen zu erweitern oder zu nutzen.
- `protected`-Member sind in abgeleiteten Klassen sichtbar, aber nicht außerhalb der Klassenhierarchie.
- Würde man `setWidth()` als `private` deklarieren, könnten abgeleitete Klassen und externe Nutzer diese Methode nicht mehr aufrufen.
- Würde man die `protected`-Sektion als `private` deklarieren, könnten abgeleitete Klassen nicht mehr direkt auf `m_width` und `m_height` zugreifen.
- Weitere Informationen zur Vererbung in C++ finden sich in der [C++ Referenz zu Vererbung](https://en.cppreference.com/w/cpp/language/derived_class).
