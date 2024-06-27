var game;

window.onload = function()
  {
    let gameConfig = {
      scale:{
        width:928,
        height:591,
        autoCenter:Phaser.Scale.CENTER_BOTH
      },
      physics:{
        default: 'arcade',
          arcade:{
          gravity: {y: 900},
          debug: false
          }
      },
      scene:[Inicial, Instrucoes, Sobre, Lista, Historia, FlorestaPrinc, CidadePrinc, CemiterioPrinc, FinalCena, GameOver]
    };
    game = new Phaser.Game(gameConfig);

    window.focus();
  }
  
