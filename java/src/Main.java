import Spiel.*;

public class Main {
    public static void main(String[] args) {
        Feld.laufendeNr = 0;
        Spiel spiel = new Spiel();
        //Ansicht Spieler Weiß
        spiel.anzeigen("Weiß");
        //simple test of figurBewegen()
        System.out.println("pawn a7 to a5");
        spiel.figurBewegen("a7a5");
        //Ansicht Spieler Schwarz
        spiel.anzeigen("Schwarz");

    }
}