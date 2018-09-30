# **Garbage Collector**

El objetivo del proyecto es programar en C la funcionalidad de un "robot" que se mueve en un tablero rectangular (matriz) recogiendo "basura", la cual aparecerá en el tablero en posiciones aleatorias cada cierto tiempo (número de movimientos del robot).

El proyecto consiste de tres partes principales:

1. Tiene que existir la funcionalidad que pinte el tablero con el robot y la basura a medida que avanza la partida, además de la puntuación.

2. La función de movimiento tiene que ser cargada en tiempo de ejecución, de manera que el mismo ejecutable pueda probar diferentes estrategias para la partida.

3. Tiene que existir una funcionalidad para generar una secuencia de llenado del tablero (basura que aparece), y otra funcionalidad que permita leer una secuencia de llenado y ejecutar una partida sobre esta con una función de movimiento, de manera que pueda comprobarse justamente que función es mejor al no variar la distribución de la "basura" a lo largo del juego.

## Especificaciones

* El tablero se representará como un puntero a punteros a char (char**), el tamaño siempre será de 15x15 (se fija el número para facilitar la generación de la secuencia de llenado).

* El robot se representa con una 'X', la basura con 'o' y los espacios vacíos del tablero con '·'.

* La función de movimiento debe tener la siguiente signatura:

```[C]
dir_t fdm(char** board);
```

    Donde `dir_t` representa la dirección a la que se mueve el robot en el turno según el tablero board, y es un entero donde 0 es arriba, 1 es derecha, 2 es abajo y 3 es izquierda.

* El robot no se mueve en diagonal.

* El robot siempre debe estar dentro del tablero.

* Se debe almacenar e imprimir también la puntuación alcanzada hasta el momento.

* La puntuación incrementa cada vez que el robot alcanza una basura y la elimina.
* El valor de la basura es constante y fijémoslo en, no sé... 10 está bien.
* El juego termina después de un límite de jugadas prefijado... digámosle 1000 jugadas.
* Mejores puntuaciones tendrán bonificaciones.
* La secuencia de llenado que debe generarse no es más que un archivo con el siguiente formato en cada línea:

```[Text]
Formato por línea: 1,2 12,4 5,8 4,2 11,10
```

* Este formato indica las posiciones en que deben agregarse basuras al en el siguiente "llenado" del tablero, la cantidad siempre debe ser 5. Si una basura cae sobre otra al llenar no cambia nada. Si cae sobre el robot se le agregan los (10) puntos. Se llena cada 10 movimientos, y llenar no es mas que leer una línea del archivo, parsearla y actualizar el tablero.

* El archivo de llenado debe ser pasado como parámetro al ejecutable. Generar un archivo de este tipo es parte del proyecto.
