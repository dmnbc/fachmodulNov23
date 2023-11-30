package Figur;

import Spiel.Feld;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Turm extends Figur {
    public Turm(String color, Map<String, Feld> spielMap) {
        super(color, (!color.equals("Weiß") ? '\u2656' : '\u265C'),  spielMap);
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte) {
        List<String> moves = new ArrayList<>();

        for (int i = 1; i <= 8; i++) {
            if (i != zeile) {
                moves.add("" + (char) (spalte + 'a' - 1) + i);
            }
            if (i != spalte) {
                moves.add("" + (char) (i + 'a' - 1) + zeile);
            }
        }

        return moves;
    }
}
