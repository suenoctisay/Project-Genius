// PROJETO GENIUS - PARA ARDUINO

// definição dos botões
#define btn4 10
#define btn3 11
#define btn2 12
#define btn1 13

// definição do buzzer e LEDs
#define buzzer 6
#define verde 5
#define amarelo 4
#define vermelho 3
#define azul 2


// definição dos botões como "x" e verificação das etapas
bool x1, x2, x3, x4;
int varEstado , varErro=0 , varFinal=0 , derrota=1 , vitoria=1 , estadoSequencia=0;

// definição das entradas e saídas de dados
void setup(){
    varEstado=0;

// LEDs e buzzer
    pinMode(verde, OUTPUT);
    pinMode(amarelo, OUTPUT);
    pinMode(vermelho, OUTPUT);
  	pinMode(azul, OUTPUT);
    pinMode(buzzer, OUTPUT);

// botões
    pinMode(btn1, INPUT);
    pinMode(btn2, INPUT);
    pinMode(btn3, INPUT);
  	pinMode(btn4, INPUT);
}

void loop(){
// leitura e atribuição dos botões    
    x4 = digitalRead(btn4);
    x3 = digitalRead(btn3);
    x2 = digitalRead(btn2);
    x1 = digitalRead(btn1);

// começo do jogo (apertar botão)
    switch(varEstado){
        case 0:
      		digitalWrite(verde,LOW);
            digitalWrite(amarelo,LOW);
            digitalWrite(vermelho,LOW);
      		digitalWrite(azul,LOW);
            if(x1 == 1 || x2 == 1 || x3 == 1 || x4 == 1){
              	digitalWrite(verde,HIGH);
                    delay(200);
                digitalWrite(verde,LOW);
                    delay(200);
                digitalWrite(amarelo,HIGH);
                    delay(200);
                digitalWrite(amarelo,LOW);
                    delay(200);
                digitalWrite(vermelho,HIGH);
                    delay(200);
                digitalWrite(vermelho,LOW);
                    delay(200);
              	digitalWrite(azul,HIGH);
                    delay(200);
                digitalWrite(azul,LOW);
                    delay(200);
                varEstado = 1;
            break;
            }
        break;

// 1ª (primeira) rodada do jogo
        case 1: 
// amarelo
// x2
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
            varErro = 0;
            while(true){
                x4 = digitalRead(btn4);
                x3 = digitalRead(btn3);
                x2 = digitalRead(btn2);
                x1 = digitalRead(btn1);
                if(x2 == 1){
                    break;
                }else if(x1 == 1 || x3 == 1 || x4 == 1){
                    varErro = 1;
                  	break;
                }
            }if(varErro == 1 ){
                varEstado = 12;  
            }else{
                varEstado = 2;
            }
        break;

// 2ª (segunda) rodada do jogo
// amarelo e vermelho | x2, x3
        case 2: 
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
                delay(500);
            digitalWrite(vermelho,HIGH); // pisca x3
                delay(500);
            digitalWrite(vermelho,LOW);
            varErro = 0;
            varFinal = 0;
            estadoSequencia = 0;
            while(true){
                 if(varFinal == 1){
                    break;
                }
                x4 = digitalRead(btn4);
                x3 = digitalRead(btn3);
                x2 = digitalRead(btn2);
                x1 = digitalRead(btn1);
                switch(estadoSequencia){
                    case 0:
                        if(x2 == 1 ){
                            estadoSequencia = 1;
                            delay(500);
                        }else if(x1 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 1:
                        if(x3 == 1){
                            varFinal= 1;
                        }else if(x1 == 1 || x2 == 1 || x4 == 1){
                            varErro = 1;
                          	varFinal = 1;
                        }
                    break;
        

                }
            }if(varErro == 1){
                varEstado = 12;
            }else{  
                varEstado = 3;
            }
        break;

// 3ª (terceira) rodada do jogo
// amarelo, vermelo e azul | x2, x3, x4
        case 3: 
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
                delay(500);
            digitalWrite(vermelho,HIGH); // pisca x3
                delay(500);
            digitalWrite(vermelho,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW);
            varErro = 0;
            varFinal = 0;
            estadoSequencia = 0;
            while(true){
                if(varFinal == 1){
                    break;
                }
                x4 = digitalRead(btn4);
                x3 = digitalRead(btn3);
    			x2 = digitalRead(btn2);
    			x1 = digitalRead(btn1);
                switch(estadoSequencia){
                    case 0:
                        if(x2 == 1 ){
                            estadoSequencia = 1;
                            delay(500);
                        }else if(x1 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 1:
                        if(x3 == 1){
                            estadoSequencia = 2;
                            delay(500);
                        }else if(x1 == 1 || x2 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 2:
                        if(x4 == 1){
                            varFinal = 1;
                        }else if(x1 == 1 || x2 == 1 || x3 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                }
            }if(varErro == 1){
                varEstado = 12;
            }else{  
                varEstado = 4;
            }
        break;

// 4ª (quarta) rodada do jogo
// amarelo, vermelho, azul e verde | x2, x3, x4, x1
        case 4: 
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
                delay(500);
            digitalWrite(vermelho,HIGH); // pisca x3
                delay(500);
            digitalWrite(vermelho,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            varErro = 0;
            varFinal = 0;
            estadoSequencia = 0;
            while(true){
                if(varFinal == 1){
                    break;
                }
                x4 = digitalRead(btn4);
                x3 = digitalRead(btn3);
    			x2 = digitalRead(btn2);
    			x1 = digitalRead(btn1);
                switch(estadoSequencia){
                    case 0:
                        if(x2 == 1 ){
                            estadoSequencia = 1;
                            delay(500);
                        }else if(x1 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 1:
                        if(x3 == 1){
                          	estadoSequencia = 2;
                            delay(500);
                        }else if(x1 == 1 || x2 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 2:
                        if(x4 == 1){
                            estadoSequencia = 3;
                            delay(500);
                        }else if(x1 == 1 || x2 == 1 || x3 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 3:
                        if(x1 == 1){
                            varFinal = 1;
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                }
            }if(varErro == 1){
                varEstado = 12;
            }else{  
                varEstado = 5;
            }
        break; 

// 5ª (quinta) rodada do jogo
// amarelo, vermelho, azul, verde e verde | x2, x3, x4, x1, x1
        case 5: 
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
                delay(500);
            digitalWrite(vermelho,HIGH); // pisca x3
                delay(500);
            digitalWrite(vermelho,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1 
                delay(500);
            digitalWrite(verde,LOW);
            varErro = 0;
            varFinal = 0;
            estadoSequencia = 0;
            while(true){
                if(varFinal == 1){
                    break;
                }
                x4 = digitalRead(btn4);
                x3 = digitalRead(btn3);
    			x2 = digitalRead(btn2);
    			x1 = digitalRead(btn1);
                switch(estadoSequencia){
                    case 0:
                        if(x2 == 1 ){
                            estadoSequencia = 1;
                            delay(500);
                        }else if(x1 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 1:
                        if(x3 == 1){
                            estadoSequencia = 2;
                            delay(500);
                        }else if(x1 == 1 || x2 == 1 || x4 == 1 ){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 2:
                        if(x4 == 1){
                            estadoSequencia = 3;
                            delay(500);
                        }else if(x1 == 1 || x2 == 1 || x3 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 3:
                        if(x1 == 1){
                            estadoSequencia = 4;
                            delay(500);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 4:
                        if(x1 == 1){
                            varFinal = 1;
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                }
            }if(varErro == 1){
                varEstado = 12;
            }else{  
                varEstado = 6;
            }
        break;

// 6ª (sexta) rodada do jogo
// amarelo, vermelho, azul, verde, verde e azul | x2, x3, x4, x1, x1, x4
        case 6:
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
                delay(500);
            digitalWrite(vermelho,HIGH); // pisca x3
                delay(500);
            digitalWrite(vermelho,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW); 
            varErro = 0;
            varFinal = 0;
            estadoSequencia = 0;
            while(true){
                if(varFinal == 1){
                    break;
                }
                x4 = digitalRead(btn4);
                x3 = digitalRead(btn3);
    			x2 = digitalRead(btn2);
    			x1 = digitalRead(btn1);
                switch(estadoSequencia){
                    case 0:
                        if(x2 == 1 ){
                            estadoSequencia = 1;
                            delay(500);
                        }else if(x1 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 1:
                        if(x3 == 1){
                            estadoSequencia = 2;
                            delay(500);
                        }else if(x1 == 1 || x2 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 2:
                        if(x4 == 1){
                            estadoSequencia = 3;
                            delay(500);
                        }else if(x1 == 1 || x2 == 1 || x3 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 3:
                        if(x1 == 1){
                            estadoSequencia = 4;
                            delay(500);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 4:
                        if(x1 == 1){
                            estadoSequencia = 5;
                            delay(500);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 5:
                        if(x4 == 1){
                            varFinal = 1 ;
                            delay(500);
                        }else if(x1 == 1 || x2 == 1 || x3 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                }
            }if(varErro == 1){
                varEstado = 12;
            }else{  
                varEstado = 7;
            }
        break;

// 7ª (sétima) rodada do jogo
// amarelo, vermelho, azul, verde, verde, azul e amarelo | x2, x3, x4, x1, x1, x4, x2
        case 7: 
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
                delay(500);
            digitalWrite(vermelho,HIGH); // pisca x3
                delay(500);
            digitalWrite(vermelho,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW);
                delay(500);
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
            varErro = 0;
            varFinal = 0;
            estadoSequencia = 0;
            while(1){
                if(varFinal == 1){
                    break;
                }
                x4 = digitalRead(btn4);
                x3 = digitalRead(btn3);
    			x2 = digitalRead(btn2);
    			x1 = digitalRead(btn1);
                switch(estadoSequencia){
                    case 0:
                        if(x2 == 1 ){
                            estadoSequencia = 1;
                            delay(500);
                        }else if(x1 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 1:
                        if(x3 == 1){
                            estadoSequencia = 2;
                            delay(500);
                        }else if(x1 == 1 || x2 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 2:
                        if(x4 == 1){
                            estadoSequencia = 3;
                            delay(500);
                        }else if(x1 == 1 || x2 == 1 || x3 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 3:
                        if(x1 == 1){
                            estadoSequencia = 4;
                            delay(500);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 4:
                        if(x1 == 1){
                            estadoSequencia = 5;
                            delay(500);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 5:
                        if(x4 == 1){
                            estadoSequencia = 6;
                            delay(500);
                        }else if(x1 == 1 || x2 == 1 || x3 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 6:
                        if(x2 == 1){
                            varFinal = 1;
                        }else if(x1 == 1 || x2 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                }
            }if(varErro == 1){
                varEstado = 12;
            }else{  
                varEstado = 8;
            }
        break;

// 8ª (oitava) rodada do jogo
// amarelo, vermelho, azul, verde, verde, azul, amarelo e verde | x2, x3, x4, x1, x1, x4, x2, x1
        case 8: 
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
                delay(500);
            digitalWrite(vermelho,HIGH); // pisca x3
                delay(500);
            digitalWrite(vermelho,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW);
                delay(500);
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
            varErro = 0;
            varFinal = 0;
            estadoSequencia = 0;
            while(1){
                if(varFinal == 1){
                    break;
                }
                x4 = digitalRead(btn4);
                x3 = digitalRead(btn3);
    			x2 = digitalRead(btn2);
    			x1 = digitalRead(btn1);
                switch(estadoSequencia){
                    case 0:
                        if(x2 == 1 ){
                            estadoSequencia = 1;
                            delay(1000);
                        }else if(x1 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 1:
                        if(x3 == 1){
                            estadoSequencia = 2;
                            delay(1000);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 2:
                        if(x4 == 1){
                            estadoSequencia = 3;
                            delay(1000);
                        }else if(x1 == 1 || x2 == 1 || x3 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 3:
                        if(x1 == 1){
                            estadoSequencia = 4;
                            delay(1000);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 4:
                        if(x1 == 1){
                            estadoSequencia = 5;
                            delay(1000);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 5:
                        if(x4 == 1){
                            estadoSequencia = 6;
                            delay(1000);
                        }else if(x1 == 1 || x2 == 1 || x3 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 6:
                        if(x2 == 1){
                            estadoSequencia = 7;
                            delay(1000);
                        }else if(x1 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 7:
                        if(x1 == 1){
                            varFinal = 1;
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                }
            }if(varErro == 1){
                varEstado = 12;
            }else{  
                varEstado = 9;
            }
        break;

// 9ª (nona) rodada do jogo
// amarelo, vermelho, azul, verde, verde, azul, amarelo, verde e vermelho | x2, x3, x4, x1, x1, x4, x2, x1, x3
        case 9: 
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
                delay(500);
            digitalWrite(vermelho,HIGH); // pisca x3
                delay(500);
            digitalWrite(vermelho,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW);
                delay(500);
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(vermelho,HIGH); // pisca x3
                delay(500);
            digitalWrite(vermelho,LOW);
            varErro = 0;
            varFinal = 0;
            estadoSequencia = 0;
            while(1){
                if(varFinal == 1){
                    break;
                }
                x4 = digitalRead(btn4);
                x3 = digitalRead(btn3);
    			x2 = digitalRead(btn2);
    			x1 = digitalRead(btn1);
                switch(estadoSequencia){
                    case 0:
                        if(x2 == 1 ){
                            estadoSequencia = 1;
                            delay(1000);
                        }else if(x1 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break; 
                    case 1:
                        if(x3 == 1){
                            estadoSequencia = 2;
                            delay(1000);
                        }else if(x1 == 1 || x2 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 2:
                        if(x4 == 1){
                            estadoSequencia = 3;
                            delay(1000);
                        }else if(x1 == 1 || x2 == 1 || x3 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 3:
                        if(x1 == 1){
                            estadoSequencia = 4;
                            delay(1000);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 4:
                        if(x1 == 1){
                            estadoSequencia = 5;
                            delay(1000);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 5:
                        if(x4 == 1){
                            estadoSequencia = 6;
                            delay(1000);
                        }else if(x1 == 1 ||x2 == 1 || x3 == 1 ){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 6:
                        if(x2 == 1){
                            estadoSequencia = 7;
                            delay(1000);
                        }else if(x1 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 7:
                        if(x1 == 1){
                            estadoSequencia = 8;
                            delay(1000);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 8:
                        if(x3 == 1){
                            varFinal = 1;
                        }else if(x1 == 1 || x2 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                }
            }if(varErro == 1){
                varEstado = 12;
            }else{  
                varEstado = 10;
            }
        break;

// 10ª (décima) rodada do jogo
// amarelo, vermelho, azul, verde, verde, azul, amarelo, verde, vermelho e verde | x2, x3, x4, x1, x1, x4, x2, x1, x3, x1
        case 10: 
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
                delay(500);
            digitalWrite(vermelho,HIGH); // pisca x3
                delay(500);
            digitalWrite(vermelho,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(azul,HIGH); // pisca x4
                delay(500);
            digitalWrite(azul,LOW);
                delay(500);
            digitalWrite(amarelo,HIGH); // pisca x2
                delay(500);
            digitalWrite(amarelo,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
                delay(500);
            digitalWrite(vermelho,HIGH); // pisca x3
                delay(500);
            digitalWrite(vermelho,LOW);
                delay(500);
            digitalWrite(verde,HIGH); // pisca x1
                delay(500);
            digitalWrite(verde,LOW);
            varErro = 0;
            varFinal = 0;
            estadoSequencia = 0;
            while(1){
                if(varFinal == 1){
                    break;
                }
                x4 = digitalRead(btn4);
                x3 = digitalRead(btn3);
    			x2 = digitalRead(btn2);
    			x1 = digitalRead(btn1);
                switch(estadoSequencia){
                    case 0:
                        if(x2 == 1 ){
                            estadoSequencia = 1;
                            delay(1000);
                        }else if(x1 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 1:
                        if(x3 == 1){
                            estadoSequencia = 2;
                            delay(1000);
                        }else if(x1 == 1 || x2 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 2:
                        if(x4 == 1){
                            estadoSequencia = 3;
                            delay(1000);
                        }else if(x1 == 1 || x2 == 1 || x3 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 3:
                        if(x1 == 1){
                            estadoSequencia = 4;
                            delay(1000);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 4:
                        if(x1 == 1){
                            estadoSequencia = 5;
                            delay(1000);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 5:
                        if(x4 == 1){
                            estadoSequencia = 6;
                            delay(1000);
                        }else if(x1 == 1 || x2 == 1 || x3 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 6:
                        if(x2 == 1){
                            estadoSequencia = 7;
                            delay(1000);
                        }else if(x1 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 7:
                        if(x1 == 1){
                            estadoSequencia = 8;
                            delay(1000);
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 8:
                        if(x3 == 1){
                            estadoSequencia = 9;
                            delay(1000);
                        }else if(x1 == 1 || x2 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                    case 9:
                        if(x1 == 1){
                            varFinal = 1;
                        }else if(x2 == 1 || x3 == 1 || x4 == 1){
                            varErro = 1;
                            varFinal = 1;
                        }
                    break;
                }
            }if(varErro == 1){
                varEstado = 12;
            }else{  
                varEstado = 11;
            }
        break;

// case - vitória
        case 11:  
            x4 = digitalRead(btn4);
            x3 = digitalRead(btn3); 
            x2 = digitalRead(btn2);
            x1 = digitalRead(btn1);    
			while(vitoria <= 3){ 
				varErro = 0;
				digitalWrite(verde,HIGH);
				delay(1000);
				digitalWrite(verde,LOW);
				delay(500);
				vitoria++;
			}if(varErro == 0){
				varEstado = 0;
				break;
			}
        break;
          
// case - derrota
        case 12: 
            x4 = digitalRead(btn4); 
            x3 = digitalRead(btn3); 
            x2 = digitalRead(btn2);
            x1 = digitalRead(btn1);    
            while(derrota <= 3){ 
                varErro = 0;
                digitalWrite(vermelho,HIGH);
                delay(1000);
                digitalWrite(vermelho,LOW);
                delay(500);
                derrota++;
                if(derrota == 4){
                    digitalWrite(buzzer,HIGH);
                    delay(1000);
                    digitalWrite(buzzer,LOW);
                }   
            }if(varErro == 0){
                varEstado = 0;
				break;    
            }
        break;
    }
}