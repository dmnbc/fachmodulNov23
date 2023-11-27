import Spiel.*;

public class Main {
    public static void main(String[] args) {
        Feld.laufendeNr = 0;
        Spiel spiel = new Spiel();
        //Ansicht Spieler Weiß
        spiel.anzeigen("Weiß");
        //Ansicht Spieler Schwarz
        spiel.anzeigen("Schwarz");

    }
}