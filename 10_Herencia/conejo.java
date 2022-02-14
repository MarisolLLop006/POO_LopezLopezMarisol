public class conejo extends Animal{
    /*
    Aqui deberia de colocar cada atributo
    nombre, raza, edad, tipo_alimento, sexo
    */

    int zapateo;

    public conejo(){
        //constructor de la clase
    }

    //sobrecarga para obtener y enviar el numero de zapateos
    public conejo(String nombre, String raza, String tipo_alimento, 
    int edad, int zapateo){
        //para poder tener los atributos por herencia
        //se debe de colocar super
        super(nombre, raza, tipo_alimento, edad);
        this.zapateo = zapateo;

    }
    public int getZapateo(){
        return zapateo;
    }

    //enviar
    public void setZapateo( int zapateo){
        this.zapateo = zapateo;
    }

    //metodo para mostrar la informacion del conejo
    public void mostrarconejo(){
        System.out.println("El nombre del conejo es es: " + getNombre() +"\n"
                            + "Su raza es: " + getRaza() +"\n"
                            + "Se alimenta de: " + getTipo_alimento() +"\n"
                            + "Tiene la edad de: " + getEdad() +"\n"
                            //"Su sexo es: " + getSexo() +"\n"
                            + "Su numero de zapateos es: " +zapateo +"\n");
    }
}