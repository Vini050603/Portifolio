class Ataque2 extends Phaser.Physics.Arcade.Group{
  constructor(scene){
    super(scene.physics.world, scene);
  

  this.createMultiple({
    frameQuantity: 5,
    active: false,
    visible: false,
    key: 'tiro',
    classType: Ataque
  });
  this.timeFromLastProjectile = null;
}

fireProjectile(initiator){
    const projectile = this.getFirstDead(false);

    if(!projectile){return;}

    if(this.timeFromLastProjectile && this.timeFromLastProjectile + projectile.cooldown > getTimestamp()){return;}

    const center = initiator.getCenter();
    let centerX;

    if(initiator.lastDirection === Phaser.Physics.Arcade.FACING_RIGHT){
      projectile.speed = Math.abs(projectile.speed);
      projectitle.setFlipX(false);
      centerX = center.x + 10;
    }else{
      projectile.speed = -Math.abs(projectile.speed);
      projectile.setFlipX(true);
      centerX = center.x - 10;
    }

    projectile.fire(centerX, center.y);
    this.timeFromLastProjectile = getTimestamp();
}
}
