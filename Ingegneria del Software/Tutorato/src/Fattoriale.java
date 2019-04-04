public class Fattoriale extends Operazione{
	
	public Fattoriale(String  operandi) {
		super(operandi);
	}
	
	/**
	 * *Calcola il risultato dell'operazione Divisione. Utilizzare la lista di valori.
	 * 
	 * @return risultato dell'operazione.
	 */
	@Override
	public float calcolaRisultato() {
		return fattoriale(valori.get(0));
	}
	
	private float fattoriale(float n) {
		if(n==1) return 1;
		return n*fattoriale(n-1);
	}
}