class Ataque extends Phaser.Physics.Arcade.Sprite{
  constructor(scene, x, y, key){
    super(scene, x, y, key);
  
  scene.add.existing(this);
  scene.physics.add.existing(this);

  this.speed = 300;
  this.disMaxima = 300;

  this.disPecorrida = 0;

  this.health = 40;

  this.damage = 10;
  this.cooldown = 600;

  this.body.setSize(this.width - 13, this.height -20);

  //this.effectManger = new EffectManager(this.scene);
  }


pUpdate(time, delta){
  super.pUpdate(time, delta);

  this.disPecorrida += this.body.deltaAbsX();

  if(this.isOutOfRange()){
    this.body.reset(0,0);
    this.ativarAtack(false);
    this.disPecorrida = 0;
  }
}

fire(x,y){
  this.ativarAtack(true);
  this.body.reset(x,y);
  this.setVelocityX(this.speed);
}

deliversHit(target){
  this.ativarAtack(false);
  this.disPecorrida = 0;
  const impactPosition = {x: this.x, y: this.y};
  this.body.reset(0,0);
  //this.effectManager.playEffectOn('hit-effect', target, impactPosition);
}

ativarAtack(condicao){
  this.setActive(condicao);
  this.setVisible(condicao);
}

isOutOfRange(){
  return this.disPecorrida && this.disPecorrida >= this.disMaxima;
}
}
