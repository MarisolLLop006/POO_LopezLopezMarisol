/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany._ventana;

import java.awt.event.MouseEvent;
import com.toedter.calendar.JDateChooser;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JOptionPane;


/**
 *
 * @author Usuario
 */
public class Registro {
   

public class Registrar implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
        
    
        /*
        Como se vio en la teoria es necesario primero crear el frame 
        */
        
        JFrame ventana = new JFrame("Registrar");
        
        //hay que definir el tamaño de la ventana
        ventana.setSize(400,220 );
        //definir sus acciones de la ventana
        ventana.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        //necesito el panel para poder incorporar los componentes de la interfaz
        JPanel panel = new JPanel();
        //en ese panel agregamos los componentes
        ventana.add(panel);
        
        //vamos a crear un metodo para agregar componentes
        agregarComponente(panel);
        
        ventana.setVisible(true);
        ventana.setLocationRelativeTo(null);
        
        
    }

    private static void agregarComponente(JPanel panel) {
        
        // el panel se debe de inicializar
        panel.setLayout(null); //el panel esta vacio
        
        //agregamos los componentes como:
        JLabel userlabel = new JLabel("Nombre de usuario");
        /*
        para inicializar los componentes se utiliza el metodo
        
        setBounds 
        
        el cual utiliza 4 parametros para poder posicionar el
        componente dentro del panel
        
        2 como coordenadas x y
        2 para definir el tamaño
        */
        
        
        userlabel.setBounds(10, -4, 120, 50);
        //lo agregamos al panel
        panel.add(userlabel);
        
        //agregar un campo de texto
        JTextField usertext = new JTextField(20);
        usertext.setBounds(160, 10, 160, 25);
        panel.add(usertext);
        
        //Apellido Paterno
        JLabel appat = new JLabel("Apellido Paterno");
        appat.setBounds(10,40,100,25);
        panel.add(appat);

        JTextField texto2 =new JTextField(20);
        texto2.setBounds(160,40,165,25);
        panel.add(texto2);

        //Apellido Materno
        JLabel appmat = new JLabel("Apellido Materno");
        appmat.setBounds(10,70,100,25);
        panel.add(appmat);

        JTextField texto3 =new JTextField(20);
        texto3.setBounds(160,70,165,25);
        panel.add(texto3);
        
        JLabel fn = new JLabel("Fecha de nacimiento");
        fn.setBounds(10,100,120,25);
        panel.add(fn);
        
        JDateChooser calendario = new con.toedter.calendar.JDateChooser();
        calendario.setBounds(160,100,165,25);
        panel.add(calendario);
        calendario.setEnabled(true);
        
        JButton guardar = new javax.swing.JButton("Guardar");
        guardar.setBounds(0,150, 120, 25); 
        guardar.setEnabled(true);
        panel.add(guardar);
        guardar.addMouseListener(new java.awt.event.MouseAdapter() {
        public void mouseClicked(java.awt.event.MouseEvent evt) {
        guardarMouseClicked(evt);
    }

        private void guardarMouseClicked(MouseEvent evt) {
            guardar.setText("Guardar");
            guardar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                guardarActionPerformed(evt);
            }

            private void guardarActionPerformed(ActionEvent evt) {
                JOptionPane.showMessageDialog(null,"Registro guardado");
                System.exit(0);
            }
        });
            }
        });
        
        //Boton salir
        JButton Salir = new javax.swing.JButton("Salir");
        Salir.setBounds(180,150, 120, 25); 
        Salir.setEnabled(true);
        panel.add(Salir);
        Salir.addMouseListener(new java.awt.event.MouseAdapter() {
        public void mouseClicked(java.awt.event.MouseEvent evt) {
        SalirMouseClicked(evt);
    }
            private void SalirMouseClicked(MouseEvent evt) {
                System.exit(0);
            }
        });
        


    }    git 
}
}
