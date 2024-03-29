package S4.Topicos_especiais_em_Programacao.Atividade10_04etapa02.Questao01;

import javax.swing.JOptionPane;

public class ConversorTemperatura extends javax.swing.JFrame {

    /**
     * Creates new form ConversorTemperatura
     */
    public ConversorTemperatura() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jTextCelsius = new javax.swing.JTextField();
        jTextFahr = new javax.swing.JTextField();
        jTextKelvin = new javax.swing.JTextField();
        jSeparator1 = new javax.swing.JSeparator();
        jButConverter = new javax.swing.JButton();
        jButLimpar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Conversor de Temperaturas");
        setMaximumSize(new java.awt.Dimension(340, 375));
        setMinimumSize(new java.awt.Dimension(340, 375));
        setPreferredSize(new java.awt.Dimension(340, 375));
        setResizable(false);
        setSize(new java.awt.Dimension(340, 375));

        jPanel1.setBorder(javax.swing.BorderFactory.createEtchedBorder());
        jPanel1.setPreferredSize(new java.awt.Dimension(340, 375));

        jLabel1.setFont(new java.awt.Font("Arial", 1, 18)); // NOI18N
        jLabel1.setText("Conversor de Temperatura");

        jLabel2.setFont(new java.awt.Font("Arial", 0, 14)); // NOI18N
        jLabel2.setText("Fahrenheit (ºF):");

        jLabel3.setFont(new java.awt.Font("Arial", 0, 14)); // NOI18N
        jLabel3.setText("Celsius (ºC):");

        jLabel4.setFont(new java.awt.Font("Arial", 0, 14)); // NOI18N
        jLabel4.setText("Kelvin (K):");

        jTextCelsius.setText("0");

        jTextFahr.setText("0");

        jTextKelvin.setText("0");

        jButConverter.setText("Converter");
        jButConverter.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButConverterActionPerformed(evt);
            }
        });

        jButLimpar.setText("Limpar");
        jButLimpar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButLimparActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jSeparator1)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(50, 50, 50)
                        .addComponent(jLabel1))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(38, 38, 38)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel2)
                            .addComponent(jLabel4)
                            .addComponent(jLabel3)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(jButConverter, javax.swing.GroupLayout.PREFERRED_SIZE, 122, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jButLimpar, javax.swing.GroupLayout.PREFERRED_SIZE, 123, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGap(104, 104, 104)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jTextFahr, javax.swing.GroupLayout.PREFERRED_SIZE, 154, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jTextCelsius, javax.swing.GroupLayout.PREFERRED_SIZE, 154, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jTextKelvin, javax.swing.GroupLayout.PREFERRED_SIZE, 153, javax.swing.GroupLayout.PREFERRED_SIZE))))))
                .addContainerGap(45, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(21, 21, 21)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 39, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextCelsius, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 39, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextFahr, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 39, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextKelvin, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(32, 32, 32)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButConverter, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButLimpar, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(39, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, 345, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private double getCelsius() {
        return Double.parseDouble(jTextCelsius.getText());
    }
    
    private double getFahrenheit() {
        return Double.parseDouble(jTextFahr.getText());
    }
    
    private double getKelvin() {
        return Double.parseDouble(jTextKelvin.getText());
    }
    
    private void setCelsius(String num) {jTextCelsius.setText(num);}
    private void setFahrenheit(String num) {jTextFahr.setText(num);}
    private void setKelvin(String num) {jTextKelvin.setText(num);}
    
    private double celsiusToFah(double tempCelsius) {return ((tempCelsius * 1.8) + 32);}
    private double fahToCelsius(double tempFah) {return ((tempFah - 32) / 9) * 5;}
    
    private double celsiusToKelvin(double tempCelsius) {return (tempCelsius + 273);}
    private double kelvinToCelsius(double tempKelvin) {return (tempKelvin - 273);}
    
    private double fahToKelvin(double tempFah) {return ((((tempFah - 32) / 9) * 5) + 273);}
    private double kelvinToFah(double tempKelvin) {return ((((tempKelvin - 273) / 5) * 9) + 32);}
    
    private void clearAll() {
        jTextCelsius.setText("0");
        jTextFahr.setText("0");
        jTextKelvin.setText("0");
    }
    
    private int statusCompletion() {
        if(getCelsius() != 0 && getFahrenheit() == 0 && getKelvin() == 0) return 1;
        else if(getCelsius() == 0 && getFahrenheit() != 0 && getKelvin() == 0) return 2;
        else if(getCelsius() == 0 && getFahrenheit() == 0 && getKelvin() != 0) return 3;
        else return -1;
    }
    
    private void convertTemperatures() {
        try {
            int actualStatus = statusCompletion();
            
            switch(actualStatus) {
                case 1: // celsius filled
                    setFahrenheit(String.format("%.2f", celsiusToFah(getCelsius())));
                    setKelvin(String.format("%.2f", celsiusToKelvin(getCelsius())));
                    break;
                case 2: // fahrenheit filled
                    setCelsius(String.format("%.2f", fahToCelsius(getFahrenheit())));
                    setKelvin(String.format("%.2f", fahToKelvin(getFahrenheit())));
                    break;
                case 3: // kelvin filled
                    setCelsius(String.format("%.2f",kelvinToCelsius(getKelvin())));
                    setFahrenheit(String.format("%.2f", kelvinToFah(getFahrenheit())));
                    break;
                default:
                    JOptionPane.showMessageDialog(
                            null,
                            "Entradas inválidas!",
                            "Erro",
                            JOptionPane.ERROR_MESSAGE
                    );
            }   
        } catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(
                    null,
                    "Digite um número válido",
                    "Erro na execução",
                    JOptionPane.ERROR_MESSAGE
            );
        }
    }
    
    private void jButLimparActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButLimparActionPerformed
        clearAll();
    }//GEN-LAST:event_jButLimparActionPerformed

    private void jButConverterActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButConverterActionPerformed
        convertTemperatures();
    }//GEN-LAST:event_jButConverterActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(ConversorTemperatura.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ConversorTemperatura.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ConversorTemperatura.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ConversorTemperatura.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        
        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ConversorTemperatura().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButConverter;
    private javax.swing.JButton jButLimpar;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JTextField jTextCelsius;
    private javax.swing.JTextField jTextFahr;
    private javax.swing.JTextField jTextKelvin;
    // End of variables declaration//GEN-END:variables
}
