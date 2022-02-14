/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package CinePrincipal;

/**
 *
 * @author Usuario
 */
public class SalaCine {
    
    int aforo;
    int horariosDisponibles;
    int asientosOcupados;
    String tituloPelicula;
    String clasificacionEdades;
    double precioEntrada;
    double totalApagar;
    
    //Precios y horarios
    public SalaCine(){
        aforo = 200;
        horariosDisponibles = 18;
        asientosOcupados = 10;
        tituloPelicula = "";
        clasificacionEdades = "";
        precioEntrada = 70;
        totalApagar = 100;
    }
    
    // Esta persona va aver las siguientes opciones
    public void setAforo(int afo){
        aforo = afo;
    }
    
    public void setHorariosDisponibles(int dispo){
        horariosDisponibles = dispo;
    }
    
    public void setAsientosOcupados(int ocu){
        asientosOcupados = ocu;
    }
    
    public void setTituloPelicula(String peli){
        tituloPelicula = peli;
    }
    
    public void setClasificacionEdades(String edad){
        clasificacionEdades = edad;
    }
    
    public void setPrecioEntrada(double entra){
        precioEntrada = entra;
    }
    
    public void setTotalApagar(double apaga){
        totalApagar = apaga;
    }
    
    public void setHorariosLibres(int lib){
        int dispo;
        
        dispo = aforo -lib;
        horariosDisponibles = dispo;
    }
    
    public void setAsientosLibres(int lib){
        int ocu;
        
        ocu = aforo - lib;
        asientosOcupados = ocu;
    }
    
    public int getAforo(){
        return aforo;
    }
    
    public int getHorariosDisponibles(){
        return horariosDisponibles;
    }
    
    public int getAsientosOcupados(){
        return asientosOcupados;
    }
    
    public String getTituloPelicula(){
        return tituloPelicula;
    }
    
    public String getClasificacionEdades(){
        return clasificacionEdades;
    }
    
    public double getPrecioEntrada(){
        return precioEntrada;
    }
    
    public double getTotalApagar(){
        return totalApagar;
    }
    
    public int getHorariosLibres(){
        int lib;
        lib = aforo - horariosDisponibles;
        return lib;
    }
    
    public  double getPorcentajeOcupacion(){
        double porc;
        porc = (double) horariosDisponibles * 18/ (double) aforo;
        return porc;
    }
    
    public double gettIngresosSala(){
        double ingre;
        ingre = horariosDisponibles * precioEntrada;
        return ingre;
    }
    
    public void vaciarsala(){
        asientosOcupados = 10;
        tituloPelicula ="";
    }
    
    public void entrdaUNO(){
        asientosOcupados++;
    }

    String getIngresosSala() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}



