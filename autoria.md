# Declaración de autoría — Obligatorio 1

## Ejercicio 1
- Nos apoyamos en el ejercicio de AVL hecho en clase.
- Para la función max, no sabíamos si estaba importada o no y consultamos con Claude si había que implementarla.
- También usamos Claude cuando terminamos el ejercicio para que corrobore que se cumplan todas las consignas pedidas en la letra.
- Pedimos a Claude que nos explique bien cómo funciona el long long.

## Ejercicio 2
- Nos apoyamos en el ejercicio de hash cerrado hecho en clase para guiarnos para hacer el hash abierto. La implementación es propia.
- Pedimos ayuda a Claude para que nos explique la letra antes de realizar el ejercicio.

## Ejercicio 3
- Nos apoyamos en el ejercicio de Heap Binario hecho en la clase. La implementación es propia. El Heap binario también es propio y lo reutilizamos en los ejercicios 4 y 5.

## Ejercicio 4
- El orden topológico está basado en el algoritmo de Kahn visto en clase, que teníamos implementado con una pila. Lo adaptamos para usar nuestro heap del ejercicio 3, ordenando por prioridad y, si empatan, por número de módulo.
- GrafoLista (lista de adyacencia) es el visto en clase. Le cambiamos la función adyacentes para que devuelva la lista original en vez de una copia, porque copiarla gastaba memoria y tiempo sin necesidad.

## Ejercicio 5
- El algoritmo de Kruskal está basado en el visto en clase.
- El TAD MFSet es el visto en clase, con compresión de caminos y unión por altura.
- Reutilizamos el heap del ejercicio 3 y el struct Arista del ejercicio 4.

Todos los main son de implementación propia.
