C++ Test-Suite
===============

- [C++ Test-Suite](#c---test-suite)
  * [Unit-Tests](#unit-tests)
    + [Was sind Unit-Tests](#was-sind-unit-tests)
    + [Nutzen von Unit-Tests](#nutzen-von-unit-tests)
    + [C++ Tools für Unit-Tests](#c---tools-f-r-unit-tests)
  * [Catch2](#catch2)
    + [Vorteile](#vorteile)
    + [Nachteile](#nachteile)
    + [Setup](#setup)
  * [Google vs Catch2 vs Boost](#google-vs-catch2-vs-boost)
    + [Catch2](#catch2-1)
    + [Boost.Test](#boosttest)
    + [Google Test](#google-test)
    + [Vergleichs Tabelle](#vergleichs-tabelle)
    + [Fazit](#fazit)
    + [Verwendungs](#verwendungs)
  * [Code Coverage](#code-coverage)
    + [Was ist Code Coverage](#was-ist-code-coverage)
    + [Nutzen von Code Coverage](#nutzen-von-code-coverage)
    + [Guter Coverage Wert](#guter-coverage-wert)
  * [Continuous Integration](#continuous-integration)
    + [Was ist Continuous Integration](#was-ist-continuous-integration)
    + [Nutzen von Continuous Integration](#nutzen-von-continuous-integration)
    + [Continuous Integration Platformen](#continuous-integration-platformen)



## Unit-Tests

### Was sind Unit-Tests

### Nutzen von Unit-Tests

### C++ Tools für Unit-Tests

## Catch2 

### Vorteile

### Nachteile

### Setup

## Google vs Catch2 vs Boost

### Catch2

1. Header only
   
2. [Unterstützt Unit-Tests im BDD-Stil](https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#bdd-style)
3. Einfaches Setup
4. Unterstützt keine Mocking Objekte.
5. Das REQUIRE-Makro für fast jeden Vergleich.
6. Einfach zu verwenden.

### Boost.Test

1. Unterstützt datengesteuerte Tests seit 1.60
2. Sehr nützlich für zufällige Tests, bei denen Daten generiert werden.

3. Keine Unterstützung für Mocking Objekte, obwohl boost.turtle eine möglichkeit wäre.

4. Unterstützt Header only und lib includes.
  
#### Setup

[Ausführliche Beschreibung aller Varianten](https://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/boost_test/usage_variants.html)

### Google Test

1. Unterstützt Death Tests (Segfaults, Memory Corruption...)

2. Wird mit [Google Mock](https://github.com/google/googletest/tree/master/googlemock) zusammen Deployed
3. Mocking ist out of the Box verfügbar

4. Muss als Source File in das Projekt eingebettet werden, um mit dem Rest des Codes zu kompilieren.

5. Viele verschiedene Makros

6. Man muss sich ein bisschen mehr merken als bei Boost.Test und Catch in diesem Bereich

### Vergleichs Tabelle

<table style="width: 40%;" border="1">
<tbody>
<tr>
 <td align = "center">Feature</td>
 <td align = "center">Boost.test</td>
 <td align = "center">Aeryn</td>
 <td align = "center">FRUCTOSE</td>
 <td align = "center">CxxTest</td>
 <td align = "center">Catch2</td>
 <td align = "center">Google-Test</td>
</tr>
<tr>
 <td align = "center">Benötigt modernen Compiler</td>
 <td align = "center">Ja</td>
 <td align = "center">Ja</td>
 <td align = "center">Nein</td>
 <td align = "center">Nein</td>
 <td align = "center">Ja</td>
 <td align = "center">Ja</td>
</tr>
<tr>
 <td align = "center">Externe abhängigkeiten</td>
 <td align = "center">Boost.test</td>
 <td align = "center">Keine</td>
 <td align = "center">/</td>
 <td align = "center">Perl oder Python</td>
 <td align = "center">Keine</td>
 <td align = "center">Google-Test Deps</td>
</tr>
<tr>
 <td align = "center">Automatisch Generierte Test Umgebung</td>
 <td align = "center">Ja</td>
 <td align = "center">Ja</td>
 <td align = "center">Nein</td>
 <td align = "center">Ja</td>
 <td align = "center">Ja</td>
 <td align = "center">Ja</td>
</tr>
<tr>
 <td align = "center">Assertion Makros</td>
 <td align = "center">Good</td>
 <td align = "center">Ausreichend</td>
 <td align = "center">Sehr gut</td>
 <td align = "center">Sehr gut</td>
 <td align = "center">Sehr gut</td>
 <td align = "center">Sehr gut</td>
</tr>
<tr>
 <td align = "center">Output format</td>
 <td align = "center">Gut lesbar und xml</td>
 <td align = "center">Gut lesbar und anpassbar</td>
 <td align = "center">Gut lesbar</td>
 <td align = "center">Gut lesbar, anpassbar und mit GUI</td>
 <td align = "center"> <a href= "https://github.com/catchorg/Catch2/blob/master/docs/reporters.md"> Eigenes modulares Reporter System</td>
 <td align = "center">Gut lesbar</td>
</tr>
</tbody>
</table>

### Anwendungsbereich

### Fazit
Alle 3 Frameworks unterstützen die automatische Registrierung von Test-Cases. Jedes Framework hat seine stärken und schwächen, für eine vollständige Lösung, würde ich Google-Test empfehlen. Wenn datengesteuertes Testen für Sie nützlich sind, können Sie Boost.Test + Boost.Turtle verwenden. Catch2 ist kleiner und nicht so umfangreich, aber auch leichter, wenn Sie nur eine Reihe von Unit-Tests durchführen möchten. Es macht einen sehr guten Job für Header-only.



## Code Coverage

### Was ist Code Coverage

### Nutzen von Code Coverage

### Guter Coverage Wert

## Continuous Integration

### Was ist Continuous Integration

### Nutzen von Continuous Integration

### Continuous Integration Platformen

### <center>Codacy: [![Codacy Badge](https://api.codacy.com/project/badge/Grade/ffcc1b9424a54e399835eec803eef58f)](https://www.codacy.com/app/timweissenfels7/Catch2-Tests?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=ChooseYourPlan/Catch2-Tests&amp;utm_campaign=Badge_Grade) 

#### <p style="border:3px; border-style:solid; border-color:#34d158; padding: 1em;">CircleCI   Master Branch: [![CircleCI](https://circleci.com/gh/ChooseYourPlan/Catch2-Tests/tree/dev.svg?style=svg)](https://circleci.com/gh/ChooseYourPlan/Catch2-Tests/tree/master) CircleCI Dev Branch: [![CircleCI](https://circleci.com/gh/ChooseYourPlan/Catch2-Tests/tree/dev.svg?style=svg)](https://circleci.com/gh/ChooseYourPlan/Catch2-Tests/tree/dev)</p>

#### <p style="border:3px; border-style:solid; border-color:#d13434; padding: 1em;"> Codecov Master Branch: [![codecov](https://codecov.io/gh/ChooseYourPlan/Catch2-Tests/branch/master/graph/badge.svg)](https://codecov.io/gh/ChooseYourPlan/Catch2-Tests) <span>Codecov Dev Branch: [![codecov](https://codecov.io/gh/ChooseYourPlan/Catch2-Tests/branch/dev/graph/badge.svg)](https://codecov.io/gh/ChooseYourPlan/Catch2-Tests)</span></p>

#### <p style="border:3px; border-style:solid; border-color:#34d158; padding: 1em;">Travis-ci Dev Branch: [![Build  ](https://travis-ci.com/ChooseYourPlan/Catch2-Tests.svg?branch=dev)](https://travis-ci.com/ChooseYourPlan/Catch2-Tests) Travis-ci   Master Branch: [![Build  ](https://travis-ci.com/ChooseYourPlan/Catch2-Tests.svg?branch=master)](https://travis-ci.com/ChooseYourPlan/Catch2-Tests) </p>

#### <p style="border:3px; border-style:solid; border-color:#73a816; padding: 1em;"> Coveralls Master Branch: [![Coverage  ](https://coveralls.io/repos/github/ChooseYourPlan/Catch2-Tests/badge.svg)](https://coveralls.io/github/ChooseYourPlan/Catch2-Tests)  Coveralls   Dev Branch: [![Coverage  ](https://coveralls.io/repos/github/ChooseYourPlan/Catch2-Tests/badge.svg?branch=dev)](https://coveralls.io/github/ChooseYourPlan/Catch2-Tests?branch=dev)
