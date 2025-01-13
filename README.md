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
./bin/1 < dia1
```
``` bash
cat dia11 | ./bin/11
```
igualmente, si no se quiere realizar una redirección de la entrada, se puede ejecutar sin la redirección y símplemente en cuanto se quiera parar la entrada de datos se pone por teclado un CTRL + D
- Los días 5 y 16 requieren que el archivo input se encuentre en el mismo lugar que el que tú te encuentres, ya que lo que hacen es abrir ellos directamente el archivo y realizar lo que tienen que hacer, por lo que la ejecución sería simplemente realizar un:
``` bash
./bin/número_de_día
```
