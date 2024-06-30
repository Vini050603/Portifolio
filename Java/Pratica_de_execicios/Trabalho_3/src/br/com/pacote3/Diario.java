package br.com.pacote3;

import javax.swing.JOptionPane;

import  br.com.pacote3.Alunos;

	public class Diario{


		public static void main(String[] args) {
			Integer matriculas;
			Integer p=1;
			Integer cont=0,i;
			Integer i2=0;
			Double media_a[] = new Double[1000];
			Double media;


		for(i2=0;p!=0;i2++) {
			Double soma=0.0;
			 String m = JOptionPane.showInputDialog(null,"\nDigite matricula do aluno: ");
			 matriculas=  Integer.parseInt(m);
			 p=matriculas;
			 String alunos = JOptionPane.showInputDialog(null,"Digite nome do aluno: ");
			 String qn = JOptionPane.showInputDialog(null,"\nDigite quantidade de notas do aluno: ");
			 Integer n_notas=  Integer.parseInt(qn);
			 
			 Double[] notas = new Double[n_notas];
			 
			for(cont=0;cont<n_notas; cont++) {			
				Integer cont1 =cont+1;
				String nota = JOptionPane.showInputDialog("Digite nota "+cont1+": ");
				Double nt = Double.parseDouble(nota);
				notas[cont] = nt;
			}

			System.out.printf("\n\nMatricula: "+matriculas+"\nAluno: "+alunos+"\nQuantidade de notas: "+n_notas);
			for(i=0; i<n_notas;i++) {
				Integer n = i+1;
				System.out.printf("\nNota "+n+" é:"+notas[i]);
				soma += notas[i];
			}
	
			media = soma/n_notas;
			System.out.printf("\nMedia: "+media);
			media_a[i2]=media;	

	
		}

		System.out.printf("\n\nQuantidade de alunos: "+i2);
		Integer n, j;
		
		for(j=0; j<i2;j++) {
			n=j+1;
			System.out.printf("\nMédia nota "+n+": "+media_a[j]);
		}
		
		Double som=0.0;
		Double media_geral=0.0;
		
		for(j=0; j<i2;j++) {
			som += media_a[j];
		}
		
		media_geral = som/i2;
		System.out.printf("\nMédia geral: "+media_geral);		
	}
		
	}


