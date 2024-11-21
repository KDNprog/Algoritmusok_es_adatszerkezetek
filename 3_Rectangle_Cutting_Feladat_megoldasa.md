# Téglalap vágása - Feladat megoldása

A probléma megoldásához a **dinamikus programozás** az optimális választás. Az algoritmus hatékonyan számolja ki az **a × b** téglalap négyzetekre bontásának minimális lépéseit az összes lehetséges vágás kipróbálásával.

A program egy **a × b** méretű téglalap minimális lépésszámban történő négyzetekre bontását oldja meg dinamikus programozás segítségével.

## A feladat megoldásának menete

### 1. Inicializálás

**Bemenet**

    int A, B;
    cin >> A >> B;

A program beolvassa A-t (a téglalap magasságát) és B-t (a téglalap szélességét).

**Dinamikus programozási tábla létrehozása**

    vector<vector<int>> dp(A + 1, vector<int>(B + 1, INF));

- A **dp[a][b]** értéke azt jelenti, hogy hány lépés szükséges egy **a × b** téglalap négyzetekre bontásához.
- Kezdetben minden értéket **INF**-re állítunk _(INF egy nagyon nagy szám)_, hogy később könnyen meghatározzuk a minimumot.

### 2. Alapeset kezelése

    for (int i = 1; i <= A; i++)
    {
      for (int j = 1; j <= B; j++)
      {
          if (i == j)
            dp[i][j] = 0;
      }
    }

- Ha egy téglalap már négyzet (**i==j**), nincs szükség további vágásokra, így **dp[i][j] = 0**.

### 3. Dinamikus programozási tábla kitöltése

**Külső ciklusok:**

    for (int a = 1; a <= A; a++)
    {
        for (int b = 1; b <= B; b++)
        {
            if (a == b)
                continue;

- Bejárjuk az összes **a × b** méretű téglalapot.
- Ha **a==b**, az alapeset szerint már négyzet, így kihagyjuk ezt az esetet.

**Vízszintes vágások:**

    for (int i = 1; i < a; i++)
    {
        dp[a][b] = min(dp[a][b], dp[i][b] + dp[a - i][b] + 1);
    }

- Az **a × b** téglalapot függőlegesen kettévágjuk **i**-edik sor után:
  - Az egyik része: **i × b**.
  - A másik része: **(a − i)×b**.
  - Az ehhez szükséges lépések: **dp[i][b] + dp[a − i][b] + 1**
  - Frissítjük **dp[a][b]**-t a minimum értékre.

**Függőleges vágások:**

    for (int i = 1; i < b; i++)
    {
        dp[a][b] = min(dp[a][b], dp[a][i] + dp[a][b - i] + 1);
    }

- Az **a × b** téglalapot vízszintesen kettévágjuk i-edik oszlop után:
  - Az egyik része: **a × i**.
  - A másik része: **a × (b − i)**.
  - Az ehhez szükséges lépések: **dp[a][i] + dp[a][b − i] + 1**
  - Frissítjük **dp[a][b]**-t a minimum értékre.

### 4. Eredmény kiírása

    cout << dp[A][B] << endl;

- Az eredmény **dp[A][B]**, amely az **A × B** téglalap négyzetekre bontásához szükséges minimális lépések száma.

### 5. Példa bemenet és kimenet

**Bemenet:**

    A = 3, B = 5

**Táblázat kitöltése:**

**dp[3][5]**-höz:

- Próbáljuk meg minden lehetséges vízszintes és függőleges vágást:

  - Vízszintes vágás:

    - **dp[1][5] + dp[2][5] + 1**
    - **dp[2][5] + dp[1][5] + 1**

  - Függőleges vágás:
    - **dp[3][1] + dp[3][4] + 1**
    - **dp[3][2] + dp[3][3] + 1**

A minimum a fentiek közül: **3**.

**Kimenet:**

    3

## Összefoglalás

A program egy dinamikus programozási megoldást használ, amely hatékonyan számolja ki az összes téglalap négyzetekre bontásának minimális lépésszámát.

Az algoritmus komplexitása:

$$O(A\cdot B \cdot max(A,B))$$

Ez megfelelő az adott feltételre $(A,B \leq 500)$
