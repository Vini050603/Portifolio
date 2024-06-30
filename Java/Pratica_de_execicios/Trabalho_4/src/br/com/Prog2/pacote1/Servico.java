package br.com.Prog2.pacote1;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JOptionPane;


public class Servico {
private Integer codigo;
private String descricao;
private Double precoHora;
private Integer qtdeHora;
private Double valor;


public Servico(Integer codigo, String descricao, Double precoHora, Integer qtdeHora) {
this.codigo = codigo;
this.descricao = descricao;
this.precoHora = precoHora;
this.qtdeHora = qtdeHora;
}


public Double ValorSaldo(Double precoHora, Integer qtdeHora) {
	valor = precoHora*qtdeHora;
	return valor;
}

public double Imprime() {
	Double valorT = ValorSaldo(precoHora, qtdeHora);
	System.out.println(codigo+"\t|"+descricao+"\t\t|"+precoHora+"\t\t|"+qtdeHora+"\t\t\t|"+valorT);
	return valorT;
}

}
