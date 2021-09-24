import java.util.Scanner;

public class aufgabeyenideneme {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int z, n;
		int g1, g2;
		int zz, nn;
		
		Scanner scan = new Scanner(System.in);
		do {
			
			System.out.println("Geben Sie Ganzzahl z ein: ");
		
			do {
				
				z = scan.nextInt();
				break;
			} while (z <= 0);
			
				do {
					System.out.println("Geben Sie Ganzzahl n ein: ");
					n = scan.nextInt();
					break;
				} while (n <= 0);
			
			g1 = z;
			g2 = n;
			
				do {
					if (g1<g2) {
						g2 = g2 - g1;
					} else {
						g1 = g1 - g2;
							} 
					} while(g1 != g2);
				
			zz = z / g1; 
			nn = n / g1;
			
			System.out.println(zz+ "/" +nn);
			
			
		
		
		break;
		
		} while(zz != 0 && nn != 0);
		

	}

}
