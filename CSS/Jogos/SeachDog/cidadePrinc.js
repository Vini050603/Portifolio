  //Classe Floresta

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
  class CidadePrinc extends Phaser.Scene {
    constructor() {
        super("CidadePrinc");
        this.bulletsCity;
        this.bulletsCity2;
        this.personagem;
        this.spaceKey;
        this.rKey;
        this.destino
        //barra de vida dos mobs
        this.vidamob1 = 120;
        this.vidamob2 = 120;
        this.vidamob3 = 120;
        this.vidamob4 = 120;
        this.vidamob5 = 125;
        this.vidamob6 = 80;
        this.vidamob61 = 80;
        this.vidamob62 = 80;
        this.vidamob7 = 125;

        //barra de vida do Rambo
        this.vidaBoss = 250;
        //barra de vida do Josh
        this.vidaPersonagem = 150;
        //Texto da quantidade de bala disponivel
        this.bulletsCityText;
        this.distance;
        this.ataqueRambo;
        this.andarRambo;
        this.nomeCidade;
        this.pontuacaoAtual;
    }
    init(data){
      this.pontuacaoAtual = data.pontos;
      this.nomeCidade = data.nome;
    }
    
    //CREATE
    create() {
        console.log('CidadePrinc iniciada com pontos:', this.pontuacaoAtual, 'e nome:', this.nomeCidade);

        //this.ramboAnimationPlayed = false;

        this.plataformafloresta = this.physics.add
            .staticGroup();

        //plataforma invisivel para o personagem ficar em cima.
        this.plataformafloresta
            .create(0, 570, 'plataformacid')
            .setScale(5.5, 1.8)
            .setOrigin(0, 0.6)
            .refreshBody();

        this.cidade = this.add
            .image(0, 0, "cidadePrinc")
            .setOrigin(0);
        this.cidade.displayWidth = 5560;
        this.cidade.displayHeigth = 591;

        this.plataformafloresta
            .create(200, 300, 'plataformacid')
            .setScale(0.4, 1)
            .setOrigin(0, 0)
            .refreshBody();

        this.plataformafloresta
            .create(1500, 300, 'plataformacid')
            .setScale(0.25, 1)
            .setOrigin(0, 0)
            .refreshBody();

        this.plataformafloresta
            .create(3000, 300, 'plataformacid')
            .setScale(0.2, 1)
            .setOrigin(0, 0)
            .refreshBody();

        this.plataformafloresta
            .create(4500, 300, 'plataformacid')
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

        // Rambo
        this.boss = this.physics.add
            .sprite(5420, 400, 'rambo', 0)
            .setCollideWorldBounds(true)
            .setScale(1.7)
            .setSize(70, 100)
            .setOffset(20, 20);


        //Esqueletos plataformas
        //ESQUELETO 1
        this.mob1 = this.physics.add
            .sprite(210, 100, 'esqueletocity', 0)
            .setScale(2.4)
            .setSize(40, 60)
            .setOffset(80, 60);
        //ESQUELETO 2
        this.mob2 = this.physics.add
            .sprite(1510, 100, 'esqueletocity', 0)
            .setScale(2.4)
            .setSize(40, 60)
            .setOffset(80, 60);
        //ESQUELETO 3
        this.mob3 = this.physics.add
            .sprite(3010, 100, 'esqueletocity', 0)
            .setScale(2.4)
            .setSize(40, 60)
            .setOffset(80, 60);
        //ESQUELETO 4
        this.mob4 = this.physics.add
            .sprite(4510, 100, 'esqueletocity', 0)
            .setScale(2.4)
            .setSize(40, 60)
            .setOffset(80, 60);

        //Esqueletos chão
        //ESQUELETO 5
        this.mob5 = this.physics.add
            .sprite(820, 350, 'esqueletocity', 0)
            .setScale(2.7)
            .setSize(40, 60)
            .setOffset(80, 60);
        //ESQUELETO 6
        this.mob6 = this.physics.add
            .sprite(1910, 350, 'esqueletocity', 0)
            .setScale(1.7)
            .setSize(40, 60)
            .setOffset(80, 60);
        this.mob61 = this.physics.add
            .sprite(2110, 350, 'esqueletocity', 0)
            .setScale(1.7)
            .setSize(40, 60)
            .setOffset(80, 60);
        this.mob62 = this.physics.add
            .sprite(2310, 350, 'esqueletocity', 0)
            .setScale(1.7)
            .setSize(40, 60)
            .setOffset(80, 60);
        //ESQUELETO 7
        this.mob7 = this.physics.add
            .sprite(3345, 350, 'esqueletocity', 0)
            .setScale(2.7)
            .setSize(40, 60)
            .setOffset(80, 60);

        //Controle
        this.controles = this.input.keyboard
            .createCursorKeys();

        //Tiro
        this.bulletsCity = new bulletsCity(this, 100);
        this.bulletsCity2 = new bulletsCity2(this, 2000);
        this.plataformamob = this.physics.add.staticGroup();
        this.plataformamob.create(0, 300, 'plataformacid').setScale(0, 4);

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
        this.physics.add.overlap(this.bulletsCity, this.mob1, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bulletsCity, this.mob2, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bulletsCity, this.mob3, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bulletsCity, this.mob4, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bulletsCity, this.mob5, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bulletsCity, this.mob6, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bulletsCity, this.mob61, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bulletsCity, this.mob62, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bulletsCity, this.mob7, this.bulletHitEnemy, null, this);
        this.physics.add.overlap(this.bulletsCity2, this.personagem, this.bulletHitEnemy, null, this);

        this.physics.add.overlap(this.bulletsCity, this.boss, this.bulletHitEnemy, null, this);
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

        //Movimentação Rambo
        this.anims.create({
            key: 'andarRambo',
            frames: this.anims
                .generateFrameNumbers('rambo', {start: 1, end: 3}),
            frameRate: 10,
            repeat: -1
        });

        this.anims.create({
            key: 'ramboParado',
            frames: this.anims
                .generateFrameNumbers('rambo', {start: 0, end: 1}),
            frameRate: 10,
            repeat: -1
        });


        this.anims.create({
            key: 'andamob',
            frames: this.anims
                .generateFrameNumbers('esqueletocity', {start: 0, end: 5}),
            frameRate: 2,
            repeat: -1
        });
        this.spaceKey = this.input.keyboard
            .addKey(Phaser.Input.Keyboard.KeyCodes.SPACE);

        //Função que atira utilizando a tecla space
        this.spaceKey.canFire = true;
        this.input.keyboard.on('keyup-SPACE', () => {
            if (this.spaceKey.canFire && this.bulletsCity.bulletQuantity > 0) {

                this.bulletsCity.fireBullet(this.personagem.x + 28, this.personagem.y - 19, this.personagem.flipX ? 'left' : 'right');
                this.bulletsCity.bulletQuantity -= 1;
                this.spaceKey.canFire = false;
            }
        });

        //Criando botão R
        this.rKey = this.input.keyboard.addKey(Phaser.Input.Keyboard.KeyCodes.R);
        //Usando o botão R para recarregar as balas. ATENÇÃO: Será mudado para quando pegar o icone de bala no mapa.
        this.rKey.on('up', () => {
            this.bulletsCity = new bulletsCity(this, 30);
            this.physics.add.collider(this.bulletsCity, this.mob1, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bulletsCity, this.mob2, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bulletsCity, this.mob3, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bulletsCity, this.mob4, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bulletsCity, this.mob5, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bulletsCity, this.mob6, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bulletsCity, this.mob61, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bulletsCity, this.mob62, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bulletsCity, this.mob7, this.bulletHitEnemy, null, this);
            this.physics.add.collider(this.bulletsCity, this.boss, this.bulletHitEnemy, null, this);
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
            this.ataqueRambo = this.time.addEvent({
                delay: Phaser.Math.Between(2000, 7000), // Atraso aleatório entre 0,6 e 2 segundos
                callback: this.ramboShoot,
                callbackScope: this,
                loop: true
            });
        }

        this.andarRambo = this.time.addEvent({
            delay: Phaser.Math.Between(100, 350), // Atraso aleatório entre 0,10 e 0,35 segundos
            callback: this.ramboWalk,
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
        this.barraVidaRambo = this.add.rectangle(0, 0, 200, 10, 0xFF0000);
        this.barraVidaPersonagem = this.add.rectangle(0, 0, 100, 10, 0x0000CD);

        //Exibe o texto de balas disponives
        this.score = 30;
        this.bulletsCityText = this.add.text(16, 16, 'Balas: ' + this.score, {fontSize: '32px', fill: '#ffffff'})
            .setShadow(0, 0, '#000', 3)
            .setScrollFactor(0)
        this.setScore()

    }

    //Atualizar Quantidade de bala
    setScore() {
        this.bulletsCityText.setText('Balas: ' + this.score)
    }

    // Coletar Balas
    coletaBala(p, bala) {
        bala.destroy()
        this.bulletsCity.bulletQuantity += 1;
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
        } else if (this.controles.space.isDown && this.bulletsCity.bulletQuantity > 0) {
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
            this.scene.start("CemiterioPrinc", { pontos: this.pontuacaoAtual , nome: this.nomeCidade});
        }

        // if (this.personagem.x >= this.cidade.displayWidth - 5450) {
        //     this.scene.start("CemiterioPrinc");
        // }

        //Move mob1
        if (this.mob1.x < 215) {
            this.mob1.setVelocityX(200); // Move para a direita
            this.mob1.anims.play('andamob', true);
            this.mob1.flipX = false;
        } else if (this.mob1.x > 800) {
            this.mob1.setVelocityX(-200); // Move para a esquerda
            this.mob1.flipX = true;
        }

        //Move mob2
        if (this.mob2.x < 1515) {
            this.mob2.setVelocityX(200); // Move para a direita
            this.mob2.anims.play('andamob', true);
            this.mob2.flipX = false;
        } else if (this.mob2.x > 1900) {
            this.mob2.setVelocityX(-200); // Move para a esquerda
            this.mob2.flipX = true;
        }

        //Move mob3
        if (this.mob3.x < 3015) {
            this.mob3.setVelocityX(200); // Move para a direita
            this.mob3.anims.play('andamob', true);
            this.mob3.flipX = false;
        } else if (this.mob3.x > 3325) {
            this.mob3.setVelocityX(-200); // Move para a esquerda
            this.mob3.flipX = true;
        }

        //Move mob4
        if (this.mob4.x < 4515) {
            this.mob4.setVelocityX(200); // Move para a direita
            this.mob4.anims.play('andamob', true);
            this.mob4.flipX = false;
        } else if (this.mob4.x > 4975) {
            this.mob4.setVelocityX(-200); // Move para a esquerda
            this.mob4.flipX = true;
        }

        //Move mob5
        if (this.mob5.x < 825) {
            this.mob5.setVelocityX(150); // Move para a direita
            this.mob5.anims.play('andamob', true);
            this.mob5.flipX = false;
        } else if (this.mob5.x > 1500) {
            this.mob5.setVelocityX(-150); // Move para a esquerda
            this.mob5.flipX = true;
        }

        //Move mob6
        if (this.mob6.x < 1925) {
            this.mob6.setVelocityX(300); // Move para a direita
            this.mob6.anims.play('andamob', true);
            this.mob6.flipX = false;
        } else if (this.mob6.x > 3000) {
            this.mob6.setVelocityX(-300); // Move para a esquerda
            this.mob6.flipX = true;
        }
        //Move mob61
        if (this.mob61.x < 2125) {
            this.mob61.setVelocityX(300); // Move para a direita
            this.mob61.anims.play('andamob', true);
            this.mob61.flipX = false;
        } else if (this.mob61.x > 3000) {
            this.mob61.setVelocityX(-300); // Move para a esquerda
            this.mob61.flipX = true;
        }
        //Move mob62
        if (this.mob62.x < 2325) {
            this.mob62.setVelocityX(300); // Move para a direita
            this.mob62.anims.play('andamob', true);
            this.mob62.flipX = false;
        } else if (this.mob62.x > 3000) {
            this.mob62.setVelocityX(-300); // Move para a esquerda
            this.mob62.flipX = true;
        }

        //Move mob7
        if (this.mob7.x < 3350) {
            this.mob7.setVelocityX(150); // Move para a direita
            this.mob7.anims.play('andamob', true);
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

          //Rambo
        this.barraVidaRambo.x = this.boss.x - 10;
        this.barraVidaRambo.y = this.boss.y - 75;
        this.barraVidaRambo.width = this.vidaBoss;

        //josh
        this.barraVidaPersonagem.x = this.personagem.x - 10;
        this.barraVidaPersonagem.y = this.personagem.y - 75;
        this.barraVidaPersonagem.width = this.vidaPersonagem;

        this.bulletsCityText.setText('Balas: ' + (this.bulletsCity.bulletQuantity));
        this.pontuacaoText.setText(`Pontuação: ${this.pontuacaoAtual}`);
    }

    mobHitpersonagem(personagem, enemy) {
        if (personagem === this.personagem && this.vidaPersonagem > 0) {
            this.vidaPersonagem -= 6;

        }

    }

    bulletHitEnemy(enemy, bullet) {

        if (enemy === this.mob1 && this.vidamob1 > 0 ) {
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

  ramboShoot() {

        if (this.vidaBoss > 0) {
            // Calcula a posição de disparo do Rambo
            const shootX = this.boss.x - 50; // Ajuste conforme necessário
            const shootY = this.boss.y; // Ajuste conforme necessário
            // Faz o Rambo atirar
            if (this.personagem.x < this.boss.x) {
                this.boss.flipX = false;
                this.boss.anims.play('ramboParado');
                this.bulletsCity2.fireBullet(shootX, shootY, 'left'); // Ajuste a direção do tiro conforme necessário
            } else {
                this.boss.flipX = true;
                this.boss.anims.play('ramboParado');
                this.bulletsCity2.fireBullet(shootX, shootY, 'right'); // Ajuste a direção do tiro conforme necessário
            }
        }
    }

    ramboWalk() {
        //Move rambo
        if (this.vidaBoss > 0) {
            if (this.boss.x <= 5000) {
                this.boss.setVelocityX(200); // Move para a direita
                this.boss.flipX = true;
                this.boss.anims.play('andarRambo');
            } else if (this.boss.x >= 5400) {
                this.boss.setVelocityX(-200); // Move para a esquerda
                this.boss.flipX = false;
                this.boss.anims.play('andarRambo');
            }
        }
    }

    checkGameOver() {
        if (this.vidaPersonagem <= 0) {
          savePontosToAPI(this.nomeCidade, this.pontuacaoAtual)
          .then(response => console.log('Pontuação salva com sucesso: ', response))
          .catch(error => console.error('Erro ao salvar a pontuação: ', error));
            this.scene.start('GameOver'); 
        }
    }
}


class BullestCity2 extends Phaser.Physics.Arcade.Sprite {
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

class bulletsCity extends Phaser.Physics.Arcade.Group {
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

class bulletcity2 extends Phaser.Physics.Arcade.Sprite {
    constructor(scene, x, y) {
        super(scene, x, y, 'tirol');
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

class bulletsCity2 extends Phaser.Physics.Arcade.Group {
    constructor(scene, quantity2) {
        super(scene.physics.world, scene);

        this.bulletQuantity = quantity2; // Armazena a quantidade total de tiros
        this.createMultiple({
            frameQuantity: quantity2,
            key: 'tirol',
            active: false,
            visible: false,
            classType: bulletcity2
        });
    }

    fireBullet(x, y, direction) {
        const bulletcity2 = this.getFirstDead(false);

        if (bulletcity2) {
            bulletcity2.body.allowGravity = false;
            bulletcity2.fire(x, y, direction);
        }
    }
}