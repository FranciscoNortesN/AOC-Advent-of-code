## Día 9
### Justificación
Hemos elegido como técnica DyV puesto que el ejercicio puede dividirse en segmentos y calcular el tamaño de cada ID recursivamente.

### Descripción técnica:
El problema se basa en eliminar los bloques vacíos de memoria y compactar los últimos archivos en los primeros huecos hasta que no queden bloques de memoria sin utilizar. Una vez se ha compactado el disco, se suma el espacio de cada ID multiplicándolo por su posición en la compactación final. Las funciones del código son analizarMapa(const string& diskMap) que convierte el mapa dado en carácteres y lo convierte a enteros para poder trabajarlo, compactSegment(vector<int>& segment) compacta un segmento del disco moviendo los valores diferentes de 0 al principio del segmento y dejando los 0's al final, mergeSegments(const vector<vector<int>>& segments) fusiona todos los segmentos del mapa en uno solo, sumaSegmentos(const vector<int>& segmentos) en cada segmento multiplica cada ID por su indice y devuelve la suma total, dividirMapa(const vector<int>& segmentos, int segmentSize) divide el imput en subsegmentos más pequeños de tamaño segmentSize, unirSegmentos(vector<int>& segmento, int segmentSize) compacta los segmentos los ordena y se llama así mismo recursivamente.

### Alternativas:
Si bien DyV no es la técnica adecuada para afrontar este problema, nos decantamos por esta técnica porque carecíamos de ella en los demás ejercicios. Por último, destacar que no ha sido sencillo encontrar en los 24 ejercicios uno que sea ideal para DyV. Una implementación básica iterativa podría haber funcionado aunque el coste pueda ser alto y la posibilidad de utilizar un árbol binario la barajamos pero nos decantamos por DyV porque ya teniamos implementados otros ejercicios con árboles.

### Valoración personal:
Consideramos que la divir el mapa en segmentos es una buena manera de resolver el problema para poder compactarlo de manera que se pueda seguir haciendo aunque el imput sea grande, Si bien DyV puede no ser la técnica más adecuada para afrontar este problema, nos decantamos por esta técnica porque carecíamos de ella en los demás ejercicios. Por último, destacar que no ha sido sencillo encontrar en los 24 ejercicios uno que sea ideal para DyV.

