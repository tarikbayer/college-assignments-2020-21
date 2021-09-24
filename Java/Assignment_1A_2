import java.io.*;
import java.lang.Math;
public class Aufgabe_1A_3 {
    public static void main(String args[]) throws IOException {
        int centerX, centerY, pointX, pointY;
        double radius, result;
        
        BufferedReader in
            = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("\nCalculation for a circle:\n");        
        System.out.println("Please enter:");

        System.out.println(" Center:");
        System.out.print("  X-Coordinate: ");
        centerX = Integer.parseInt(in.readLine());
        System.out.print("  Y-Coordinate: ");
        centerY = Integer.parseInt(in.readLine());

        System.out.println(" Point on the circular line: ");
        System.out.print("  X-Coordinate: ");
        pointX = Integer.parseInt(in.readLine());
        System.out.print("  Y-Coordinate: ");
        pointY = Integer.parseInt(in.readLine());
        
        radius = Math.sqrt((Math.pow((pointX - centerX), 2)) + Math.pow((pointY - centerY), 2));
        
        result = Math.PI * Math.pow(radius, 2);
        
        System.out.println("\nResult: "+result);
    }
}
