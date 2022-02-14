public class Hamster extends Animal{
    /*
    Aqui deberia de colocar cada atributo
    nombre, raza, edad, tipo_alimento, sexo
    */

    String color;

    public Hamster(){
        //constructor de la clase
    }

    //sobrecarga para obtener y enviar el color
    public Hamster(String nombre, String raza, String tipo_alimento, 
    int edad, String color){
        //para poder tener los atributos por herencia
        //se debe de colocar super
        super(nombre, raza, tipo_alimento, edad);
        this.color = color;

    }
    public String getColor(){
        return color;
    }

    //enviar
    public void setColor(String color){
        this.color = color;
    }

    //metodo para mostrar la informacion del hamster
    public void mostrarHamster(){
        System.out.println("El nombre del hamster es: " + getNombre() +"\n"
                            + "Su raza es: " + getRaza() +"\n"
                            + "Se alimenta de: " + getTipo_alimento() +"\n"
                            + "Tiene la edad de: " + getEdad() +"\n"
                            //"Su sexo es: " + getSexo() +"\n"
                            + "Su color es: " + color +"\n");
    }
}