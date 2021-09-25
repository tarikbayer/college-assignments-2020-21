package praktikum_4;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Assignment_6 {

	public static void main(String[] args) {
		//Frame
		JFrame frame = new JFrame ("A simple calculator");
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
		
		//When + button is pressed
		plus.addActionListener((e) -> {
			//Check whether there is something in both input text fields
			if (links.getText().length() == 0 || rechts.getText().length() == 0) {
            	ergebnis.setText("keine Eingabe");
                return;
            }
			//Convert input to integer
            int eingabeL = Integer.parseInt(links.getText());
            int eingabeR = Integer.parseInt(rechts.getText());
            int erg;
            
            //Calculate the result and write it back into the 3rd text field as a string
            erg = eingabeL + eingabeR;
            ergebnis.setText(String.valueOf(erg));
        });
		//When - button is pressed
		minus.addActionListener((e) -> {
			//Check whether there is something in both input text fields
            if (links.getText().length() == 0 || rechts.getText().length() == 0) {
            	ergebnis.setText("keine Eingabe");
                return;
            }
            //Convert input to integer
            int eingabeL = Integer.parseInt(links.getText());
            int eingabeR = Integer.parseInt(rechts.getText());
            int erg;
            
            //Calculate the result and write it back into the 3rd text field as a string
            erg = eingabeL - eingabeR;
            ergebnis.setText(String.valueOf(erg));
        });
		 
		//Add all text fields and buttons to the frame and then make it visible (also delete the frame if the window is closed)
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
