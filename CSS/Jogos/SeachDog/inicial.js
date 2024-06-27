let nomeUsuario;
let inicialScene; // variável que irá armazenar uma referência à cena 'Inicial'

document.getElementById('usuarioForm').addEventListener('submit', function(e) {
    e.preventDefault();
    nomeUsuario = document.getElementById('nomeUsuario').value;
    document.getElementById('entradaUsuario').style.display = 'none'; // Esconder o formulário após submeter

    if (inicialScene) {
        inicialScene.scene.start('Inicial', { nome: nomeUsuario }); // Use a referência para iniciar a cena
    }
});

class Inicial extends Phaser.Scene {
    constructor() {
        super("Inicial");
    }

    init() {
        // Salvar uma referência à cena na variável quando ela é iniciada
        inicialScene = this;
    }

  preload(){
    this.load.audio("beatit", 'assets/it.ogg');
    this.load.image("tela1", "assets/tela1.png");
    this.load.image("tela2", "assets/tela2.png");
    this.load.image("tela3", "assets/tela3.png");
    this.load.image("btnPlay", "assets/btnplay.png")
    
    this.load.image("btnContinuar", "assets/botoes/continuar.png")
    this.load.image("btnTentar", "assets/botoes/tentar-novamente.png")
    this.load.image("telaInstrucoes", "assets/telas/instrucoes.png");
    this.load.image("telaSobre", "assets/telas/sobre.png");
    
    this.load.image("telaHistoria", "assets/telahistoria.png");
    this.load.image("btnAceito", "assets/btnAceito.png");
    this.load.image("floresta", "assets/background-floresta.png");
    this.load.spritesheet('personagem','assets/josh.png',{frameWidth:125, frameHeight:168.2});
    this.load.image("plataformacid", "assets/plataformacid.png");
    //floresta
    this.load.image("plataformafloresta", "assets/plataformafloresta2.png");
    this.load.spritesheet("ghostface", "assets/ghostface.png",{frameWidth:187.5, frameHeight:170});
    this.load.spritesheet("esqueletoflo", "assets/esqueletoflo.png",{frameWidth:100, frameHeight:100});
    //cidade
    this.load.image("cidade", "assets/cidadefull.png");
    this.load.image("cidadePrinc", "assets/cidade-princ.png");
    this.load.spritesheet('personagem','assets/josh.png',{frameWidth:125, frameHeight:168});
    this.load.image("plataformacid", "assets/plataformacid.png");
    this.load.spritesheet("rambo", "assets/rambo.png",{frameWidth:106, frameHeight:110});
    this.load.spritesheet("esqueletocity", "assets/esqueletocity.png",{frameWidth:200, frameHeight:120});
    //cemiterio
    this.load.image("cemiterioimgPrinc", "assets/cemiterio/backgroundCemiterio.png");
    this.load.image("cemiterio", "assets/cemiterio/cemiteriofull.png");
    this.load.spritesheet("mtfantasma", "assets/cemiterio/motoqueirofantasma.png",{frameWidth:105, frameHeight:88});
    this.load.image("Tfinal", 'assets/endcena.png');
    this.load.image("Over", 'assets/gameOver.png');
    this.load.image("pcemiterio", "assets/cemiterio/plataformaCemiterio.png");
    //ataque
    this.load.image("tiro", 'assets/tiro.png');
    this.load.image("fogo", 'assets/cemiterio/fogoMotoqueiro.png');
    this.load.image("tirol", 'assets/tirol.png');
    this.load.image("bala", 'assets/colete_bullet.png');
    this.load.spritesheet("faca", 'assets/faca.png',{frameWidth:116.5, frameHeight:75});
    this.load.spritesheet("mob1city", 'assets/mob1city.png',{frameWidth:375, frameHeight:380});
  }

  create(){
    this.music =  this.sound.add("beatit");
    this.music.play({volume: 0.08, loop: true});
    this.add.image(0,0,"tela1").setOrigin(0,0);
    setTimeout(()=>{
            this.add.image(0,0,"tela2").setOrigin(0,0);
    },1500);
        setTimeout(()=>{
            this.add.image(0,0,"tela3").setOrigin(0,0);
    },2500);
    setTimeout(()=>{
          var btnPlay = this.add.image(380, 210, "btnPlay").setOrigin(0,0);
          btnPlay.setInteractive();
          btnPlay.on("pointerdown", ()=>this.scene.start("Instrucoes", { nome: nomeUsuario}));
    },3500);
  }
  
}
