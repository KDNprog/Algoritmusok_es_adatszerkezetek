# Csapatépítés - Feladat leírása

Adott **n** tanuló és **m** barátság közöttük. A feladat az, hogy a tanulókat két csapatra osszuk úgy, hogy **egy csapaton belül senki ne legyen barát a másikkal**. A csapatok mérete szabadon választható, azaz nem kell egyenlő méretűeknek lenniük.

## Bemenet

1. Az első sor tartalmazza az nn-et és az mm-et:

   - **n:** tanulók száma.
   - **m:** barátságok száma.

2. A következő **m** sor mindegyike két egész számot **(a,b)** tartalmaz, ami azt jelenti, hogy az **a** tanuló és a **b** tanuló barátok.

## Kimenet

1. Ha a tanulók két csapatra oszthatók a megadott feltételek szerint, akkor:

   - Írjunk ki **n** számot, ahol minden szám vagy **1**, vagy **2**, attól függően, hogy az adott tanuló melyik csapatba tartozik.

2. Ha a tanulók nem oszthatók két csapatra, írjuk ki: **IMPOSSIBLE**.

## Feltételek

$$1 \leq n \leq 10^5$$
$$1 \leq m \leq 2 \cdot 10^5$$
$$1 \leq a,b \leq n$$

Minden barátság különböző tanulók között van, és nincs ismétlődő barátság.

## Példa

_Bemenet:_

    5 3
    1 2
    1 3
    4 5

_Kimenet:_

    1 2 2 1 2

**Magyarázat:**

- Az 1-es tanulót az 1-es csapatba tesszük.
- Az 1-es tanuló barátai, a 2-es és 3-as tanulók, a 2-es csapatba kerülnek.
- A 4-es és 5-ös tanulók különálló baráti kapcsolatban vannak, ezért ők külön csapatokba kerülnek.

## Magyarázat

Ez a probléma **gráfokra** vezethető vissza, ahol:

- A tanulók a gráf csúcsai.
- A barátságok a gráf élei.

A feladat lényegében annak vizsgálata, hogy a gráf kétkomponensű (bipartit) tulajdonságú-e:

- Ha a gráf kétkomponensű, akkor a csúcsokat (tanulókat) két csoportra (csapatra) oszthatjuk.
- Ha nem, akkor az osztás nem lehetséges.

**Algoritmus:**

1. **Gráf építése:**
   - Használjunk szomszédsági listát a barátságok tárolására.
2. **Színezés (csapatok elosztása):**
   - Indítsunk egy **DFS**-t vagy **BFS**-t, és próbáljuk meg a gráf csúcsait váltakozó módon színezni:
   - Egy csúcsot az 1-es csapathoz (szín: 1).
   - A szomszédjait a 2-es csapathoz (szín: 2).
   - Ha egy csúcs szomszédját ugyanazzal a színnel próbáljuk színezni, ellentmondás van, és az osztás nem lehetséges.
3. **Eredmény kiírása:**
   - Ha sikeres a színezés, a színek adják a csapatokat.
   - Ha nem, akkor kiírjuk, hogy **"IMPOSSIBLE"**.
