using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessGameConsole
{
    // 'Turm' ist eine Klasse, die von 'Schachfigur' erbt. Hier wird spezifiziert, was ein Bauer im Schach so macht.
    public class Bauer : Schachfigur
    {
        // Der Konstruktor für den Bauer. Er ruft den Basiskonstruktor mit 'farbe' auf und setzt das spezifische Symbol für den Bauer.
        public Bauer(string farbe) : base(farbe)
        {
            // Setzt das Symbol des Bauers entsprechend seiner Farbe.
            // Hier wird entweder das Unicode-Symbol für den weißen oder schwarzen Bauern verwendet.
            Symbol = farbe == "Weiss" ? '\u2659' : '\u265F';
        }

        // Überschreibung der Methode 'MoeglicheZuege', um die Zuglogik des Bauern zu definieren.
        // 'x' und 'y' repräsentieren die aktuelle Position des Bauern auf dem Brett.
        public override List<(int, int)> MoeglicheZuege(int x, int y)
        {
            // In dieser Methode werden später alle gültigen Züge, die ein Bauer machen kann, berechnet und zurückgegeben.
            // Die Liste wird mit Paaren von Koordinaten gefüllt sein, die darstellen, wohin der Bauer ziehen kann.
            return new List<(int, int)>();
        }
    }
}

