# include "iGraphics.h"                    
#include "info.h"
#include <string.h>
#include <math.h>
#include<stdlib.h>
#include "pic.h"
//Done by Member-1(17.02.04.110)
//Sorts the ranking
//Parameters:
// p1[]-player's name & score
// n-number of players
void sort(Player pl[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)if(pl[j].score>pl[j+1].score)
		{
			Player temp;
			strcpy(temp.name,pl[j+1].name);
			temp.score=pl[j+1].score;
			strcpy(pl[j+1].name,pl[j].name);
			pl[j+1].score=pl[j].score;
		    strcpy(pl[j].name,temp.name);
			pl[j].score=temp.score;
		  
		}
	}
}
//Done by Member-1(17.02.04.110)
//Determines the winner
//Variables:
// tech-declares game over
// (current_postion1,current_position2)-game board positions of two coins
// global_indicator-switches to the game over page with winner's name and score
void winnermeth()
{
	if(tech)
	{
		if(current_position1==100)global_indicator=21;
		else if(current_position2==100)global_indicator=22;
	}
}
//Done by Member-1(17.02.04.110)
//Shows game over page 
//Variables:
//	igover- loaded game over background image 
//	global_indicator-to show winner's info
//	repeat-avoids writing winner's info in the file repeatedly
//	(pnm1,pnm2)-two players name
//	(score1,score2)-two player's scores
//	(sc1,sc2)-two player's scores as string
//After calling win() it will  write winner's info
//in ranking file and show it on game over page.
void win()
{
	iShowImage(0,0,1400,900,igover);

	if(global_indicator==21)
	{
		iSetColor(0,0,0);
		iText(648,500,pnm1,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(sc1,"%d",score1);
		iText(668,280,sc1,GLUT_BITMAP_TIMES_ROMAN_24);
		if(repeat==0){
		repeat=1;
		FILE *fpp=fopen("ranking.txt","w");
		if(player[4].score>score1)player[4].score=score1,strcpy(player[4].name,pnm1);
		sort(player,5);
		for(int i=0;i<5;i++)
	    sprintf(ranklist[i],"%s                                    %d",player[i].name,player[i].score);


		for(int i=0;i<5;i++)
		{
			fprintf(fpp,"%s %d ",player[i].name,player[i].score);
		}

		fclose(fpp);
		}
	}
	else 
	{
		iSetColor(0,0,0);
		iText(648,500,pnm2,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(sc2,"%d",score2);
		iText(668,280,sc2,GLUT_BITMAP_TIMES_ROMAN_24);
	
	if(repeat==0)
	{
		repeat=1;
		
		FILE *fpp=fopen("ranking.txt","w");
		if(player[4].score>score2)player[4].score=score2,strcpy(player[4].name,pnm2);
		sort(player,5);
		for(int i=0;i<5;i++)
	    sprintf(ranklist[i],"%s                                    %d",player[i].name,player[i].score);

		for(int i=0;i<5;i++)
		{
			fprintf(fpp,"%s %d",player[i].name,player[i].score);
		}
		fclose(fpp);
	}
}
}
//Done by Member-2(17.02.04.111)
//Describes about the game
//Variables:
//	aboutim-loaded about background image 
//	backim-loaded back button image 
//Array:
//	abouttext[]=description of the game
void about()
{
	
	iShowImage(0,0,1400,900,aboutim);
	iShowImage(10,830,100,75,backim);

	iSetColor(0,0,0);
	for(int i=0;i<15;i++)
		iText(300,600-30*i,abouttext[i],GLUT_BITMAP_TIMES_ROMAN_24);
	
}
//Done by Member-3(17.02.04.113)
//Describes developer's information
//Variables:
//	creditim-loaded credit background image
//	backim-loaded back button image
//Array:
//	credittext[i]-description of the developers
void credit()
{
		iShowImage(0,0,1400,900,creditim);
	iShowImage(10,830,100,75,backim);
	
	iSetColor(0,0,0);
	for(int i=0;i<36;i++)
		iText(600,900-20*i,credittext[i],GLUT_BITMAP_TIMES_ROMAN_24);
}
//Done by Member-1(17.02.04.110)
//Shows top five winner's name
//Variables:
//	rankingim-loaded ranking background image
//	backim-loaded back button image
//Array:
//	ranklist[i]-description of the five winners
void ranking()
{
	iShowImage(0,0,1400,900,rankingim);
	iShowImage(10,830,100,75,backim);
	iSetColor(255,0,0);
	for(int i=0;i<5;i++)iText(600,460-i*60,ranklist[i],GLUT_BITMAP_TIMES_ROMAN_24);

}
//Done by Member-2(17.02.04.111)
//Increments the value timc2 variable
//After calling time2 function through iSetTimer
//the value of timec2 will increment
void time2()
{
	if(timec2>=100000)timec2=0;
		timec2++;
}
//Done by Member-3(17.02.04.113)
//Takes names of two players as input from user
//Variables:
//	namingim-loaded background image
//	backim-loaded back button image
//	(pnm1,pnm2)-names of two players
void thirdice_pic1age()
{
	iShowImage(0, 0, 1400, 900,namingim);
	iShowImage(10,830,100,75,backim);
	iSetColor(0,0,0);
	iText(660,522,pnm1,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(660,302,pnm2,GLUT_BITMAP_TIMES_ROMAN_24);
}
//Done by Member-2(17.02.04.111) and Member-1(17.02.04.110)
//Rotates the dice and moves coins
//After calling dice_run,the dice rotation will happen(Member-2) and
//the coin will start moving after dice rotation(Member-1)
//Variables:
//	timec2-rotates the dice after a while
//	cn-counts the rotation of dice
//	cnnn-holds dice rotation for a while
//	u2-value of dice at last rotation
//	randm-shows dice random faces by it's value
//	final-avoids last value of dice to come consecutively
//	(dpn,dpn1,dpn2,dpn3,dpn4,dpn5,dpn6)-loaded images of dice's faces
//	ranindex-number of index of ranno array
//	indicator-determines which dice is clicked
//	strike-counts coin moves 
//	num-last rotated value of dice
//	(cd1,cd2)-shows the last value of dice at corner
//	gutmv-holds coin move for a while
//	(gut_x1,gut_y1,gut_x2,gut_y2)- co-ordinates of coins
//	(musicon1,musicon2,musicon3,musicon4)-plays sounds 
//	tech-declares game over
//Arrays:
//	ranno[]-fifty random numbers(1-6)
//	pictoint[]-dice six values
//	sirisap[]-coin position according to ladder and snake
void dice_run()
{
	if (timec2 % 2 == 0&&cn<10)
	{
		if(cnnn==0){cnnn=1;
		cn++;
		if(cn==10)
		{
			time_t t;
			srand((unsigned)time(&t));
			int ra = rand();
			int u2=ra%6;
			if(u2<0)u2*=-1;
            if(u2==0)u2=6;
			randm=u2;
			if(final==randm)
			{
				ra%=50;
				if(ra<0)ra*=-1;
				randm=ranno[ra];
			}
			final=randm;
		}
		else
		randm=ranno[ranindex++];
		if(ranindex>=50)ranindex=0;

		switch (randm)
		{
		case 1:dpn=dpn1;
			break;
		case 2:dpn=dpn2;
			break;
		case 3:dpn=dpn3;
			break;
		case 4:dpn=dpn4;
			break;
		case 5:dpn=dpn5;
			break;
		case 6:dpn=dpn6;
			break;
		}
		
	}
	}
	else cnnn=0;

	iShowImage(653, 400, 100, 100, dpn);


	if (cn >= 10&&((indicator==1&&current_position1+pictoint[randm]-strike<=100)||
		(indicator==2&&current_position2+pictoint[randm]-strike<=100)))
	{	
		num=pictoint[randm];
		
		
		if(indicator==1 &&current_position1==0&&num==1)
		{	cd1=1;
			
		strike++;current_position1=1;guti_x1=x[0],guti_y1=y[0];}
		else if(indicator==2 &&current_position2==0&&num==1)
		{
		cd2=1;
		
		strike++;current_position2=1;guti_x2=x[0],guti_y2=y[0];}
		else if((indicator==1&&current_position1>0)||(indicator==2&&current_position2>0))
        {
		
		if(timec2%2)
		{
			
			if(gutmv==0)
				{	
					
					if(indicator==1){
					cd1=1;
					
					current_position1++,gutmv=1,strike++,guti_x1=x[current_position1-1],guti_y1=y[current_position1-1];
					}
					else{
						cd2=1;
						
						current_position2++,gutmv=1,strike++,guti_x2=x[current_position2-1],guti_y2=y[current_position2-1];
					}
					}

		}
		else 
		{	
			gutmv=0;
		}
		}
	
		if(strike>=num)
			{	
				if(indicator==1&&current_position1<sirisap[current_position1]||
					(indicator==2&&current_position2<sirisap[current_position2]))
				{
				musicon2=0;
				}

				else if(indicator==1&&current_position1>sirisap[current_position1]||
					(indicator==2&&current_position2>sirisap[current_position2]))
				{
					musicon3=0;
				}

				if(current_position1==100||current_position2==100)tech=1,musicon4=0;
				if(indicator==1){

					
					current_position1=sirisap[current_position1],
					guti_x1=x[current_position1-1],guti_y1=y[current_position1-1];
				}
				else {
				
					current_position2=sirisap[current_position2],
					guti_x2=x[current_position2-1],guti_y2=y[current_position2-1];
				}
				
				indicator=0;}

	}		
}
//Done by all members
//Shows game board page
//Variables:
//	gamepageim-loaded image of gameboard
//	(coinim1,coinim2)-loaded images of coins
//	(diceim1,diceim2)-loaded dice button images
//	backim-	loaded back button image
//After calling bgmain(),the images will be 
//shown in the gameboard.To start dice rotation,
//call dice_run()
void bgmain()
{
	iShowImage(0, 100, 1400, 800,gamepageim);
	iShowImage(guti_x1, guti_y1, 80, 80,coinim1);
	iShowImage(guti_x2, guti_y2, 80, 80,coinim2);
	iShowImage(30, 200, 150, 150,diceim1);
	iShowImage(1280, 200, 150, 150,diceim2);
	if(cd1==1)iShowImage(30, 130, 80, 50,dpn);
	if(cd2==1)iShowImage(1280, 130, 80, 50,dpn);
	iShowImage(10,710,100,75,backim);
	iText(110,522,pnm1,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1250,522,pnm2,GLUT_BITMAP_TIMES_ROMAN_24);
	if(indicator)dice_run();
	
}
//Done by Member-2(17.02.04.111)
//Gets fifty random values and stores them in array
//Variables:
//	randm-random value(1-6)
//	antirepeat-avoids last random value coming consecutively
//Array:
//	ranno[]-assigned fifty random values
void randomfunction()
{
	for(int i=0;i<50;i++){
	do {
			time_t t;
			srand((unsigned)time(&t));
			randm = rand() % 6;
			if (randm == 0)randm = 6;
			if (randm < 0)randm *= (-1);
		} while (randm == antirepeat);
		ranno[i]=randm;
		antirepeat=randm;
		
	}	
}
//Done by Member-2(17.02.04.111)
//Shows the first page of the game
//Variables:
//	timecount-shows loading image bar
//  firstpageim-loaded first page background image
//	(Lim1,lim2,Lim3,Lim4,Lim5,Lim6,Lim7)-parts of images of Loading Bar
//	ran-calls random function for once
//After calling first page,the loading image bar 
//will be shown.To start storing fifty random values
//in ranno array,call random function().
void firstpage()
{

	iShowImage(0, 0, 1400, 900,firstpageim);
	if (timecount<5)
		iShowImage(80, 50, 300, 100,Lim1);
	else if (timecount<15){
		iShowImage(80, 50, 1100, 100,Lim2);
		if(ran==0)
	randomfunction();
		ran=1;
	}
	else if (timecount<20)
		iShowImage(80, 50, 1100, 100,Lim3);
	else if (timecount<35)
		iShowImage(80, 50, 1100, 100,Lim4);
	else if (timecount<43)
		iShowImage(80, 50, 1100, 100,Lim5);
	else if (timecount<48)
		iShowImage(80, 50, 1100, 100,Lim6);
	else
		iShowImage(80, 50, 1100, 100,Lim7);
	iText(200, 120, "Loading", GLUT_BITMAP_HELVETICA_18);
	
}
//Done by Member-3(17.02.04.113)
//Shows Main Menu Page
//Variables:
//	pos-increase the size of the buttons for blinking
//	playbtim-loaded play button image
//	aboutbtim-loaded about button image
//	rankingbtim-loaded ranking button image
//	creditbtim-loaded credit button image
//	quitbtim-loaded quit button image
//	blink-blinks buttons
void secondice_pic1age()
{
	
	int pos = 30;

	iShowImage(0, 0, 1400, 900,secondpageim);

	iShowImage(850 - pos * (blink == 1), 700 - pos * (blink == 1),
		400 + 2 * pos * (blink == 1), 200 + 2 * pos * (blink == 1), playbtim);
	iShowImage(850 - pos * (blink == 2), 580 - pos * (blink == 2),
		400 + 2 * pos * (blink == 2), 200 + 2 * pos * (blink == 2),aboutbtim);
	iShowImage(850 - pos * (blink == 3), 460 - pos * (blink == 3),
		400 + 2 * pos * (blink == 3), 200 + 2 * pos * (blink == 3),rankingbtim);
	iShowImage(850 - pos * (blink == 4), 340 - pos * (blink == 4),
		400 + 2 * pos * (blink == 4), 200 + 2 * pos * (blink == 4),creditbtim);
	iShowImage(850 - pos * (blink == 5), 220 - pos * (blink == 5),
		400 + 2 * pos * (blink == 5), 200 + 2 * pos * (blink == 5),quitbtim);
}
//Done by Member-2(17.02.04.111)
//Increments the value of timecount variable
void showTime()
{
	if (timecount < 100000)timecount++;
}
//Done by Member-2(17.02.04.111) and Member-1(17.02.04.110)
//Calls funtions(Member-2) and plays sounds(Member-1)
//Variables:
//musicon1-plays dice throw music at the time of dice clicking
//musicon2-plays ladder pick music when the coin is at the bottom of Ladder
//musicon3-plays snake bite music when the coin is at the top of snake
//musicon4-plays game over music while is being over
//global_indicator-To call different functions through its different values
//timecount-shows first page for limited time
//After calling iDraw(),it will switch to different pages
//calling their respective functions based on 
//the value of gloabal_indicator
void iDraw()
{	
	if(musicon1==0){musicon1=1;PlaySound("dice_throw_0.wav",NULL,SND_ASYNC);}
	if(musicon2==0){musicon2=1;PlaySound("ladder_pick.wav",NULL,SND_ASYNC);}
	if(musicon3==0){musicon3=1;PlaySound("snake_bite.wav",NULL,SND_ASYNC);}
	if(musicon4==0){musicon4=1;PlaySound("game_over.wav",NULL,SND_ASYNC);}
	iClear();
	if (timecount < 50)
		firstpage();
	else if (global_indicator == 1) {
		secondice_pic1age();
	}
	else if (global_indicator == 2)thirdice_pic1age();
	else if (global_indicator >= 3 && global_indicator <= 9)bgmain();
	else if(global_indicator==21){win();}
	else if(global_indicator==22){win();}
	else if(global_indicator == 121)about();
	else if(global_indicator==122)ranking();
	else if(global_indicator==123)credit();
	else if(global_indicator ==124)exit(0);

}
void iMouseMove(int mx, int my)
{
	
}
//Done by Member-3(17.02.04.113)
//Blink Main menu page buttons
//	(mx,my)- the position where the mouse pointer is 
//Variables:
//	blink-blinks buttons according to the value
void iPassiveMouse(int mx, int my)
{
	
    if (global_indicator == 1 && mx > 850 && mx < 1250 && my < 900 && my > 700)  blink = 1;
	else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>580 && my < 780) blink = 2;
	else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>460 && my < 660)blink = 3;
	else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>340 && my < 540)blink = 4;
	else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>220 && my < 420)blink = 5;
	else blink = 0;
}
//Done by all members
//function iMouse() is called when the user presses or releases the mouse
//(mx,my)-the position where the mouse pointer is 
//Variables:
//	(score1,score2)-counts two players dice clicking
//	indicator-determines which dice is clicked
//	mode-determines which name box is clicked
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{    
		
		if(mx>=43&&mx<=68&&my>=860&&my<=890&&global_indicator!=1){global_indicator=1;return;}
		else if(mx>=41 && mx<=103 && my>=737 && my<=773 && global_indicator>=3 &&global_indicator<=9){global_indicator=1;return;}
		
		
		if (global_indicator == 3 && mx > 50 && mx < 112 && my>259 && my < 313)musicon1=0,score1++,indicator=1,cd1=1,cd2=0,cn=0,cnnn=0,strike=0;
		else if (global_indicator == 3 && mx > 1306 && mx < 1363 && my>260 && my < 317)musicon1=0,score2++,indicator=2,cd2=1,cd1=0,cn=0,cnnn=0,strike=0;
			

		if (global_indicator == 1 && mx > 850 && mx < 1250 && my<900 && my > 700)global_indicator = 2;
		else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>580 && my < 780)global_indicator = 121;
		else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>460 && my < 660)global_indicator = 122;
		else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>340 && my < 540)global_indicator = 123;
		else if (global_indicator == 1 && mx > 850 && mx < 1250 && my>220 && my < 420)exit(0);
		else if(global_indicator==2&&mx>653&&mx<1310&&my>491&&my<555){mode=1;}
		else if(global_indicator==2&&mx>653&&mx<1310&&my>288&&my<328){mode=2;}
		else if (global_indicator == 2 && mx>684 && mx<847 && my<266)
		{
			global_indicator = 3;
		}
		
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			
		}
	}
}
//Done by Member-3(17.02.04.113)
//Takes name of players as input
//Variables:
//(len1,len2)-number of index of two arrays
//mode-determines which player's name should be taken
//Arrays:
//	(pnm1,pnm2)-two players name
void iKeyboard(unsigned char key)
{
	  if(mode == 1&&global_indicator==2)
    {
		if(key=='\b')
		{pnm1[len1]='\0';if(len1)len1--;}
		else {
       pnm1[len1]=key;
	   len1++;
	   pnm1[len1]='\0';
		}
    }
	  else if(mode==2&&global_indicator==2)
	  {
		  if(key=='\b')
		  {pnm2[len2]='\0';if(len2)len2--;}
		else {
		  pnm2[len2]=key;
	   len2++;
	   pnm2[len2]='\0';
	  }

	  }
}
//Done by Member-3(17.02.04.113)
//Terminates the program
//END KEY-quits the game
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

}
//Done by all members
//Reads files and store them in 2D arrays
//Files:
//	about.txt-description of the game
//	ranking.txt-top five players details
//	credit.txt-developers information
//Variables:
//	ch-character read from files
//	(player.name,player.score)-objects of player structure
//Arrays:
//	abouttext[][]-characters of "about.txt" file
//	ranking[][]-characters of "ranking.txt" file
//	credit[][]-characters of "credit.txt" file
//this function will read files and stores the characters in respective arrays.To
//sort the names in ranking and load all pictures,call sort() and loadpic().
//it also calls time2(),showtime(),winnermath() and iDraw() at last.
int main()
{	

	int i=0,j=0;
	FILE *fabout=fopen("about.txt","r");
	while(fscanf(fabout,"%c",&ch)!=EOF)
	{
		if(ch=='\n'||i==100)i=0,j++;
		else abouttext[j][i++]=ch;
	}
	fclose(fabout);
  

	FILE *frank=fopen("ranking.txt","r");
	for(int i=0;i<5;i++)
	{
		int score;
		char name[100];
		fscanf(frank,"%s %d",&name,&score);
		strcpy(player[i].name,name);
		player[i].score=score;
	}
	sort(player,5);
	fclose(frank);
	for(int i=0;i<5;i++)
	sprintf(ranklist[i],"%s                                    %d",player[i].name,player[i].score);
	
	
	FILE *fcredit=fopen("credit.txt","r");
	while(fscanf(fcredit,"%c",&ch)!=EOF)
	{
		if(ch=='\n'||i==100)i=0,j++;//
		else credittext[j][i++]=ch;//
	}
	fclose(fcredit);

	
	iSetTimer(80, time2);
	global_indicator = 1;
	iInitialize(1400, 900, "Snake Ladder");

	loadpic();
	iSetTimer(10,winnermeth);
	iSetTimer(100, showTime);
	iStart();
	return 0;
}


