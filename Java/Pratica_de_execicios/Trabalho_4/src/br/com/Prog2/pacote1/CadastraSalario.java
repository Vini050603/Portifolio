package br.com.Prog2.pacote1;
import java.util.ArrayList;
import java.util.List;
import br.com.Prog2.pacote1.*;
import javax.swing.JOptionPane;


public class CadastraSalario {

	public static void main(String[] args) {

		List <Servico> servi = new ArrayList<Servico>();
		Integer codigo = 0;
		do {
			codigo = Integer.parseInt(JOptionPane.showInputDialog("Digite c�digo:"));
			if(codigo ==0) {
				System.out.println("Cadastramento cancelado");
				break;
			}
			String descricao = JOptionPane.showInputDialog("Digite descri��o: ");
			Double precoHora= Double.parseDouble(JOptionPane.showInputDialog("Digite o pre�o por hora:"));
			Integer qtdeHora= Integer.parseInt(JOptionPane.showInputDialog("Digite quantidade de horas:"));

			servi.add(new Servico(codigo, descricao, precoHora, qtdeHora));
		}while(codigo!=0);
		System.out.println("C�digo\tDescri��o\tValor da Valor\tQtde Hora\t\tValor total");
		Double total = (double) 0;
		for (Servico servico : servi) {
			total += servico.Imprime();
		}
		System.out.println("Total: \t" + total);
}
}

