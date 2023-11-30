package Figur;

import Spiel.Feld;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Springer extends Figur {
    public Springer(String color, Map<String, Feld> spielMap) {
        super(color, (!color.equals("Weiß") ? '\u2658' : '\u265E'), spielMap);
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        List<String> moves = new ArrayList<>();
        int[][] richtungen = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

        for (int[] richtung : richtungen) {
            int neueZeile = zeile + richtung[0];
            int neueSpalte = spalte + richtung[1];
            String koordinate = Character.toString('`' + neueSpalte) + Character.toString('0' + neueZeile);
            if ((neueZeile >= 1 && neueZeile <= 8 && neueSpalte >= 1 && neueSpalte <= 8)
                    && (getSpielMap().get(koordinate).getFigure() == null
                    || !getColor().equals(getSpielMap().get(koordinate).getFigure().getColor()))) {
                moves.add("" + (char) (neueSpalte + 'a' - 1) + neueZeile);
            }
        }

        return moves;
    }
}
