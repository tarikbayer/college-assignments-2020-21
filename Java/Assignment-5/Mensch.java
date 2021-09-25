package praktikum_4;

import java.io.*;

@SuppressWarnings("serial")
public class Mensch implements Serializable {
	private String name;
	private double groesse;
	private int alter;
	Mensch next;
	
	Mensch(){}
	
	//Konstruktor
	Mensch(String name, double groesse, int alter){
		this.name = name;
		this.groesse = groesse;
		this.alter = alter;
		this.next = null;
	}
	
	//Print-Methode
	public void print() {	
		System.out.println("Name: " + name);
		System.out.println("Größe: " + groesse);
		System.out.println("Alter: " + alter);
		
	}
}
