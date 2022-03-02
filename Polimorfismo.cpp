// Polimorfismo

#include <iostream>
using namespace std;

//Practica de Herencia y Encapsulamiento con polimorfismo

//Clase Base: Genereos de Juegos
class generosDeJuegos {

    //Declaramos las siguientes variables como privadas, solo puede ser accedida por medio de metodos que pertenezcan a esta clase
private:
    string rating = "";
    string nombre = "";

    //Declaramos metodos publicos que nos permitan retornar el valor de la variable privada y modificarlo (Setters & Getters)
public:
    //Declararemos un metodo para modificar las variables privadas
    void defineRatingDeAcuerdoALaEdad(int edad) {

        if (edad < 12) {
            rating = "E / Everyone / Todos";
        }
        if (edad >= 12 && edad < 15) {
            rating = "E10+ / Everyone 10+ / 12+";
        }
        if (edad >= 15 && edad < 18) {
            rating = "T / Teen / 15+";
        }
        if (edad >= 18) {
            rating = "M / Mature 17+ / 18+";
        }
    }

    //Declaramos un metodo especifico para casos extremos
    void defineRatingExtremo() {
        rating = "A / Adults Only / Exclusivo Adultos";
    }

    //Metodo para asignar nombre
    void setNombre(string nombrecito) {
        nombre = nombrecito;
    }

    //Metodo para retornar el valor de nombre
    string getNombre() {
        return nombre;
    }

    //Metodo para retornar el valor de rating
    string getRating() {
        return rating;
    }

    //Metodo declarado con virtual para generar polimorfismo
    virtual void generaDesarrolladora() {
        cout << "Desarrolladora: X" << endl;
    }
};


//Declaramos Sublclase y heredamos de la clase base
class genero : public generosDeJuegos {
    //Comienza el bloque polimorfico
public:
    void generaDesarrolladora() {
        cout << "Desarrolladora: A" << endl;
    }
};

int main()
{
    //delcaramos variables que nos serviran para almacenar datos
    string nombreIngresado = "";
    string respuestaDeContenidoExplicito = "";
    int edadIngresada = 0;
    bool valorIngresadoCorrecto = false;

    //declaramos la subclase
    genero gen1;

    //pedimos valores al usuario
    cout << "Porfavor ingrese el nombre del genero:" << endl;
    cin >> nombreIngresado;
    cout << "Ingrese la edad recomendada para este genero:" << endl;
    cin >> edadIngresada;

    gen1.defineRatingDeAcuerdoALaEdad(edadIngresada);

    while (valorIngresadoCorrecto == false) {
        cout << "Se trata de un genero dedicado solo para adultos (Responda Si o No)" << endl;
        cin >> respuestaDeContenidoExplicito;
        if (respuestaDeContenidoExplicito == "Si" || respuestaDeContenidoExplicito == "No" || respuestaDeContenidoExplicito == "si" || respuestaDeContenidoExplicito == "no") {
            if (respuestaDeContenidoExplicito == "Si" || respuestaDeContenidoExplicito == "si") {
                gen1.defineRatingExtremo();
            }
            valorIngresadoCorrecto = true;
        }
    }

    //Asignamos el valor a la subclase que ha heredado esta caracteristica de la clase base
    gen1.setNombre(nombreIngresado);

    cout << "El genero es: " << gen1.getNombre() << ", Clasificacion: " << gen1.getRating() << endl;
    
    //llamamos al metodo polimorfico
    gen1.generaDesarrolladora();

}
