import java.io.*;
import java.lang.Math;
public class Assignment_1A {
    public static void main(String args[]) throws IOException {
        double radius, result;
        
        BufferedReader in
            = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("\nCalculation for a circle:\n");
        System.out.println("Please enter:");

        System.out.print(" Radius: ");        
        radius = Double.parseDouble(in.readLine());

        result = Math.PI * Math.pow(radius, 2);
        
        System.out.println("\nResult: "+result);
    }
}
