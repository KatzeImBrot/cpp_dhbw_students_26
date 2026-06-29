# Berechnung der absoluten Luftfeuchtigkeit in C++

## 01_const - Implementierung: const Variablen

C++-Programm zur Berechnung der absoluten Luftfeuchtigkeit (in g/m³) basierend auf:

* **Temperatur in Grad Celsius**
* **relativer Luftfeuchtigkeit in Prozent**

---

### Verwendete Formel

Die absolute Luftfeuchtigkeit (AH) gibt an, wie viel Gramm Wasserdampf sich in einem Kubikmeter Luft befinden:

$$
\rho_{abs} = \frac{6{,}112 \cdot \exp\left(\frac{17{,}67 \cdot T}{T + 243{,}5}\right) \cdot r_H \cdot 2{,}1674}{273{,}15 + T}
$$

Dabei gilt:

* **T** = Temperatur in °C
* **r_H** = relative Luftfeuchtigkeit in %
* **ρ_abs** = absolute Luftfeuchtigkeit in g/m³

### Konstanten in der Formel

- **6,112**: Sättigungsdampfdruck bei 0 °C (Magnus-Formel, Basiswert in hPa)
- **17,67**: Magnus-Koeffizient A (empirischer Wert für Wasser)
- **243,5**: Magnus-Koeffizient B in °C (empirischer Wert für Wasser)
- **2,1674**: Umrechnungsfaktor aus idealer Gasgleichung (für Einheit g/m³)
- **273,15**: Kelvin-Offset (Umrechnung von °C nach Kelvin)



### Beispielausgabe

**Eingabe:**

```bash
Temperatur in °C: 20
Relative Luftfeuchtigkeit in %: 50
```

**Ausgabe:**

```bash
Absolute Luftfeuchtigkeit: 8.63909 g/m³
```

### Anwendung

Diese Berechnung ist nützlich z. B. für:

* **Klimaanlagensteuerung**
* **Wohnklimaregelung / Hausautomation (z. B. mit Home Assistant)**
* **Wetter- oder Umweltmesssysteme**

### Hinweis

Die Formel basiert auf einer vereinfachten Näherung zur Sättigungsdampfdruckberechnung (Magnusformel) und liefert praxisnahe Ergebnisse für Temperaturen von ca. 0–40 °C.

---

## 02_const_constexp_static - Implementierung: Verwendung von const in Methoden und Member-Variablen

Um die Verwendung von `const` in Methoden und Member-Variablen zu demonstrieren, wurde das Beispiel erweitert. Die neue Implementierung verwendet eine Klasse `HumidityCalculator`, die die absolute Luftfeuchtigkeit berechnet.

Die Klasse `HumidityCalculator` enthält:

* **`const` Member-Variable**: `m_sensorData` (vom Typ SensorData) ist konstant und kann nach der Initialisierung nicht geändert werden.
* **`const` Methoden**: Methoden wie `calculateAbsoluteHumidity`, `getTemperature`, und `getHumidity` ändern keine Member-Variablen.
* **SensorData struct**: Fasst Temperatur und relative Luftfeuchtigkeit in einer Struktur zusammen.

### Erweiterung: Verwendung von constexpr und static

Um die Effizienz und Sicherheit des Codes zu erhöhen, wurde die Verwendung von `constexpr` ergänzt. `constexpr` ermöglicht die Berechnung von Werten zur Compile-Zeit, wodurch Laufzeitkosten reduziert werden.
`static` sorgt dafür, dass der Wert einmalig zur Compile-Time im Speicher angelegt wird und nicht bei jeder Instanziierung der Klasse neu (eigener Speicherbereich für Static-Variablen). 

In der Klasse `HumidityCalculator` werden alle Formelkonstanten als `static constexpr` definiert:

```cpp
static constexpr double MAGNUS_BASE_HPA{6.112};
static constexpr double MAGNUS_COEFF_A{17.67};
static constexpr double MAGNUS_COEFF_B_C{243.5};
static constexpr double HUMIDITY_CONVERSION_FACTOR{2.1674};
static constexpr double KELVIN_OFFSET{273.15};
// Compile-Zeit-Berechnung: Kombination zweier Konstanten
static constexpr double MAGNUS_HUMIDITY_FACTOR{MAGNUS_BASE_HPA * HUMIDITY_CONVERSION_FACTOR};
```

Diese Werte werden zur Compile-Zeit berechnet und sind während der Laufzeit verfügbar. Der `MAGNUS_HUMIDITY_FACTOR` demonstriert besonders die Compile-Zeit-Berechnung: Der Compiler berechnet `6.112 * 2.1674 = 13.247088` bereits beim Kompilieren, nicht erst zur Laufzeit. Durch die benannten Konstanten ist die Formel in der Methode `calculateAbsoluteHumidity` deutlich lesbarer und wartbarer.

---

## 03_static - Implementierung: Verwendung von static in Member-Variablen

Die Implementierung `03_static` demonstriert die Verwendung von `static` Member-Variablen in der Klasse `HumidityCalculator`. Dies ermöglicht die Verfolgung der Anzahl der zur Laufzeit erstellten Instanzen.

Hauptmerkmale:

* **Statische Member-Variable**: `m_instanceCount` ist eine statische Variable, die die Gesamtzahl der Instanzen der Klasse `HumidityCalculator` verfolgt.
* **Instanzzählung**: Die Methode `getInstanceCount` bietet Zugriff auf die aktuelle Anzahl der Instanzen.
* **Destruktor-Protokollierung**: Der Destruktor protokolliert, wann eine Instanz zerstört wird, und bietet Einblicke in das Management des Objektlebenszyklus.

---

## 04_auto - Implementierung: Verwendung des Keywords auto

Die Implementierung `04_auto` demonstriert die Verwendung des Keywords `auto` in C++. Das Keyword `auto` ermöglicht es dem Compiler, den Typ einer Variablen automatisch basierend auf dem zugewiesenen Wert zu bestimmen. Dies kann den Code lesbarer und flexibler machen.

Hauptmerkmale:

* **Automatische Typbestimmung**: Mit `auto` kann der Compiler den Typ einer Variablen automatisch ableiten, was die Lesbarkeit verbessert und den Code flexibler macht.
* **Beispielverwendung in main.cpp**: 
  - `const auto humCalculator{HumidityCalculator(sensorData)};`

Hinweis:

Die Verwendung von `auto` sollte mit Bedacht erfolgen, da sie die Lesbarkeit des Codes beeinträchtigen kann, wenn der Typ nicht sofort ersichtlich ist. Es ist ratsam, `auto` nur dann zu verwenden, wenn der Typ klar aus dem Kontext hervorgeht oder die Typ-Deklaration sehr lang und komplex wäre.

## 05_friend - Implementierung: Verwendung des Keywords friend

Die Implementierung `05_friend` demonstriert die Verwendung des Keywords `friend` in C++. Das Keyword `friend` ermöglicht es einer Funktion oder Klasse, auf private und geschützte Member einer anderen Klasse zuzugreifen, ohne dass diese Member öffentlich gemacht werden müssen. Dies kann nützlich sein, um den Zugriff auf bestimmte Daten zu ermöglichen, ohne die Kapselung zu verletzen.

Hauptmerkmale:

* **Friend-Klasse**: `HumidityCalculatorTester` ist als friend der Klasse `HumidityCalculator` deklariert
* **Zugriff auf private Member**: Die Tester-Klasse kann auf alle privaten Member zugreifen
* **Typische Anwendung**: Testing, Debugging oder eng gekoppelte Hilfsklassen

---

## Zusammenfassung des Keywords-Projekts

### Vorteile der Verwendung von const in Methoden und Member-Variablen

* **Sicherheit**: `const` stellt sicher, dass Member-Variablen nicht versehentlich geändert werden.
* **Sicherheit**: `const` stellt sicher, dass Methoden keine unerwarteten Änderungen vornehmen.
* **Lesbarkeit**: Der Code ist klarer und zeigt die Absicht, dass bestimmte Werte unveränderlich sind.
* **Optimierung**: Der Compiler kann Optimierungen vornehmen, da er weiß, dass bestimmte Werte konstant sind.

### Vorteile von constexpr (Compile-Time Constants)

* **Compile-Zeit-Berechnung**: Werte, die mit `constexpr` deklariert sind, werden bereits zur Compile-Zeit berechnet, was die Effizienz erhöht. Beispiel: `MAGNUS_HUMIDITY_FACTOR{MAGNUS_BASE_HPA * HUMIDITY_CONVERSION_FACTOR}` wird vom Compiler zu `13.247088` vorberechnet.
* **Konstante Werte**: `constexpr` stellt sicher, dass die Werte unveränderlich sind und zur Laufzeit nicht geändert werden können.
* **Optimierung**: Der Compiler kann Optimierungen vornehmen, da er weiß, dass bestimmte Werte konstant sind.

### Vorteile der constexpr-static-Erweiterung für Member-Variablen

* Die Kombination von `constexpr` und `static` ermöglicht es, Konstanten zu definieren, die zur Compile-Zeit berechnet werden und nur einmal im Speicher abgelegt werden.

### Vorteile der statischen Zuweisung

* **Objektlose Member / Globale Verfolgung**: `static` Member-Variablen ermöglichen die Verfolgung von Daten über alle Instanzen einer Klasse hinweg.
* **Speichereffizienz**: `static` Variablen werden in einem gemeinsamen, speziellen Speicherbereich abgelegt. Das Betriebssystem verwaltet diesen Bereich, wodurch der Speicherverbrauch optimiert wird.
* **Objektlose Methoden**: `static` Methoden haben keinen `this` Zeiger und können ohne Instanz der Klasse aufgerufen werden. Das erhöht die Flexibilität und ermöglicht die Verwendung von Klassenmethoden ohne Instanziierung. Statische Methoden können daher nicht auch `const` sein.

### Vorteile der Verwendung von auto

* **Lesbarkeit**: `auto` verbessert die Lesbarkeit des Codes, da der Typ nicht explizit angegeben werden muss.
* **Flexibilität**: Der Compiler kann den Typ automatisch ableiten, was die Flexibilität erhöht und den Code anpassungsfähiger macht.

### Vorteile der Verwendung von friend

* **Zugriff auf private Member**: `friend` ermöglicht es einer Funktion oder Klasse, auf private und geschützte Member einer anderen Klasse zuzugreifen, ohne diese öffentlich machen zu müssen. Damit können beispielsweise Tests oder Hilfsklassen auf private Daten zugreifen, ohne die Kapselung zu verletzen.
