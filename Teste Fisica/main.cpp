#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include <time.h>
using namespace std;

#define ESC    	27


unsigned char *T1,*T2, *T3, *T4, *T5, *T5M,*T6, *T6M, *run[6], *runmask[6], *jump[3], *jumpmask[3];
char tecla;
int pg = 1;


void PreparaImg(int Tam, unsigned char *Img, unsigned char *Msk) {
// Tam � o tamanho dos ponteiros da imagem e da m�scara
// Img � o ponteiro que aponta para o vetor que cont�m a imagem capturada com getimage(..)
// Msk � o ponteiro que ser� transformado em m�scara
  int i;
  unsigned char B, G, R;
  B = Img[24];
  G = Img[25];
  R = Img[26];
  for(i=24; i < Tam; i+=4) {
    if (Img[i]==B and Img[i+1]==G and Img[i+2]==R) {
      Img[i] = 0;
      Img[i+1] = 0;
      Img[i+2] = 0;
      Msk[i] = 255;
      Msk[i+1] = 255;
      Msk[i+2] = 255;
    }
    else {
      Msk[i] = 0;
      Msk[i+1] = 0;
      Msk[i+2] = 0;
    }
  }
}

struct coords{
	int x,y;
};
//F coordenadas do jogador
//A coordenadas do Anubis
//plat  coordenadas das plataformas
//item coordenadas dos itens
//B1 e B2 coordenadas do fundo
coords plat[20], F, A, B1, B2, espaco, item[20];


void desenho(){
	int Tam = imagesize(0, 0, 49, 49);
	int Tam2 = imagesize(0, 0, 229, 99);
	int Tam3 = imagesize(0,0,1279,133);
	int Tam4 = imagesize(0,0,1999,799);
	int Tam5 = imagesize(0,0,40,74);
	int Tam6 = imagesize(0,0,169,599);
//	int sprtam = imagesize(0,0,234,224);
  	T1 = (unsigned char *)malloc(Tam);
  	T2 = (unsigned char *)malloc(Tam2);
  	T3 = (unsigned char *)malloc(Tam3);
  	T4 = (unsigned char *)malloc(Tam4);
  	T5 = (unsigned char *)malloc(Tam5);
  	T5M = (unsigned char *)malloc(Tam5);
  	T6 = (unsigned char *)malloc(Tam6);
  	T6M = (unsigned char *)malloc(Tam6);
  	
//	for (int i=0;i<6;i++){
//		run[i] = (unsigned char *)malloc(sprtam);
//  		runmask[i] = (unsigned char *)malloc(sprtam);
//  	}
//  	for (int i=0;i<3;i++){
//		jump[i] = (unsigned char *)malloc(sprtam);
//  		jumpmask[i] = (unsigned char *)malloc(sprtam);
//  	}
  	
  	cleardevice();
  	setactivepage(10);
  	
  	readimagefile(".\\Sprites\\Personagem\\teste.bmp", 0, 0, 49, 49);
  	getimage(0, 0, 49, 49, T1); // captura para o ponteiro P
  	cleardevice();
  	
  	readimagefile(".\\Sprites\\Objetos\\plataforma_rect.bmp", 0, 0, 229, 99);
  	getimage(0, 0, 229, 99, T2); // captura para o ponteiro P
  	cleardevice();
  	
  	readimagefile(".\\Sprites\\Objetos\\chao.bmp", 0,0,1279,133);
  	getimage(0,0,1279,133, T3); // captura para o ponteiro P
  	cleardevice();
  	
  	readimagefile(".\\Sprites\\Fundo\\background.bmp", 0,0,1999,799);
  	getimage(0,0,1999,799, T4); // captura para o ponteiro P
  	cleardevice();
  	
  	readimagefile(".\\Sprites\\Objetos\\ankh.bmp", 0,0,40,74);
  	getimage(0,0,40,74, T5); // captura para o ponteiro P
  	getimage(0,0,40,74, T5M);
  	PreparaImg(Tam5, T5, T5M);
  	cleardevice();
  	
  	readimagefile(".\\Sprites\\Personagem\\anubis.bmp", 0,0,169,599);
  	getimage(0,0,169,599, T6); // captura para o ponteiro P
  	getimage(0,0,169,599, T6M);
  	PreparaImg(Tam6, T6, T6M);
  	cleardevice();
  	
//  	readimagefile(".\\Sprites\\Personagem\\run1.bmp", 0,0,234,224);
//  	getimage(0,0,234,224, run[0]); // captura para o ponteiro P
//  	getimage(0,0,234,224, runmask[0]);
//  	PreparaImg(sprtam, run[0], runmask[0]);
//  	cleardevice();
//  	
//  	readimagefile(".\\Sprites\\Personagem\\run2.bmp", 0,0,234,224);
//  	getimage(0,0,234,224, run[1]); // captura para o ponteiro P
//  	getimage(0,0,234,224, runmask[1]);
//  	PreparaImg(sprtam, run[1], runmask[1]);
//  	cleardevice();
//  	
//  	readimagefile(".\\Sprites\\Personagem\\run3.bmp", 0,0,234,224);
//  	getimage(0,0,234,224, run[2]); // captura para o ponteiro P
//  	getimage(0,0,234,224, runmask[2]);
//  	PreparaImg(sprtam, run[2], runmask[2]);
//  	cleardevice();
//  	
//  	readimagefile(".\\Sprites\\Personagem\\run4.bmp", 0,0,234,224);
//  	getimage(0,0,234,224, run[3]); // captura para o ponteiro P
//  	getimage(0,0,234,224, runmask[3]);
//  	PreparaImg(sprtam, run[3], runmask[3]);
//  	cleardevice();
//  	
//  	readimagefile(".\\Sprites\\Personagem\\run5.bmp", 0,0,234,224);
//  	getimage(0,0,234,224, run[4]); // captura para o ponteiro P
//  	getimage(0,0,234,224, runmask[4]);
//  	PreparaImg(sprtam, run[4], runmask[4]);
//  	cleardevice();
//  	
//  	readimagefile(".\\Sprites\\Personagem\\run6.bmp", 0,0,234,224);
//  	getimage(0,0,234,224, run[5]); // captura para o ponteiro P
//  	getimage(0,0,234,224, runmask[5]);
//  	PreparaImg(sprtam, run[5], runmask[5]);
//  	cleardevice();
//  	
//  	readimagefile(".\\Sprites\\Personagem\\jump1.bmp", 0,0,234,224);
//  	getimage(0,0,234,224, jump[0]); // captura para o ponteiro P
//  	getimage(0,0,234,224, jumpmask[0]);
//  	PreparaImg(sprtam, jump[0], jumpmask[0]);
//  	cleardevice();
//  	
//  	readimagefile(".\\Sprites\\Personagem\\jump2.bmp", 0,0,234,224);
//  	getimage(0,0,234,224, jump[1]); // captura para o ponteiro P
//  	getimage(0,0,234,224, jumpmask[1]);
//  	PreparaImg(sprtam, jump[1], jumpmask[1]);
//  	cleardevice();
//  	
//  	readimagefile(".\\Sprites\\Personagem\\jump3.bmp", 0,0,234,224);
//  	getimage(0,0,234,224, jump[2]); // captura para o ponteiro P
//  	getimage(0,0,234,224, jumpmask[2]);
//  	PreparaImg(sprtam, jump[2], jumpmask[2]);
//  	cleardevice();
  	
}

void criaPlat() {
	espaco.y = 75 ;
	for (int i=0;i<10;i++){
		plat[i].x = 200 + rand()%1700;;
		plat[i].y = espaco.y;
		espaco.y = espaco.y + 175;
		if (espaco.y >= 750) espaco.y = 75;
	}
}
void criaItem(){
	for (int i=0;i<10;i++){
		item[i].x = plat[i].x + 95;
		item[i].y = plat[i].y - 75;
	}
}
int main()  { 
	initwindow(1920, 800);
	srand(time(0));
	int pontuacao = 0;
	int s = 0;
	
/* --------- Booleanas para verifica��o ---------  */
	bool onAir = false;
	bool onTop = false;
	
/* --------- Posi��o inicial do personagem ---------  */
	F.x = 300;
	F.y = 660;
/* --------- Posi��o inicial do Anubis ---------  */
	A.x = 0;
	A.y = 110;
/* --------- Posi��o inical do Background ---------  */
	B1.x = 0;
	B2.x = 1900;
	
/* --------- Posi��o das plataformas e dos itens ---------  */
	criaPlat();
	criaItem();

/* --------- Vari�veis para auxiliar na f�sica ---------  */
    float dx=5,dy=0;
	float px = -5;
/* --------- Preparas as imagens ---------  */
	desenho();

/* --------- Espa�amento minimo entre as plataformas ---------  */
  	espaco.y = 75;
	espaco.x = 75;	
 	 while(tecla != ESC) {
    	
    	if (pg == 1) pg = 2; else pg=1;
    	setactivepage(pg);
    	
    	pontuacao += 10;
		cleardevice();
		
		setbkcolor(WHITE);
		
/* --------- Background e movimenta��o ---------  */
		putimage(B1.x,0,T4, AND_PUT);
		putimage(B1.x,0,T4, OR_PUT);
//		putimage(B2.x,0,T4, AND_PUT);
//		putimage(B2.x,0,T4, OR_PUT);
//		B1.x += -10;
//		B2.x += -10;
//		printf("%d", B1.x);
//		if (B1.x <= -2000){
//			B1.x = 1900;
//		}
//
//		if (B2.x <= -2000){
//			B2.x = 1900;
//		}
		
		
		
		
		
		
/* --------- F�sica do personagem ---------  */	
		dy+=1;
    	F.y+=dy;
    	
    	
    	if (F.y >= 660){
    		F.y = 660;
    		onAir = false;
		}
    	
    	
    	if(F.y <= 470 && onTop == false)
    		onAir = true;
    		
/* --------- Movimenta��o do personagem ---------  */
//    	if(GetKeyState(VK_RIGHT)&0x80 && F.x < 200) F.x += dx;
//    	if(GetKeyState(VK_LEFT)&0x80 && F.x > 100) F.x -= dx;
    	if ((GetKeyState(VK_SPACE)&0x80 && onAir == false) || (GetKeyState(VK_UP)&0x80 && onAir == false)){
    		dy = -20;
    		onTop = false;
			onAir = true;
		} 
		
		if (GetKeyState(VK_DOWN)&0x80 && onAir == true){
			dy += 2;	
		}
		
		if (GetKeyState(VK_SHIFT)&0x80){
			printf("X = %d\n", F.x);
			printf("Y = %d\n", F.y);
		}
		
/* --------- Plataforma ---------  */
		//Cria novas plataformas e itens
		for (int i=0;i<10;i++){
			if (plat[i].x + 230 <= 0){
					plat[i].x = 1920 + (rand()%500) ;
					plat[i].y = espaco.y;
					espaco.y = espaco.y + 175;
					if (espaco.y >= 750) espaco.y = 75;
					item[i].x = plat[i].x + 95;
					item[i].y = plat[i].y - 75;
			}
		}
		
		//Colis�o com o topo das plataformas
    	for (int i=0;i<10;i++){
     		if ((F.x+45>plat[i].x) && (F.x+15<plat[i].x+230) && (F.y+50>plat[i].y ) && (F.y+25<plat[i].y+100) && (dy>0)){
      			F.y = plat[i].y -50;
      			dy = 0;
      			onAir = false;
      			onTop = true;
      			
			  }
			
					
      }
      	
      	//Colis�o com a base das plataformas
      	for (int i=0;i<10;i++){
      		if ((F.y <= plat[i].y+100) && (F.x+50>=plat[i].x) && (F.x<=plat[i].x+230) && (F.y+50>=plat[i].y) && (dy<0)){ 
      			if (F.y > plat[i].y + 80 ){
      				F.y = plat[i].y + 101;
      				dy = 3;
      				
      			}
			}
      		
		}
		
		//Colis�o com a borda da plataforma
		for (int i=0;i<10;i++){
			if (((F.x + 50 > plat[i].x) && (F.y > plat[i].y) && (F.y < plat[i].y+100))){
				if ((F.x + 50 < plat[i].x + 230)){
					F.x = plat[i].x - 50;
				}

			}
		}
		
//		for (int i=0;i<10;i++){
//			if ((F.x + 50 > plat[i].x) && (F.x < plat[i].x+230) && (F.y > plat[i].y) && (F.y < plat[i].y+100) && (GetKeyState(VK_LEFT)&0x80)){
//				F.x = plat[i].x + 230;
//			}
//
//		}

/* --------- Items ---------  */	
		for (int i=0;i<10;i++){
			if (((F.x+50 > item[i].x) && (F.y > item[i].y) && (F.y < item[i].y+40)) || ((F.x+45>item[i].x) && (F.x+15<item[i].x+40) && (F.y+50>item[i].y ) && (F.y+25<item[i].y+75) && (dy>0))){
				item[i].x = -100;
				item[i].y = -100;
				pontuacao += 100;
			}
			
		}
/* --------- Colis�o com Anubis ---------  */	
		if (F.x <= A.x + 100){
			printf("Perdeste");
		}
/* --------- Desenhos e movimenta��o ---------  */
    	//Desenho das plataformas
    	for (int i=0;i<10;i++)	
    	{
    		putimage(plat[i].x,plat[i].y,T2, AND_PUT);
    		putimage(plat[i].x,plat[i].y,T2, OR_PUT);
    	
	    }
	    //Desenho dos Items
	    for (int i=0;i<10;i++)	
    	{
    		putimage(item[i].x,item[i].y,T5M, AND_PUT);
    		putimage(item[i].x,item[i].y,T5, OR_PUT);
    	
	    }
	    //Movimenta��o das plataformas e itens para a direita
	    for (int i=0;i<10;i++)
    	{
    		plat[i].x += px;
			item[i].x += px;
	    }

		//Desenho do ch�o
		putimage(0,700,T3, AND_PUT);
		putimage(0,700,T3, OR_PUT);		
		putimage(1280,700,T3, AND_PUT);
		putimage(1280,700,T3, OR_PUT);	
		
		//Desenho do personagem e Anubis
		//Jogador
		putimage(F.x, F.y, T1, AND_PUT);
    	putimage(F.x, F.y, T1, OR_PUT);
    	//Anubis
    	putimage(A.x, A.y, T6M, AND_PUT);
    	putimage(A.x, A.y, T6, OR_PUT);

//    	putimage(F.x, F.y, runmask[s], AND_PUT);
//    	putimage(F.x, F.y, run[s], OR_PUT);
//    	s++;
//    	if (s == 5) s = 0;
    	
  		setvisualpage(pg);
  		delay(50);
  		fflush(stdin);
    	if (kbhit())
    		tecla = getch();
    	
}
		closegraph();	
		free(T1);
		free(T2);
		free(T3);
		free(T4);
		free(T5);
		free(T5M);
		return 0; 

}
