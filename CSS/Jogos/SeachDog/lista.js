var nome = '';
async function fetchDataFromAPI() {

  try{
  
    const response = await axios.get("https://back-end-seach-dog.wanderson-xavie.repl.co/pontos/buscarTodos");    
      return response.data;  
    }
    catch(error) {
      throw error;
    }
}

class Lista extends Phaser.Scene{
    init(data){
      nome = data.nome;
    }
  constructor(){
	super("Lista");
  }
 async create(){
        this.add.image(0,0,"tela1").setOrigin(0,0);

        setTimeout(()=>{
        var btnContinuar = this.add.image(380, 445, "btnContinuar").setScale(1.5).setOrigin(0,0);
        btnContinuar.setInteractive();
        btnContinuar.on("pointerdown", ()=>this.scene.start("Historia", { nome: nome}))
        },1500);
   
        const rankingText = this.add.text(400, 50, 'Ranking melhores jogadores', { fontSize: '40px', fill: '#FFFFFF' });
        rankingText.setOrigin(0.5); 
  
        let dados = await fetchDataFromAPI();


        this.textObjects = [];

dados.forEach((item, index) => {
    const text = this.add.text(10, 100 + index * 40, `${index+1} - ${item.nome}: ${item.pontos}`, { fontSize: '35px', fill: '#FFFFFF' });
    this.textObjects.push(text);
});
    }

}