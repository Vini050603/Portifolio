package Pacotes;

import javax.swing.JOptionPane;

public class main {

	public static void main(String[] args) {
		double salario;
		
		do {
		String s = JOptionPane.showInputDialog("Digite o valor do salário: (digite 0 (zero) para parar)");
		salario = Double.parseDouble(s);
		
		
		String dependem = JOptionPane.showInputDialog("Digite quantidade de dependentes: ");
		double dependentes= Double.parseDouble(dependem);
		//salarios s1 = new salarios(salario, dependentes );
		
		double DP;
		double IRPF = 0;
		double SL;
		double INSS = 0;
		
		if(salario <= 1212.00) {

			INSS =salario * (0.075);
		}
		else if(salario >= 1212.01 && salario <= 2427.35 ) {

			INSS=salario * (0.09);
		}
		else if( salario >= 2427.36 && salario <= 3641.03 ) {

			INSS =salario * (0.12);
		}
		else if(salario >= 3641.04 && salario <= 7087.22 ) {

			INSS =salario * (0.14);
		}
		else if(7087.23 <= salario) {

			INSS = 992.22;
		}
		
		DP= dependentes*(189.59);
		
		if(salario <= 1903.98) {

			IRPF = salario - INSS - DP;
		}
		else if(1903.99 <= salario && salario <= 2836.65) {

			IRPF =(salario - INSS - DP) * (0.075) - 142.80;
		}
		else if(2826.66 <= salario && salario <= 3751.05) {

			IRPF =(salario - INSS - DP) * (0.15) - 354.80;
		}
		else if(3751.06 <= salario && salario  <= 4664.68) {

			IRPF =(salario - INSS - DP) * (0.225) - 636.13;
		}
		else if(4664.68 <= salario) {

			IRPF =(salario - INSS - DP) * 0.275 - 869.36;
			
		}

		SL =Math.round( salario-INSS-IRPF);
		
		System.out.printf("INSS: "+INSS+"\nDedução com depedentes: "+DP+"\nIRPF: "+IRPF+"\nLíquido: "+SL);

	}while(salario != 0);
		
	}
	}

