package Figur;

public class Figur {
    private final String color; // Entweder Weiß oder Schwarz
    private final char symbol; // UniCode Zeichen für die Spielfiguren.
    private final String name;

    public Figur(String color, char symbol) {
        this.color = color;
        this.symbol = symbol;
        this.name = getClass().getSimpleName();
    }

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
