# Távoli bolygó DNS-e - Feladat megoldása

**Input:** Két genetikai leírásból (karakterláncokból) álló **M** párt kapunk. A genetikai kódok **K** karakteres darabokra vannak bontva.

**Cél:** Megállapítani, hogy az adott párok genetikai kódjai azonos fajba tartoznak-e. Azonos fajba tartoznak, ha az azonos hosszúságú (K karakteres) darabjaik ugyanolyan gyakorisággal fordulnak elő mindkét kódban.

## A feladat megoldásának menete

### 1. A kód felépítése és működése

**Segédfüggvény:** _countGeneticCodes_

A _countGeneticCodes_ függvény egy genetikai kód szekvenciáját **K** karakteres darabokra bontja, majd megszámolja minden darab előfordulását. Az eredményt egy asszociatív konténerben (map) tárolja.

- **Bemenet:**

  - **sequence:** Egy genetikai kód (karakterlánc).
  - **K:** A darabok (genetikai kódok) hossza.

- **Működés:**

  - Létrehoz egy üres **map** változót **(freq)**, amely minden genetikai kódhoz **(string)** eltárolja az előfordulások számát **(int)**.
  - Végighalad a **sequence** karakterláncon, minden K karakteres szakaszt **(code)** kivág a **substr** függvénnyel.
  - Növeli az adott **code** előfordulási számát a **freq** térképen.
  - Visszaadja az előfordulási gyakoriságokat tartalmazó **map**-et.

- **Kimenet**
  - Egy **map<string, int>** típusú gyakorisági táblázat, amely tartalmazza az összes K karakteres genetikai kódot és azok előfordulási számát.

### 2. Főprogram: Main függvény

A főprogram a bemenetet kezeli és összehasonlítja az egyes genetikai kódokat.

**Bemeneti adatok beolvasása:**

- A felhasználótól a program beolvassa:
  - **M**: Az élőlény párok száma.
  - **K**: A genetikai kód darabolásának hossza.
- Ezután M páronként beolvassa:
  - **code1** és **code2**: Az élőlények genetikai kódjait tartalmazó karakterláncok.

**Gyakorisági táblázatok előállítása:**

- Minden pár esetében meghívja a **countGeneticCodes** függvényt mindkét genetikai kódra (**code1** és **code2**).
- Ezáltal két **map** keletkezik:
  - **freq1**: Az első genetikai kód K karakteres darabjainak gyakorisági táblázata.
  - **freq2**: A második genetikai kód K karakteres darabjainak gyakorisági táblázata.

**Összehasonlítás:**

- Az **if (freq1 == freq2)** kifejezéssel a program összehasonlítja a két gyakorisági táblázatot:
  - Ha megegyeznek, akkor a két élőlény azonos fajba tartozik **(cout << "IGEN")**.
  - Ha eltérnek, akkor nem tartoznak azonos fajba **(cout << "NEM")**.

**Kimenet:**

- Az eredményeket soronként kiírja a standard kimenetre.

## A kód lépései példán keresztül

### Bemenet

    2 2
    aabbcc
    ccbbaa
    abcabc
    abcabc

**1. A bemenet értelmezése:**

- **M = 2**: Két élőlény pár van.
- **K = 2**: A genetikai kódokat 2 karakteres darabokra kell bontani.
- Az első pár:
  - code1 = "aabbcc"
  - code2 = "ccbbaa"
- A második pár:
  - code1 = "abcabc"
  - code2 = "abcabc"

**2. Feldolgozás első pár:**

- countGeneticCodes("aabbcc", 2) → {aa: 1, bb: 1, cc: 1}
- countGeneticCodes("ccbbaa", 2) → {cc: 1, bb: 1, aa: 1}
- A **freq1** és **freq2** mapek azonosak → Kimenet: **IGEN**.

**3. Feldolgozás második pár:**

- countGeneticCodes("abcabc", 2) → {ab: 1, bc: 1, ca: 1}
- countGeneticCodes("abcabc", 2) → {ab: 1, bc: 1, ca: 1}
- A **freq1** és **freq2** mapek azonosak → Kimenet: **IGEN**.

### Kimenet

    IGEN
    IGEN

## Teljes működés összegzése

1. **Beolvasás**: Az M élőlény pár genetikai kódját és a K darabolási hosszát olvassa be.
2. **Darabolás**: A kódokat K karakteres genetikai kódokra bontja, és megszámolja azok előfordulásait.
3. **Összehasonlítás**: A két kód előfordulási táblázatait hasonlítja össze.
4. **Eredmény kiírása**: Az _IGEN_ vagy _NEM_ kimenetet adja az egyes párokra.

## Megjegyzések

- **Hatékonyság**: A megoldás hatékony, mivel a _map_-ek használata logaritmikus keresést és beszúrást biztosít. Ez különösen fontos a nagy bemeneteknél.
- **Korlátok**: A program feltételezi, hogy a bemeneti genetikai kód hossza osztható K-val, ahogy a feladatban is szerepel.
- **Robusztusság**: Ha a bemenet hibás, a program nem tartalmaz explicit hibaellenőrzést.

Ez a megoldás hatékonyan kezeli a feladatot, és a fenti lépések logikusan követik a problémamegoldás folyamatát.
