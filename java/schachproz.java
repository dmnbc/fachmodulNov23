public class Helper {
    static int zugNr;
    static char hell, dunkel;

    static final boolean test = true; // replace any 'test' by false

    static void debug(String message) {
        if (test) {
            System.out.println(Thread.currentThread().getStackTrace()[1].getLineNumber() + ": " +
                    Helper.class.getSimpleName() + message);
        }
    }

    static void greetings() {
        debug("debug ist " + test);
    }

    static boolean onBoard(String userInput) {
        if (userInput.charAt(0) >= 'a' && userInput.charAt(0) <= 'h'
                && userInput.charAt(2) >= 'a' && userInput.charAt(2) <= 'h'
                && userInput.charAt(1) >= '1' && userInput.charAt(1) <= '8'
                && userInput.charAt(3) >= '1' && userInput.charAt(3) <= '8') {
            debug("Der Zug " + userInput + " wurde als auf dem Spielfeld erkannt\n");
            return true;
        } else {
            debug("Der Zug " + userInput + " wurde als nicht auf dem Spielfeld erkannt\n");
            return false;
        }
    }

    static boolean ownPiece(char piece2move) {
        boolean colorSource = piece2move <= 'Z' && piece2move >= 'A';
        boolean colorPlayer = zugNr % 2 == 0;

        if (colorSource == colorPlayer) {
            debug("Die Figur " + piece2move + " wird als eigen erkannt " + colorSource + " - " + colorPlayer + "\n");
            return true;
        } else {
            debug("Die Figur " + piece2move + " wird nicht als eigen erkannt " + colorSource + " - " + colorPlayer + "\n");
            return false;
        }
    }

    static boolean fieldEmpty(char startField) {
        if (startField == hell || startField == dunkel) {
            debug("Das Startfeld " + startField + " ist leer \n");
            return true;
        } else {
            debug("Das Startfeld " + startField + " ist nicht leer \n");
            return false;
        }
    }
}

import java.util.Arrays;
import java.util.Scanner;

public class ChessGame {
    static final int zeilen = 10;
    static final int spalten = 10;
    static char hell = 176;  // ASCII Tabelle extended
    static char dunkel = 32;
    static char[][] spielBrett = new char[zeilen][spalten];
    static String[] spieler = {"Schwarz", "Weiss"};
    static int zugNr = 0;

    // Functions

    static void brettAufstellen() {
        for (int zeile = 0; zeile < spielBrett.length; zeile++) {
            for (int spalte = 0; spalte < spielBrett[zeile].length; spalte++) {
                switch (zeile) {
                    case 0:
                    case 9:
                        spielBrett[zeile][spalte] = (spalte >= 1 && spalte <= 8) ? (char) (64 + spalte) : ' ';
                        break;
                    default:
                        if (spalte == 0 || spalte == 9) {
                            spielBrett[zeile][spalte] = (char) (57 - zeile); // 1 2 3 .......
                        } else {
                            spielBrett[zeile][spalte] = ((zeile + spalte) % 2 == 0) ? hell : dunkel;
                        }
                }
            }
        }
    }

    static void darstellen(boolean richtung) {
        for (int zeile = 0; zeile < spielBrett.length; zeile++) {
            for (int spalte = 0; spalte < spielBrett[zeile].length; spalte++) {
                int z = (richtung) ? zeile : (spielBrett.length - 1 - zeile);
                int s = (richtung) ? spalte : (spielBrett.length - 1 - spalte);
                System.out.print(spielBrett[z][s]);
            }
            System.out.println();
        }
    }

    static void grundstellung() {
        for (int spalte = 1; spalte < 9; spalte++) {
            spielBrett[7][spalte] = 'B';
            spielBrett[2][spalte] = 'b';
        }

        String offz = " TSLDKLST";
        for (int spalte = 1; spalte < 9; spalte++) {
            spielBrett[8][spalte] = offz.charAt(spalte);
            spielBrett[1][spalte] = (char) (offz.charAt(spalte) | 32);
        }
    }

    static void ziehen(boolean wer) {
        int zeileVon, spalteVon, zeileNach, spalteNach;
        boolean zugOK = false;
        Scanner scanner = new Scanner(System.in);

        while (!zugOK) {
            System.out.println("Zug Nr: " + zugNr + " " + (wer ? spieler[0] : spieler[1]) + " ist am Zug ");
            String userEingabe = scanner.next();
            userEingabe = userEingabe.toLowerCase();
            zeileVon = 9 - userEingabe.charAt(1) + 48;
            spalteVon = userEingabe.charAt(0) - 96;
            zeileNach = 9 - userEingabe.charAt(3) + 48;
            spalteNach = userEingabe.charAt(2) - 96;

            zugOK = Helper.onBoard(userEingabe) &&
                    Helper.ownPiece(spielBrett[zeileVon][spalteVon]) &&
                    !Helper.ownPiece(spielBrett[zeileNach][spalteNach]) &&
                    !Helper.fieldEmpty(spielBrett[zeileVon][spalteVon]);
        }

        spielBrett[zeileNach][spalteNach] = spielBrett[zeileVon][spalteVon];
        spielBrett[zeileVon][spalteVon] = ((zeileVon + spalteVon) % 2 == 0) ? hell : dunkel;
    }

    public static void main(String[] args) {
        brettAufstellen();
        grundstellung();
        Helper.greetings();

        do {
            darstellen(true);
            ziehen(zugNr++ % 2);
            darstellen(false);
            ziehen(zugNr++ % 2);
        } while (zugNr < 6); // nur wenige Durchläufe
    }
}
