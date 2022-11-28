# ♠️ ♥️  Game_BlackJack  ♦️ ♣️
## Game made in c++ 👨🏻‍💻

![Image](https://github.com/luroalfa/perfil/blob/main/Init_game.jpeg)

La implementación fue basada las reglas de negocio del cliente.


Este juego de cartas es conocido como Blackjack o 21 consiste en un sencillo juego cuyo objetivo es lograr obtener 21 puntos o lo más cercano posible, pero sin pasarse. 

En la baraja cada carta numérica vale sus respectivos puntos, cada carta con dibujo (J, Q, K) valen 10 puntos y el As vale 1 u 11 puntos, el valor del As lo decide el jugador a su conveniencia. 
Se reparten 2 cartas a cada jugador, y cada jugador decide si pide más cartas o se queda con su valor actual. 

Gana la persona que logre obtener 21 puntos, o lo más cercano posible, pero sin pasarse. 

REGLAS DE NEGOCIO: Son las reglas del cliente que vamos a seguir para desarrollar el juego.


Implementación: 

Realice una aplicación de consola que permita a 3 personas jugar una partida de Blackjack, no se utilizarán las reglas oficiales (dividir, doblar, rendirse, seguro, cobrar 1 a 1, etc.). Tampoco existirán las reglas de verse obligado a pedir si se tiene mayor o menor cantidad de ciertos puntos. No existirá la figura oficial del crupier (repartidor), ya que este tiene reglas diferentes. 

Se realizará una partida sencilla en donde al iniciar se le reparten 2 cartas a cada una de las 3 personas. Cada persona puede decidir si quiere una carta más en cada ronda, pero si se pasa de 21 automáticamente pierde. 

Si una persona tiene un As se tomará como 11. Pero cuando una persona se pase de 21 automáticamente se tomará el As como 1.

En cada ronda cada persona decide si desea tomar otra carta o no, y además cada vez que una persona toma una carta se comprueba si tiene un 21 para declarar que ganó. 

Cuando las 3 personas ya hayan indicado que no desean tomar más cartas, entonces el programa calculará quién ganó, tomando como ganadora a la persona cuyos puntos estén más cerca de 21, pero sin pasarse, como se indicó anteriormente. Podría haber empates. 
