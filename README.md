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

## Cómo compilar el código
Para cada uno de los días dentro de un archivo Makefile se han colocado instrucciones que compilan automáticamente el código. Para realizar la compilación lo único que se debe hacer es:
``` bash
make bin/número_de_día
```
Luego ya depende del día que se está mirando el cómo se ejecuta. Esto es porque cada problema posee su propia forma de hacer un input de los datos y porque así se encuentra la variabilidad que se busca en los problemas.
- Los días 1 y 11 requieren que tú les pases el archivo como redirección de entrada, es decir requieren que hagas por ejemplo una de estas 2:
``` bash
./bin/1 < inputs/dia1
```
``` bash
cat inputs/dia11 | ./bin/11
```
igualmente, si no se quiere realizar una redirección de la entrada, se puede ejecutar sin la redirección y símplemente en cuanto se quiera parar la entrada de datos se pone por teclado un CTRL + D
- Los días 5 y 16 requieren que el archivo input se encuentre en el mismo lugar que el que tú te encuentres, ya que lo que hacen es abrir ellos directamente el archivo y realizar lo que tienen que hacer, por lo que la ejecución sería simplemente realizar un:
``` bash
./bin/número_de_día
```

# Explicaciones de código
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

## Día 5
### Justificación
 Elegimos este problema porque fue el primer día en el que detectamos que claramente nos encontrábamos ante un grafo de precedencia, y como todavía no habían salido y teníamos tiempo antes de empezar exámenes decidimos hacerlo. Además, lo vimos como un problema que no era trivial pero tampoco presentaba una dificultad excesiva. 
### Descripción técnica
#### Primera Parte
 Para la primera parte se nos dan varias reglas del tipo A|B, donde A debe preceder a B. Después, aparecen secuencias de números y se debe comprobar si todos los números de la secuencia cumplen las reglas que tienen asociadas. Después debemos calcular la suma de los números del medio de todas las secuencias correctas.

Lo primero de todos es crear el grafo. Para ello se usa un diccionario ```unordered_map<int, unordered_set<int>> grafo```. Las claves son números enteros y el valor que tienen asociado es un conjunto de enteros, el cual contiene todos los números que deben ir después del número de la clave. Para ir rellenando el grafo,  se lee línea por línea un fichero con el input. Si se lee el carácter ‘|’,  se trata de una norma (al principio se quiso usar una función ```vector<int> split()``` que implementamos, pero misteriosamente hacía que el algoritmo de la segunda parte no funcionase correctamente).  Así que tomamos carácter por carácter e hicimos las operaciones necesarias para convertirlos a enteros. Al primer número lo llamamos A y al segundo B, y luego hacemos ```grafo[A].pushback(B)``` y así al acceder acceder a ```grafo[A]``` tendremos todos los números que deben ir después de A. 

Cuando ya no leemos ‘|’, se trata de una secuenciar, y aquí sí que usamos la función split, la cual devuelve un vector con los números leídos. Para comprobar si es correcta vamos a usar dos funciones. Una llamada ```bool a_b(int a, int b, const unordered_map<int, unordered_set<int>>& grafo)``` , la cual devuelve si b debe ir después de a según las reglas. Para ello es tan simple como devolver si ```b``` se encuentra en ```grafo[a]```. Después, definimos una función llamada ```bool cumple_reglas(vector<int> input, const unordered_map<int, unordered_set<int>>& grafo)```. Esta usa dos bucles ```for```  anidados, el primero, recorriendo el vector input del último al primero, toma un número ```i``` y el anidado recorre el resto de números ```j```. Así por cada iteración se se llama a ```a_b(i, j, grafo)```. Si a_b() devuelve ```true``` significa que se ha encontrado un número j antes de i, pero que según las reglas debería ir después de i, así que la línea input es automáticamente incorrecta. Por cada línea llamamos a cumple_reglas() y si las cumple calculamos el número del medio y lo sumamos a la variable de la suma de los correctos. 

 
#### Segunda Parte

Para la segunda parte se pide ordenar las secuencias que no cumplen las reglas, y como en la primera parte, calcular la suma de los elementos del medio. Como se pide que se ordenen, asumimos que los números de cada secuencia no forman un grafo cíclico. 

Si la función cumple_reglas() devuelve ```false```, se llama a una función ```vector<int> sortUpdate(const vector<int> &update, const unordered_map<int, unordered_set<int>>& grafo)``` que aplica un orden topológico. Primera sea crea un ```unordered_map<int, vector<int>> grafo_temp```, que sirve como un grafo temporal que únicamente contiene los nodos que aparecen en la línea update, y un ```unordered_map<int, int> inDegree``` que es un diccionario que contiene los grados de entrada de los nodos del grafo temporal, que inicialmente está tiene todos los valores 0. Luego se lee el grafo original y se rellenan el grafo temporal y el diccionario de los grados de entrada. Una vez tenemos las estructuras de datos necesarias se aplica el orden topológico usando el algoritmo de Kahn, el cual usa una cola ``` queue<int> q```. Inicialmente, entran a la cola todos los nodos con grado de entrada 0, pues no dependen de nadie y pueden ir primero. Después, mientras la cola no esté vacía se procesan los nodos: Para comenzar, sale el primer nodo de la fila y lo añadimos a nuestro vector ```vector<int> ordenado```, después, decrementamos el grado de entrada de los nodos a los que apuntaba el nodo que ha salido y si estos también han quedado sin grados de entrada los añadimos a la cola. Cuando la cola esté vacía, significa que hemos procesado así que devolvemos el vector ordenado. Actualizamos la secuencia de números, ahora correctamente ordenada, y procedemos igual que en la primera parte para calcular la suma.

### Alternativas 
En un principio se pensó en usar un array con 90 posiciones, ya que los números van del 10 al 99, pero nos dimos cuenta de que se desperdiciaba demasiada memoria y optamos por el unordered_map. Por otro lado, en otro momento también se almacenaron las precedencias de forma inversa a la actual, es decir, en grafo[B] se almacenaban todos los números A que debían ir antes de B. Así la función a_b() devolvía si a debía ir antes de b. Además para la parte de ordenación, y con la excusa de usar Divide y Vencerás, probamos con un MergeSort() modificado, donde sustituimos el operador “<” por la función a_b() a la hora de ordenar los números. Este MergeSort() funcionaba pero era muy ineficiente hacer tantas comprobaciones, así que finalmente implementamos el algoritmo de Kahn. De todos modos quedan algunos misterios sin   resolver. Por ejemplo, al principio en lugar de split se usaba un ```while ((pos=linea.find(',')) != string::npos)``` y se iban metiendo los números haciendo un stoipor alguna razón el orden topológico no funcionaba correctamente. Además hay una función para imprimir el grafo y por un motivo que escapa nuestro entendimiento se guarda una clave: -479 con valor 37, aunque no afecta al resultado.

### Valoración Personal 

En lo personal creemos que este problema nos ha servido para establecer las bases de cómo implementar grafos dirigidos en C++ y ordenarlos. En la parte personal, si bien el problema no parecía demasiado complicado y teníamos claro lo que debíamos hacer, han aparecido problemas y complicaciones, como las explicadas en las alternativas, que no comprendemos. Es algo que ha resultado muy frustrante pero entendemos que es parte del aprendizaje y ayuda a enfrentar futuros problemas. 

## Día 9
### Justificación
Hemos elegido como técnica DyV puesto que el ejercicio puede dividirse en segmentos y calcular el tamaño de cada ID recursivamente.

### Descripción técnica:
El problema se basa en eliminar los bloques vacíos de memoria y compactar los últimos archivos en los primeros huecos hasta que no queden bloques de memoria sin utilizar. Una vez se ha compactado el disco, se suma el espacio de cada ID multiplicándolo por su posición en la compactación final. Las funciones del código son analizarMapa(const string& diskMap) que convierte el mapa dado en carácteres y lo convierte a enteros para poder trabajarlo, compactSegment(vector<int>& segment) compacta un segmento del disco moviendo los valores diferentes de 0 al principio del segmento y dejando los 0's al final, mergeSegments(const vector<vector<int>>& segments) fusiona todos los segmentos del mapa en uno solo, sumaSegmentos(const vector<int>& segmentos) en cada segmento multiplica cada ID por su indice y devuelve la suma total, dividirMapa(const vector<int>& segmentos, int segmentSize) divide el imput en subsegmentos más pequeños de tamaño segmentSize, unirSegmentos(vector<int>& segmento, int segmentSize) compacta los segmentos los ordena y se llama así mismo recursivamente.

### Alternativas:
Si bien DyV no es la técnica adecuada para afrontar este problema, nos decantamos por esta técnica porque carecíamos de ella en los demás ejercicios. Por último, destacar que no ha sido sencillo encontrar en los 24 ejercicios uno que sea ideal para DyV. Una implementación básica iterativa podría haber funcionado aunque el coste pueda ser alto y la posibilidad de utilizar un árbol binario la barajamos pero nos decantamos por DyV porque ya teniamos implementados otros ejercicios con árboles.

### Valoración personal:
Consideramos que la divir el mapa en segmentos es una buena manera de resolver el problema para poder compactarlo de manera que se pueda seguir haciendo aunque el imput sea grande, Si bien DyV puede no ser la técnica más adecuada para afrontar este problema, nos decantamos por esta técnica porque carecíamos de ella en los demás ejercicios. Por último, destacar que no ha sido sencillo encontrar en los 24 ejercicios uno que sea ideal para DyV.

## Día 11
### Primera Parte
Originalmente este día se hizo mediante fuerza bruta, pero incorporando programación dinámica para que fuera algo más eficiente. Pero tras no poder hacer la segunda parte se dejó el día de lado hasta que se hayan decidido que días entregar. Tras un tiempo, se volvió a ver el problema y se vío que la forma en el que el problema iba se parecía bastante a un arbol binario.

El problema indicaba que se nos daban unos números que significaban piedras y cada vez que parpadeabamos estas eran modificadas de alguna manera, siendo una de estas:
- Si la piedra era 0, se convertía en 1.
- Si la piedra poseía un número par de dígitos, se partía en dos piedras con la mitad superior de dígitos en una y la mitad inferior en otra piedra.
- Si no se cumplía ninguna de las reglas anteriores, el número de la piedra se multiplicaba por 2024.

Aquí lo que se vío que dijo que esto podría ser un arbol, es que cada piedra es independiente de sus vecinas y que esta o producía una piedra distinta o producía dos piedras. Por lo que se acabó reescribiendo el código por completo para que fuera un arbol aunque no se hiciera la segunda parte. Luego ya, como se nos pedía que dijeramos cuantas piedras habian en el nivel n, lo que se hizo es recorrer el arbol hasta llegar a ese nivel y sumar 1 si había una piedra en ese nivel.

Además, para crear el arbol se quiso usar un poco de programación dinámica (y así además ahorrar bastante memoria porque cuanto más grande el arbol más memoria se necesita) y se creó un vector de vectores de punteros a nodos del arbol, al cual se añadía el nodo del arbol una vez completo ese nodo en las llamadas recursivas.

### Justificación
Este problema, viendo cómo se ha solucionado la primera parte, claramente se vé porqué se ha elegido este problema, siendo la razón el hecho de que el problema tal y como lo hemos resuelto implementa un arbol binario, lo cual es una técnica que no se ha usado en ningún otro problema, pero además, al meterle programación dinámica a cómo se genera el arbol, se trata de un problema del que se está orgulloso, ya que creemos que es una idea que no se le ha ocurrido a otros compañeros y que es bastante eficiente sobre todo con una cantidad de parpadeos grande.

### Alternativas
En cuanto a alternativas, como se dijo antes, se intentó hacer mediante fuerza bruta, pero si nos fijamos en el hecho de que el problema está usando arboles, tambíen hay varias opciones sobre cómo se podría haber hecho el arbol, como por ejemplo solo avanzar un nivel si se ha partido una piedra o guardar en el arbol el número de piedras que hay en cada nivel. Igualmente nos quedamos con este, porque como se ha dicho, de este día se está orgulloso.

### Valoración personal
En cuanto a la valoración personal, cómo se ha dicho, se está orgulloso de cómo se ha resuelto el problema, ya que se ha hecho algo que no se ha hecho en ningún otro problema y que es bastante eficiente. Además, se ha hecho un problema que no se ha hecho en ningún otro día, lo cual es algo que se buscaba, ya que se quería hacer problemas que no fueran siempre lo mismo. Además con este problema se ha aprendido cómo juntar programación dinámica con arboles, lo cual es una nueva experiencia.

## Dia 16
### Primera Parte
Primeramente, para gestionar los movimientos se ha creado un una esteructura Punto que almacena las cooredenadas de posición y dirección, además del coste necesario para llegar a ese punto.

En un principio se probó una busqueda en profudunidad haciendo llamadas recursivas con todos los movimientos posibles y quedándote con el valor mínimo---



