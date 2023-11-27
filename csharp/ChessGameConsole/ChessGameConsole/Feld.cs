using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessGameConsole
{
    // Die Klasse  Feld, repräsentiert Feld auf einem Schachbrett.
    public class Feld
    {
        // Wir definieren die Eigenschaften X und Y, die die Position des Feldes auf dem Schachbrett darstellen.
        public int X { get; set; }
        public int Y { get; set; }

        // Wir definieren eine Eigenschaft Figur(Konstruktor der Klasse Schachfigur), die die Schachfigur auf dem Feld darstellt. 
        // Es ist als Nullable markiert, was bedeutet, dass es null sein kann, wenn kein Stück auf dem Feld ist.
        public Schachfigur? Figur { get; set; }

        // Dies ist der Konstruktor der Klasse Feld, der aufgerufen wird, wenn ein neues Feldobjekt erstellt wird.
        // Es nimmt die X- und Y-Positionen als Parameter und setzt die Figur auf null, da das Feld zu Beginn leer ist.
        public Feld(int x, int y)
        {
            X = x;
            Y = y;
            Figur = null;
        }
        // Diese Methode überprüft, ob das Feld besetzt ist, indem sie überprüft, ob die Figur null ist oder nicht.
        public bool IstBesetzt()
        {
            return Figur != null;
        }

        // Diese Methode gibt die Figur auf dem Feld zurück.
        public Schachfigur? GetFigur()
        {
            return Figur;
        }

        // Diese Methode setzt die Figur auf dem Feld. Sie nimmt eine Schachfigur als Parameter.
        public void SetFigur(Schachfigur? figur)
        {
            Figur = figur;
        }

        //// Diese Methode entfernt die Figur vom Feld, indem sie die Figur auf null setzt.
        //public void EntferneFigur()
        //{
        //    Figur = null;
        //}
    }
}
