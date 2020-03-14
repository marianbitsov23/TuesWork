import org.elsys.mbitsov.Rapper;

public class Main {
    public static void main(String[] args){
        /*Rapper drake = new Rapper();
        System.out.println(drake.name + " - " + drake.getEarnings());

        Rapper eminem = new Rapper("Eminem", 1000000);
        System.out.println(eminem.name  + " - " + eminem.getEarnings());

        System.out.println(Rapper.getCount());
        */

        Main.strings();
    }

    static void strings() {
        String str1 = "asdf";
        String str2 = "asd" + "xcv" + 123 + true;
        String str3 = "asd" + "xcv" + 123 + true;

        System.out.println(str1);
        System.out.println(str2);
        System.out.println(str3 == str2);
        System.out.println(str1.equals(str2));
        System.out.println(str1.compareTo(str2));

        System.out.println(str2.contains("d"));
        System.out.println(str2.hashCode());
        System.out.println(str2.indexOf('c'));
        System.out.println(str2.length());
    }

    static void boxedTypes() {
        int a = new Integer(15);
        System.out.println(a);
        System.out.println(((Integer)a).toString());
    }
}