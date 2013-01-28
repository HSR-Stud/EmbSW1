using System;
using System.Collections.Generic;

class MainClass {
	public static void Main (string[] args) {
		Console.WriteLine ("Hello World!");

		Messdaten daten = new Messdaten();
		daten.NeuerMesswert(DateTime.Now, 10);

		daten.neueMessdaten+= delegate(DateTime Zeitpunkt, decimal Wert) {
			Console.WriteLine(Zeitpunkt);
			Console.WriteLine(Wert);
		};
		daten.NeuerMesswert(DateTime.Now, 12);
	}
}

public delegate void NeueMessdaten(DateTime Zeitpunkt, decimal Wert);

public class Messwert {
	private DateTime zeitpunkt;
	private decimal wert;
	public Messwert (DateTime Zeitpunkt, decimal Wert) {
		zeitpunkt = Zeitpunkt;
		wert = Wert;
	}
}

public class Messdaten {
	private List<Messwert> messwerte;
	public event NeueMessdaten neueMessdaten;

	public Messdaten () {
		messwerte = new List<Messwert>();
	}

	public void NeuerMesswert(DateTime Zeitpunkt, decimal Wert) {
		Messwert wert = new Messwert(Zeitpunkt, Wert);
		messwerte.Add(wert);
		if(neueMessdaten != null) neueMessdaten(Zeitpunkt, Wert);
	}
}
