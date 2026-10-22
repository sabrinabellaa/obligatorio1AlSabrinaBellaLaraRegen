# Justificación de órdenes — Obligatorio 1

## Ejercicio 1
- Justificación: La letra exige ALTA y BUSCAR en O(log K) y RANGO en O(log K + R). Usamos un árbol AVL que al estar balanceado, su altura es O(log K), ALTA y BUSCAR recorren un único camino y las rotaciones son O(1). RANGO es un inorden que solo visita los caminos hacia desde y hasta (O(log K)) más los R nodos que imprime.

## Ejercicio 2
- Justificación: La letra exige registrar y consultar en O(L) promedio (siendo L el largo de la palabra involucrada), la última línea de salida en O(1) y el problema completo lineal en el tamaño de la entrada. Usamos una tabla de hash abierta. La clave es el conteo de las 26 letras, que se arma en O(L), el hash y la comparación de claves recorren 26 posiciones (O(1), alfabeto constante). Cada cajón se guarda como un único nodo con un contador, así que el largo de las listas no depende de cuántas palabras comparten cajón, y con 2N+1 buckets el largo esperado es constante. La cantidad de cajones y el cajón más grande se actualizan al registrar, por lo que la última línea es O(1). Sumando O(L) por palabra, el total es lineal en la cantidad de letras de la entrada. 
Como hay a lo sumo N cajones distintos, con un tamaño primo ≥ 2N+1 el factor de carga queda ≤ 0,5 durante todo el ejercicio, sin rehash y con espacio O(N).

## Ejercicio 3
- Justificación: La letra exige un heap binario, O(N log N) en tiempo y O(N) en espacio. Usamos un min-heap sobre arreglo, se insertan los N archivos y en cada paso se extraen los dos menores y se inserta su suma (N - 1 pasos). Cada operación es O(log N) porque flotar y hundir recorren a lo sumo la altura del árbol. El heap ocupa N posiciones.

## Ejercicio 4
- Justificación: La letra exige un heap binario, O((V + A) log V) en tiempo y O(V + A) en espacio. Usamos el algoritmo de Kahn con un min-heap ordenado por (prioridad, número), cada módulo entra y sale del heap una vez (O(log V)) y cada arista se recorre una vez. El grafo se guarda con lista de adyacencia (O(V + A)).

## Ejercicio 5
- Justificación: La letra pide usar Kruskal con conjuntos disjuntos, en O(A log A) de tiempo y O(V + A) de espacio. Para recorrer las aristas de la más barata a la más cara las guardamos en un min-heap ordenado por peso: cada una entra y sale una sola vez, y cada operación cuesta O(log A). Para saber si dos refugios ya están conectados usamos un MFSet con compresión de caminos y unión por altura, así que find y merge son prácticamente constantes. En memoria solo tenemos el heap con las A aristas y los dos arreglos del MFSet, de tamaño V.