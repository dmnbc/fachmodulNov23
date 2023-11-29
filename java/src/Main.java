import Spiel.*;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Feld.laufendeNr = 0;
        Spiel spiel = new Spiel();
        Scanner scanner = new Scanner(System.in);
        // Ansicht Spieler Weiß
        spiel.anzeigen("Weiß");
        // simple test of figurBewegen()
        System.out.println("pawn a2 to a4");
        spiel.figurBewegen(spiel.spielerEingabe(scanner));
        // Ansicht Spieler Schwarz
        spiel.anzeigen("Schwarz");
        System.out.println("pawn h7 to h5");
        spiel.figurBewegen(spiel.spielerEingabe(scanner));
        spiel.anzeigen("Weiß");

    }
}