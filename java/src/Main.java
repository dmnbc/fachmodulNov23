import Spiel.*;
// Problem VS Code kann UFC8 nicht im Terminal wieder geben Lösung: Eingabe  -> Terminal: chcp 65001
// Problem (Evaluation failed because the thread is not suspended.) VS Code kann keine Java Eingabe in der Debug Console auswerten Lösung: Eingabe ->über Terminal
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Feld.laufendeNr = 0;
        int zugNr = 0;
        Spiel spiel = new Spiel();
        Scanner scanner = new Scanner(System.in);
        // Ansicht Spieler Weiß
        while (zugNr <= 10){
            String spieler = (zugNr % 2 == 0) ? "Weiß" : "Schwarz";
            spiel.anzeigen(spieler);
            String move = spiel.spielerEingabe(scanner);
            List<String> possibleMoves = spiel.getSpielMap().get(move.substring(0,2)).getPossibleMoves(spiel);
            System.out.println(possibleMoves);
            if (possibleMoves.contains(move.substring(2,4))) {
                spiel.figurBewegen(move);
                zugNr++;
            }else {
                System.out.println("Kein erlaubter Zug");
            }
        }
    }
}