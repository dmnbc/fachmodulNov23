package Spiel;


import Figur.*;

import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import static KonsolenFarbe.KonsolenFarbe.*;

public class Spiel {
    Map<String, Feld> spielMap = new HashMap<>();
    int zugNummer;
    HashMap<Integer, String> zugVerlauf = new HashMap<>(); //bei jeden figurBewegen(), (zugNummer, zug) in zugVerlauf speichern

    public Spiel() {
        String key;

        char spalte;
        char zeile;
        for (int nr = 0; nr < 64; nr++) {
            spalte = (char) ('a' + nr % 8);
            zeile = (char) ('1' + nr / 8);
            key = spalte + "" + zeile;
            spielMap.put(key, new Feld(key));
        }
        initialisiereFiguren();
    }

    public int getZugNummer() {return zugNummer;}

    private void initialisiereFiguren() {
        for (char z = 'a'; z < 'i'; z++) {
            spielMap.get(z + "" + 2).setFigur(new Bauer("Weiß"));
            spielMap.get(z + "" + 7).setFigur(new Bauer("Schwarz"));
        }
        spielMap.get('a' + "" + 1).setFigur(new Turm("Weiß"));
        spielMap.get('b' + "" + 1).setFigur(new Springer("Weiß"));
        spielMap.get('c' + "" + 1).setFigur(new Laeufer("Weiß"));
        spielMap.get('d' + "" + 1).setFigur(new Dame("Weiß"));
        spielMap.get('e' + "" + 1).setFigur(new Koenig("Weiß"));
        spielMap.get('f' + "" + 1).setFigur(new Laeufer("Weiß"));
        spielMap.get('g' + "" + 1).setFigur(new Springer("Weiß"));
        spielMap.get('h' + "" + 1).setFigur(new Turm("Weiß"));

        spielMap.get('a' + "" + 8).setFigur(new Turm("Schwarz"));
        spielMap.get('b' + "" + 8).setFigur(new Springer("Schwarz"));
        spielMap.get('c' + "" + 8).setFigur(new Laeufer("Schwarz"));
        spielMap.get('d' + "" + 8).setFigur(new Dame("Schwarz"));
        spielMap.get('e' + "" + 8).setFigur(new Koenig("Schwarz"));
        spielMap.get('f' + "" + 8).setFigur(new Laeufer("Schwarz"));
        spielMap.get('g' + "" + 8).setFigur(new Springer("Schwarz"));
        spielMap.get('h' + "" + 8).setFigur(new Turm("Schwarz"));

    }

    public void anzeigen(String color) {
        String bezeichnung = color.equals("Weiß") ? "  A  B  C D  E F  G  H" : "  H  G  F E  D C  B  A";
        char zeilenAnfang = color.equals("Weiß") ? '8' : '1';
        char zeilenEnde = color.equals("Weiß") ? '0' : '9';
        char spaltenAnfang = color.equals("Weiß") ? 'a' : 'h';
        char spaltenEnde = color.equals("Weiß") ? 'i' : '`';
        int step = color.equals("Weiß") ? -1 : 1;

        System.out.println(bezeichnung);
        for (char zeile = zeilenAnfang; zeile != zeilenEnde; zeile += step) {
            System.out.print(zeile + " ");
            for (char spalte = spaltenAnfang; spalte != spaltenEnde; spalte -= step) {
                String key = spalte + "" + zeile;
                if (spielMap.get(key).getFigure() != null) {
                    System.out.print(spielMap.get(key).getFigure().getSymbol() + " ");
                } else {
                    System.out.print(spielMap.get(key).getFeldFarbe() + " ");
                }
            }
            System.out.println(zeile);
        }
        System.out.println(bezeichnung);

    }

    //function to move a figure to a new field any appropriate outputs. It does NOT CHECK if the move is valid.
    public void figurBewegen(String zug) {
        //TODO message on taking an enemy piece
        //TODO message on putting enemy in check
        spielMap.get(zug.substring(2, 4)).setFigur(spielMap.get(zug.substring(0, 2)).getFigure()); //move the Figur to the destination field
        zugVerlauf.put(getZugNummer(), spielMap.get(zug.substring(0, 2)).getFigure().getSymbol() + zug); //add move to zugVerlauf with figur that was moved
        spielMap.get(zug.substring(0, 2)).setFigur(null); //set source field to null
        //TODO remove following test of zugVerlauf
        System.out.println(zugVerlauf);
        zugNummer++;

    }
    //based on zugNummer a Field will be checked to see if contains a figure of the current players color. return false means enemy or empty.
    // should accept any string of length 2 or greater where the first two char are valid coordinates
    public boolean eigeneFarbe(String zug){
        if (spielMap.get(zug.substring(0, 2)).getFigure() == null){
            return false;
        }
        String currentPlayer = zugNummer%2 == 0 ? "Weiß" : "Schwarz";
        return spielMap.get(zug.substring(0,2)).getFigure().getColor().equals(currentPlayer);
    }
    public boolean gegnerFarbe(String zug){
        if (spielMap.get(zug.substring(0, 2)).getFigure() == null){
            return false;
        }
        String currentPlayer = zugNummer%2 == 1 ? "Weiß" : "Schwarz";
        return spielMap.get(zug.substring(0,2)).getFigure().getColor().equals(currentPlayer);
    }
    public boolean feldLeer(String zug){
        return spielMap.get(zug.substring(0, 2)).getFigure() == null;
    }

    /**
     * Die Methode speichert die Zugnummer des Spiels und für jede vorhandene Figur die Koordinate, Farbe und Namen.
     *
     * @param currentGame    Das Spielfeld, das als Container der Felder und der dazugehörigen Figuren dient.
     * @param fileName Der Name der Textdatei in der die Daten hinterlegt werden.
     */
    public void save(Map<String, Feld> currentGame, String fileName) {
        String filePath = "java\\src\\savedFiles\\" + fileName + ".txt";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            writer.write("Runde: " + getZugNummer());
            writer.newLine();
            for (String key : currentGame.keySet()) {
                if (currentGame.get(key).getFigure() != null) {
                    writer.write(key + " " + currentGame.get(key).getFigure().getColor() + " "
                            + currentGame.get(key).getFigure().getName());
                    writer.newLine();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Diese Methode speichert in einer seperaten Zeile den ausgeführten Zug.
     *
     * @param zug      Ein String der die Eingabe der ZugKoordinaten annimmt.
     * @param fileName Der Name der Textdatei in der die Daten hinterlegt werden.
     */
    public void saveZug(String zug, String fileName) {
        String filePath = "java\\src\\savedFiles\\" + fileName + ".txt";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            writer.write(zug);
            writer.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String spielerEingabe(Scanner scanner) {
        String userInput;
        String currentPlayer = zugNummer%2 == 0 ? "Weiß" : "Schwarz";

        do {
            System.out.println(currentPlayer + ", du bist dran. Bitte Spielzug eingeben (Format: a1b2):");
            userInput = scanner.next();

        } while (!istKorrekteKoordinatenEingabe(userInput));

        return userInput.toLowerCase();
    }

    private boolean istKorrekteKoordinatenEingabe(String userInput) {
        // Überprüfen, ob die Eingabe leer oder null ist
        if (userInput == null || userInput.isEmpty()) {
            return false;
        }
        // Überprüfen, ob die Eingabe die erwartete Länge hat
        if (userInput.length() != 4) {
            return false;
        }

        String inputLower = userInput.toLowerCase();

        // Extrahieren der Werte aus der Eingabe
        char startSpalte = inputLower.charAt(0);
        char startZeile = inputLower.charAt(1);
        char zielSpalte = inputLower.charAt(2);
        char zielZeile = inputLower.charAt(3);

        // Überprüfen, ob die Spalten- und Zeilenwerte im richtigen Bereich liegen
        if (!(startSpalte >= 'a' && startSpalte <= 'h') || !(zielSpalte >= 'a' && zielSpalte <= 'h') ||
                !(startZeile >= '1' && startZeile <= '8') || !(zielZeile >= '1' && zielZeile <= '8')) {
            return false;
        }

        // Start- und Zielkoordinaten dürfen nicht gleich sein
        if (startSpalte == zielSpalte && startZeile == zielZeile) {
            return false;
        }
        if (!eigeneFarbe(userInput)){
            return false;
        }
        if (feldLeer(userInput)){
            return false;
        }

        // Rückgabe true, wenn alle Bedingungen erfüllt sind
        return true;
    }
}
