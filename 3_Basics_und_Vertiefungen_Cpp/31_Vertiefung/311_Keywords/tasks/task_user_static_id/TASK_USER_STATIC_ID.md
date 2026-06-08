# Aufgabe: User mit automatischer ID-Vergabe

## Beschreibung

Erstellen Sie eine Klasse `User`, bei der jeder User automatisch eine **eindeutige, aufsteigende ID** erhält. Die Klasse soll selbstständig dafür sorgen, dass keine zwei User dieselbe ID haben.

## Anforderungen

### Klasse `User`

**Eigenschaften:**
- Jeder User hat einen **Namen**
- Jeder User hat eine **eindeutige ID**
- Der Name wird bei der Erstellung übergeben
- Die ID wird **automatisch** von der Klasse vergeben

**Konstruktoren:**
- Default-Konstruktor
- Konstruktor mit Name-Parameter

**Methoden:**
- `printInfo()` – Gibt Name und ID des Users aus

## Funktionale Anforderungen

- Die ID-Vergabe muss **automatisch** im Konstruktor erfolgen
- Die erste vergebene ID ist **1**
- Jede weitere ID wird um 1 erhöht
- Die Klasse muss sicherstellen, dass **alle User unterschiedliche IDs** erhalten
- Die IDs müssen **fortlaufend** sein (1, 2, 3, 4, ...)

**Hinweis:** Überlegen Sie sich, wie die Klasse "wissen" kann, welche ID als nächstes vergeben werden muss. Welche Art von Variable könnte von allen User-Objekten gemeinsam genutzt werden?

## Vorgehen

1. Implementieren Sie die Klasse `User` mit Name und ID als Member-Variablen
2. Überlegen Sie, wie Sie einen Zähler für die nächste ID realisieren können
3. Implementieren Sie die Konstruktoren so, dass die ID automatisch zugewiesen wird
4. Implementieren Sie die `printInfo()`-Methode
5. Testen Sie die Klasse durch Anlegen mehrerer User

## Beispielablauf

```cpp
std::vector<User> myUser;
myUser.push_back(User("Erik C."));
myUser.push_back(User("Paul M."));
myUser.push_back(User("Dennis G."));
myUser.push_back(User("Lukas F."));
myUser.push_back(User("Lars P."));

for (auto &user : myUser)
{
    user.printInfo();
}
```

**Erwartete Ausgabe:**
```
Name: Erik C.
ID: 1
Name: Paul M.
ID: 2
Name: Dennis G.
ID: 3
Name: Lukas F.
ID: 4
Name: Lars P.
ID: 5
```

