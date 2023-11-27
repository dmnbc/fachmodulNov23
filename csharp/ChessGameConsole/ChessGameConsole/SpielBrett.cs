using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessGameConsole
{
    // Hier definieren wir die Klasse SpielBrett, die das Schachbrett repräsentiert.
    public class SpielBrett
    {
        // Ein Dictionary, um die Felder des Bretts zu speichern. Jedes Feld hat 'ne Adresse (x, y).
        private Dictionary<(int, int), Feld> felder;

        // Groesse des Bretts - normalerweise 8x8, aber hey, wir sind flexibel!
        public int Groesse { get; private set; }

        // Konstruktor: Wenn das Spielbrett erstellt wird, passiert hier die ganze Magie.
        public SpielBrett(int groesse)
        {
            Groesse = groesse; // Größe festlegen - klassische 8x8 oder was auch immer.
            felder = new Dictionary<(int, int), Feld>(); // Dictionary für die Felder erstellen.
            InitialisiereFelder(); // Felder auf dem Brett initialisieren.
            InitialisiereFiguren(); // Figuren auf die Startpositionen bringen.
        }

        // Diese Methode füllt das Brett mit Feldern. Jedes Feld bekommt eine Koordinate.
        private void InitialisiereFelder()
        {
            for (int y = 0; y < Groesse; y++)
            {
                for (int x = 0; x < Groesse; x++)
                {
                    // Jedes Feld wird durch seine Koordinaten (x, y) im Dictionary gespeichert.
                    felder.Add((x, y), new Feld(x, y));
                }
            }
        }

        // Diese Methode initialisiert die Figuren auf dem Schachbrett.
        private void InitialisiereFiguren()
        {
            // Hier setzen wir die weißen Figuren auf das Brett.
            felder[(7, 0)].SetFigur(new Turm("Weiss"));
            felder[(7, 7)].SetFigur(new Turm("Weiss"));
            felder[(7, 1)].SetFigur(new Springer("Weiss"));
            felder[(7, 6)].SetFigur(new Springer("Weiss"));
            felder[(7, 2)].SetFigur(new Laeufer("Weiss"));
            felder[(7, 5)].SetFigur(new Laeufer("Weiss"));
            felder[(7, 3)].SetFigur(new Dame("Weiss"));
            felder[(7, 4)].SetFigur(new Koenig("Weiss"));

            for (int i = 0; i < Groesse; i++)
            {
                felder[(6, i)].SetFigur(new Bauer("Weiss"));
            }

            // Hier setzen wir die schwarzen Figuren auf das Brett.
            felder[(0, 0)].SetFigur(new Turm("Schwarz"));
            felder[(0, 7)].SetFigur(new Turm("Schwarz"));
            felder[(0, 1)].SetFigur(new Springer("Schwarz"));
            felder[(0, 6)].SetFigur(new Springer("Schwarz"));
            felder[(0, 2)].SetFigur(new Laeufer("Schwarz"));
            felder[(0, 5)].SetFigur(new Laeufer("Schwarz"));
            felder[(0, 3)].SetFigur(new Dame("Schwarz"));
            felder[(0, 4)].SetFigur(new Koenig("Schwarz"));
            for (int i = 0; i < Groesse; i++)
            {
                felder[(1, i)].SetFigur(new Bauer("Schwarz"));
            }
        }

        // Diese Methode zeichnet das Schachbrett auf der Konsole.
        public void ZeichneBrett()
        {
            for (int y = 0; y < Groesse; y++)
            {
                for (int h = 0; h < 3; h++) // Jedes Feld wird dreimal vertikal gezeichnet
                {
                    for (int x = 0; x < Groesse; x++)
                    {
                        ZeichneFeld(x, y, h);
                    }
                    Console.WriteLine();
                }
                Console.BackgroundColor = ConsoleColor.Black;
            }
        }

        // Diese Methode zeichnet ein einzelnes Feld auf der Konsole.
        private void ZeichneFeld(int x, int y, int h)
        {
            // Hier definieren wir die Farben für die Felder.
            ConsoleColor dunkleFarbe = ConsoleColor.DarkYellow;
            ConsoleColor helleFarbe = ConsoleColor.Yellow;
            /*
             * Hier wird die Farbe des aktuellen Feldes bestimmt. Wenn die Summe der x- und y-Koordinaten gerade ist,
             * wird die helle Farbe verwendet, ansonsten die dunkle Farbe. Dies erzeugt das Schachbrettmuster.
            */
            ConsoleColor aktuelleFarbe = (x + y) % 2 == 0 ? helleFarbe : dunkleFarbe;

            // Hier setzen wir die Hintergrundfarbe der Konsole auf die aktuelle Farbe.
            Console.BackgroundColor = aktuelleFarbe;

            /*
             * Hier holen wir die Figur, die sich auf dem aktuellen Feld befindet. Wenn keine Figur auf dem Feld steht, 
             * ist der Wert null.
             */
            Schachfigur? figur = felder[(y, x)].GetFigur();

            /* Wenn eine Figur auf dem Feld steht und wir uns in der mittleren Zeile des Feldes befinden (h == 1), 
             * zeichnen wir das Symbol der Figur. Die Schriftfarbe wird auf Schwarz gesetzt, damit das Symbol auf dem 
             * farbigen Hintergrund sichtbar ist.
             */ 
            if (figur != null && h == 1)
            {
                Console.ForegroundColor = ConsoleColor.Black;
                Console.Write(" " + figur.Symbol + " ");
            }
            else
            {
                /*
                 * Wenn keine Figur auf dem Feld steht oder wir uns nicht in der mittleren Zeile des Feldes befinden, 
                 * zeichnen wir ein leeres Feld. Die Schriftfarbe wird auf Weiß gesetzt, damit das leere Feld auf dem 
                 * farbigen Hintergrund sichtbar ist.
                 */
                Console.ForegroundColor = ConsoleColor.White;
                Console.Write("   ");
            }

        }
    }
}
