using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessGameConsole
{
    // 'Laeufer' ist eine Klasse, die von 'Schachfigur' erbt. Hier wird spezifiziert, was ein Läuefer im Schach so macht.

    public class Laeufer : Schachfigur
    {
        // Konstruktor des Laeufers, ruft den Konstruktor der Basisklasse 'Schachfigur' auf und übergibt die Farbe.

        public Laeufer(string farbe) : base(farbe)
        {
            // Setzt das Symbol des Koeniges entsprechend seiner Farbe.
            // Hier wird entweder das Unicode-Symbol für den weißen oder schwarzen Koenig verwendet.
            Symbol = farbe == "Weiss" ? '\u2657' : '\u265D'; // Weißer bzw. schwarzer Läufer
        }

        // Überschreibung der abstrakten Methode 'MoeglicheZuege' aus der Basisklasse.
        // Diese Methode berechnet alle möglichen Züge, die der König von seiner aktuellen Position 'x' und 'y' aus machen kann.
        public override List<(int, int)> MoeglicheZuege(int x, int y)
        {
            // Hier wird die tatsächliche Logik zur Bestimmung der möglichen Züge des Läufers implementiert.

            return new List<(int, int)>();
        }
    }
}
