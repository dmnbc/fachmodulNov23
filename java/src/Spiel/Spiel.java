package Spiel;

import java.util.HashMap;
import java.util.Map;

import static KonsolenFarbe.KonsolenFarbe.*;

public class Spiel {
    //Feld[][] spielFeld = new Feld[8][8]; // Spielbrett als Array
    Map<String, Feld> spielMap = new HashMap<>();

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

    public void anzeigen() {
        for (char zeile = '8'; zeile >= '1' ; zeile--) {
            for (char spalte = 'a'; spalte <= 'h'; spalte++) {
                String key = spalte + "" + zeile;
                String farbe = ((zeile + spalte) % 2 == 0 ? RED : BLUE);
                System.out.print(farbe + key + " " + RESET); 
                System.out.print(spielMap.get(key).getFeldFarbe() + " ");
            }
            System.out.println();
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
