package Spiel;

import Figur.Figur;

public class Feld {
    private char feldFarbe = 32;
    private Figur figur;
    private int feldNr;
    private int zeile;
    private int spalte;
    public static int laufendeNr;


    public Feld() {
        feldNr = laufendeNr++;
        zeile = feldNr / 8;
        spalte = feldNr % 8;
        feldFarbe = (char) ((zeile + spalte) % 2 == 0 ? 176 : 32);
        //System.out.printf("%d: %d,%d %c\n", feldNr, zeile, spalte, feldFarbe);
    }

    public Feld(String koordinaten) {
        feldNr = laufendeNr++;
        zeile = koordinaten.charAt(1) - '0';
        spalte = koordinaten.charAt(0) - 'b';
        feldFarbe = (char) ((zeile + spalte) % 2 == 0 ? 176 : 32);
    }

    public char getFeldFarbe() {
        return feldFarbe;
    }

    public int getFeldNr() {
        return feldNr;
    }

    public int getZeile() {
        return zeile;
    }

    public int getSpalte() {
        return spalte;
    }
    public Figur getFigure(){
        return this.figur;
    }
}
