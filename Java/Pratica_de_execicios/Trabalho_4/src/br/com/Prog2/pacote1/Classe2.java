package br.com.Prog2.pacote1;

import java.util.ArrayList;
import java.util.List;
import javax.swing.JOptionPane;

public class Classe2 {
	List lista = new ArrayList();
	String lt = new String();
	
	for(int i=0; i<2; i++) {
		lt = JOptionPane.showInputDialog("Digite item "+(i+1)+" da lista:");
		lista.add(lt);
	}
}
