# AOC (Advent-of-code)
## Aclaraciones previas sobre el github que luego (cuando todos las hayais leido) se eliminarán
Aquí irán las explicaciones de los códigos de cada uno de los problemas resueltos que se encuentren en el github.  
Si terminas con 2 espacios es un salto de línea.  
Si dejas una línea en blanco en medio de dos líneas en el markdown, tambien te lo detecta como línea.

Un hashtag (almuadilla) es un título de nivel 1, dos son un título de nivel 2; tres, de nivel tres...  
Si se quiere hacer una tabla, se puede poner una combinación de | y - (el primero enseña líneas y el segundo separa el nombre de las columnas del resto de columnas, cada fila una vez separado el nombre de la columna de lo demás, se crea simplemente añadiendo una línea nueva, | tambien separa columnas).  
Otras cosas que o no queden claras por cómo las he explicado o no estén explicadas, preguntarselas a vuestra IA de confianza.
También se puede incluir otras cosas usando html, por si os sirve.  

Sobre cómo rellenar el readme, de manera que tengamos las cosas claras entre nosotros y claras en cuanto a presentación (supongo que tendremos que entregar o el github o un documento que lo posea todo explicado) hablaremos en una reunion futura.  
Considero que es mejor que tengamos desde un primer momento esto ya definido para así poder entregarlo sin problemas.

## Días resueltos 
Si se tiene un problema que está en curso, no es necesario actualizar el readme (si quieres, como mucho, quita la cruz).  
Para indicar que está incompleto/se ha empezado pero no se sabe cómo completar se pondrá 📝, el emoji indicará que se le deja a otra persona.  
Si hay algun problema en el que uno quiere dedicar su tiempo sin que nadie se meta pero puede tardar un tiempo largo, se pondrá ⌛.  
Si un problema está completado pero no se ha añadido la explicación se pondrá 🔄.
Si un problema está completo, se pondrá ✅.
Sé que esto es demasiado, pero está por mantener un orden (y porque me he flipado un poco al escribir todo esto).

|Lunes|Martes|Miercoles|Jueves|Sabado|Domingo|
|-----|------|---------|------|------|-------|
||||||✅1|
|✅2|❌3|❌4|❌5|❌6|❌7|❌8|
|❌9|❌10|❌11|❌12|❌13|❌14|❌15|
|❌16|❌17|❌18|❌19|❌20|❌21|❌22|
|❌23|❌24|❌25|||||

## Otras explicaciones
Con poner make bin/"número del día" se compila el código y se guarda directamente en una carpeta bin. Se puede editar el makefile si se requiere una compilación diferente (por ejemplo si a la hora de compilar se requiere de una librería). En inputs, se colocará el input que resuelve nuestro código, así se puede ejecutar poniendo ./bin/"número del día" < inputs/dia"número del día".

# Explicaciones de código
## Día 1
### Primera Parte
Para la primera parte, se nos pedía que dadas 2 listas de números, que juntaramos los números más pequeños de cada lista y calcularamos la diferencia, luego, que se hiciera lo mismo con los segundos más pequeños y así hasta terminar las listas. Una vez conocidas las diferencias, se nos pedía que se sumaran y que se entregara el resultado de la suma.

Para las comparaciones, se pensó que lo más sencillo sería ordenar las dos listas mediante un quicksort y ya una vez ordenadas, tendríamos el menor elemento con el menor elemento, el seguno menor con el segundo... El resto de lo que se tenía que hacer para la primera parte es coger el valor absoluto de la resta de ambos elementos y realizar la suma de cada uno de los valores absolutos.

Lo último por comentar es que para la entrada de datos, pensamos que lo más sencillo sería un bucle while cuya condición era un cin.

### Segunda Parte
En cuanto a la segunda parte, se nos pedía que esta vez en vez de entregar la suma de las diferencias, lo que teníamos que hacer es multiplicar cada número de la primera lista, por el número de veces que aparece dicho número en la segunda lista.

En este caso, no se hizo ninguna solución complicada, símplemente se recorrió la lista y se hizo la multiplicación con lo que devuelvia una función, la cual simplemente contaba el número de veces que salía el número que se le pasaba en la segunda lista. Además se le puso un poco de memoria a la función para aumentar su velocidad (si ya se había contado el número, no se volvía a contar).

## Día 2
### Primera Parte
En esta parte, se nos pedía que dada una lista de reportes de longitud no mencionada, que analizaramos si estos eran seguros. Un reporte se consideraba seguro si los niveles que contenía eran 100% crecientes o decrecientes y si la diferencia entre cada uno de los niveles en el reporte se encontraba entre 1 y 3. Por último se nos pedía que entregaramos el número de reportes seguros.

Este día se complicó un poco porque se trató de aplicar una solución que utilizara lo aprendido en clase de PRA, pero tras un tiempo de complicaciones, se decidió aplicar una solución más sencilla la cual consistía en recorrer cada uno de los reportes unas 2 veces, una para comprobar que todos los niveles o subían o bajaban y otra para comprobar que los niveles no posean una diferencia mayor a 3 o menor a 1.

### Segunda Parte
En esta parte se nos dijo que se admitía que los reportes tuvieran un nivel erroneo si al eliminarlo se cumplían las condiciones de la primera parte, es decir, si un reporte había fallado, pero tras eliminar un solo nivel del reporte este ya no fallaba, se consideraba que el reporte era seguro. Otra vez se nos pidió que entregaramos el número de reportes seguros.

Otra vez se complicó un poco la solución, porque integrarla en la solución de la primera parte era complicado por cómo estaba escrito el código de la primera parte. Se decidió por reescribir el código de la primera parte de tal manera que fuera más facil integrar los cambios necesarios para la segunda parte. Una vez hecho esto, originalmente se pensó que sería una buena idea guardar donde está el elemento que ocasionaba el fallo y eliminarlo y volver a hacer la prueba, pero por si acaso, se decidió que era una mejor idea hacer una copia del reporte e ir haciendo el análisis eliminando con un elemento eliminado distinto cada vez.
