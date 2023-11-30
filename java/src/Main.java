import Spiel.*;
// Problem VS Code kann UFC8 nicht im Terminal wieder geben Lösung: Eingabe  -> Terminal: chcp 65001
// Problem (Evaluation failed because the thread is not suspended.) VS Code kann keine Java Eingabe in der Debug Console auswerten Lösung: Eingabe ->über Terminal
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Feld.laufendeNr = 0;
        Spiel spiel = new Spiel();
        Scanner scanner = new Scanner(System.in);
        // Ansicht Spieler Weiß
        spiel.anzeigen("Weiß");
        // simple test of figurBewegen()
        spiel.figurBewegen(spiel.spielerEingabe(scanner));
        //color test
        System.out.println("a2 ist leer: " + spiel.feldLeer("a2"));
        System.out.println("a2 ist eigene Figur: " + spiel.eigeneFarbe("a2"));
        System.out.println("a2 ist gegner Figur: " + spiel.gegnerFarbe("a2"));
        // Ansicht Spieler Schwarz
        spiel.anzeigen("Schwarz");

        // test

    }
}