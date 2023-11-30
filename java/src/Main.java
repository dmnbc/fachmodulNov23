import Spiel.*;
// Problem VS Code kann UFC8 nicht im Terminal wieder geben Lösung: Eingabe  -> Terminal: chcp 65001
// Problem (Evaluation failed because the thread is not suspended.) VS Code kann keine Java Eingabe in der Debug Console auswerten Lösung: Eingabe ->über Terminal
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Feld.laufendeNr = 0;
        Scanner scanner = new Scanner(System.in);
        Spiel spiel = new Spiel(scanner);

        // Ansicht Spieler Weiß
        while(true){
            spiel.anzeigen("Weiß");
            spiel.figurBewegen(spiel.spielerEingabe());
        }
        // simple test of figurBewegen()

        //color test

    }
}