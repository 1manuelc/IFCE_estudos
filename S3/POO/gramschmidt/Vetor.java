package S3.POO.gramschmidt;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Vetor {
    List<Double> coord = new ArrayList<Double>();

    public void preencherVetor(List<Double> coord, int espacoVetorial) {
        Scanner in = new Scanner(System.in);
        
        int k = 0;  
        while(k < espacoVetorial) {
            System.out.print("Digite a coordenada: ");
            coord.add(in.nextDouble());
            k =  k + 1;
        }

        in.close();
    }

    public void exibirVetor(List<Double> coord, int espacoVetorial) {
        System.out.print("v = (");
        
        int k;
        for(k = 0; k < espacoVetorial; k++) {
            if(k != espacoVetorial - 1)
                System.out.print(coord.get(k) + ",");
            else
                System.out.print(coord.get(k) + ")");
        }
    }
}
