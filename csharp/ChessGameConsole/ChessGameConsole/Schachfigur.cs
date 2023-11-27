using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessGameConsole
{
    // 'Schachfigur' ist eine abstrakte Klasse, das heißt: sie ist eine Vorlage für konkrete Figuren wie Bauer, König usw.
    // Wir können von dieser Klasse keine direkten Objekte erstellen, sie ist nur die Klasse.
    public abstract class Schachfigur
    {
        // 'Farbe' hält fest, ob die Figur weiß oder schwarz ist. Im Schach ist das sehr wichtig!
        public string Farbe { get; set; }

        // 'Symbol' ist das Zeichen, das die Figur auf dem Brett darstellt.
        // 'protected set' bedeutet, dass nur die Figur selbst bzw. abgeleitete Klassen das Symbol ändern können.
        public char Symbol { get; protected set; }

        // Der Konstruktor der Klasse von Jede Figur bekommt beim erstellen die Farbe zugewiesen.
        // Der Konstruktor ist 'protected', also nur für diese Klasse und ihre abgeleite Klassen sichtbar.
        protected Schachfigur(string farbe)
        {
            Farbe = farbe; // Speichert die gegebene Farbe.
            Symbol = ' '; // Das Symbol ist ein Leerzeichen, es wird aber in den Unterklassen überschrieben.
        }

        // 'MoeglicheZuege' ist eine abstrakte Methode, die in jeder abgeleiteten Klasse implementiert werden muss.
        // Sie gibt eine Liste von Koordinaten zurück, wohin die Figur sich bewegen könnte.
        // 'x' und 'y' Koordinaten der Figur auf dem Brett.
        public abstract List<(int, int)> MoeglicheZuege(int x, int y);
    }
}
