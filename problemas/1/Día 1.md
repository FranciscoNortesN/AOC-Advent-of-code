## Día 1
### Primera Parte
Para la primera parte, se nos pedía que dadas 2 listas de números, que juntaramos los números más pequeños de cada lista y calcularamos la diferencia, luego, que se hiciera lo mismo con los segundos más pequeños y así hasta terminar las listas. Una vez conocidas las diferencias, se nos pedía que se sumaran y que se entregara el resultado de la suma.

Para las comparaciones, se pensó que lo más sencillo sería ordenar las dos listas mediante un quicksort y ya una vez ordenadas, tendríamos el menor elemento con el menor elemento, el seguno menor con el segundo... El resto de lo que se tenía que hacer para la primera parte es coger el valor absoluto de la resta de ambos elementos y realizar la suma de cada uno de los valores absolutos.

Lo último por comentar es que para la entrada de datos, pensamos que lo más sencillo sería un bucle while cuya condición era un cin.

### Segunda Parte
En cuanto a la segunda parte, se nos pedía que esta vez en vez de entregar la suma de las diferencias, lo que teníamos que hacer es multiplicar cada número de la primera lista, por el número de veces que aparece dicho número en la segunda lista.

En este caso, no se hizo ninguna solución complicada, símplemente se recorrió la lista y se hizo la multiplicación con lo que devuelvia una función, la cual simplemente contaba el número de veces que salía el número que se le pasaba en la segunda lista. Además se le puso un poco de memoria a la función para aumentar su velocidad (si ya se había contado el número, no se volvía a contar).

### Razón de elección
Se eligió este problema porque aun siendo un problema relativamente sencillo es el problema perfecto para combinar divide y vencerás con una pizca de programación dinámica, además del hecho de que de acuerdo con otros usuarios de AOC, este problema se puede resolver mediante tabla hash, lo que no nos dimos cuenta hasta que se vió que en nuestra solución (aunque de manera no intencionada) se estaba haciendo algo parecido a una tabla hash muy simple (practicamente se podría decir que no había función de hash ni colisiones, pero la idea era la misma). Luego, la solución que se le dió al problema fue una que hace que este no fuera tan sencillo como lo resolvería una persona cualquiera, lo cual consideramos que al final el problema podía calificar para entrega en cuanto a dificultad.

### Alternativas
En cuanto a alternativas, cómo se ha mencionado antes, se podría haber hecho una tabla hash, pero no se implementó una porque consideramos que lo que hay implementa mejor lo aprendido en clase. Además, se podría haber hecho una solución iterativa, pero consideramos que la solución que se le dió al problema es más elegante y más eficiente.

### Valoración personal
En cuanto a la valoración personal, consideramos que este problema es un problema que se ha resuelto de manera muy eficiente y que además, es un problema que ha sido muy interesante de resolver, ya que posee varias formas de solucionarse. Además el problema al ser libre, nos ha permitido hacer una solución que no es la más sencilla, pero que es la más eficiente y elegante y nos potencío a seguir haciendo problemas de AOC.

