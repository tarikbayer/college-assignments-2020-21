package praktikum_3;

@SuppressWarnings("hiding")
public interface GList<Object> {

	int getLength();       // liefert die Länge der Liste.
	
	int insertLast(Object value);      // fügt value am Ende der List ein.
	
	Object getFirst();    // liefert das erste Element der Liste.
	
	int deleteFirst();     // entfernt das erste Element von der Liste.
	
	boolean search(Object value, int datentyp);       // prüft, ob der Wert in der Liste vorhanden ist.
	
	void print();       // zeigt den Inhalt der Liste an.
}
