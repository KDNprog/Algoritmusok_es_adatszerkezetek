# Koncertjegyek - Feladat leírása

Egy koncertre **n** darab jegy áll rendelkezésre, mindegyik egy adott árral. Ezt követően **m** vásárló érkezik sorban egymás után.

- Minden vásárló megadja a maximális összeget, amelyet hajlandó fizetni egy jegyért.
- A vásárló a legdrágább olyan jegyet kapja, amely nem haladja meg az általa megadott maximális árat.
- Ha egy vásárló megkap egy jegyet, azt többé nem lehet eladni.

Ha egy vásárló számára nincs elérhető jegy, amely megfelel az ajánlatának, akkor **-1**-et kell kiírni.

## Bemenet

1. Az első sor tartalmazza az **n** és **m** egész számokat, ahol:

   - **n**: a jegyek száma,
   - **m**: a vásárlók száma.

2. A második sor **n** darab egész számot tartalmaz: a jegyek árait (**h₁, h₂, ..., hₙ**).
3. Az utolsó sor **m** darab egész számot tartalmaz: a vásárlók által megadott maximális árakat (**t₁, t₂, ..., tₘ**).

## Kimenet

A kimenetben minden vásárló esetében ki kell írni azt az árat, amelyért jegyet kapott:

- Ha a vásárló nem tud megfelelő jegyet vásárolni (mert nincs olyan jegy, amelynek ára nem haladja meg a megadott maximális árat), ki kell írni a **-1**-et.
- Ha a vásárló talál megfelelő jegyet, ki kell írni a jegy árát.

## Feltételek

$$1 \leq n, m \leq 2 \cdot 10^5$$
$$1 \leq h_i, t_i \leq 10^9$$

## Példa

_Bemenet:_

    5 3
    5 3 7 8 5
    4 8 3

_Kimenet:_

    3
    8
    -1

## Magyarázat

1. **Kezdeti jegyek:** [5, 3, 7, 8, 5]
   - Rendezés után: [3, 5, 5, 7, 8].
2. **Első vásárló maximális ajánlata:** 4.
   - A legdrágább elfogadható jegy: 3.
   - Frissített jegyek: [5, 5, 7, 8].
3. **Második vásárló maximális ajánlata:** 8.
   - A legdrágább elfogadható jegy: 8.
   - Frissített jegyek: [5, 5, 7].
4. **Harmadik vásárló maximális ajánlata:** 3.
   - Nincs megfelelő jegy.
   - Kimenet: -1.
