public class Moltiplicazione extends Operazione{

	public Moltiplicazione(String  operandi) {
		super(operandi);
	}
	
	/**
	 * *Calcola il risultato dell'operazione Divisione. Utilizzare la lista di valori.
	 * 
	 * @return risultato dell'operazione.
	 */
	@Override
	public float calcolaRisultato() {
		float result = 0;
		
		for (float f : valori) {
			result *= f;
		}
		return result;
	}
}