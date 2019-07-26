C++ Test-Suite
===============

<img align="right" width="150" height="150" src="https://www.monkeyuser.com/assets/images/2018/86-fixing-unit-tests.png">

- [C++ Test-Suite](#c---test-suite)
  * [Unit-Tests](#unit-tests)
    + [Was sind Unit-Tests](#was-sind-unit-tests)
    + [Nutzen von Unit-Tests](#nutzen-von-unit-tests)
    + [C++ Tools für Unit-Tests](#c---tools-f-r-unit-tests)
  * [Vorgestellte Frameworks - Kurzbeschreibung](#vorgestellte-frameworks---kurzbeschreibung)
    + [Catch2](#catch2)
    + [boost.test](#boosttest)
    + [Google Test](#google-test)
  * [Vorteile](#vorteile)
    + [Catch2-Vorteile](#catch2-vorteile)
    + [Boost.Test-Vorteile](#boosttest-vorteile)
    + [Google Test-Vorteile](#google-test-vorteile)
  * [Nachteile](#nachteile)
    + [Catch2-Nachteile](#catch2-nachteile)
    + [Boost.test-Nachteile](#boosttest-nachteile)
    + [Google Test-Nachteile](#google-test-nachteile)
  * [Setup](#setup)
    + [Catch2-Setup](#catch2-setup)
    + [Boost.test-Setup](#boosttest-setup)
    + [Google Test-Setup](#google-test-setup)
  * [Test-Beispiele](#test-beispiele)
    + [Catch2](#catch2-1)
    + [boost.test](#boosttest-1)
    + [Google Test](#google-test-1)
    + [Vergleichs Tabelle](#vergleichs-tabelle)
  * [Fazit](#fazit)

## Unit-Tests

### Was sind Unit-Tests
Ein Unit Test ist ein funktionaler Test eines Teils einer Software, um die Korrektheit eines Codeblocks zu testen. Ein Unit Test ist automatisiert, d.h. er wird von einem Unit Testing Framework/Unit Testing Tool und nicht von einem Menschen manuell durchgeführt.
### Nutzen von Unit-Tests
Der Vorteil eines Unit Testes ist, dass schneller und damit häufiger getestet werden kann als bei manuellen Tests. Somit können Fehler (insbesondere Regressionsfehler, die sich durch Änderungen am Programmcode ergeben haben) zeitnah festgestellt werden. Unit Tests erlauben die automatisierte, wiederholbare und kontinuierliche Prüfung von Code. 

### C++ Tools für Unit-Tests
 * Cantata: Kommerzielles Werkzeug für Modultests, Modulintegrationstests und Überdeckungstests von C und C++ Code.
 * CppUnit: die Portierung von JUnit auf C++.
 * cfix:Spezialisiert für Win32 und Windows NT kernel mode-Entwicklung. Basierend auf cfix existiert mit Visual Assert ein Add-In, welches Visual Studio um Unit Testing-Funktionalität erweitert.
 * CUTE: ein simples, erweiterbares C++ Unit Testing Framework mit einem an JUnit angelehnten Plugin für Eclipse CDT.

 * Boost Test Library
 * libunittest: Eine portable Testbibliothek basierend auf C++11.
 * TESSY: Professionelles Werkzeug für Modul-/Unit-Tests, speziell von Embedded Software.
 * Testwell CTA++: C++ Test Aider
 * Testwell ctc++: Test Coverage Analyser für Modul-/Unit-Tests (C, C++, Java, C#)
 * Time Partition Testing (TPT): Modellbasiertes Testen eingebetteter Steuerungs- und Regelungssysteme.
 * Qt: unterstützt Modultests (QTestLib).
 * Google Test: von Google entwickeltes C++-Test-Framework.

## Vorgestellte Frameworks - Kurzbeschreibung

### Catch2
Catch2 ist ein [Multi-Paradigma](https://de.wikipedia.org/wiki/Programmierparadigma)-Testframework für C++. Es unterstützt auch Objective-C (und vielleicht C). Es wird als header only released, obwohl für bestimmte Erweiterungen möglicherweise zusätzliche Header erforderlich sind.

### boost.test
Boost.Test ist eine Unit-Testing Bibliothek für C++ 03 und C++ 11/14, die auf einer Vielzahl von Plattformen und Compilern verfügbar ist.

Die Bibliothek ist Teil von Boost. Die neueste Version der Bibliothek ist auf der [Boost-Website](https://www.boost.org/users/download/) verfügbar.

### Google Test
Das Google C++ Testing framework basiert auf der [xUnit](https://de.wikipedia.org/wiki/XUnit) Architektur. Es ist ein plattformübergreifendes framework, das automatische test discovery liefert. Tests müssen nicht  wir nicht manuell registriert werden. Es unterstützt eine Vielzahl von Assertions: fatal assertion (ASSERT_), non-fatal assertions (EXPECT_). Des Weiteren unterstützt es death tests.

## Vorteile

### Catch2-Vorteile

1. Header only
   
2. [Unterstützt Unit-Tests im BDD-Stil](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#bdd-style)
3. Einfaches Setup
4. Unterstützt keine Mocking Objekte.
5. Das REQUIRE-Makro für fast jeden Vergleich.
6. Einfach zu verwenden.

### Boost.Test-Vorteile

1. [Unterstützt datengesteuerte Tests seit 1.60](https://www.boost.org/users/history/version_1_60_0.html)
2. Sehr nützlich für zufällige Tests, bei denen Daten generiert werden.

3. Keine Unterstützung für Mocking Objekte, obwohl boost.turtle eine Möglichkeit wäre.

4. Unterstützt Header only und lib includes.

### Google Test-Vorteile

1. Unterstützt Death Tests (Segfaults, Memory Corruption...)

2. Wird mit [Google Mock](https://github.com/google/googletest/tree/master/googlemock) zusammen Deployed
3. Mocking ist out of the Box verfügbar

4. Muss als Source File in das Projekt eingebettet werden, um mit dem Rest des Codes zu kompilieren.

5. Viele verschiedene Makros

6. Es muss sich ein bisschen mehr gemerkt werden im Vergleich zu Boost.Test und Catch
 
8. Fatal und non-fatal assertions

## Nachteile

### Catch2-Nachteile

1. Compilation times könnten in Zukunft oder bei falscher Verwendung stark ansteigen
 
3. [Keine Eigen Optimierung](https://github.com/catchorg/Catch2/blob/master/docs/slow-compiles.md)
4. Keine thread safe assertion macros
5. Aus 4 resultierend kein Multi-Threading
6. Nur Serielle Tests keine parallelen
7. [Bekannte Probleme mit VS](https://github.com/catchorg/Catch2/blob/master/docs/limitations.md#visual-studio-2017----raw-string-literal-in-assert-fails-to-compile)

### Boost.test-Nachteile
1. Viel Template Programmierung
  
2. Aus 2 resultierend schwer zu findende Fehler
3. In Verbindung mit boost.turtel -> Nicht virtuelle Methoden können nicht gemocked werden 
4. In Verbindung mit boost.turtel -> Template Methoden können nicht gemocked werden
5.  In Verbindung mit boost.turtel -> Methoden mit dem throw keyword können nicht gemocked werden

### Google Test-Nachteile
1. Googles thread-safe Implementation ist auf Systemen verfügbar, auf denen die pthreads-Bibliothek verfügbar ist. 

2. Es ist nicht sicher, Google Test assertions von zwei Threads aus gleichzeitig zu verwenden.

3. Aufwändigste Installation

4. Möglicher Bug mit Shared Objects? [#247](https://github.com/google/googletest/issues/247)

## Setup

### Catch2-Setup

[Auführung aller Varianten](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#where-to-put-it)

<u>Header-Only:</u>
Alles, was zu tun ist, die Datei an einer Stelle abzulegen, die vom Ihrem Projekt aus erreichbar ist.
Der Header kann dann über: `#include <PFAD/catch.hpp>`

### Boost.test-Setup

[Ausführliche Beschreibung aller Varianten](https://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/boost_test/usage_variants.html)

<u>Header-Only:</u>
Bei dieser Variante muss wie aus dem Namen schon hervorgeht nur der einzelne Header eingebunden werden: `#include <boost/test/included/unit_test.hpp>`, es ist nicht erforderlich, eine Bibliothek zulinken. 

### Google Test-Setup

<u>Anleitung des Setups unter Ubuntu:</u>

Den Anfang macht das gtest development Packet:
`sudo apt-get install libgtest-dev`

Das Development Packet installiert die benötigten Quelldateien.

Nun sollten die Dateien in `/usr/src/gtest` liegen, von hier an braucht es CMake.

```bash
sudo apt-get install cmake # installiert cmake 

cd /usr/src/gtest

sudo cmake CMakeLists.txt  

sudo make 
 
#Kopiert libgtest.a and libgtest_main.a in den /usr/lib Ordner.

sudo cp *.a /usr/lib
```
 https://pastebin.com/GJVJZtrr

## Test-Beispiele

### Catch2
Catch bietet in begleitung des Tutorials sogar einen [kompletten sub-folder](https://github.com/catchorg/Catch2/tree/master/examples) mit Beipielen an.

Beispiel Fakultät von Zahlen:
```C++
#include <catch2/catch.hpp>

int Factorial( int number ) {
   return number <= 1 ? number : Factorial( number - 1 ) * number;  // fail
// return number <= 1 ? 1      : Factorial( number - 1 ) * number;  // pass
}

TEST_CASE( "2: Factorial of 0 is 1 (fail)") {
    REQUIRE( Factorial(0) == 1 );
}

TEST_CASE( "2: Factorials of 1 and higher are computed (pass)") {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}
```
### boost.test
Boost hingegen hat eine etwas andere Test-Struktur.

Beispiel Addition von Zahlen:
```C++
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Add
#include <boost/test/unit_test.hpp>

int add(int i, int j)
{
    return i + j;
}

BOOST_AUTO_TEST_CASE("Add Nums")
{
    BOOST_Require(add(2, 2) == 5);
}
```

### Google Test
Wie auch Catch2 stellt Google einen [kompletten sub-folder](https://github.com/google/googletest/tree/master/googletest/samples) mit Beipielen an.

Beispiel Fakultät von Zahlen:
```C++
int Factorial( int number ) {
   return number <= 1 ? number : Factorial( number - 1 ) * number;  // fail
// return number <= 1 ? 1      : Factorial( number - 1 ) * number;  // pass
}
// Tests factorial of 0.
TEST(FactorialTest, HandlesZeroInput) {
  EXPECT_EQ(1, Factorial(0));
}

// Tests factorial of positive numbers.
TEST(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(40320, Factorial(8));
}
```
[Gute GTest Referenz](http://www.yolinux.com/TUTORIALS/Cpp-GoogleTest.html)

### Vergleichs Tabelle

<table style="width: 40%;" border="3">
<tbody>
<tr>
 <td align = "center">Feature</td>
 <td align = "center">Boost.test</td>
 <td align = "center">CxxTest</td>
 <td align = "center">Catch2</td>
 <td align = "center">Google-Test</td>
</tr>
<tr>
 <td align = "center">Benötigt modernen Compiler(c++11)</td>
 <td align = "center">Ja</td>
 <td align = "center">Nein</td>
 <td align = "center">Ja</td>
 <td align = "center">Ja</td>
</tr>
<tr>
 <td align = "center">Externe Abhängigkeiten</td>
 <td align = "center">Boost.test</td>
 <td align = "center">Perl oder Python</td>
 <td align = "center">Keine</td>
 <td align = "center">Google-Test Deps + cmake</td>
</tr>
<tr>
 <td align = "center">Assertion Makros</td>
 <td align = "center">Gut</td>
 <td align = "center">Sehr gut</td>
 <td align = "center">Sehr gut</td>
 <td align = "center">Sehr gut</td>
</tr>
<tr>
 <td align = "center">Output format</td>
 <td align = "center">Xml Ausgabe</td>
 <td align = "center">Anpassbar und mit GUI</td>
 <td align = "center"> <a href= "https://github.com/catchorg/Catch2/blob/master/docs/reporters.md"> Eigenes modulares Reporter System</td>
 <td align = "center">Xml Ausgabe</td>
</tr>
</tbody>
</table>

## Fazit
Alle 3 Frameworks unterstützen die automatische Registrierung von Test-Cases. Jedes Framework hat seine Stärken und Schwächen, für eine vollständige Lösung, würde ich Google-Test empfehlen. Wenn datengesteuertes Testen für Sie nützlich sind, können Sie Boost.Test + Boost.Turtle verwenden. Catch2 ist kleiner und nicht so umfangreich, aber auch leichter, wenn Sie nur eine Reihe von Unit-Tests durchführen möchten. Es macht einen sehr guten Job für Header-only.

Codacy  : [![Codacy Badge](https://api.codacy.com/project/badge/Grade/ffcc1b9424a54e399835eec803eef58f)](https://www.codacy.com/app/timweissenfels7/Catch2-Tests?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=ChooseYourPlan/Catch2-Tests&amp;utm_campaign=Badge_Grade) </center>

CircleCI   Master Branch: [![CircleCI](https://circleci.com/gh/ChooseYourPlan/Catch2-Tests/tree/dev.svg?style=svg)](https://circleci.com/gh/ChooseYourPlan/Catch2-Tests/tree/master) 

CircleCI Dev Branch: [![CircleCI](https://circleci.com/gh/ChooseYourPlan/Catch2-Tests/tree/dev.svg?style=svg)](https://circleci.com/gh/ChooseYourPlan/Catch2-Tests/tree/dev)</p>

Codecov  Master Branch: [![codecov](https://codecov.io/gh/ChooseYourPlan/Catch2-Tests/branch/master/graph/badge.svg)](https://codecov.io/gh/ChooseYourPlan/Catch2-Tests) 

Codecov Dev Branch: [![codecov](https://codecov.io/gh/ChooseYourPlan/Catch2-Tests/branch/dev/graph/badge.svg)](https://codecov.io/gh/ChooseYourPlan/Catch2-Tests)

Travis-ci   Dev Branch: [![Build  ](https://travis-ci.com/ChooseYourPlan/Catch2-Tests.svg?branch=dev)](https://travis-ci.com/ChooseYourPlan/Catch2-Tests) 

Travis-ci   Master Branch: [![Build  ](https://travis-ci.com/ChooseYourPlan/Catch2-Tests.svg?branch=master)](https://travis-ci.com/ChooseYourPlan/Catch2-Tests) </p>

Coveralls   Master Branch: [![Coverage  ](https://coveralls.io/repos/github/ChooseYourPlan/Catch2-Tests/badge.svg)](https://coveralls.io/github/ChooseYourPlan/Catch2-Tests) 
 
 Coveralls Dev Branch: [![Coverage  ](https://coveralls.io/repos/github/ChooseYourPlan/Catch2-Tests/badge.svg?branch=dev)](https://coveralls.io/github/ChooseYourPlan/Catch2-Tests?branch=dev)
