# Téglalap vágása - Feladat leírása

Adott egy **a × b** méretű téglalap. A feladat az, hogy a téglalapot **négyzetekre** vágjuk. Minden lépésben kiválaszthatunk egy téglalapot, és kettévághatjuk úgy, hogy az oldalak hossza **egész szám** maradjon. A cél, hogy a négyzetekre bontáshoz szükséges **minimális lépésszámot** meghatározzuk.

Ez a feladat egy **dinamikus programozási probléma**, amelynek célja, hogy minimális vágásokkal négyzetekre bontsuk a téglalapot.

## Bemenet

- Egyetlen sor tartalmazza az **a** és **b** egész számokat, amelyek a téglalap méretét jelentik.

## Kimenet

- Egyetlen számot kell kiírni: a négyzetekre bontáshoz szükséges **minimális lépésszámot**.

## Feltételek

$$1 \leq a, b \leq 500$$

## Példa

_Bemenet:_

    3 5

_Kimenet:_

    3

## Magyarázat

1. A **3 × 5** méretű téglalapot négyzetekre bontjuk.
2. Az első lépésben a téglalapot elvágjuk egy **3 × 3**-as négyzetre és egy **3 × 2**-es téglalapra.
3. A megmaradt **3 × 2**-es téglalapot két **1 × 1**-es négyzetre és egy **2 × 2**-es négyzetre vágjuk.
4. Ez összesen **3 lépés**.
