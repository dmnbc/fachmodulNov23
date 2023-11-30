package Figur;

import Spiel.Spiel;

import java.util.ArrayList;
import java.util.List;

public class Springer extends Figur {
    public Springer(String color) {
        super(color, (!color.equals("Weiß") ? '\u2658' : '\u265E'));
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte, Spiel spiel) {
        List<String> moves = new ArrayList<>();
        int[][] richtungen = { { -2, -1 }, { -2, 1 }, { 2, -1 }, { 2, 1 }, { -1, -2 }, { -1, 2 }, { 1, -2 }, { 1, 2 } };

        for (int[] richtung : richtungen) {
            int neueZeile = zeile + richtung[0];
            int neueSpalte = spalte + richtung[1];
            if (neueZeile >= 1 && neueZeile <= 8 && neueSpalte >= 1 && neueSpalte <= 8) {

                String key = "" + (char) (spalte + 'a' - 1) + (char) (zeile + '1' - 1) + (char) (neueSpalte + 'a' - 1) + neueZeile;
                String eigeneFarbe = spiel.getSpielMap().get(key.substring(0,2)).getFigure().getColor();

                // Mögliches Zielfeld könnte eigene Figur sein
                if (spiel.getSpielMap().get(key.substring(2,4)).getFigure() != null){
                    // Zielfeld ist keine eigene Figur
                    if (!(spiel.getSpielMap().get(key.substring(2,4)).getFigure().getColor().equals(eigeneFarbe))){
                        moves.add("" + (char) (neueSpalte + 'a' - 1) + neueZeile);
                    }
                }else {
                    moves.add("" + (char) (neueSpalte + 'a' - 1) + neueZeile);
                }
            }
        }

        return moves;
    }
}
