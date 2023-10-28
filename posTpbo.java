import java.util.Scanner;

// Kelas induk Hewan
class Hewan {
  private String nama;
  private String suara;

  public Hewan(String nama, String suara) {
    this.nama = nama;
    this.suara = suara;
  }

  public String getNama() {
    return nama;
  }

  public String getSuara() {
    return suara;
  }
}

// Kelas anak Bebek yang mewarisi Hewan
class Bebek extends Hewan {
  private String warnaBulu;

  public Bebek(String nama, String warnaBulu) {
    super(nama, "kwek");
    this.warnaBulu = warnaBulu;
  }

  public String getWarnaBulu() {
    return warnaBulu;
  }
}

// Kelas anak Harimau yang mewarisi Hewan
class Harimau extends Hewan {
  private int jumlahGarisHitam;

  public Harimau(String nama, int jumlahGarisHitam) {
    super(nama, "aum");
    this.jumlahGarisHitam = jumlahGarisHitam;
  }

  public int getJumlahGarisHitam() {
    return jumlahGarisHitam;
  }
}

public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    System.out.println("Masukkan data Bebek:");
    System.out.print("Nama Bebek: ");
    String namaBebek = input.nextLine();
    System.out.print("Warna Bulu Bebek: ");
    String warnaBuluBebek = input.nextLine();

    System.out.println("Masukkan data Harimau:");
    System.out.print("Nama Harimau: ");
    String namaHarimau = input.nextLine();
    System.out.print("Jumlah Garis Hitam Harimau: ");
    int jumlahGarisHitamHarimau = input.nextInt();

    Bebek bebek = new Bebek(namaBebek, warnaBuluBebek);
    Harimau harimau = new Harimau(namaHarimau, jumlahGarisHitamHarimau);

    System.out.println("\nInformasi tentang Bebek:");
    System.out.println("Nama Bebek: " + bebek.getNama());
    System.out.println("Suara Bebek: " + bebek.getSuara());
    System.out.println("Warna Bulu Bebek: " + bebek.getWarnaBulu());

    System.out.println("\nInformasi tentang Harimau:");
    System.out.println("Nama Harimau: " + harimau.getNama());
    System.out.println("Suara Harimau: " + harimau.getSuara());
    System.out.println("Jumlah Garis Hitam Harimau: " + harimau.getJumlahGarisHitam());

    input.close();
  }
}
