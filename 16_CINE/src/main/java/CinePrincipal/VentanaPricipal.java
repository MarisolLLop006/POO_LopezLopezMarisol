/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package CinePrincipal;

/**
 *
 * @author Usuario
 */
public class VentanaPricipal{
    
    SalaCine salaNormal;
    SalaCine sala3D;
    private Object etiNormalPelicula;
    private Object J0ptionPane;
    private Object eti3DPelicula;
    
    /** 
     */
    public VentanaPricipal(){
        initComponents();
        
        salaNormal = new SalaCine();
        sala3D = new SalaCine();
        
        salaNormal.setAforo(500);
        salaNormal.setPrecioEntrada(80);
        
        sala3D.setAforo(60);
        sala3D.setPrecioEntrada(100);
    }
    
private void btnNormalCambiarActionPerformed(java.awt.event.ActionEvent evt) {
    String titulo;
    
    titulo = J0ptionPane.showInputDialog(null, "Escribe el Titulo de la Pelicula:");
    salaNormal.setTituloPelicula(titulo);
    etiNormalPelicula.setText(titulo);
}

private void btnNormalNuevaEntradaAtionPerformed(java.awt.event.ActionEvent evt){
    salaNormal.entrdaUNO();
}

private void btnNormalPorcentajeOcupacionActionPerformed(java.awt.event.ActionEvent evt){
    String info;

    info = "SALA NORMAL\n";
    info = info + "Pelicula; " + salaNormal.getTituloPelicula() + "\n";
    info = info + "Aforo: " + salaNormal.getAforo() + "\n";
    info = info + "Asientos Ocupados: " + salaNormal.getAsientosOcupados() + "\n";
    info = info + "Asientos Libres; " + salaNormal.getAsientosOcupados() + "\n";
    info = info + "Porcentaje de Ocupacion: " + salaNormal.getPorcentajeOcupacion() + "\n";
    
    J0ptionPane.showMessageDialog(null, info);
}

private void btnNormalVaciarActionPerformed(java.awt.event.ActionEvent evt){
    salaNormal.vaciarsala();
    etiNormalPelicula.setText("");
}

private void btnNormalIngresosActionPermed(java.awt.event.ActionEvent evt){
    String info;
    
    info = "Ingresos de la Sala Normal: " + salaNormal.getIngresosSala() + "Euros.";
    J0ptionPane.showMessageDialog(null, info);
}    

    private void initComponents() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    
    public class VentanaPricipal{
    
    SalaCine salaNormal;
    SalaCine sala3D;
    private Object etiNormalPelicula;
    private Object J0ptionPane;
    private Object eti3DPelicula;
    
    /**
     * 
     */
    public VentanaPricipal(){
        initComponents();
        
        salaNormal = new SalaCine();
        sala3D = new SalaCine();
        
        sala3D.setAforo(500);
        sala3D.setPrecioEntrada(80);
        
        salaNormal.setAforo(60);
        salaNormal.setPrecioEntrada(100);
    }
    
private void btn3DCambiarActionPerformed(java.awt.event.ActionEvent evt) {
    String titulo;
    
    titulo = J0ptionPane.showInputDialog(null, "Escribe el Titulo de la Pelicula:");
    sala3D.setTituloPelicula(titulo);
    eti3DPelicula.setText(titulo);
}

private void btn3DNuevaEntradaAtionPerformed(java.awt.event.ActionEvent evt){
    sala3D.entrdaUNO();
}

private void btn3DPorcentajeOcupacionActionPerformed(java.awt.event.ActionEvent evt){
    String info;

    info = "SALA 3D\n";
    info = info + "Pelicula; " + sala3D.getTituloPelicula() + "\n";
    info = info + "Aforo: " + sala3D.getAforo() + "\n";
    info = info + "Asientos Ocupados: " + sala3D.getAsientosOcupados() + "\n";
    info = info + "Asientos Libres; " + sala3D.getAsientosOcupados() + "\n";
    info = info + "Porcentaje de Ocupacion: " + sala3D.getPorcentajeOcupacion() + "\n";
    
    J0ptionPane.showMessageDialog(null, info);
}

private void btn3DVaciarActionPerformed(java.awt.event.ActionEvent evt){
    sala3D.vaciarsala();
    eti3DPelicula.setText("");
}

private void btn3DIngresosActionPermed(java.awt.event.ActionEvent evt){
    String info;
    
    info = "Ingresos de la Sala 3D: " + sala3D.getIngresosSala() + "Euros.";
    J0ptionPane.showMessageDialog(null, info);
}  