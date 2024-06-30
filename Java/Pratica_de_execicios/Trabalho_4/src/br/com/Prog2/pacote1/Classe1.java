package br.com.Prog2.pacote1;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JOptionPane;

public class Classe1 {

	public static void main(String[] args) {
		List lista = new ArrayList();
		List lista2 = new ArrayList();
		String lt = new String();

		for(int i=0; i<2; i++) {
			lt = JOptionPane.showInputDialog("Digite item "+(i+1)+" da lista:");
	lista.add(lt);
		}
		
		for(int i=0; i<3; i++) {
	lista2.add("String " + (i +1));	
	lista2.add("String " + (i +1));
		}
		for(int i=0; i<lista2.size(); i++) {
		System.out.print(lista2.get(i));
		System.out.print("\n");
	
		}
		
	}
//Existem 6 elementos
}
