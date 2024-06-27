
Portugês:

	Alunos: Emanuelly Parreira 
		Lucas Bomfim
		Vinicius Matheus
	
	** Trabalho: Simulador de um Sistema Detector de Incêndios Florestais **
	
	** Para compilar e executar: 
	
		Vá ao diretório onde se encontra o arquivo main.c e, no terminal, insira o comando <gcc main.c -o main>. Isso irá criar o executável, daí basta digitar ./main para executar o código.
	
	** Sobre o funcionamento do programa:
	
		O programa foi desenvolvido usando uma técnica multithreading, ou seja, usamos várias threads que executam simultaneamente as rotinas determinadas. Sendo assim, para simular um sistema detector de incêndios usamos 4 rotinas de thread diferentes:
	
			-Thread de Incêndio: responsável por gerar uma posição aleatória na matriz (que representa o mapa florestal) e na posição definida gerar um incêndio (plotar um '@'); também é responsável por imprimir o mapa enquanto o programa estiver executando.
			-Thread Sensor: é responsável por ficar monitorando nas posições vizinhas de cada thread sensor se existe algum '@'(que indica que há incêndio). Se o incêndio é identificado informações sobre o incêndio e sobre o censor são guardados em uma struct que representa cada sensor; além disso, quando o incêndio é identificado é chamado uma função auxiliar que é responsável por propagar essa informação pelos outros sensores vizinhos, até que se chegue nos sensores que se encontram na borda de cima, de baixo, da esquerda e da direita.
			-Thread Central: é responsável por ficar monitorando se os sensores da borda do mapa receberam alguma informação (mensagem de incêndio), quando sim, essa rotina irá gravar essa mensagem em um arquivo chamado "incendio.log", e também vai chamar a thread bombeiro para apagar o incendio (transforma '@' em '-')
			-Thread Bombeiro: é responsável por apagar o incendio identificado pelo sensor.

Inglês:

	Students: Emanuelly Parreira
	Lucas Bomfim
	Vinicius Matheus
	
	** Project: Forest Fire Detection System Simulator **
	
	** To compile and run:
	
	Navigate to the directory where the main.c file is located and, in the terminal, enter the command <gcc main.c -o main>. This will create the executable; then simply type ./main to run the code.
	
	** About the program:
	
	The program was developed using a multithreading technique, meaning we use multiple threads that execute the determined routines simultaneously. To simulate a fire detection system, we use four different thread routines:
	
	Fire Thread: responsible for generating a random position in the matrix (which represents the forest map) and at the defined position, generating a fire (plotting an '@'); it is also responsible for printing the map while the program is running.
	Sensor Thread: responsible for monitoring neighboring positions of each sensor thread to see if there is an '@' (indicating a fire). If a fire is detected, information about the fire and the sensor is stored in a struct representing each sensor; additionally, when a fire is detected, an auxiliary function is called to propagate this information to other neighboring sensors until it reaches the sensors on the top, bottom, left, and right edges.
	Central Thread: responsible for monitoring if the sensors at the map's edges have received any information (fire message); if so, this routine will record this message in a file called "incendio.log", and will also call the firefighter thread to extinguish the fire (transform '@' into '-').
	Firefighter Thread: responsible for extinguishing the fire identified by the sensor.
