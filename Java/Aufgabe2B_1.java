import java.util.Scanner;

public class Aufgabe2B_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		double x;
		Scanner scan = new Scanner(System.in);
		
		do {
			x = scan.nextDouble();
		} while(x < 1.0 || x > 5.0);
		
		if(1.0 <=_x && x < 1.6){
			anzahl = 5;
			System.out.println(" Sehr gut");		
		}
		
		else if(1.6 <= x && x < 2.6) {
			anzahl = 4;
			System.out.println();
		}
		
		else if(2.6 <= x && x < 3.6) {
			anzahl = 3;
			System.out.println();
		}
		
		else if(3.6 <= x && x < 4.6) {
			anzahl = 2;
			System.out.println();
		}
		
		else if(4.6 <= x && x < 5.0) {
			anzahl = 1;
			System.out.println();
		}
		
		
		

	}

}
