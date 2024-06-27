var nome = '';
class Instrucoes extends Phaser.Scene{
    init(data){
      nome = data.nome;
    }
  constructor(){
	super("Instrucoes");
  }
  create(){
    this.add.image(0,0,"telaInstrucoes").setOrigin(0,0);
    setTimeout(()=>{
    var btnContinuar = this.add.image(380, 435, "btnContinuar").setScale(1.5).setOrigin(0,0);
    btnContinuar.setInteractive();
    btnContinuar.on("pointerdown", ()=>this.scene.start("Sobre", { nome: nome}))
    },1500);
  }

}