package S4.Topicos_especiais_em_Programacao.Atividade03_2;

/*
* #3. Elabore um algoritmo que calcule o que deve ser pago por um produto,
* considerando o preço normal de etiqueta e a escolha da condição de pagamento.
* Utilize os códigos da tabela a seguir para ler qual a condição de pagamento
* escolhida e efetuar o cálculo adequado. (Usar estrutura de seleção de múltipla escolha).
Código Condição de pagamento
    1 -  À vista em dinheiro ou cheque, recebe 10% de desconto;
    2 - À vista no cartão de crédito, recebe 15% de desconto;
    3 - Em duas vezes, preço normal de etiqueta sem juros;
    4 - Em três vezes, preço normal de etiqueta mais juros de 10%.
*/

import javax.swing.JOptionPane;

public class Questao03 {
    public static void main(String[] args) {
        try {
            int opcao;
            do {
                double precoEtiqueta = Double.parseDouble(JOptionPane.showInputDialog(null,
                        "Digite o preço de etiqueta:",
                        "Ferramenta de pagamento", JOptionPane.QUESTION_MESSAGE));

                opcao = Integer.parseInt(JOptionPane.showInputDialog(null,
                        ("Selecione uma opção de pagamento pelo número:\n" +
                                "\t(0) Sair do Programa\n" +
                                "\t(1) -  À vista em dinheiro ou cheque, recebe 10% de desconto;\n" +
                                "\t(2) - À vista no cartão de crédito, recebe 15% de desconto;\n" +
                                "\t(3) - Em duas vezes, preço normal de etiqueta sem juros;\n" +
                                "\t(4) - Em três vezes, preço normal de etiqueta mais juros de 10%."),
                        "Ferramenta de pagamento", JOptionPane.QUESTION_MESSAGE));

                while(opcao < 0 || opcao > 4) {
                    opcao = Integer.parseInt(JOptionPane.showInputDialog(null,
                            ("Digite uma opção válida:\n" +
                                    "\t(0) Sair do Programa\n" +
                                    "\t(1) -  À vista em dinheiro ou cheque, recebe 10% de desconto;\n" +
                                    "\t(2) - À vista no cartão de crédito, recebe 15% de desconto;\n" +
                                    "\t(3) - Em duas vezes, preço normal de etiqueta sem juros;\n" +
                                    "\t(4) - Em três vezes, preço normal de etiqueta mais juros de 10%."),
                            "Ferramenta de pagamento", JOptionPane.QUESTION_MESSAGE));
                }

                switch (opcao) {
                    case 1:
                        JOptionPane.showMessageDialog(null,
                                String.format("Preço á vista ou no cheque: %.2f",
                                        precoEtiqueta * 0.9));
                        break;
                    case 2:
                        JOptionPane.showMessageDialog(null,
                                String.format("Preço á vista no cartão de crédito: %.2f",
                                        precoEtiqueta * 0.85));
                        break;
                    case 3:
                        JOptionPane.showMessageDialog(null,
                                String.format("Preço em 2x sem juros: 2x de %.2f",
                                        (precoEtiqueta / 2)));
                        break;
                    case 4:
                        JOptionPane.showMessageDialog(null,
                                String.format(
                                        "Preço em 3x com juros: 3x de %.2f",
                                        ((precoEtiqueta * 1.1) / 3)
                                ));
                        break;
                    default:
                        JOptionPane.showMessageDialog(null,
                                "Fechando o programa...",
                                "Ferramenta de Pagamento", JOptionPane.INFORMATION_MESSAGE);
                }
            } while(opcao != 0);

        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null,
                    "Entrada inválida, digite um número real",
                    "Erro", JOptionPane.ERROR_MESSAGE);
        } catch(NullPointerException e) {
            JOptionPane.showMessageDialog(null,
                    "Execução cancelada",
                    "Aviso", JOptionPane.WARNING_MESSAGE);
        }
    }
}