# Csapatépítés - Feladat megoldása

Ez egy gráf-alapú probléma, amelynek célja a tanulók két csapatra osztása úgy, hogy azonos csapatban lévő tanulók között ne legyen barátság (él).

## A feladat megoldásának menete

### 1. Bemenet feldolgozása

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

- **N**: a tanulók száma.
- **M**: a barátságok (élek) száma.
- Egy szomszédsági listát **(G)** használunk a **gráf** reprezentálására:
  - **G[a]** tartalmazza azokat a csúcsokat (tanulókat), amelyek barátok az **a**-val.
  - Mindkét irányban (a barátság kölcsönös) tároljuk az élt.

### 2. Alapváltozók inicializálása

    bool possible = true;
    int team[maxN] = {0};

- **team**: Ez egy tömb, amely minden tanuló csapatát tárolja:

  - 0: még nem látogatott tanuló.
  - 1: első csapat.
  - 2: második csapat.

- **possible**: Ez a logikai változó tárolja, hogy a gráfot kétkomponensűként tudjuk-e színezni:
  - Ha ellentmondás lép fel (két barát azonos csapatba kerülne), akkor **possible = false**.

### 3. Mélységi keresés (DFS)

    void dfs(int u, int t)
    {
        team[u] = t; // Jelöljük ki a tanulót az adott csapatba (1 vagy 2)
        for (int v : G[u]) // Minden szomszédot (barátot) ellenőrzünk
        {
            if (team[v] == 0) // Ha még nem látogattuk
            {
                dfs(v, 3 - t); // Az ellentétes csapatba tesszük (1 -> 2, 2 -> 1)
            }
            else if (team[v] == t) // Ha a szomszéd ugyanabban a csapatban van
            {
                possible = false; // Ez ellentmondás, nem lehetséges osztás
            }
        }
    }

**Funkció bemenete:**

- **u**: az aktuális tanuló (csúcs).
- **t**: a csapat (1 vagy 2), amelybe **u** tartozik.

**Lépések:**

- Az **u**-t **t**-be színezzük.
- Minden szomszédját bejárjuk:
  - Ha a szomszéd még nincs színezve, az ellenkező csapatba helyezzük.
  - Ha a szomszéd már ugyanabban a csapatban van, az osztás nem lehetséges.

### 4. DFS meghívása minden komponensre

    for (int i = 1; i <= N; i++)
    {
        if (team[i] == 0) // Ha még nem látogattuk meg
        {
            dfs(i, 1); // Kezdjük az első csapattal
        }
    }

- Mivel a gráf nem feltétlenül összefüggő (lehet több különálló komponens), minden csúcsot (tanulót) ellenőrizni kell.
- Ha egy csúcs még nincs színezve, elindítjuk rajta a DFS-t, kezdve az 1-es csapattal.

### 5. Eredmény kiírása

    if (!possible)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            cout << team[i] << " ";
        }
        cout << "\n";
    }

- Ha ellentmondás történt:

  - Kiírjuk: **IMPOSSIBLE**.

- Ha nincs ellentmondás:
  - A team tömb tartalmazza, hogy melyik tanuló melyik csapatban van:
    - Minden tanulónál kiírjuk a csapat számát (1 vagy 2).

## Példa bemenet és kimenet

**Bemenet:**

    5 3
    1 2
    1 3
    4 5

**Kimenet:**

    1 2 2 1 2

**Lépések:**

- Az 1-es tanulót az 1-es csapatba helyezzük.
- Az 1-es szomszédai (2-es és 3-as) a 2-es csapatba kerülnek.
- A 4-es tanuló egy külön komponens része, ezért az 1-es csapatba kerül.
- A 4-es szomszédja (5-ös) a 2-es csapatba kerül.

## Hatékonyság

1. **Időbeli komplexitás:** - A DFS minden csúcsot és élt egyszer látogat meg:
   $$O (N + M)$$

2. **Memóriahasználat:**
   - Szomszédsági lista: $O(N+M).$
   - team tömb: $O(N).$

## Összefoglalás

Ez a program hatékony, és megfelelően működik az adott feltételek esetén:

$$N \leq 10^5$$
$$M \leq 2 \cdot 10^5$$

Ez a megoldás egy gráfelméleti problémát old meg, amelyben azt vizsgáljuk, hogy lehetséges-e a gráf csúcsait (tanulókat) két csoportra (csapatra) osztani úgy, hogy az azonos csoportba tartozók között ne legyen él (barátság). A megoldás alapja, hogy a gráf kétkomponensűségét (bipartit voltát) ellenőrizzük.

A DFS alapú kétkomponensűség-ellenőrzés nemcsak a helyes osztást biztosítja, hanem képes gyorsan azonosítani, ha a probléma nem megoldható.
