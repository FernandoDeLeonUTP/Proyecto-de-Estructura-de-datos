# Proyecto-de-Estructura-de-datos
Proyecto acerca de progama de recomendación de peliculas
Este proyecto es una aplicación de consola en C++ que permite gestionar y visualizar una lista de películas organizada en distintas categorías (Acción, Romance, Drama, Comedia y Terror). Las películas se almacenan en una matriz bidimensional y están ordenadas por año dentro de cada categoría.

Características
Almacena y organiza películas en cinco categorías: Acción, Romance, Drama, Comedia y Terror.
Permite agregar películas a cada categoría y ordenarlas por año de lanzamiento.
Incluye un menú de opciones para que el usuario elija la categoría de películas que desea visualizar.
Estructura del Proyecto
El código utiliza estructuras básicas de datos en C++:

Estructura Pelicula: Representa cada película con atributos de nombre, plataforma y año.
Estructura MatrizPeliculas: Almacena las películas organizadas en una matriz bidimensional. Cada fila de la matriz representa una categoría, y cada columna almacena una película en esa categoría.
Funciones de Ordenamiento y Visualización:
agregarPelicula: Agrega una nueva película a una categoría específica.
mostrarPeliculas: Muestra las películas de una categoría seleccionada.
ordenarPeliculas: Ordena las películas dentro de una categoría por año.

Menú de Opciones
Al iniciar la aplicación, se le pedirá al usuario que seleccione una categoría para visualizar las películas disponibles en ella.
Según la selección, se mostrarán las películas de esa categoría, ordenadas cronológicamente.

Ejemplo de Funcionamiento
Entrada
El usuario selecciona una categoría, por ejemplo, 1. Acción.

Salida
La aplicación muestra todas las películas de la categoría "Acción" ordenadas por año.

Personalización
Para añadir una nueva categoría o incrementar el número de películas permitidas por categoría:

Cambia el valor de CATEGORIAS o MAX_PELICULAS en el código según tus necesidades.
