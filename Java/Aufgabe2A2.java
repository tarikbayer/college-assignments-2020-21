import java.util.Scanner;



public class Aufgabe2A2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
			
		int n;
		int geteilt = 0;
		 Scanner scan = new Scanner(System.in);
		 
		 System.out.println("Geben Sie Ganzzahl n ein: ");
		 
		  do {
		 n = scan.nextInt();
		 if(n > 0) {
			 continue;
		 }
		 } while (n <= 0);
		 
		 while (n > 0) {
			  geteilt = n / 10;
		 }
		 
		 System.out.println(geteilt);
		 
		

	}

}
