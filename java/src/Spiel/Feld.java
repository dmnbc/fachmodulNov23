package Spiel;

import Figur.Figur;

import java.util.List;

public class Feld {
    private String feldFarbe;
    private Figur figur;
    private int feldNr;
    private int zeile;
    private int spalte;
    public static int laufendeNr;
    private final String hell = ((char) 9724 + "" + (char) (8202));
    private final String dunkel = ((char) 9723 + "" + (char) (8202));


    public Feld() {
        feldNr = laufendeNr++;
        zeile = feldNr / 8;
        spalte = feldNr % 8;
        feldFarbe = ((zeile + spalte) % 2 == 0 ? hell : dunkel);
        //System.out.printf("%d: %d,%d %c\n", feldNr, zeile, spalte, feldFarbe);
    }

    public Feld(String koordinaten) {
        feldNr = laufendeNr++;
        zeile = koordinaten.charAt(1) - '0';
        spalte = koordinaten.charAt(0) - '`';
        feldFarbe =  ((zeile + spalte) % 2 == 0 ? hell : dunkel);
    }

    public String getFeldFarbe() {
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

    public Figur getFigure() {
        return figur;
    }

    public void setFigur(Figur figur) {
        this.figur = figur;
    }
    public List<String> getPossibleMoves(Spiel spiel){
        if(figur!=null){
            return figur.getPossibleMoves(zeile,spalte);
        }else return null;
    }
}