var nome = '';
class Sobre extends Phaser.Scene{
    init(data){
      nome = data.nome;
    }
  constructor(){
	super("Sobre");
  }
  create(){
    this.add.image(0,0,"telaSobre").setOrigin(0,0);
    setTimeout(()=>{
    var btnContinuar = this.add.image(380, 445, "btnContinuar").setScale(1.5).setOrigin(0,0);
    btnContinuar.setInteractive();
    btnContinuar.on("pointerdown", ()=>this.scene.start("Lista", { nome: nome}))
    },1500);
  }

}