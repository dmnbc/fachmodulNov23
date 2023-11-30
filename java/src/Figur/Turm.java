package Figur;

import Spiel.Feld;

import java.util.ArrayList;
import Spiel.Spiel;

import  java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Turm extends Figur {
    public Turm(String color, Map<String, Feld> spielMap) {
        super(color, (!color.equals("Weiß") ? '\u2656' : '\u265C'),  spielMap);
    }

    @Override
    public List<String> getPossibleMoves(int zeile, int spalte, Spiel spiel) {
        List<String> moves = new ArrayList<>();
        String key;
        for (int i = 1; i <= 8; i++) {
            key = "" + (char) (spalte + 'a' - 1) + (char) (zeile + '1' - 1) + (char) (spalte + 'a' - 1) + i;
            if (i != zeile && spiel.isWegFrei(key,spiel)) {
                moves.add("" + (char) (spalte + 'a' - 1) + i);
            }
            key = "" + (char) (spalte + 'a' - 1) + (char) (zeile + '1' - 1) + (char) (i + 'a' - 1) + (char) (zeile + '1' - 1);
            if (i != spalte && spiel.isWegFrei(key,spiel)) {
                moves.add("" + (char) (i + 'a' - 1) + zeile);
            }
        }

        return moves;
    }
}