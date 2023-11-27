package Spiel;


import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import static KonsolenFarbe.KonsolenFarbe.*;

public class Spiel {
    //Feld[][] spielFeld = new Feld[8][8]; // Spielbrett als Array
    Map<String, Feld> spielMap = new HashMap<>();
    int zug;

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
    }

    public int getZugnummer() {
        return this.zug;
    }

    public void anzeigen() {
        for (char zeile = '8'; zeile >= '1'; zeile--) {
            for (char spalte = 'a'; spalte <= 'h'; spalte++) {
                String key = spalte + "" + zeile;
                String farbe = ((zeile + spalte) % 2 == 0 ? RED : BLUE);
                System.out.print(farbe + key + " " + RESET);
                System.out.print(spielMap.get(key).getFeldFarbe() + " ");
            }
            System.out.println();
        }
    }

    /**
     * Die Methode speichert die Zugnummer des Spiels und für jede vorhandene Figur die Koordinate, Farbe und Namen.
     *
     * @param spiel Das Spielfeld, das als Container der Felder und der dazugehörigen Figuren dient.
     * @param fileName Der Name der Textdatei in der die Daten hinterlegt werden.
     */
    public void save(Map<String, Feld> spiel, String fileName) {
        String filePath = "./saveFiles/" + fileName + ".txt";
        int zugNummer = getZugnummer();
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            writer.write("Runde: " + zugNummer);
            writer.newLine();
            for (String key : spiel.keySet()) {
                if (spiel.get(key).getFigure() != null) {
                    writer.write(key + " " + spiel.get(key).getFigure().getColor() + " "
                            + spiel.get(key).getFigure().getName());
                    writer.newLine();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Diese Methode speichert in einer seperaten Zeile den ausgeführten Zug.
     * @param zug   Ein String der die Eingabe der ZugKoordinaten annimmt.
     * @param fileName Der Name der Textdatei in der die Daten hinterlegt werden.
     */
    public void saveZug(String zug, String fileName){
        String filePath = "./saveFiles/" + fileName + ".txt";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            writer.write(zug);
            writer.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
/*    public Spiel() { // Methode für das Spielbrett als Array

       for (int z = 0; z < 8; z++) {
           for (int s = 0; s < 8; s++) {
               spielFeld[z][s] = new Feld();

           }
       }
   }
   public void anzeigen() { // Anzeigen des Array Spielbretts
       for (Feld[] zeile : spielFeld) {
           for (Feld feld : zeile) {
               System.out.print(feld.getFeldFarbe());
           }
           System.out.println();
       }
   } */
}
