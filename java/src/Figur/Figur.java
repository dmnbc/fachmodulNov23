package Figur;

import java.util.List;

public abstract class Figur {
    private final String color; // Entweder Weiß oder Schwarz
    private final char symbol; // UniCode Zeichen für die Spielfiguren.
    private final String name;

    public Figur(String color, char symbol) {
        if (!color.equals("Weiß") && !color.equals("weiß")) {
            this.color = "Schwarz";
        } else {
            this.color = color.toUpperCase().charAt(0) + color.substring(1);
        }

        this.symbol = symbol;
        this.name = getClass().getSimpleName();
    }
    public abstract List<String> getPossibleMoves(int zeile,int spalte);
    public String getColor() {
        return color;
    }

    public char getSymbol() {
        return symbol;
    }

    public String getName() {
        return name;
    }
}
