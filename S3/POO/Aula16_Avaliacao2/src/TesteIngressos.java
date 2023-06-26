package S3.POO.Aula16_Avaliacao2.src;

public class TesteIngressos {
    public static void main(String[] args) {
        IngressoNormal normal = new IngressoNormal();
        IngressoVIP vip = new IngressoVIP();

        normal.setValor(150);
        vip.setValor(500);

        normal.imprimeValor();
        vip.imprimeValor();
    }
}
