#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>

//Variables globales
int mya,myb,myc,myd,mye,myf,myg,myh,myi,myj,myk,myl,mym,myn,myo,myp,myq,myr,mys,myt,myu,myv,myw,myx,myy;
int ena,enb,enc,end,ene,enf,eng,enh,eni,enj,enk,enl,enm,enn,eno,enp,enq,enr,ens,ent,enu,env,enw,enx,eny;
int cont_eny=0, cont_my=0;
int K[24], i;

//Declaracion de funciones
void Portada();
void MyCuadricula();
void EnyCuadricula();
void MyNumeracion();
void EnyNumeracion();
void Coords(int tecla);
void PintaBarco(int x, int y);
void EnyNew();
void PintaExpl(int x, int y);
void PintaMar(int x, int y);
void EnyRevision(int tecla);
void CPU();
void MyRevision(int i);
void Fin(int eny, int my);
void Instrucciones();


void Portada(){
		settextstyle(8,0,5);
	setcolor(LIGHTGREEN);
	outtextxy(500,50, "Batalla Naval");
	outtextxy(300,100, "Presiona tecla para empezar");
	
	int vect[10];
	vect[0]= 400;
    vect[1]= 500;
    vect[2]= 500;
    vect[3]= 600;
    vect[4]= 800;
    vect[5]= 600;
    vect[6]= 900;
    vect[7]= 500;
	vect[8]= vect[0];
    vect[9]= vect[1];
    setcolor(BROWN);
    setfillstyle(1,BROWN);
    fillpoly(4,vect);
    
    int vel1[8];
    vel1[0]=650;
    vel1[1]=250;
    vel1[2]=440;
    vel1[3]=430;
    vel1[4]=650;
    vel1[5]=480;
    vel1[6]=vel1[0];
    vel1[7]=vel1[1];
    setcolor(YELLOW);
    setfillstyle(1,YELLOW);
    fillpoly(3,vel1);
    
    int vel2[8];
    vel2[0]=650;
    vel2[1]=270;
    vel2[2]=650;
    vel2[3]=480;
    vel2[4]=830;
    vel2[5]=430;
    vel2[6]=vel2[0];
    vel2[7]=vel2[1];
    setcolor(CYAN);
    setfillstyle(1,CYAN);
    fillpoly(3,vel2);
    
    setcolor(BROWN);
    setlinestyle(1,1,5);
    line(650, 250, 650, 500);
    
    setcolor(RED);
    circle(650,245,5);
    setfillstyle(1,RED);
    floodfill(650,248,RED);
	
	int tri[8];
	tri[0]= 650;
    tri[1]= 250;
    tri[2]= 650;
    tri[3]= 270;
    tri[4]= 680;
    tri[5]= 260;
    tri[6]= tri[0];
    tri[7]= tri[1];
    setfillstyle(1,RED);
    fillpoly(3,tri);
    
	setcolor(LIGHTCYAN);
	circle(650,550,10);
	setfillstyle(3,LIGHTCYAN);
	floodfill(651,551,LIGHTCYAN);
	circle(515,550,10);
	floodfill(516,551,LIGHTCYAN);
	circle(785,550,10);
	floodfill(786,551,LIGHTCYAN);
    
    getch();

//BORRAR
	setcolor(BLACK);
	setfillstyle(1, BLACK);
	floodfill(103, 173, MAGENTA);
}

void Instrucciones(){
	setcolor(WHITE);
	settextstyle(2,0,9);
	outtextxy(100,150,"Tendras 6 barcos");
	getch();
	outtextxy(100,250,"Acomodalos en la posicion que desees");
	getch();
	outtextxy(100,350,"Utiliza el teclado");
	getch();
	outtextxy(100,450,"Sigue las instrucciones que apareceran debajo de tu tablero");
	getch();
	outtextxy(100,550,"Gana el primero en hundir todos los barcos del enemigo");
	getch();
	//BORRAR
	setcolor(BLACK);
	setfillstyle(1, BLACK);
	floodfill(103, 173, MAGENTA);
}

void MyCuadricula(){
	setcolor(MAGENTA);
	rectangle(50,100, 550, 600);
	floodfill(51,101,MAGENTA);
	setcolor(BLUE);
	settextstyle(2,0,9);
	outtextxy(100,50,"Player");
	setcolor(WHITE);
	rectangle(50,100, 550, 600);
	
	line(150,100, 150, 600);
	line(250,100, 250, 600);
	line(350,100, 350, 600); 
	line(450,100, 450, 600);
	
	line(50,200, 550, 200);
	line(50,300, 550, 300);
	line(50,400, 550, 400);
	line(50,500, 550, 500);
}

void EnyCuadricula(){
	setcolor(RED);
	settextstyle(2,0,9);
	outtextxy(800,50,"Comp");
	setcolor(WHITE);
	rectangle(750,100, 1250, 600);
	
	line(850,100, 850, 600);
	line(950,100, 950, 600);
	line(1050,100, 1050, 600); 
	line(1150,100, 1150, 600);
	
	line(750,200, 1250, 200);
	line(750,300, 1250, 300);
	line(750,400, 1250, 400);
	line(750,500, 1250, 500);
}

void MyNumeracion(){
	setcolor(GREEN);
	settextstyle(2,0,9);
	outtextxy(100,150,"A");
	outtextxy(200,150,"B");
	outtextxy(300,150,"C");
	outtextxy(400,150,"D");
	outtextxy(500,150,"E");
	
	outtextxy(100,250,"F");
	outtextxy(200,250,"G");
	outtextxy(300,250,"H");
	outtextxy(400,250,"I");
	outtextxy(500,250,"J");
	
	outtextxy(100,350,"K");
	outtextxy(200,350,"L");
	outtextxy(300,350,"M");
	outtextxy(400,350,"N");
	outtextxy(500,350,"O");
	
	outtextxy(100,450,"P");
	outtextxy(200,450,"Q");
	outtextxy(300,450,"R");
	outtextxy(400,450,"S");
	outtextxy(500,450,"T");
	
	outtextxy(100,550,"U");
	outtextxy(200,550,"V");
	outtextxy(300,550,"W");
	outtextxy(400,550,"X");
	outtextxy(500,550,"Y");
}

void EnyNumeracion(){
	setcolor(RED);
	settextstyle(2,0,9);
	outtextxy(800,150,"A");
	outtextxy(900,150,"B");
	outtextxy(1000,150,"C");
	outtextxy(1100,150,"D");
	outtextxy(1200,150,"E");
	
	outtextxy(800,250,"F");
	outtextxy(900,250,"G");
	outtextxy(1000,250,"H");
	outtextxy(1100,250,"I");
	outtextxy(1200,250,"J");
	
	outtextxy(800,350,"K");
	outtextxy(900,350,"L");
	outtextxy(1000,350,"M");
	outtextxy(1100,350,"N");
	outtextxy(1200,350,"O");
	
	outtextxy(800,450,"P");
	outtextxy(900,450,"Q");
	outtextxy(1000,450,"R");
	outtextxy(1100,450,"S");
	outtextxy(1200,450,"T");
	
	outtextxy(800,550,"U");
	outtextxy(900,550,"V");
	outtextxy(1000,550,"W");
	outtextxy(1100,550,"X");
	outtextxy(1200,550,"Y");
}

void Coords(int tecla){
	int cx,cy;
	
	if (tecla=='a'||tecla=='A'){
			cx=60;
			cy=110;
			mya=1;
			PintaBarco(cx,cy);
	}else if (tecla=='b'||tecla=='B'){
			cx=160;
			cy=110;
			myb=1;
			PintaBarco(cx,cy);
	}else if (tecla=='c'||tecla=='C'){
			cx=260;
			cy=110;
			myc=1;
			PintaBarco(cx,cy);
	}else if (tecla=='d'||tecla=='D'){
			cx=360;
			cy=110;
			myd=1;
			PintaBarco(cx,cy);
	}else if (tecla=='e'||tecla=='E'){
			cx=460;
			cy=110;
			mye=1;
			PintaBarco(cx,cy);
	///////////////////////////////////		
	}else if (tecla=='f'||tecla=='F'){
			cx=60;
			cy=210;
			myf=1;
			PintaBarco(cx,cy);
	}else if (tecla=='g'||tecla=='G'){
			cx=160;
			cy=210;
			myg=1;
			PintaBarco(cx,cy);
	}else if (tecla=='h'||tecla=='H'){
			cx=260;
			cy=210;
			myh=1;
			PintaBarco(cx,cy);
	}else if (tecla=='i'||tecla=='I'){
			cx=360;
			cy=210;
			myi=1;
			PintaBarco(cx,cy);
	}else if (tecla=='j'||tecla=='J'){
			cx=460;
			cy=210;
			myj=1;
			PintaBarco(cx,cy);
	///////////////////////////////////////		
	}else if (tecla=='k'||tecla=='K'){
			cx=60;
			cy=310;
			myk=1;
			PintaBarco(cx,cy);
	}else if (tecla=='l'||tecla=='L'){
			cx=160;
			cy=310;
			myl=1;
			PintaBarco(cx,cy);
	}else if (tecla=='m'||tecla=='M'){
			cx=260;
			cy=310;
			mym=1;
			PintaBarco(cx,cy);
	}else if (tecla=='n'||tecla=='N'){
			cx=360;
			cy=310;
			myn=1;
			PintaBarco(cx,cy);
	}else if (tecla=='o'||tecla=='O'){
			cx=460;
			cy=310;
			myo=1;
			PintaBarco(cx,cy);
	/////////////////////////////////////
	}else if (tecla=='p'||tecla=='P'){
			cx=60;
			cy=410;
			myp=1;
			PintaBarco(cx,cy);
	}else if (tecla=='q'||tecla=='Q'){
			cx=160;
			cy=410;
			myq=1;
			PintaBarco(cx,cy);
	}else if (tecla=='r'||tecla=='R'){
			cx=260;
			cy=410;
			myr=1;
			PintaBarco(cx,cy);
	}else if (tecla=='s'||tecla=='S'){
			cx=360;
			cy=410;
			mys=1;
			PintaBarco(cx,cy);
	}else if (tecla=='t'||tecla=='T'){
			cx=460;
			cy=410;
			myt=1;
			PintaBarco(cx,cy);
	///////////////////////////////////
	}else if (tecla=='u'||tecla=='U'){
			cx=60;
			cy=510;
			myu=1;
			PintaBarco(cx,cy);
	}else if (tecla=='v'||tecla=='V'){
			cx=160;
			cy=510;
			myv=1;
			PintaBarco(cx,cy);
	}else if (tecla=='w'||tecla=='W'){
			cx=260;
			cy=510;
			myw=1;
			PintaBarco(cx,cy);
	}else if (tecla=='x'||tecla=='X'){
			cx=360;
			cy=510;
			myx=1;
			PintaBarco(cx,cy);
	}else if (tecla=='y'||tecla=='Y'){
			cx=460;
			cy=510;
			myy=1;
			PintaBarco(cx,cy);
	}	
}

void PintaBarco(int x, int y){
	setfillstyle(3, GREEN);
	setcolor(GREEN);
	rectangle(x,y,x+80,y+80);
	floodfill(x+1,y+1,GREEN);
}

void EnyNew(){
	int random, ii;
	
	srand(time(NULL));
	
	for (ii=1; ii<7; ii++){
		random=(rand()%25)+1;
		printf("%d, ", random);
		
		switch (random){
			case 1:
				ena=1;
				break;
			case 2:
				enb=1;
				break;
			case 3: 
				enc=1;
				break;
			case 4:
				end=1;
				break;
			case 5:
				ene=1;
				break;
			/////////////
			case 6:
				enf=1;
				break;
			case 7:
				eng=1;
				break;
			case 8: 
				enh=1;
				break;
			case 9:
				eni=1;
				break;
			case 10:
				enj=1;
				break;
			////////////
			case 11:
				enk=1;
				break;
			case 12:
				enl=1;
				break;
			case 13: 
				enm=1;
				break;
			case 14:
				enn=1;
				break;
			case 15:
				eno=1;
				break;
			/////////////
			case 16:
				enp=1;
				break;
			case 17:
				enq=1;
				break;
			case 18: 
				enr=1;
				break;
			case 19:
				ens=1;
				break;
			case 20:
				ent=1;
				break;
			////////////
			case 21:
				enu=1;
				break;
			case 22:
				env=1;
				break;
			case 23: 
				enw=1;
				break;
			case 24:
				enx=1;
				break;
			case 25:
				eny=1;
				break;
		}
	}
}

void PintaExpl(int x, int y){
	setfillstyle(4, YELLOW);
	setcolor(YELLOW);
	rectangle(x,y,x+80,y+80);
	floodfill(x+1,y+1,YELLOW);
}

void PintaMar(int x, int y){
	setfillstyle(1, CYAN);
	setcolor(CYAN);
	rectangle(x,y,x+80,y+80);
	floodfill(x+1,y+1,CYAN);
}

void EnyRevision(int tecla){
	int cx, cy;
	if (tecla=='a'||tecla=='A'){
		cx=760;
		cy=110;
		if (ena==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='b'||tecla=='B'){
		cx=860;
		cy=110;
		if (enb==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='c'||tecla=='C'){
		cx=960;
		cy=110;
		if (enc==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='d'||tecla=='D'){
		cx=1060;
		cy=110;
		if (end==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='e'||tecla=='E'){
		cx=1160;
		cy=110;
		if (ene==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='f'||tecla=='F'){
		cx=760;
		cy=210;
		if (enf==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='g'||tecla=='G'){
		cx=860;
		cy=210;
		if (eng==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='h'||tecla=='H'){
		cx=960;
		cy=210;
		if (enh==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='i'||tecla=='I'){
		cx=1060;
		cy=210;
		if (eni==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='j'||tecla=='J'){
		cx=1160;
		cy=210;
		if (enj==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='k'||tecla=='K'){
		cx=760;
		cy=310;
		if (enk==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='l'||tecla=='L'){
		cx=860;
		cy=310;
		if (enl==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='m'||tecla=='M'){
		cx=960;
		cy=310;
		if (enm==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='n'||tecla=='N'){
		cx=1060;
		cy=310;
		if (enn==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='o'||tecla=='O'){
		cx=1160;
		cy=310;
		if (eno==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='p'||tecla=='P'){
		cx=760;
		cy=410;
		if (enp==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='q'||tecla=='Q'){
		cx=860;
		cy=410;
		if (enq==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='r'||tecla=='R'){
		cx=960;
		cy=410;
		if (enr==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='s'||tecla=='S'){
		cx=1060;
		cy=410;
		if (ens==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='t'||tecla=='T'){
		cx=1160;
		cy=410;
		if (ent==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='u'||tecla=='U'){
		cx=760;
		cy=510;
		if (enu==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='v'||tecla=='V'){
		cx=860;
		cy=510;
		if (env==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='w'||tecla=='W'){
		cx=960;
		cy=510;
		if (enw==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='x'||tecla=='X'){
		cx=1060;
		cy=510;
		if (enx==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
	
	else if (tecla=='y'||tecla=='Y'){
		cx=1160;
		cy=510;
		if (eny==1){
			PintaExpl(cx,cy);
			cont_eny=cont_eny+1;
		} else{
			PintaMar(cx, cy);
		}
	}
}

void CPU(){
	int random;
	srand(time(NULL));
	random=(rand()%4)+1;
	
	printf("Random %d \n", random);
	switch (random){
		case 1:
			K[0]=1;
			K[1]=24;
			K[2]=9;
			K[3]=4;
			K[4]=12;
			K[5]=8;
			K[6]=20;
			K[7]=7;
			K[8]=25;
			K[9]=10;
			K[10]=17;
			K[11]=3;
			K[12]=18;
			K[13]=5;
			K[14]=11;
			K[15]=22;
			K[16]=2;
			K[17]=21;
			K[18]=15;
			K[19]=19;
			K[20]=16;
			K[21]=13;
			K[22]=23;
			K[23]=6;
			K[24]=14;
			break;
		case 2:
			K[0]=8;
			K[1]=2;
			K[2]=11;
			K[3]=15;
			K[4]=7;
			K[5]=9;
			K[6]=17;
			K[7]=16;
			K[8]=1;
			K[9]=24;
			K[10]=5;
			K[11]=10;
			K[12]=6;
			K[13]=20;
			K[14]=23;
			K[15]=12;
			K[16]=3;
			K[17]=14;
			K[18]=18;
			K[19]=22;
			K[20]=13;
			K[21]=4;
			K[22]=21;
			K[23]=19;
			K[24]=25;
			break;
		case 3:
			K[0]=3;
			K[1]=8;
			K[2]=16;
			K[3]=13;
			K[4]=17;
			K[5]=2;
			K[6]=21;
			K[7]=10;
			K[8]=20;
			K[9]=12;
			K[10]=4;
			K[11]=7;
			K[12]=22;
			K[13]=11;
			K[14]=24;
			K[15]=15;
			K[16]=23;
			K[17]=6;
			K[18]=25;
			K[19]=18;
			K[20]=5;
			K[21]=14;
			K[22]=19;
			K[23]=9;
			K[24]=1;
			break;
		case 4:
			K[0]=24;
			K[1]=9;
			K[2]=3;
			K[3]=11;
			K[4]=25;
			K[5]=15;
			K[6]=6;
			K[7]=16;
			K[8]=8;
			K[9]=23;
			K[10]=14;
			K[11]=7;
			K[12]=1;
			K[13]=19;
			K[14]=4;
			K[15]=13;
			K[16]=10;
			K[17]=4;
			K[18]=18;
			K[19]=20;
			K[20]=17;
			K[21]=22;
			K[22]=12;
			K[23]=21;
			K[24]=2;
			break;
	}
}

void MyRevision(int i){
	int mx, my;
	printf("Revision %d \n", K[i]);
		
	switch(K[i]){
		case 1:
			mx=60;
			my=110;
			if (mya==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 2:
			mx=160;
			my=110;
			if (myb==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}break;
		case 3:
			mx=260;
			my=110;
		if (myc==1){
			PintaExpl(mx,my);
			cont_my=cont_my+1;
		} else{
			PintaMar(mx, my);
		}
			break;
		case 4:
			mx=360;
			my=110;
			if (myd==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 5:
			mx=460;
			my=110;
			if (mye==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 6:
			mx=60;
			my=210;
			if (myf==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 7:
			mx=160;
			my=210;
			if (myg==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 8:
			mx=260;
			my=210;
			if (myh==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 9:
			mx=360;
			my=210;
			if (myi==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 10:
			mx=460;
			my=210;
			if (myj==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 11:
			mx=60;
			my=310;
			if (myk==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 12:
			mx=160;
			my=310;
			if (myl==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 13:
			mx=260;
			my=310;
			if (mym==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 14:
			mx=360;
			my=310;
			if (myn==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 15:
			mx=460;
			my=310;
			if (myo==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 16:
			mx=60;
			my=410;
			if (myp==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 17:
			mx=160;
			my=410;
			if (myq==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 18:
			mx=260;
			my=410;
			if (myr==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 19:
			mx=360;
			my=410;
			if (mys==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 20:
			mx=460;
			my=410;
			if (myt==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 21:
			mx=60;
			my=510;
			if (myu==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 22:
			mx=160;
			my=510;
			if (myv==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 23:
			mx=260;
			my=510;
			if (myw==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 24:
			mx=360;
			my=510;
			if (myx==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}
			break;
		case 25:
			mx=460;
			my=510;
			if (myy==1){
				PintaExpl(mx,my);
				cont_my=cont_my+1;
			} else{
				PintaMar(mx, my);
			}	
			break;
}
	
}

void Fin(int eny, int my){
	//BORRAR
	setcolor(BLACK);
	setfillstyle(1, BLACK);
	floodfill(103, 173, MAGENTA);
	//
	settextstyle(8,0,7);
	setcolor(LIGHTGREEN);
	outtextxy(500,50, "Juego terminado");

	int vect[10];
	vect[0]= 400;
    vect[1]= 500;
    vect[2]= 500;
    vect[3]= 600;
    vect[4]= 800;
    vect[5]= 600;
    vect[6]= 900;
    vect[7]= 500;
	vect[8]= vect[0];
    vect[9]= vect[1];
    setcolor(BROWN);
    setfillstyle(1,BROWN);
    fillpoly(4,vect);
    
    int vel1[8];
    vel1[0]=650;
    vel1[1]=250;
    vel1[2]=440;
    vel1[3]=430;
    vel1[4]=650;
    vel1[5]=480;
    vel1[6]=vel1[0];
    vel1[7]=vel1[1];
    setcolor(YELLOW);
    setfillstyle(1,YELLOW);
    fillpoly(3,vel1);
    
    int vel2[8];
    vel2[0]=650;
    vel2[1]=270;
    vel2[2]=650;
    vel2[3]=480;
    vel2[4]=830;
    vel2[5]=430;
    vel2[6]=vel2[0];
    vel2[7]=vel2[1];
    setcolor(CYAN);
    setfillstyle(1,CYAN);
    fillpoly(3,vel2);
    
    setcolor(BROWN);
    setlinestyle(1,1,5);
    line(650, 250, 650, 500);
    
    setcolor(RED);
    circle(650,245,5);
    setfillstyle(1,RED);
    floodfill(650,248,RED);
	
	int tri[8];
	tri[0]= 650;
    tri[1]= 250;
    tri[2]= 650;
    tri[3]= 270;
    tri[4]= 680;
    tri[5]= 260;
    tri[6]= tri[0];
    tri[7]= tri[1];
    setfillstyle(1,RED);
    fillpoly(3,tri);
    
	setcolor(LIGHTCYAN);
	circle(650,550,10);
	setfillstyle(3,LIGHTCYAN);
	floodfill(651,551,LIGHTCYAN);
	circle(515,550,10);
	floodfill(516,551,LIGHTCYAN);
	circle(785,550,10);
	floodfill(786,551,LIGHTCYAN);
	
	if (my<eny){
		outtextxy(500,650, "Ganaste");
	}else if (my>eny){
		outtextxy(500,650, "Perdiste");
	}else if (my==eny){
		outtextxy(500,650, "Empate");
	}
    
    getch();
}

main(){
	int controlador_de_graficos = DETECT;
	int modografico;
	initgraph(&controlador_de_graficos, &modografico, "c:\\TC\\BGI");
	
	int tecla, z, gameover=0, tecla_eny, i=0;
	Portada();
	Instrucciones();
	
	setlinestyle(0,1,1);

	MyCuadricula();
	EnyCuadricula();
	MyNumeracion();
	
	setcolor(LIGHTGRAY);
	settextstyle(1,0,2);
	outtextxy(50,650,"Acomoda 6 barcos");
	outtextxy(50,670,"Ingresa posicion Barco");
	
	for(z=1; z<7; z++){
		tecla=getch();
		Coords(tecla);
	}
	EnyNumeracion();
	
	setcolor(BLACK);
	settextstyle(1,0,2);
	outtextxy(50,650,"Acomoda 6 barcos");
	outtextxy(50,670,"Ingresa posicion Barco");
	
	EnyNew();
	CPU();
	
	do{
		setcolor(WHITE);
		settextstyle(1,0,2);
		outtextxy(50,670,"Ingresa posicion Barco Enemigo");
		tecla_eny=getch();
		EnyRevision(tecla_eny);
		
		MyRevision(i);
		i++;
		outtextxy(50,670,"CPU Turn Presiona SPACE");
		getch();
		
		if (cont_eny==6 || cont_my==6){
			gameover=1;
		}
		
	}while (gameover!=1);
	
	Fin(cont_eny, cont_my);
	getch();
	closegraph();	
}
