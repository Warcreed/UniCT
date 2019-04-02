// classe che chiama metodi di ListaOperazioni
// compilare con javac MainOperazioni.java
// eseguire con java MainOperazioni
import java.io.IOException;

public class MainOperazioni {
	public static void main(String[] args) {
		System.out.println("inizio esecuzione");
		ListaOperazioni lsop = new ListaOperazioni();

		try {
			lsop.leggiFile("csvfiles", "Operazioni.csv");
		} catch (IOException e) {
			System.err.println(e.getMessage());
			return;
		}
		
		System.out.println("somma totale "+ lsop.calcolaSommaTotale());
	}
}