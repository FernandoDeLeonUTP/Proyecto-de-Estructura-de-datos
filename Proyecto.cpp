#include <iostream>
#include <string>
using namespace std;

const int MAX_PELICULAS = 10; // Número máximo de películas por categoría
const int CATEGORIAS = 5; // Número de categorías

// Estructura para almacenar los detalles de cada película
struct Pelicula {
    string nombre;
    string plataforma;
    int a;

    // Constructor para inicializar cada película
    Pelicula() : nombre(""), plataforma(""), a(0) {} // Constructor vacío para inicializar una película sin datos
    Pelicula(string nom, string plat, int year) : nombre(nom), plataforma(plat), a(year) {}
};

// Estructura para manejar la matriz de películas por categoría
struct MatrizPeliculas {
    Pelicula peliculas[CATEGORIAS][MAX_PELICULAS]; // Matriz de películas
    int contador[CATEGORIAS] = { 0 }; // Contador para cada categoría

    // Función para agregar una película en la categoría seleccionada
    void agregarPelicula(int categoria, string nombre, string plataforma, int a) {
        if (categoria < 0 || categoria >= CATEGORIAS) {
            cout << "Categoría inválida.\n";
            return;
        }
        if (contador[categoria] < MAX_PELICULAS) {
            peliculas[categoria][contador[categoria]] = Pelicula(nombre, plataforma, a);
            contador[categoria]++;
        }
        else {
            cout << "Límite de películas alcanzado para esta categoría.\n";
        }
    }

    // Función para mostrar todas las películas de una categoría específica
    void mostrarPeliculas(int categoria) const {
        if (categoria < 0 || categoria >= CATEGORIAS) {
            cout << "Categoría inválida.\n";
            return;
        }
        for (int i = 0; i < contador[categoria]; i++) {
            cout << "- " << peliculas[categoria][i].nombre << " (" << peliculas[categoria][i].a
                << ") - puedes encontrarla en la plataforma de: " << peliculas[categoria][i].plataforma << endl;
        }
    }

    // Método para ordenar las películas por año en cada categoría
    void ordenarPeliculas(int categoria) {
        if (categoria < 0 || categoria >= CATEGORIAS) {
            cout << "Categoría inválida.\n";
            return;
        }
        for (int i = 0; i < contador[categoria] - 1; i++) {
            for (int j = i + 1; j < contador[categoria]; j++) {
                if (peliculas[categoria][i].a > peliculas[categoria][j].a) {
                    swap(peliculas[categoria][i], peliculas[categoria][j]);
                }
            }
        }
    }
};

int main() {
    MatrizPeliculas matrizPeliculas;

    // Agregar películas a la matriz en la categoría de Acción
    matrizPeliculas.agregarPelicula(0, "Mad Max: Fury Road", "HBO Max", 2015);
    matrizPeliculas.agregarPelicula(0, "John Wick", "Peacock", 2014);
    matrizPeliculas.agregarPelicula(0, "Gladiator", "Netflix", 2000);
    matrizPeliculas.agregarPelicula(0, "Die Hard", "Disney+", 1988);
    matrizPeliculas.agregarPelicula(0, "The Dark Knight", "HBO Max", 2008);

    // Agregar películas a la matriz en la categoría de Romance
    matrizPeliculas.agregarPelicula(1, "The Notebook", "Netflix", 2004);
    matrizPeliculas.agregarPelicula(1, "Pride and Prejudice", "HBO Max", 2005);
    matrizPeliculas.agregarPelicula(1, "Titanic", "Disney+", 1997);
    matrizPeliculas.agregarPelicula(1, "La La Land", "Netflix", 2016);
    matrizPeliculas.agregarPelicula(1, "A Star is Born", "HBO Max", 2018);

    // Agregar películas a la matriz en la categoría de Drama
    matrizPeliculas.agregarPelicula(2, "The Godfather", "Paramount+", 1972);
    matrizPeliculas.agregarPelicula(2, "Schindler's List", "Peacock", 1993);
    matrizPeliculas.agregarPelicula(2, "Forrest Gump", "Netflix", 1994);
    matrizPeliculas.agregarPelicula(2, "The Shawshank Redemption", "HBO Max", 1994);
    matrizPeliculas.agregarPelicula(2, "Fight Club", "Hulu", 1999);

    // Agregar películas a la matriz en la categoría de Comedia
    matrizPeliculas.agregarPelicula(3, "Superbad", "Netflix", 2007);
    matrizPeliculas.agregarPelicula(3, "The Hangover", "HBO Max", 2009);
    matrizPeliculas.agregarPelicula(3, "Step Brothers", "Amazon Prime", 2008);
    matrizPeliculas.agregarPelicula(3, "Groundhog Day", "Hulu", 1993);
    matrizPeliculas.agregarPelicula(3, "Anchorman", "Peacock", 2004);

    // Agregar películas a la matriz en la categoría de Terror
    matrizPeliculas.agregarPelicula(4, "The Exorcist", "HBO Max", 1973);
    matrizPeliculas.agregarPelicula(4, "A Nightmare on Elm Street", "Netflix", 1984);
    matrizPeliculas.agregarPelicula(4, "Halloween", "Peacock", 1978);
    matrizPeliculas.agregarPelicula(4, "The Shining", "HBO Max", 1980);
    matrizPeliculas.agregarPelicula(4, "It", "Hulu", 2017);

    // Ordenar las películas de la categoría de Acción
    matrizPeliculas.ordenarPeliculas(0);

    // Menú de categorías
    cout << "Bienvenido a tu recomendador de peliculas favorito que categoria de peliculas deseas ver hoy:\n";
    cout << "1. Accion\n";
    cout << "2. Romance\n";
    cout << "3. Drama\n";
    cout << "4. Comedia\n";
    cout << "5. Terror\n";
    cout << "Ingrese el numero de la categoria: ";

    int opcion;
    cin >> opcion;

    // Mostrar las películas en la categoría seleccionada
    cout << "\nOpciones de peliculas:\n";
    if (opcion >= 1 && opcion <= CATEGORIAS) {
        matrizPeliculas.mostrarPeliculas(opcion - 1);
    }
    else {
        cout << "Opción inválida. Por favor, seleccione una categoría válida.\n";
    }

    return 0;
}
