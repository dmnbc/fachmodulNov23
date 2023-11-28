import Spiel.*;

public class Main {
    public static void main(String[] args) {
        Feld.laufendeNr = 0;
        Spiel spiel = new Spiel();
        //Ansicht Spieler Weiß
        spiel.anzeigen("Weiß");
        //simple test of figurBewegen()
        System.out.println("pawn a2 to a4");
        spiel.figurBewegen("a2a4");
        //Ansicht Spieler Schwarz
        spiel.anzeigen("Schwarz");
        System.out.println("pawn h7 to h5");
        spiel.figurBewegen("h7h5");
        spiel.anzeigen("Weiß");

    }
}