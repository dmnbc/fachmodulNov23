using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessGameConsole
{
    // 'Springer' ist eine Klasse, die von 'Schachfigur' erbt. Hier wird spezifiziert, was ein Springer im Schach so macht.

    public class Springer : Schachfigur
    {
        // Konstruktor des Springers, ruft den Konstruktor der Basisklasse 'Schachfigur' auf und übergibt die Farbe.

        public Springer(string farbe) : base(farbe)
        {
            // Setzt das Symbol des Springer entsprechend seiner Farbe.
            // Hier wird entweder das Unicode-Symbol für den weißen oder schwarzen Springer verwendet.
            Symbol = farbe == "Weiss" ? '\u2658' : '\u265E'; // Weißer bzw. schwarzer Springer
        }
        // Überschreibung der abstrakten Methode 'MoeglicheZuege' aus der Basisklasse.
        // Diese Methode berechnet alle möglichen Züge, die der Läufer von seiner aktuellen Position 'x' und 'y' aus machen kann.

        public override List<(int, int)> MoeglicheZuege(int x, int y)
        {
            // Hier wird die tatsächliche Logik zur Bestimmung der möglichen Züge des Königes implementiert.
            return new List<(int, int)>();
        }
    }
}
