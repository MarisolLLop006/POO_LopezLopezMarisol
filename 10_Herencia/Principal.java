


public class Principal{


    public static void main(String[] args){

        //gracias al constructor podemos hacer las instancias de las celdas
        Perro dog = new Perro("pulgas", "de la calle", "Croquetas dogcaut", 1, "hace guau guau" );
        Gato cat = new Gato("Michi", "de colores", "wiscas", 2, 7);
        Hamster hamster = new Hamster("bolita", "de colores", "semillas", 3,"movimientos");
        
        conejo rabbit = new conejo("peludo", "de tamaño", "zanahorias", 4,10);

        //vamos a mostar los datos del perro y del gato
        dog.mostrarPerro();
        cat.mostrarGato();    
        hamster.mostrarHamster(); 
        rabbit.mostrarconejo();

        /*
        Quiero que se imprima el sexo de los animales
        Quiero que agreguen la clase hamster
        Quiero que se agregue alguna otra clase de otro animal domestico
        */
    }
}