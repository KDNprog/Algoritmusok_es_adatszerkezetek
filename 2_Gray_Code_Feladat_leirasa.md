# Gray-kód - Feladat leírása

A **Gray-kód** egy 2ⁿ-elemű lista, amely **n**-hosszú bináris számokat tartalmaz. Az egyedi tulajdonsága, hogy az egymást követő elemek között pontosan egy bit különbség van (azaz **Hamming-távolságuk 1**).

## Feladat

- Generáljunk Gray-kódot egy adott n hosszra!
- Írjuk ki a kódokat soronként úgy, hogy minden bináris szám új sorba kerüljön!
- A kimenet lehet bármely érvényes Gray-kód.

## Bemenet

- Egyetlen sorban egy egész szám: **n**, amely az egyes Gray-kódok bitjeinek számát adja meg.

## Kimenet

- 2ⁿ sor, mindegyik egy **n**-bites Gray-kód.

## Feltételek

$$1 \leq n \leq 16$$

## Példa

_Bemenet:_

    2

_Kimenet:_

    00
    01
    11
    10

## Magyarázat

Az **n = 2** Gray-kód minden bináris számot tartalmaz, ahol az egymást követő elemek között pontosan egy bit különbség van:

    00 → 01 → 11 → 10
