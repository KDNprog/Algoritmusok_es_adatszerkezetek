# Gray-kód - Feladat megoldása

A Gray-kód generálásának problémáját **rekurzív módszerrel** oldjuk meg.

A Gray-kód egy olyan speciális bináris számsorozat, amelyben az egymást követő számok között pontosan egy bit különbség van. Ez a tulajdonság különösen hasznos különböző területeken, például digitális elektronikában, hibadetektálásban és kódolási technikákban.

A feladat célja, hogy adott n-bit hosszúságú Gray-kódot generáljunk és soronként kiírjunk.

## A Gray-kód felépítése

### Alaptulajdonságok:

- Az n-bites Gray-kód egy 2ⁿ-hosszúságú lista bináris számokból.
- Az egymást követő számok között csak egyetlen bit különbözik (Hamming-távolságuk 1).
- Az n = 1 Gray-kód egyszerű: ["0","1"].

### Rekurzív szerkezet:

- Egy n-bites Gray-kód az n − 1-bites Gray-kódból generálható:
  - Az n − 1-es Gray-kód elemeit "0"-val egészítjük ki az elejükön.
  - Az n − 1-es Gray-kód elemeit fordított sorrendben "1"-gyel egészítjük ki az elejükön.

## A feladat megoldásának menete

### 1. Alapeset

A program a következő adatokat várja bemenetként:

- Ha n = 1:
  - A Gray-kód: ["0","1"].

Ez az alapeset, amelyet közvetlenül visszaadunk, mivel itt nincs szükség további számításra.

### 2. Rekurzió

A **rekurzió** az a módszer, amikor egy függvény önmagát hívja meg kisebb részfeladatokra.
Például:

- Az n = 2-es Gray-kódot az n = 1-es Gray-kód alapján generáljuk:
  - n = 1: ["0","1"]
  - Első rész: ["0"+"0","0"+"1"] = ["00","01"]
  - Második rész: ["1"+"1","1"+"0"] = ["11","10"]
  - Egyesítés: ["00","01","11","10"]

### 3. Rekurzió általánosítása

- Ha n>1:
  - Generáljuk az n − 1-es Gray-kódot rekurzív hívással!
  - Az n − 1-es Gray-kód első felét "0"-val egészítjük ki.
  - Az n − 1-es Gray-kód második felét fordított sorrendben "1"-gyel egészítjük ki.
  - Visszatérünk az egyesített listával.

### 4. Példa

- n = 3

**Alapeset (n = 1):**

- Gray-kód: ["0","1"]

**Következő szint (n = 2):**

- Előző Gray-kód: ["0","1"]
- Első rész: ["0"+"0","0"+"1"] = ["00","01"]
- Második rész: ["1"+"1","1"+"0"] = ["11","10"]
- Egyesítés: ["00","01","11","10"]

**További szint (n=3):**

- Előző Gray-kód: ["00","01","11","10"]
- Első rész: ["0"+"00","0"+"01","0"+"11","0"+"10"] = ["000","001","011","010"]
- Második rész: ["1"+"10","1"+"11","1"+"01","1"+"00"] = ["110","111","101","100"]
- Egyesítés: ["000","001","011","010","110","111","101","100"]

### 5. Magyarázat

Rekurzív függvény **(gray_codes):**

- Az alapeset (n = 0) egy üres lista ([′′]).
- Rekurzív hívással generáljuk a kisebb Gray-kódot.
- Az első felét "0"-val, a második felét "1"-gyel egészítjük ki.

**Kimenet:**

- Soronként kiírja a Gray-kód elemeit.

## Tesztelés

**Bemenet_1**

    2

**Kimenet_1**

    00
    01
    11
    10

**Bemenet_2**

    3

**Kimenet_2**

    000
    001
    011
    010
    110
    111
    101
    100

## Összefoglalás

Ez a rekurzív megoldás könnyen érthető, jól skálázódik a megadott $n \leq 16$ tartományban, és hatékonyan generálja a Gray-kódot.

Miért Hatékony a rekurzió?

- **Egyszerűség:**
  - A nagyobb n-es problémát kisebb részproblémákra bontja (n−1).
- **Hatékonyság:**
  - Az _O_(2ⁿ) idő- és memóriaigény optimális, mert minden n-bites Gray-kód pontosan egyszer kerül legenerálásra.
