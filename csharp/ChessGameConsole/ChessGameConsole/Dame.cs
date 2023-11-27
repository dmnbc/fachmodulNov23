using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessGameConsole
{
    // 'Dame' ist eine Klasse, die von 'Schachfigur' erbt. Hier wird spezifiziert, was ein Dame im Schach so macht.
    public class Dame : Schachfigur
    {
        // Konstruktor der Dame, ruft den Konstruktor der Basisklasse 'Schachfigur' auf und übergibt die Farbe.
        public Dame(string farbe) : base(farbe)
        {
            // Setzt das Symbol der Dame entsprechend ihrer Farbe.
            // '\u2655' ist das Unicode-Symbol für die weiße Dame, '\u265B' für die schwarze Dame.
            Symbol = farbe == "Weiss" ? '\u2655' : '\u265B';
        }

        // Überschreibung der abstrakten Methode 'MoeglicheZuege' aus der Basisklasse.
        // Diese Methode berechnet alle möglichen Züge, die die Dame von ihrer aktuellen Position 'x' und 'y' aus machen kann.
        public override List<(int, int)> MoeglicheZuege(int x, int y)
        {
            // In dieser Methode werden später alle gültigen Züge, die die Dame machen kann, berechnet und zurückgegeben.
            // Die Liste wird mit Paaren von Koordinaten gefüllt sein, die darstellen, wohin die Dame ziehen kann.
            return new List<(int, int)>();
        }
    }
}

