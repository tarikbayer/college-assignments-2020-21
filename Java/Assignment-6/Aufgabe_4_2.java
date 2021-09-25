package praktikum_4;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Aufgabe_4_2 {

	public static void main(String[] args) {
		//Frame
		JFrame frame = new JFrame ("Ein einfacher Taschenrechner");
		frame.setLocation(700, 400);
		frame.setSize(400, 300);

		//Layout
		GridLayout layout = new GridLayout(3,2);
		
		//Textfelder
		JTextField links = new JTextField();
		JTextField rechts = new JTextField();
		JTextField ergebnis = new JTextField();
		links.setFont (new Font ("Arial", Font.BOLD, 26));
		rechts.setFont (new Font ("Arial", Font.BOLD, 26));
		ergebnis.setFont (new Font ("Arial", Font.BOLD, 26));
		
		//Buttons
		JButton plus = new JButton ("+");
		JButton minus = new JButton ("-");
		plus.setFont (new Font ("Arial", Font.BOLD, 30));
		minus.setFont (new Font ("Arial", Font.BOLD, 30));
		
		//Wenn + Button gedrückt wird 
		plus.addActionListener((e) -> {
			//Überprüfen ob in beiden Eingabe Text Feldern etwas steht
			if (links.getText().length() == 0 || rechts.getText().length() == 0) {
            	ergebnis.setText("keine Eingabe");
                return;
            }
			//Eingabe zu Integer umwandeln
            int eingabeL = Integer.parseInt(links.getText());
            int eingabeR = Integer.parseInt(rechts.getText());
            int erg;
            
            //Ergebnis berechnen und als String wieder in das 3. Textfeld schreiben
            erg = eingabeL + eingabeR;
            ergebnis.setText(String.valueOf(erg));
        });
		//Wenn - Button gedrückt wird 
		minus.addActionListener((e) -> {
			//Überprüfen ob in beiden Eingabe Text Feldern etwas steht
            if (links.getText().length() == 0 || rechts.getText().length() == 0) {
            	ergebnis.setText("keine Eingabe");
                return;
            }
            //Eingabe zu Integer umwandeln
            int eingabeL = Integer.parseInt(links.getText());
            int eingabeR = Integer.parseInt(rechts.getText());
            int erg;
            
            //Ergebnis berechnen und als String wieder in das 3. Textfeld schreiben
            erg = eingabeL - eingabeR;
            ergebnis.setText(String.valueOf(erg));
        });
		 
		//Alle Textfelder und Buttons dem frame hinzufügen und es anschließen sichtbar machen (außerdem den frame löschen falls das Fenster geschlossen wird)
		frame.add(links);
		frame.add(rechts);
		frame.add(plus);
		frame.add(minus); 
		frame.add(ergebnis);
        frame.setLayout(layout);
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent we) {
                frame.dispose();
            }
        });
		frame.setVisible(true);
	}

}
