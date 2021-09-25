package praktikum_3;

@SuppressWarnings("hiding")
public interface GList<Object> {

	int getLength();       // liefert die L�nge der Liste.
	
	int insertLast(Object value);      // f�gt value am Ende der List ein.
	
	Object getFirst();    // liefert das erste Element der Liste.
	
	int deleteFirst();     // entfernt das erste Element von der Liste.
	
	boolean search(Object value, int datentyp);       // pr�ft, ob der Wert in der Liste vorhanden ist.
	
	void print();       // zeigt den Inhalt der Liste an.
}
