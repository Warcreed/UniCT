// Divisione.java
public class Divisione extends Operazione {

	public Divisione(String operandi) {
		super(operandi);
	}

	/**
	 * Calcola il risultato dell'operazione Divisione. Utilizzare la lista di valori.
	 * 
	 * @return risultato dell'operazione.
	 */
	@Override
	public float calcolaRisultato() {
		float result = 0;
		float div = valori.get(0);
		
		for (int i=1; i<valori.size();i++) {
			if(div!=0) result+=valori.get(i)/div;
		}
		return result;
	}
}
