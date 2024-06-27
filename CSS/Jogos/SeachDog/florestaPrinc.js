//Classe Floresta
    var nome = '';

async function savePontosToAPI(nome, pontos) {
  try {
    const data = {
      nome: nome,
      pontos: pontos
    };

    console.log("Enviando dados para o servidor:", data);

    const response = await axios.post("https://back-end-seach-dog.wanderson-xavie.repl.co/pontos/salvar", data);

    console.log("Resposta do servidor:", response.data);

    return response.data;  
  } catch(error) {
    console.error("Erro na requisição:", error);
    throw error;
  }
}
class FlorestaPrinc extends Phaser.Scene {
    init(data){
      nome = data.nome;
    }
    constructor() {
        super("FlorestaPrinc");
        this.bullets;
        this.bullets2;
        this.personagem;
        this.spaceKey;
        this.rKey;
        this.destino
        //barra de vida dos mobs
        this.vidamob1 = 100;
        this.vidamob2 = 100;
        this.vidamob3 = 100;
        this.vidamob4 = 100;
        this.vidamob5 = 105;
        this.vidamob6 = 60;
        this.vidamob61 = 60;
        this.vidamob62 = 60;
        this.vidamob7 = 105;

        //barra de vida do GhostFace
        this.vidaBoss = 200;
        //barra de vida do Josh
        this.vidaPersonagem = 200;
        //Texto da quantidade de bala disponivel
        this.bulletsText;
        this.distance;
        this.ataqueGhost;
        this.andarGhost;
        this.pontuacaoInicial = 1000; // Defina o valor inicial desejado
        this.pontuacaoAtual = this.pontuacaoInicial;
    }
 

    //CREATE
    create() {
        console.log('CidadePrinc iniciada com pontos:', this.pontuacaoAtual, 'e nome:', nome);

        //this.ghostAnimationPlayed = false;

        this.plataformafloresta = this.physics.add
            .staticGroup();

        //plataforma invisivel para o personagem ficar em cima.
        this.plataformafloresta
            .create(0, 570, 'plataformafloresta')
            .setScale(5.5, 1.8)
            .setOrigin(0, 0.6)
            .refreshBody();

        this.cidade = this.add
            .image(0, 0, "floresta")
            .setOrigin(0);
        this.cidade.displayWidth = 5560;
        this.cidade.displayHeigth = 591;

        this.plataformafloresta
            .create(200, 300, 'plataformafloresta')
            .setScale(0.4, 1)
            .setOrigin(0, 0)
            .refreshBody();

        this.plataformafloresta
            .create(1500, 300, 'plataformafloresta')
            .setScale(0.25, 1)
            .setOrigin(0, 0)
            .refreshBody();

        this.plataformafloresta
            .create(3000, 300, 'plataformafloresta')
            .setScale(0.2, 1)
            .setOrigin(0, 0)
            .refreshBody();

        this.plataformafloresta
            .create(4500, 300, 'plataformafloresta')
            .setScale(0.3, 1)
            .setOrigin(0, 0)
            .refreshBody();

        //Coleta bala
        this.bala1 = this.physics.add.group({
            key: 'bala',
            repeat: 8,
            setXY: {
                x: 230,
                y: 100,
                stepX: 70
            }
        })

        this.bala2 = this.physics.add.group({
            key: 'bala',
            repeat: 5,
            setXY: {
                x: 1510,
                y: 100,
                stepX: 70
            }
        })

        this.bala3 = this.physics.add.group({
            key: 'bala',
            repeat: 4,
            setXY: {
                x: 3030,
                y: 100,
                stepX: 70
            }
        })

        this.bala4 = this.physics.add.group({
            key: 'bala',
            repeat: 6,
            setXY: {
                x: 4530,
                y: 100,
                stepX: 70
            }
        })

        this.bala1.children.iterate((c) => {
            c.setBounceY(Phaser.Math.FloatBetween(.4, .8))
        })

        //JOSH
        this.personagem = this.physics.add
            .sprite(200, 400, 'personagem', 16)
            .setCollideWorldBounds(true)
            .setScale(1)
            .setSize(100, 150)
            .setOffset(15, 20);
        this.personagem.canJump = true;

        // GHOSTFACE
        this.boss = this.physics.add
            .sprite(5420, 400, 'ghostface', 0)
            .setCollideWorldBounds(true)
            .setScale(1)
            .setSize(100, 150)
            .setOffset(40, 20);


        //Esqueletos plataformas
        //ESQUELETO 1
        this.mob1 = this.physics.add.image(210, 100, 'esqueletoflo')
            .setScale(1.5)
            .setSize(40, 90)
            .setOffset(30, 20);
        //ESQUELETO 2
        this.mob2 = this.physics.add.image(1510, 200, 'esqueletoflo')
            .setScale(1.5)
            .setSize(40, 90)
            .setOffset(30, 20);
        //ESQUELETO 3
        this.mob3 = this.physics.add.image(3010, 200, 'esqueletoflo')
            .setScale(1.5)
            .setSize(40, 90)
            .setOffset(30, 20);
        //ESQUELETO 4
        this.mob4 = this.physics.add.image(4510, 200, 'esqueletoflo')
            .setScale(1.5)
            .setSize(40, 90)
            .setOffset(30, 20);

        //Esqueletos chão
        //ESQUELETO 5
        this.mob5 = this.physics.add.image(820, 400, 'esqueletoflo')
            .setScale(1.8)
            .setSize(40, 90)
            .setOffset(30, 20);
        //ESQUELETO 6
        this.mob6 = this.physics.add.image(1910, 400, 'esqueletoflo')
            .setScale(1)
            .setSize(40, 90)
            .setOffset(30, 20);
        this.mob61 = this.physics.add.image(2110, 400, 'esqueletoflo')
            .setScale(1)
            .setSize(40, 90)
            .setOffset(30, 20);
        this.mob62 = this.physics.add.image(2310, 400, 'esqueletoflo')
            .setScale(1)
            .setSize(40, 90)
            .setOffset(30, 20);

        //ESQUELETO 7
        this.mob7 = this.physics.add.image(3345, 400, 'esqueletoflo')
            .setScale(1.8)
            .setSize(40, 90)
            .setOffset(30, 20);


        //Controle
        this.controles = this.input.keyboard
            .createCursorKeys();

        //Tiro
        this.bullets = new Bullets(this, 100);
        this.bullets2 = new Bullets2(this, 2000);
        this.plataformamob = this.physics.add.staticGroup();
        this.plataformamob.create(0, 300, 'plataforma').setScale(0, 4);

        //Colisões
        this.physics.add.collider(this.personagem, this.plataformafloresta);
        this.physics.add.collider(this.boss, this.plataformafloresta);
        this.physics.add.collider(this.mob1, this.plataformafloresta);
        this.physics.add.collider(this.mob2, this.plataformafloresta);
        this.physics.add.collider(this.mob3, this.plataformafloresta);
        this.physics.add.collider(this.mob4, this.plataformafloresta);
        this.physics.add.collider(this.mob5, this.plataformafloresta);
        this.physics.add.collider(this.mob6, this.plataformafloresta);
        this.physics.add.collider(this.mob61, this.plataformafloresta);
        this.physics.add.collider(this.mob62, this.plataformafloresta);
        this.physics.add.collider(this.mob7, this.plataformafloresta);
        this.physics.add.collider(this.bala1, this.plataformafloresta);
        this.physics.add.collider(this.bala2, this.plataformafloresta);
        this.physics.add.collider(this.bala3, this.plataformafloresta);
        this.physics.add.collider(this.bala4, this.plataformafloresta);

        //Colisões de balas com inimigos
        this.physics.add.overlap(this.bullets, this.mob1, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bullets, this.mob2, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bullets, this.mob3, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bullets, this.mob4, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bullets, this.mob5, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bullets, this.mob6, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bullets, this.mob61, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bullets, this.mob62, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bullets, this.mob7, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bullets2, this.personagem, this.bulletHitEnemy, null, this);

        this.physics.add.overlap(this.bullets, this.boss, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.personagem, this.mob1, this.mobHitpersonagem, null, this);
        this.physics.add.overlap(this.personagem, this.mob2, this.mobHitpersonagem, null, this);
        this.physics.add.overlap(this.personagem, this.mob3, this.mobHitpersonagem, null, this);
        this.physics.add.overlap(this.personagem, this.mob4, this.mobHitpersonagem, null, this);
        this.physics.add.overlap(this.personagem, this.mob5, this.mobHitpersonagem, null, this);
        this.physics.add.overlap(this.personagem, this.mob6, this.mobHitpersonagem, null, this);
        this.physics.add.overlap(this.personagem, this.mob61, this.mobHitpersonagem, null, this);
        this.physics.add.overlap(this.personagem, this.mob62, this.mobHitpersonagem, null, this);
        this.physics.add.overlap(this.personagem, this.mob7, this.mobHitpersonagem, null, this);
        this.physics.add.overlap(this.personagem, this.boss, this.mobHitpersonagem, null, this);
        this.physics.add.overlap(this.personagem, this.bala1, this.coletaBala, null, this);
        this.physics.add.overlap(this.personagem, this.bala2, this.coletaBala, null, this);
        this.physics.add.overlap(this.personagem, this.bala3, this.coletaBala, null, this);
        this.physics.add.overlap(this.personagem, this.bala4, this.coletaBala, null, this);


        //Bordas
        this.physics.world
            .setBounds(0, 0, 5560, 591);
        this.cameras.main
            .setBounds(0, 0, 5560, 591)
            .startFollow(this.personagem);
        this.personagem.body
            .setCollideWorldBounds(true);

        //Movimentação Josh
        this.anims.create({
            key: 'andar',
            frames: this.anims
                .generateFrameNumbers('personagem', {start: 3, end: 5}),
            frameRate: 10,
            repeat: -1
        });
        this.anims.create({
            key: 'cima',
            frames: [{key: 'personagem', frame: 15}],
            frameRate: 10,
            repeat: -1
        });
        this.anims.create({
            key: 'baixo',
            frames: [{key: 'personagem', frame: 13}],
            frameRate: 10,
            repeat: -1
        });
        this.anims.create({
            key: 'ataque',
            frames: [{key: 'personagem', frame: 1}],
            frameRate: 10,
            repeat: -1
        });

        //Movimentação ghostface
        this.anims.create({
            key: 'andarGhost',
            frames: this.anims
                .generateFrameNumbers('ghostface', {start: 4, end: 5}),
            frameRate: 10,
            repeat: -1
        });

        this.anims.create({
            key: 'ghostParado',
            frames: [{key: 'ghostface', frame: 0}],
            frameRate: 10,
            repeat: -1
        });

        this.anims.create({
            key: 'ghostAtacando',
            frames: this.anims
                .generateFrameNumbers('ghostface', {start: 2, end: 3}),
            frameRate: 10,
            repeat: -1
        });

        this.anims.create({
            key: 'ghostMorrendo',
            frames: this.anims
                .generateFrameNumbers('ghostface', {start: 8, end: 11}),
            frameRate: 5,
            repeat: -1
        });

        this.spaceKey = this.input.keyboard
            .addKey(Phaser.Input.Keyboard.KeyCodes.SPACE);

        //Função que atira utilizando a tecla space
        this.spaceKey.canFire = true;
        this.input.keyboard.on('keyup-SPACE', () => {
            if (this.spaceKey.canFire && this.bullets.bulletQuantity > 0) {

                this.bullets.fireBullet(this.personagem.x + 28, this.personagem.y - 19, this.personagem.flipX ? 'left' : 'right');
                this.bullets.bulletQuantity -= 1;
                this.spaceKey.canFire = false;
            }
        });

        //Criando botão R
        this.rKey = this.input.keyboard.addKey(Phaser.Input.Keyboard.KeyCodes.R);
        //Usando o botão R para recarregar as balas. ATENÇÃO: Será mudado para quando pegar o icone de bala no mapa.
        this.rKey.on('up', () => {
            this.bullets = new Bullets(this, 30);
            this.physics.add.collider(this.bullets, this.mob1, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bullets, this.mob2, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bullets, this.mob3, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bullets, this.mob4, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bullets, this.mob5, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bullets, this.mob6, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bullets, this.mob61, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bullets, this.mob62, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bullets, this.mob7, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bullets, this.boss, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.personagem, this.mob1, this.mobHitpersonagem, null, this);
            this.physics.add.collider(this.personagem, this.mob2, this.mobHitpersonagem, null, this);
            this.physics.add.collider(this.personagem, this.mob3, this.mobHitpersonagem, null, this);
            this.physics.add.collider(this.personagem, this.mob4, this.mobHitpersonagem, null, this);
            this.physics.add.collider(this.personagem, this.mob5, this.mobHitpersonagem, null, this);
            this.physics.add.collider(this.personagem, this.mob6, this.mobHitpersonagem, null, this);
            this.physics.add.collider(this.personagem, this.mob61, this.mobHitpersonagem, null, this);
            this.physics.add.collider(this.personagem, this.mob62, this.mobHitpersonagem, null, this);
            this.physics.add.collider(this.personagem, this.mob7, this.mobHitpersonagem, null, this);
            this.physics.add.collider(this.personagem, this.boss, this.mobHitpersonagem, null, this);
        });

        this.pontuacaoText = this.add.text(600, 16, `Pontuação: ${this.pontuacaoAtual}`, {
            fontSize: '32px',
            fill: '#ffffff'
        }).setShadow(0, 0, '#000', 3)
            .setScrollFactor(0);


        this.time.addEvent({
            delay: 500,
            callback: () => {
                this.spaceKey.canFire = true;
            },
            callbackScope: this,
            loop: true
        });

        if (this.personagem.x <= 4000) {
            this.ataqueGhost = this.time.addEvent({
                delay: Phaser.Math.Between(2000, 7000), // Atraso aleatório entre 0,6 e 2 segundos
                callback: this.ghostShoot,
                callbackScope: this,
                loop: true
            });
        }

        this.andarGhost = this.time.addEvent({
            delay: Phaser.Math.Between(100, 350), // Atraso aleatório entre 0,10 e 0,35 segundos
            callback: this.ghostWalk,
            callbackScope: this,
            loop: true
        });

        this.umHit = this.time.addEvent({
            delay: Phaser.Math.Between(3000, 35000), // Atraso aleatório entre 0,10 e 0,35 segundos
            callback: this.colisoes,
            callbackScope: this,
            loop: true
        });


        this.time.addEvent({
            delay: 30000, // 30 segundos (em milissegundos)
            loop: true,
            callback: () => {
                const pontosPerdidos = 50; // Defina o valor de pontos perdidos desejado
                this.pontuacaoAtual -= pontosPerdidos;
            }
        });
        //cria a barra de vida dos personagens
        this.barraVidamob1 = this.add.rectangle(0, 0, 100, 10, 0xFF0000);
        this.barraVidamob2 = this.add.rectangle(0, 0, 100, 10, 0xFF0000);
        this.barraVidamob3 = this.add.rectangle(0, 0, 100, 10, 0xFF0000);
        this.barraVidamob4 = this.add.rectangle(0, 0, 100, 10, 0xFF0000);
        this.barraVidamob5 = this.add.rectangle(0, 0, 100, 10, 0xFF0000);
        this.barraVidamob6 = this.add.rectangle(0, 0, 80, 10, 0xFF0000);
        this.barraVidamob61 = this.add.rectangle(0, 0, 80, 10, 0xFF0000);
        this.barraVidamob62 = this.add.rectangle(0, 0, 80, 10, 0xFF0000);
        this.barraVidamob7 = this.add.rectangle(0, 0, 100, 10, 0xFF0000);
        this.barraVidaGhostface = this.add.rectangle(0, 0, 200, 10, 0xFF0000);
        this.barraVidaPersonagem = this.add.rectangle(0, 0, 100, 10, 0x0000CD);

        //Exibe o texto de balas disponives
        this.score = 30;
        this.bulletsText = this.add.text(16, 16, 'Balas: ' + this.score, {fontSize: '32px', fill: '#ffffff'})
            .setShadow(0, 0, '#000', 3)
            .setScrollFactor(0)
        this.setScore()

    }

    //Atualizar Quantidade de bala
    setScore() {
        this.bulletsText.setText('Balas: ' + this.score)
    }

    // Coletar Balas
    coletaBala(p, bala) {
        bala.destroy()
        this.bullets.bulletQuantity += 1;
        this.setScore()
    }

    update() {
        this.checkGameOver();
        //Realiza mudança de sprit ao apertar uma tecla do jogo
        if (this.controles.left.isDown) {
            this.personagem.flipX = true;
            this.personagem.setVelocityX(-300);
            this.personagem.anims.play('andar', true);
        } else if (this.controles.right.isDown) {
            this.personagem.flipX = false;
            this.personagem.setVelocityX(300);
            this.personagem.anims.play('andar', true);
        } else if (this.controles.down.isDown) {
            this.personagem.setVelocityY(300);
            this.personagem.setVelocityX(0);
            this.personagem.anims.play('baixo', true);
        } else if (this.controles.space.isDown && this.bullets.bulletQuantity > 0) {
            this.personagem.anims.play('ataque', true);
        } else if (!this.personagem.body.touching.down && this.controles.down.isDown) {
            this.personagem.setVelocityY(300).setFrame(15);
        } else {
            this.personagem.setVelocityX(0).setFrame(0);
        }
        if (!this.personagem.body.touching.down) {
            this.personagem.setFrame(
                this.personagem.body.velocity.y < 0 ? 3 : 9
            )
        }
        if (this.controles.up.isDown && this.personagem.canJump && this.personagem.body.touching.down) {
            this.personagem.setVelocityY(-650);
            this.personagem.canJump = true;
        }
        if (!this.controles.up.isDown && !this.personagem.canJump && !this.personagem.body.touching.down) {
            this.personagem.canJump = true;
        }
       if (this.personagem.x >= this.cidade.displayWidth - 100 && this.vidaBoss == 0) {
            console.log('Iniciando CidadePrinc com pontos:', this.pontuacaoAtual, 'e nome:', nome);
            this.scene.start('CidadePrinc', { pontos: this.pontuacaoAtual , nome: nome});
        } 

        //Move mob1
        if (this.mob1.x < 215) {
            this.mob1.setVelocityX(200); // Move para a direita
            this.mob1.flipX = false;
        } else if (this.mob1.x > 800) {
            this.mob1.setVelocityX(-200); // Move para a esquerda
            this.mob1.flipX = true;
        }

        //Move mob2
        if (this.mob2.x < 1515) {
            this.mob2.setVelocityX(200); // Move para a direita
            this.mob2.flipX = false;
        } else if (this.mob2.x > 1900) {
            this.mob2.setVelocityX(-200); // Move para a esquerda
            this.mob2.flipX = true;
        }

        //Move mob3
        if (this.mob3.x < 3015) {
            this.mob3.setVelocityX(200); // Move para a direita
            this.mob3.flipX = false;
        } else if (this.mob3.x > 3325) {
            this.mob3.setVelocityX(-200); // Move para a esquerda
            this.mob3.flipX = true;
        }

        //Move mob4
        if (this.mob4.x < 4515) {
            this.mob4.setVelocityX(200); // Move para a direita
            this.mob4.flipX = false;
        } else if (this.mob4.x > 4975) {
            this.mob4.setVelocityX(-200); // Move para a esquerda
            this.mob4.flipX = true;
        }

        //Move mob5
        if (this.mob5.x < 825) {
            this.mob5.setVelocityX(150); // Move para a direita
            this.mob5.flipX = false;
        } else if (this.mob5.x > 1500) {
            this.mob5.setVelocityX(-150); // Move para a esquerda
            this.mob5.flipX = true;
        }

        //Move mob6
        if (this.mob6.x < 1925) {
            this.mob6.setVelocityX(300); // Move para a direita
            this.mob6.flipX = false;
        } else if (this.mob6.x > 3000) {
            this.mob6.setVelocityX(-300); // Move para a esquerda
            this.mob6.flipX = true;
        }
        //Move mob61
        if (this.mob61.x < 2125) {
            this.mob61.setVelocityX(300); // Move para a direita
            this.mob61.flipX = false;
        } else if (this.mob61.x > 3000) {
            this.mob61.setVelocityX(-300); // Move para a esquerda
            this.mob61.flipX = true;
        }
        //Move mob62
        if (this.mob62.x < 2325) {
            this.mob62.setVelocityX(300); // Move para a direita
            this.mob62.flipX = false;
        } else if (this.mob62.x > 3000) {
            this.mob62.setVelocityX(-300); // Move para a esquerda
            this.mob62.flipX = true;
        }

        //Move mob7
        if (this.mob7.x < 3350) {
            this.mob7.setVelocityX(150); // Move para a direita
            this.mob7.flipX = false;
        } else if (this.mob7.x > 4500) {
            this.mob7.setVelocityX(-150); // Move para a esquerda
            this.mob7.flipX = true;
        }


        //atualiza a barra de vida em cima da cabeça dos personagens
        //mobs
        this.barraVidamob1.x = this.mob1.x - 10;
        this.barraVidamob1.y = this.mob1.y - 75;
        this.barraVidamob1.width = this.vidamob1;

        this.barraVidamob2.x = this.mob2.x - 10;
        this.barraVidamob2.y = this.mob2.y - 75;
        this.barraVidamob2.width = this.vidamob2;

        this.barraVidamob3.x = this.mob3.x - 10;
        this.barraVidamob3.y = this.mob3.y - 75;
        this.barraVidamob3.width = this.vidamob3;

        this.barraVidamob4.x = this.mob4.x - 10;
        this.barraVidamob4.y = this.mob4.y - 75;
        this.barraVidamob4.width = this.vidamob4;

        this.barraVidamob5.x = this.mob5.x - 10;
        this.barraVidamob5.y = this.mob5.y - 75;
        this.barraVidamob5.width = this.vidamob5;

        this.barraVidamob6.x = this.mob6.x - 10;
        this.barraVidamob6.y = this.mob6.y - 75;
        this.barraVidamob6.width = this.vidamob6;

        this.barraVidamob61.x = this.mob61.x - 10;
        this.barraVidamob61.y = this.mob61.y - 75;
        this.barraVidamob61.width = this.vidamob61;

        this.barraVidamob62.x = this.mob62.x - 10;
        this.barraVidamob62.y = this.mob62.y - 75;
        this.barraVidamob62.width = this.vidamob62;

        this.barraVidamob7.x = this.mob7.x - 10;
        this.barraVidamob7.y = this.mob7.y - 75;
        this.barraVidamob7.width = this.vidamob7;

        //ghostFace
        this.barraVidaGhostface.x = this.boss.x - 10;
        this.barraVidaGhostface.y = this.boss.y - 75;
        this.barraVidaGhostface.width = this.vidaBoss;

        //josh
        this.barraVidaPersonagem.x = this.personagem.x - 10;
        this.barraVidaPersonagem.y = this.personagem.y - 75;
        this.barraVidaPersonagem.width = this.vidaPersonagem;

        this.bulletsText.setText('Balas: ' + (this.bullets.bulletQuantity));
        this.pontuacaoText.setText(`Pontuação: ${this.pontuacaoAtual}`);
    }

    mobHitpersonagem(personagem, enemy) {
        if (personagem === this.personagem && this.vidaPersonagem > 0) {
            this.vidaPersonagem -= 3;

        }
    }

    bulletHitEnemy(enemy, bullet) {

        if (enemy === this.mob1 && this.vidamob1 > 0) {
            this.vidamob1 -= 20;
            bullet.destroy();
        } else if (enemy === this.boss && this.vidaBoss > 0) {
            this.vidaBoss -= 10;
            bullet.destroy();
        } else if (enemy === this.mob2 && this.vidamob2 > 0) {
            this.vidamob2 -= 20;
            bullet.destroy();
        } else if (enemy === this.mob3 && this.vidamob3 > 0) {
            this.vidamob3 -= 20;
            bullet.destroy();
        } else if (enemy === this.mob4 && this.vidamob4 > 0) {
            this.vidamob4 -= 20;
            bullet.destroy();
        } else if (enemy === this.mob5 && this.vidamob5 > 0) {
            this.vidamob5 -= 15;
            bullet.destroy();
        } else if (enemy === this.mob6 && this.vidamob6 > 0) {
            this.vidamob6 -= 20;
            bullet.destroy();
        } else if (enemy === this.mob61 && this.vidamob61 > 0) {
            this.vidamob61 -= 20;
            bullet.destroy();
        } else if (enemy === this.mob62 && this.vidamob62 > 0) {
            this.vidamob62 -= 20;
            bullet.destroy();
        } else if (enemy === this.mob7 && this.vidamob7 > 0) {
            this.vidamob7 -= 15;
            bullet.destroy();
        } else if (enemy === this.personagem && this.vidaPersonagem > 0) {
            this.vidaPersonagem -= 20;
            bullet.destroy();
        }

        if (enemy === this.mob1 && this.vidamob1 <= 0) {
            this.mob1.destroy();
            bullet.destroy();
            this.pontuacaoAtual += 100;
        }
        if (enemy === this.boss && this.vidaBoss <= 10) {
            this.boss.anims.play('ghostMorrendo');
            bullet.destroy();
            if (this.vidaBoss <= 0) {
                this.boss.destroy();
                this.pontuacaoAtual += 500;
            }
        }
        if (enemy === this.mob2 && this.vidamob2 <= 0) {
            this.mob2.destroy();
            bullet.destroy();
            this.pontuacaoAtual += 100;
        }
        if (enemy === this.mob3 && this.vidamob3 <= 0) {
            this.mob3.destroy();
            bullet.destroy();
            this.pontuacaoAtual += 100;
        }
        if (enemy === this.mob4 && this.vidamob4 <= 0) {
            this.mob4.destroy();
            bullet.destroy();
            this.pontuacaoAtual += 100;
        }
        if (enemy === this.mob5 && this.vidamob5 <= 0) {
            this.mob5.destroy();
            bullet.destroy();
            this.pontuacaoAtual += 100;
        }
        if (enemy === this.mob6 && this.vidamob6 <= 0) {
            this.mob6.destroy();
            bullet.destroy();
            this.pontuacaoAtual += 75;
        }
        if (enemy === this.mob61 && this.vidamob61 <= 0) {
            this.mob61.destroy();
            bullet.destroy();
            this.pontuacaoAtual += 75;
        }
        if (enemy === this.mob62 && this.vidamob62 <= 0) {
            this.mob62.destroy();
            bullet.destroy();
            this.pontuacaoAtual += 75;
        }
        if (enemy === this.mob7 && this.vidamob7 <= 0) {
            this.mob7.destroy();
            bullet.destroy();
            this.pontuacaoAtual += 100;
        }

    }

    verificarColisoes() {
        if (Phaser.Geom.Intersects.RectangleToRectangle(personagem.getBounds(), npc.getBounds())) {
            // Há colisão entre o personagem e o NPC
            colisoes++;

            // Verifica se já se passaram cinco segundos desde a última perda de vida
            if (colisoes % 5 === 0) {
                vidaPersonagem -= 10; // Reduz 10 pontos de vida

                // Atualiza a vida do personagem no jogo (exemplo: atualiza a barra de vida na tela)
                atualizarVidaPersonagem();
            }
        }
    }

    ghostShoot() {

        if (this.vidaBoss > 0) {
            // Calcula a posição de disparo do Ghost
            const shootX = this.boss.x - 50; // Ajuste conforme necessário
            const shootY = this.boss.y; // Ajuste conforme necessário
            // Faz o Ghost atirar
            if (this.personagem.x < this.boss.x) {
                this.boss.flipX = true;
                this.boss.anims.play('ghostAtacando');
                this.bullets2.fireBullet(shootX, shootY, 'left'); // Ajuste a direção do tiro conforme necessário
            } else {
                this.boss.flipX = false;
                this.boss.anims.play('ghostAtacando');
                this.bullets2.fireBullet(shootX, shootY, 'right'); // Ajuste a direção do tiro conforme necessário
            }
        }
    }

    ghostWalk() {
        //Move ghostFace
        if (this.vidaBoss > 0) {
            if (this.boss.x <= 5000) {
                this.boss.setVelocityX(200); // Move para a direita
                this.boss.flipX = false;
                this.boss.anims.play('andarGhost');
            } else if (this.boss.x >= 5400) {
                this.boss.setVelocityX(-200); // Move para a esquerda
                this.boss.flipX = true;
                this.boss.anims.play('andarGhost');
            }
        }
    }

    checkGameOver() {
        if (this.vidaPersonagem <= 0) {
          savePontosToAPI(nome, this.pontuacaoAtual)
          .then(response => console.log('Pontuação salva com sucesso: ', response))
          .catch(error => console.error('Erro ao salvar a pontuação: ', error));
            this.scene.start('GameOver');
        }
    }
}

class Bullet extends Phaser.Physics.Arcade.Sprite {
    constructor(scene, x, y) {
        super(scene, x, y, 'tiro');
    }

    fire(x, y, direction) {
        this.body.reset(x, y);
        this.setActive(true);
        this.setVisible(true);
        if (direction === 'left') {
            this.flipX = true;
            this.setVelocityX(-500);
        } else if (direction === 'right') {
            this.setVelocityX(500);
        }

    }

    preUpdate(time, delta) {
        super.preUpdate(time, delta);

        if (this.x <= 0 || this.x >= game.config.height) {
            this.setActive(false);
        }
    }
}

class Bullets extends Phaser.Physics.Arcade.Group {
    constructor(scene, quantity) {
        super(scene.physics.world, scene);

        this.bulletQuantity = quantity; // Armazena a quantidade total de tiros
        this.createMultiple({
            frameQuantity: quantity,
            key: 'tiro',
            active: false,
            visible: false,
            classType: Bullet
        });
    }

    fireBullet(x, y, direction) {
        const bullet = this.getFirstDead(false);

        if (bullet) {
            bullet.body.allowGravity = false;
            bullet.fire(x, y, direction);
        }
    }
}

class Bullet2 extends Phaser.Physics.Arcade.Sprite {
    constructor(scene, x, y) {
        super(scene, x, y, 'faca');
    }

    fire(x, y, direction) {
        this.body.reset(x, y);
        this.setActive(true);
        this.setVisible(true);
        if (direction === 'left') {
            this.flipX = true;
            this.setVelocityX(-300);
        } else if (direction === 'right') {
            this.setVelocityX(300);
        }

    }

    preUpdate(time, delta) {
        super.preUpdate(time, delta);

        if (this.x <= 0 || this.x >= game.config.height) {
            this.setActive(false);
        }
    }
}

class Bullets2 extends Phaser.Physics.Arcade.Group {
    constructor(scene, quantity2) {
        super(scene.physics.world, scene);

        this.bulletQuantity = quantity2; // Armazena a quantidade total de tiros
        this.createMultiple({
            frameQuantity: quantity2,
            key: 'faca',
            active: false,
            visible: false,
            classType: Bullet2
        });
    }

    fireBullet(x, y, direction) {
        const bullet2 = this.getFirstDead(false);

        if (bullet2) {
            bullet2.body.allowGravity = false;
            bullet2.fire(x, y, direction);
        }
    }
}