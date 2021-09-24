import java.util.Scanner;

public class Aufgabe2A1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int g1 = 0, g2 = 0;
		int zz = 0, nn = 0;
		
		
		Scanner scan = new Scanner(System.in);
		System.out.println("Geben Sie Zahl z ein: ");
		int z = scan.nextInt();
		  	do {
			  g1 = z;
		  		} while(z <= 0); 
		  	
		
		Scanner scan2 = new Scanner(System.in);
		System.out.println("Geben Sie Zahl n ein: ");
		int n = scan2.nextInt();
			do {
			  g2 = n;
				} while(n <= 0); 
		
		while(g1 != g2) {
			if(g1<g2) {
				g2 = g2 - g1;
			} else {
				g1 = g1 - g2;				
			}break;
		}	
			
		 zz = z / g1;
		 nn = n / g1;
		System.out.println(zz+"/"+nn);
		
		
			
		

	}

}
