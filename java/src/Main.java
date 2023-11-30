import Spiel.*;
// Problem VS Code kann UFC8 nicht im Terminal wieder geben Lösung: Eingabe  -> Terminal: chcp 65001
// Problem (Evaluation failed because the thread is not suspended.) VS Code kann keine Java Eingabe in der Debug Console auswerten Lösung: Eingabe ->über Terminal
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Feld.laufendeNr = 0;
        int zugNr = 0;
        Scanner scanner = new Scanner(System.in);
        Spiel spiel = new Spiel(scanner);

        // Ansicht Spieler Weiß
        while(true){
            spiel.anzeigen(spiel.getCurrentPlayer());
            String move = spiel.spielerEingabe();
            List<String> possibleMoves = spiel.getSpielMap().get(move.substring(0,2)).getPossibleMoves(spiel);
            //System.out.println(possibleMoves);
            if (possibleMoves.contains(move.substring(2,4))) {
                spiel.figurBewegen(move);
            }else {
                System.out.println("Kein erlaubter Zug");
            }
        }
        // simple test of figurBewegen()

        //color test

    }
}