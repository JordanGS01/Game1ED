# Dungeons WarRunners
  El proyecto desarrollado en este repositorio corresponde a un juego retro estilo laberinto en 2D. El juego está desarrollado en C++ y utiliza como librería principal SDL2. La principal razón por la cual se desarrollo un proyecto de este estilo fue poner en practica y usar las estructuras de datos estudiadas en el curso.
  
## Grupo desarrollador
  Ambos desarrolladores son estudiantes del Instituto Tecnológico de Costa Rica y cuyos nombres son:
  
**Victor**
  Correos electrónicos:
  - victorjulio345@gmail.com
  
**Jordán Guzmán Salas**
  Correos electrónicos:
  - jordan-guzman-salas@hotmail.com
  - jorggss01@gmail.com
  
  
## Historia del juego

Dungeons WarRunners

En el mundo medieval de Ogstrap, donde la magia nacia hasta de la más pequeña flor y sustentava de vida a todo elemento de su alrededor, donde todas las razas de la tierra vivian y trabajaban conjuntamente para poder, mantienendo así la paz...hasta que un dia la avaricia corrumpio al druida Zar. 

El mundo de Ogstrap posee siete sustancias mágicas, sumamente poderosas e importantes, que mantienen el mundo equilibrado, todas y cada una de ellas localizadas en las zonas más ocultas de este vasto mundo. Los druidas poseen una de las siete sustancias, llamada Ark, la cual se encarga de darle vida a todo la naturaleza.

Zar, conquistado por la voz de un desconocido encapuchado, se dejó seducir por las promesas de poder ilimitado que obtendría si poseia cada una de las esencias mágicas...robó el Ark de los bosques druidas, y como consecuencia de sus acciones, se desató una ola de marchitación global...

Es acá donde entras en acción, encarnando a Master y Rudy, en la busqueda de Zar para recuperar el Ark de los druidas y evitar que consiga encontrar y robar las demas esencias mágicas de la tierra...ya que esto podria desencadenar un suceso fatal.

Viaja a traves de masmorras, bosques y mucho más en el mundo de Ogstrap, elimina a Zar y devuelve la esencia del Ark a su lugar de origen antes de que todo sea demasiado tarde, y la última planta de la tierra haya perdido su magia...y su vida.

## Principales estructuras de datos creadas
 
**Matriz para pintado del mapa**

Se creó una matriz de 20x25 para manejar el pintado del laberinto, siendo un valor 0 para una casilla, y un valor 1 para una pared.

**Matriz de manejo de coordenadas para las recompensas**

   Función que se usa para tener información sobre la ubicación exacta de las recompensas, una vez una de ellas es recogida, la coordenada es eliminada.
   
**Manejo de la posición y animaciones de sprites**

   Se hace manejo de las estructuras de datos SDL_Rect para el pintado de personajes y el laberinto. manejando las posiciones de estos mediante el incremento 
   o decremento de los valores de la estructura.

## Metodos principales

  **Pintado del laberinto**
  
  Se recorre una estructura matricial para reconocer donde pintar los sprite siendo el laberinto el que indica donde se debe colocar un sprite específico.
  
  **Crear las recompensas**
  
  Se encarga de generar una posicion aleatoria y agregarla al laberinto, para que luego este cuando proceda a pintarlo, cuando se recoja la recompensa esta pasa a ser borrada del laberinto por lo que cuando se actualiza, no se vuelve a imprimir. Esta tambien almacena la coordenada de la recompensa para en una estructura matricial, para que asi se pueda saber la posición exacta para que esta pueda ser luego recogida.
  
  **Comprobar recompensa**
  
  Se encarga de recoger la recompensa, este la elimina del mapa, reproduce un sonido, para ello compara la posición del jugador con la estructura con la de la recompensa recorriendo la matriz previamente fabricada,si estas son limitan, activa tanto el sonido como el borrado, y borra la coordenada de la estructura matricial,
  esta sujeta a cambios para fases futuras.
  
  **Muertes y vidas**
  
  Los enemigos carecen de programación por lo que se asigno a modo de prueba en el botón "m" para matar al primer jugador y "k" para el segundo, con esto se eliminan los personajes,vuelven a las posiciones iniciales y se decrementan las vidas, las cuales son compartidas, cuando se acaban las vidas, se termina el juego. Cada vez que un personaje muere se crea una explosion.
  
  **Personajes,animación y movimiento**
  
  El personaje se genera inmóvil,y cuando se mueve procede a animarse,para ello se recorre la estructura de datos correspondiente al sprite de personaje y se anima mediante de ticks, para el desplazamiento se alteran los valores de la posición "x" y "y" presentes en la estructura de datos SDL_Rect. 

## Analisis de resultados

Se logro con éxito al implementación de movimiento, animación, y el pintado del laberinto, los personajes pueden reconocer con exito las recompensas, asi como la implementación de
  sonido, en esta fase del proyecto del proyecto no se implementaron colisiones con paredes del laberinto estas quedaran abiertas a cambios en futuras fases, así tambien
  como los métodos de recompensa quedaran abiertos a cambios para lograr adaptarse a partes posteriores, el principal problema esta presente con el modulado de clases y métodos, esto se procedera a corregir en futuras fases.
  
## Biografia
- [1]S. Baquero, "SDL sonidos - ID-000244379", Sites.google.com, 2014. [Online]. Available: https://sites.google.com/site/id000244379/sdl/sdl-1. [Accessed: 19- Oct- 2020].
- [2]Code, Tech, and Tutorials, SOUND WITH C++ | PART 1 | SDL2 Mixer Walkthrough Tutorial How-To | Playing Sound Effects. 2020.
- [3]D. D'Agostino, "SDL2: Animations with Sprite Sheets", Programmersranch.com, 2014. [Online]. Available: https://www.programmersranch.com/2014/03/sdl2-animations-with-sprite-sheets.html. 
