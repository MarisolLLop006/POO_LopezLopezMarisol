
import java.util.Scanner;

public class Arreglos{

    Scanner entrada = new Scanner(System.in);

    char op;


    public void menu(){
        System.out.println("elija una opcion deseada: ");
        System.out.println("a. Elabore un programa que lea por el teclado 10 números enteros y los guarde en un Array");
        System.out.println("b.- Elabore un programa que lea 10 números enteros por teclado y los guarde en un array. ");
        System.out.println("c.- Realice un programa que permita leer 10 calificaciones de una asignatura y los guarde en un array para que muestre: ");
        System.out.println("d.- matiz 3x3 ");
        System.out.println("e.- matiz 4x4 ");
        System.out.println("f, - palíndronma");
        System.out.println("Cualquier otra opcion sale del programa");

        op = entrada.next().charAt(0);

        switch(op){
            case 'a':
                //implementar metodos independientes para cada opcion
                arreglos1();
                break;

            case 'b':
                arreglos2();
                break;

             case 'c':
             arreglos3();
             break;

             case 'd':
             arreglos4();
             break;

             case 'e':
             arreglos5();
             break;

             case 'f':
             arreglos6();
             break;



            

             default: 
                System.out.println("Gracias por su atencion ");
        }
    
    }


        private void arreglos1() {
        /* 
        Elabore un programa que lea por el teclado 
        10 números enteros y los guarde en un Array, posteriormente que calcule y muestre el promedio de los 
        valores positivos y  de los negativos.*/
    
            Scanner sc = new Scanner(System.in);
            int i;
            int pos = 0, neg = 0;
            int[] numeros = new int[10]; 
            double sumaPos = 0, sumaNeg = 0; 
           
            System.out.println("Lectura de los elementos del array: ");
            for (i = 0; i < 10; i++) {
                System.out.print("numeros[" + i + "]= ");
                numeros[i]=sc.nextInt();
            }
    
            //recorrer el array para sumar por separado los números positivos 
             // y los negativos 
            for (i = 0; i < 10; i++) {
                if (numeros[i] > 0){
                    sumaPos += numeros[i];
                    pos++;
                } else if (numeros[i] < 0){ 
                    sumaNeg += numeros[i];
                    neg++;
                }
            }
    
            //Calcular y mostrar las medias
            if (pos != 0) {
                System.out.println("Media de los valores positivos: " + sumaPos / pos);                
            } else {
                System.out.println("No ha introducido numeros positivos");
            }
            if (neg != 0) {
                System.out.println("Media de los valores negativos: " + sumaNeg / neg);
            } else {
                System.out.println("No ha introducido numeros negativos");
            }
        
    }
    
   
    
             private void arreglos2(){
              
                Scanner sc = new Scanner(System.in);
                int i;
                int[] numeros = new int[10];
                double media = 0;

        
                System.out.println("Lectura de los elementos del array: ");
                for (i = 0; i < 10; i++) {
                System.out.print("numeros[" + i + "]= ");
                numeros[i] = sc.nextInt();
                }
        
        
                 for (i = 0; i < 10; i++) {
                 if (i % 2 == 0){ 
                 media = media + numeros[i]; 
                 }
           
             }
                 System.out.println("Media de los valores que se encuentran en posiciones pares: "+ media/5);              
             }
            


            private void arreglos3(){
                Scanner sc = new Scanner(System.in);
        int numAlum, i;
        double suma = 0, media;

        
        do {
            System.out.print("Número de alumnos de la clase: ");
            numAlum = sc.nextInt();
        } while (numAlum <= 0);

        
        double[] notas = new double[numAlum]; 
        
        
        for (i = 0; i < notas.length; i++) {
            System.out.print("Alumno " + (i + 1) + " Nota final: ");
            notas[i] = sc.nextDouble();
        }

        
        for (i = 0; i < notas.length; i++) {
            suma = suma + notas[i];
        }

        
        media = suma / notas.length;

        
        System.out.printf("Nota media del curso: %.2f %n", media);

        
        System.out.println("Listado de notas superiores a la media: ");
        for (i = 0; i < notas.length; i++) {
            if (notas[i] > media) {
                System.out.println("Alumno numero " + (i + 1)+ " Nota final: " + notas[i]);
            }
        }
    }



     private void arreglos4(){
        
        int i;
int j;
int matriza[][]=new int[3][3];

Scanner dato = new Scanner (System.in);
System.out.println("Escribir datos de la matriz ");

    for (i=0;i<=2;i++){
        for (j=0;j<=2;j++){
            System.out.print("Escribir valor " + i + " , " + j + " : ");
            matriza [i][j] = dato.nextInt();
        }
    }
         System.out.println("MATRIZ 3x3");
        for (i=0;i<=2;i++){
         for (j=0;j<=2;j++){
         System.out.print(matriza[i][j]+"");
        }
         System.out.println("");
         }
       } 


        private void arreglos5(){
            int i;
         int j;
          int matriza[][]=new int[4][4];

          Scanner dato = new Scanner (System.in);
         System.out.println("Escribir datos de la matriz ");

         for (i=0;i<=3;i++){
          for (j=0;j<=3;j++){
            System.out.print("Escribir valor " + i + " , " + j + " : ");
            matriza [i][j] = dato.nextInt();
         } 
         }
          System.out.println("MATRIZ 4x4");
          for (i=0;i<=3;i++){
          for (j=0;j<=3;j++){
          System.out.print(matriza[i][j]+"");
        }
         System.out.println("");
         }
         }
         private void arreglos6(){
            Scanner sc= new Scanner(System.in);
            System.out.print("Introduce una frase (puede tener puntos, comas y espacios): ");
            String s=sc.nextLine();
            
            s=s.replace(" ", "");
            s=s.replace(",", "");
            s=s.replace(".", "");
            System.out.print(s);
            int fin = s.length()-1;
            int ini=0;
            boolean espalin=true;
            
            while(ini < fin){
                if(s.charAt(ini)!=s.charAt(fin)){
                    espalin=false;
                }
            ini++;
            fin--;
            }
            if(espalin)
                System.out.print("\nEs palindromo.");
            else
                System.out.print("\nNo es palindromo.");
            
        }
    }
         

       
            
 