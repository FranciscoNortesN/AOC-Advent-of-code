# AOC (Advent-of-code)
## Días resueltos 
Aquí se indican los problemas que se han resuelto, ⌛ indica que solo se encuentra la primera parte, ✅ indica que se encuentran ambas partes o la segunda parte que se ha hecho a partir de la primera parte y por ende posee el código de dicha parte y ❌ indica que no se ha colocado ninguna parte.

|Lunes|Martes|Miercoles|Jueves|Sabado|Domingo|
|-----|------|---------|------|------|-------|
||||||✅1|
|❌2|❌3|❌4|✅5|❌6|❌7|❌8|
|❌9|❌10|⌛11|❌12|❌13|❌14|❌15|
|⌛16|❌17|❌18|❌19|❌20|❌21|❌22|
|❌23|❌24|❌25|||||

# Explicaciones de código
## Día 1
### Primera Parte
Para la primera parte, se nos pedía que dadas 2 listas de números, que juntaramos los números más pequeños de cada lista y calcularamos la diferencia, luego, que se hiciera lo mismo con los segundos más pequeños y así hasta terminar las listas. Una vez conocidas las diferencias, se nos pedía que se sumaran y que se entregara el resultado de la suma.

Para las comparaciones, se pensó que lo más sencillo sería ordenar las dos listas mediante un quicksort y ya una vez ordenadas, tendríamos el menor elemento con el menor elemento, el seguno menor con el segundo... El resto de lo que se tenía que hacer para la primera parte es coger el valor absoluto de la resta de ambos elementos y realizar la suma de cada uno de los valores absolutos.

Lo último por comentar es que para la entrada de datos, pensamos que lo más sencillo sería un bucle while cuya condición era un cin.

### Segunda Parte
En cuanto a la segunda parte, se nos pedía que esta vez en vez de entregar la suma de las diferencias, lo que teníamos que hacer es multiplicar cada número de la primera lista, por el número de veces que aparece dicho número en la segunda lista.

En este caso, no se hizo ninguna solución complicada, símplemente se recorrió la lista y se hizo la multiplicación con lo que devuelvia una función, la cual simplemente contaba el número de veces que salía el número que se le pasaba en la segunda lista. Además se le puso un poco de memoria a la función para aumentar su velocidad (si ya se había contado el número, no se volvía a contar).

## Día 5
### Primera Parte
Para la primera parte se ha creado un 
```cpp
unordered_map<int, unordered_set<int>> grafo 
```
donde los pares clave valor están compuestos respectivamente por un número y el conjunto de los números que deben ir después de él(nodos de salida). Para comprobar si una secuencia de números respeta las normas, basta con tomar un número y analizar los números anteriores a él. Si se encuentra un número que debería ir después del número que hemos tomado, la secuencia es automaticamente incorrecta. Así para todos los números de la secuencia. Sabiendo las secuencias correctas calculamos su número del medio y lo sumamos a la variable de la suma de los correctos.
 
### Segunda Parte
Para la segunda parte se ha usado un orden topológico usando el algoritmo de Kahn para ordenar cada secuencia. Una vez ordenado se procede igual que en la primera parte para la suma de los que han tenido que ser ordenados.

## Día 11
### Primera Parte
Originalmente este día se hizo mediante fuerza bruta, pero incorporando programación dinámica para que fuera algo más eficiente. Pero tras no poder hacer la segunda parte se dejó el día de lado hasta que se hayan decidido que días entregar. Tras un tiempo, se volvió a ver el problema y se vío que la forma en el que el problema iba se parecía bastante a un arbol binario.

El problema indicaba que se nos daban unos números que significaban piedras y cada vez que parpadeabamos estas eran modificadas de alguna manera, siendo una de estas:
- Si la piedra era 0, se convertía en 1.
- Si la piedra poseía un número par de dígitos, se partía en dos piedras con la mitad superior de dígitos en una y la mitad inferior en otra piedra.
- Si no se cumplía ninguna de las reglas anteriores, el número de la piedra se multiplicaba por 2024.

Aquí lo que se vío que dijo que esto podría ser un arbol, es que cada piedra es independiente de sus vecinas y que esta o producía una piedra distinta o producía dos piedras. Por lo que se acabó reescribiendo el código por completo para que fuera un arbol aunque no se hiciera la segunda parte. Luego ya, como se nos pedía que dijeramos cuantas piedras habian en el nivel n, lo que se hizo es recorrer el arbol hasta llegar a ese nivel y sumar 1 si había una piedra en ese nivel.

Además, para crear el arbol se quiso usar un poco de programación dinámica (y así además ahorrar bastante memoria porque cuanto más grande el arbol más memoria se necesita) y se creó un vector de vectores de punteros a nodos del arbol, al cual se añadía el nodo del arbol una vez completo ese nodo en las llamadas recursivas.

## Dia 16
### Primera Parte
Primeramente, para gestionar los movimientos se ha creado un una esteructura Punto que almacena las cooredenadas de posición y dirección, además del coste necesario para llegar a ese punto.

En un principio se probó una busqueda en profudunidad haciendo llamadas recursivas con todos los movimientos posibles y quedándote con el valor mínimo---



