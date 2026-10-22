# Bitácora — Obligatorio 1

**Integrantes:** Sabrina Bella (326445) y Lara Regen (289762)

## 2026-09-10 — En conjunto
- Clonamos el repositorio y comenzamos a leer las consignas

## 2026-09-25 — En conjunto
- Hicimos el struct y la clase del AVL del ejercicio 1, incluyendo las funciones de insertar, buscar y rango.
- Tomamos la decicion de hacer un solo template AVL<T> instanciado dos veces, AVL<long long> para monedas (porque los números llegan hasta 10^12) y AVL<string> para pinturas. Dejamos todo en ejercicio1.cpp porque solo lo usa este ejercicio.
- Hicimos el main, chequeamos que el código coincida con lo pedido en la consigna y corrimos las pruebas con Claude, checkeamos que correspondan con lo esperado.
- Hicimos la autoría del ejercicio 1.

## 2026-10-10 - En conjunto
- Empezamos el ejercicio 2, hicimos la parte privada de la clase Hash Abierto.

## 2026-10-13 - En conjunto
- Ejercicio 2: Hicimos la parte pública de la clase y el main, y chequeamos que el código coincida con lo pedido en la consigna.
- Tomamos la decisión de hacer la clase HashAbierto dentro de ejercicio2.cpp, en vez de en un archivo aparte en tads/, porque solo la usa este ejercicio.
- Compila, en este caso, probamos todos los ejemplos de la letra nosotras con g++ -std=c++11 -o ejercicio2 ejercicio2.cpp y dan bien.
- Hicimos la autoría del ejercicio 2.

## 2026-10-15 - En conjunto
- Ejercicio 3: Hicimos un TAD Heap Binario, en el que hicimos su clase, con la estructura y las operaciones del TAD.
- Tomamos la decisión de hacer el heap como un TAD aparte en tads/ (HeapBinario.cpp), en vez de dentro de ejercicio3.cpp, porque también lo íbamos a necesitar en los ejercicios 4 y 5. Lo hicimos genérico (template) y con una función de comparación para poder usarlo con distintos tipos.
- Luego hicimos el main en ejercicio3.cpp
- Compila, probamos todos los ejemplos de la letra con g++ -std=c++11 -o ejercicio3 ejercicio3.cpp y dan bien.
- Hicimos la autoría del ejercicio 3.

## 2026-10-17 - En conjunto
- Ejercicio 4: Hicimos el tad de grafos con la estructura de lista de adyacencia, y definimos las aristas en definiciones.cpp
- Tomamos la decisión de poner el grafo como un TAD aparte en tads/ (ListaAdy.cpp, con las aristas en definiciones.cpp), en vez de dentro de ejercicio4.cpp, porque es el TAD que vimos en clase y el struct Arista también lo íbamos a usar en el ejercicio 5. Para elegir el próximo módulo reutilizamos el heap de tads/ del ejercicio 3. 
- En ejercicio4.cpp, hicimos la estructura Modulo y el booleano compararModulos, que le dice al heap cuál de dos módulos tiene que salir primero. Devuelve true si a va antes que b, y por último armamos el main.
- Compila, probamos todos los ejemplos de la letra con g++ -std=c++11 -o ejercicio4 ejercicio4.cpp y dan bien.
- Hicimos la autoría del ejercicio 4.

## 2026-10-20 - En conjunto
- Ejercicio 5: Hicimos un TAD MFSet, en el que declaramos las funciones find y merge.
- Tomamos la decisión de poner el MFSet como un TAD aparte en tads/ (MFSet.cpp), en vez de dentro de ejercicio5.cpp, para que quede separado igual que el resto de los TADs. Reutilizamos el heap y el struct Arista que ya estaban en tads/. La función compararAristas la dejamos en ejercicio5.cpp porque solo la usa este ejercicio.
- En ejercicio5.cpp hicimos la función compararAristas, que ordena el heap por peso, y el main con el algoritmo de Kruskal. 
- Compila, probamos todos los ejemplos de la letra con g++ -std=c++11 -o ejercicio5 ejercicio5.cpp y dan bien.
- Hicimos la autoría del ejercicio 5.

## 2026-10-21 - En conjunto
- Escribimos la justificación de órdenes de los ejercicios y chequeamos que todos los ejercicios compilen bien nuevamente.

## 2026-10-22 - En conjunto
- Revisando nos dimos cuenta que cambiamos el tamaño de la tabla de 2N+1 al primer primo ≥ 2N+1. Nuestra función de hash multiplica por 31 en cada paso. Si el tamaño de la tabla es múltiplo de 31 (por ejemplo N = 15 → 31 buckets), h*31 % tamaño pierde la información de las letras anteriores y muchas claves distintas caen en el mismo bucket. Con un tamaño primo la base y el tamaño no comparten factores y las claves se distribuyen mejor. El factor de carga sigue siendo ≤ 0,5 porque hay a lo sumo N cajones.
- Compilamos de nuevo con g++ y salió todo bien.