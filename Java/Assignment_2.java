/* Nicole Schmidt */
/* Aufgabe 1.1: Klasse zum Arbeiten mit Stacks */

import java.io.*;
import java.util.Scanner;

class Stacks {
    private int[] a;
    private int top;

    //Constructor for the class Stacks, which receives the length for the array and then creates it and sets top to -1, since the array is always empty
    Stacks(int laenge) {
        this.a = new int[laenge];
        this.top = -1;
    }

    //Push method with value passed by the user
    public int push(int wert){
        //If top is smaller than the array length then write the value entered by the user in the stack in place top + 1, otherwise return -1
        if (top+1 < a.length){
            a[top+1] = wert;
            top++;
            return 0;
        }
        else return -1;
    }

    //Pop-Method
    public int pop(){
        //If the array is not empty, then set the top value to 0 and return the value just deleted using a temp variable, otherwise return -1
        if(top > -1){
            int temp = a[top];
            a[top] = 0;
            top--;
            return temp;
        }
        else return -1;
    }

    //Print method that uses a for loop to print the array on the screen
    public int print(){
        for(int i = 0; i < a.length; i++){
            System.out.println(i+": "+a[i]);
        }
        return 0;
    }
}

public class Assignment_2 {
    public static void main(String args[]) throws IOException {
        int laenge, auswahl, pushWert;
        byte x = 1;

        Scanner scanner = new Scanner(System.in); 

        //Let the user determine the length of the stack
        System.out.print("Please enter the length of the stack: ");
        laenge = scanner.nextInt();

        //Create a stack object and transfer the desired array length
        Stacks stack1 = new Stacks(laenge);

        do{
            //Users ask which method should be used or whether the program should be terminated
            do{
                System.out.println("\nWhich method do you want to use? ");
                System.out.println("1 = Push-Method");
                System.out.println("2 = Pop-Method");
                System.out.println("3 = Print-Method");
                System.out.println("4 = Exit Program");
                auswahl = scanner.nextInt();
            } while (auswahl < 1 || auswahl > 4);

            switch(auswahl){
                //Let the user enter a value for the push method, call it and output the return value
                case 1  :   System.out.print("    Please enter the desired value: ");
                            pushWert = scanner.nextInt();
                            System.out.println("    Return value: " + stack1.push(pushWert)); break;

                //Call the Pop method and output the return value
                case 2  :   System.out.println("    Return value: " + stack1.pop()); break;

                //Call the print method
                case 3  :   stack1.print(); break;

                //Set condition for ending the program
                case 4  :   x = 0; break;

                default :   System.out.println("    Error"); break;
            }
        //End the program when the user has entered 4
        } while (x != 0);
        scanner.close();
    }
}
