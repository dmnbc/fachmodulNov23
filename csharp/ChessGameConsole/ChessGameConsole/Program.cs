using System;

namespace ChessGameConsole
{
    class Programm
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Willkommen zum Schachspiel!");
            SchachSpiel spiel = new();
            spiel.StarteSpiel();
        }
    }
}
