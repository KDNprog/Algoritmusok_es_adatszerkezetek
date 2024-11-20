# Koncertjegyek - Feladat megoldása

A program célja, hogy meghatározza minden vásárló által megvásárolt koncertjegy árát az adott feltételek alapján.

A cél, hogy minden vásárlót a lehető legjobban kiszolgáljunk az alábbi szabályok alapján.

## A feladat leírása

Egy koncertre jegyeket árulnak, amelyek különböző árakon érhetők el. A vásárlók érkezési sorrendben érkeznek, és mindegyikük megad egy maximális árat, amelyet hajlandó fizetni egy jegyért. A feladatunk az, hogy minden vásárlónak kijelöljünk egy megfelelő jegyet a következő szabályok alapján:

**Legdrágább elfogadható jegy:**

- A vásárló a legdrágább olyan jegyet kapja meg, amelynek ára nem haladja meg az általa megadott maximális árat.

**Jegyek egyedi kiosztása:**

- Egy jegy csak egyszer adható el. Miután egy vásárló megkapta, az a jegy többet nem elérhető.

**Megfelelő jegy hiánya:**

- Ha egy vásárló számára nincs olyan jegy, amely nem haladja meg az általa megadott maximális árat, akkor -1 a kimenet.

## A feladat megoldásának menete

### 1. Bemenet

A program a következő adatokat várja bemenetként:

**Első sor:**

- Két egész szám, **n** és **m**:
  - **n**: a jegyek száma.
  - **m**: a vásárlók száma.

**Második sor:**

- **n** darab egész szám (**h₁, h₂, ..., hₙ**), amelyek a jegyek árait jelentik.

**Harmadik sor:**

- **m** darab egész szám (**t₁, t₂, ..., tₘ**), amelyek a vásárlók által megadott maximális árakat jelentik.

### 2. Kimenet

A program **m** sort ad vissza. Minden sor:

- Egy vásárló által megvett jegy árát tartalmazza, vagy
- **1**-et, ha a vásárló nem tudott jegyet vásárolni.

### 3. Példa

**_Bemenet:_**

    5 3
    5 3 7 8 5
    4 8 3

**_Kimenet:_**

    3
    8
    -1

### 4. Magyarázat

**Jegyek:**

- Kezdeti állapot: [5, 3, 7, 8, 5].
- Rendezve a multiset: [3, 5, 5, 7, 8].

**Első vásárló (maximális ár: 4):**

- A legdrágább elfogadható jegy: 3.
- Frissített jegyek: [5, 5, 7, 8].

**Második vásárló (maximális ár: 8):**

- A legdrágább elfogadható jegy: 8.
- Frissített jegyek: [5, 5, 7].

**Harmadik vásárló (maximális ár: 3):**

- Nincs megfelelő jegy.
- Kimenet: **-1**.

## C++ megoldás magyarázata

Használt adatszerkezet: **multiset**

A jegyeket egy **multiset** adatszerkezetben tároljuk, amely automatikusan rendezett marad, és lehetővé teszi a gyors keresést és törlést.

### **multiset&lt;int&gt;**

- Tárolja a jegyek árait.
- Rendezett sorrendben tartja az elemeket, beleértve az ismétlődő értékeket is.

**Jegyek hozzáadása**

A jegyeket a bemenet alapján beszúrjuk a multiset-be:

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        tickets.insert(x);
    }

**Keresés és törlés**

- Minden vásárló esetében a **upper_bound** metódust használjuk:
  - Ez a vásárló által megadott maximális ár fölött lévő első elemet keresi meg.
  - Ha nincs ilyen elem, akkor a vásárló nem kap jegyet (**-1**).
- Az **upper_bound** által visszaadott iterátort egyel csökkentjük (**it--**), hogy elérjük a legnagyobb elfogadható jegyet.

- A jegyet eltávolítjuk a **multiset**-ből:

        tickets.erase(it);

**Kimenet**

Minden vásárló eredményét soronként írjuk ki:

    cout << *it << "\n";

## Hatékonysági elemzés

**Keresés (upper_bound):**

- Logaritmikus idő (_O_(log n)).

**Törlés:**

- Szintén logaritmikus idő (_O_(log ⁡n)).

**Összes vásárló:**

- _O_(m ⋅ log⁡ n), ahol **m** a vásárlók száma.

**Teljes komplexitás:**

- _O_((n + m) ⋅ log ⁡n), mivel **n** a jegyek száma.

Ez hatékonyan működik nagy adathalmazokon is
(n, m ≤ 200 000).

## Összefoglalás

Ez a megoldás hatékonyan használja ki a **C++ multiset** adatszerkezetét, amely automatikusan rendezett, és támogatja a gyors keresést és törlést. A program minden vásárlónak biztosítja a legjobb elérhető jegyet, vagy jelzi, ha nem található számára megfelelő opció. A megoldás időkomplexitása elegendően gyors nagy méretű bemenetek kezelésére is.
