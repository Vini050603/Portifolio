class GameOver extends Phaser.Scene{

  constructor(){
	super("GameOver");
  }
  
  create(){
    this.add.image(0,0,"Over").setOrigin(0,0);
            setTimeout(()=>{
          var btnPlay = this.add.image(380, 230, "btnTentar").setOrigin(0,0);
          btnPlay.setInteractive();
          btnPlay.on("pointerdown", ()=>this.scene.start("Historia"));
    },3500);
  }
}