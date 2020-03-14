package org.elsys.mbitsov;

public class Rapper {
    private static int count = 0;

    public static void increment(){
        count++;
    }

    public static int getCount() {
        return count;
    }

    String name;
    private double earnings;

    public double getEarnings(){
        return earnings;
    }

    Rapper(){
        this("Ivan",0);
    }

    public Rapper(String name, double earnings) {
        this.name = name;
        this.earnings = earnings;
        Rapper.increment();
    }
}