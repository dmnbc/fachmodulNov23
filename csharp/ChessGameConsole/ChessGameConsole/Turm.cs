using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessGameConsole
{
    // 'Turm' ist eine Klasse, die von 'Schachfigur' erbt. Hier wird spezifiziert, was ein Turm im Schach so macht.
    public class Turm : Schachfigur
    {
        // Der Konstruktor für den Turm. Er ruft den Basiskonstruktor mit 'farbe' auf und setzt das spezifische Symbol für den Turm.
        public Turm(string farbe) : base(farbe)
        {
            // Setze das Symbol basierend auf der Farbe. Wenn weiß, dann das Unicode-Symbol für den weißen Turm, sonst für den schwarzen.
            Symbol = farbe == "Weiss" ? '\u2656' : '\u265C';
        }

        // Überschreiben der Methode 'MoeglicheZuege' aus der Basisklasse. Hier wird definiert, wie ein Turm sich bewegen kann.
        public override List<(int, int)> MoeglicheZuege(int x, int y)
        {
            // In dieser Methode werden später alle gültigen Züge, die den Turm machen kann, berechnet und zurückgegeben.
            // Die Liste wird mit Paaren von Koordinaten gefüllt sein, die darstellen, wohin der Turm ziehen kann.
            return new List<(int, int)>();
        }
    }
}

