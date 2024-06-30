
    //estrutura de um item
    typedef struct {
        char desc[100];
        int nivel;
        int dano;
        int resist;
    } Item;

    //impressao de item
    void imprime_item(Item I){
        printf("\n descricao: %s \n nivel: %d \n dano: %d \n resist: %d \n",I.desc,I.nivel,I.dano,I.resist);
    }




