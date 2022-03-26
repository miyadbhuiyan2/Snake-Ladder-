//Done by all members
//This header file loads all the images of the game in respective 
//variables.
//All kinds of variables arrays are declared
//in this header file.
#ifndef PIC_H_INCLUDED
#define PIC_H_INCLUDED

int timecount = 0;
int global_indicator = 0, blink = 0;
char abouttext[17][300],ch,credittext[37][300];
char ranklist[5][300];
int guti_x1 = 120, guti_y1 = 200, guti_x2 = 1200, guti_y2 = 200;
int randm = 0, antirepeat = 0;
int guti_move = 0, cn = 0;
int indicator=0;
int current_position1 = 0, current_position2 = 0;
int timec2 = 0;
int musicon1=1,musicon2=1,musicon3=1,musicon4=1,final=0;
char sc1[100],sc2[100];
int cnnn=0,gutmv=0,strike=0,num,score1=0,score2=0,tech=0,repeat=0,mode=1,len1=0,len2=0,cd1=0,cd2=0;
char pnm1[1000],pnm2[1000];
int ranno[1000],ranindex=0,ran=0;
int pictoint[]={0,1,2,3,4,5,6};
int sirisap[]={0,1,2,3,25,5,6,7,8,9,10,
11,12,46,14,15,16,17,18,19,20,
21,22,23,24,25,26,5,28,29,30,
31,32,49,34,35,36,37,38,39,3,
41,63,18,44,45,46,47,48,49,69,
51,52,53,31,55,56,57,58,59,60,
61,81,63,64,65,45,67,68,69,70,
71,72,73,92,75,58,77,78,79,80,
81,82,83,84,85,86,87,88,53,90,
91,92,93,94,95,96,97,98,41,100}; 

int x[]={270,360,448,536,624,712,800,888,976,1064, 
1064,976,888,800,712,624,536,448,360,270,
270,360,448,536,624,712,800,888,976,1064,
1064,976,888,800,712,624,536,448,360,270,
270,360,448,536,624,712,800,888,976,1064,
1064,976,888,800,712,624,536,448,360,270,
270,360,448,536,624,712,800,888,976,1064,
1064,976,888,800,712,624,536,448,360,270,
270,360,448,536,624,712,800,888,976,1064,
1064,976,888,800,712,624,536,448,360,270};

int y[]={105,105,105,105,105,105,105,105,105,105,
184,184,184,184,184,184,184,184,184,184,
263,263,263,263,263,263,263,263,263,263,
342,342,342,342,342,342,342,342,342,342,
421,421,421,421,421,421,421,421,421,421,
500,500,500,500,500,500,500,500,500,500,
579,579,579,579,579,579,579,579,579,579,
658,658,658,658,658,658,658,658,658,658,
737,737,737,737,737,737,737,737,737,737,
816,816,816,816,816,816,816,816,816,816};

int igover;
int dpn1,dpn,dpn2,dpn3,dpn4,dpn5,dpn6,dpn7,dpn8,dpn9,dpn10,dpn11;
int aboutim;
int backim;
int creditim;
int rankingim;
int namingim;
int gamepageim;
int coinim1;
int coinim2;
int diceim1;
int diceim2;
int firstpageim;
int Lim1;
int Lim2;
int Lim3;
int Lim4;
int Lim5;
int Lim6;
int Lim7;
int secondpageim;
int playbtim;
int aboutbtim;
int rankingbtim;
int creditbtim;
int quitbtim;

void loadpic()
{
	 aboutim=iLoadImage("pic\\about.png");
 backim=iLoadImage("pic\\back.png");
 creditim=iLoadImage("pic\\credit.png");
 rankingim=iLoadImage("pic\\ranking.png");
 namingim=iLoadImage("pic\\1.jpg");
 gamepageim=iLoadImage("pic\\bg.jpg");
 coinim1=iLoadImage("pic\\coin1.png");
 coinim2=iLoadImage("pic\\coin2.png");
 diceim1=iLoadImage("pic\\d2.png");
 diceim2=iLoadImage("pic\\d2.png");
 firstpageim= iLoadImage("pic\\fp.png");
 Lim1= iLoadImage("pic\\ld\\4.png");
 Lim2=iLoadImage("pic\\ld\\5.png");
 Lim3=iLoadImage("pic\\ld\\6.png");
 Lim4=iLoadImage("pic\\ld\\8.png");
 Lim5=iLoadImage("pic\\ld\\9.png");
 Lim6=iLoadImage("pic\\ld\\10.png");
 Lim7=iLoadImage("pic\\ld\\11.png");
 secondpageim= iLoadImage("pic\\bg1.png");
 playbtim=iLoadImage("pic\\bt1.png");
 aboutbtim= iLoadImage("pic\\bt2.png");
 rankingbtim= iLoadImage("pic\\bt3.png");
 creditbtim=iLoadImage("pic\\bt4.png");
 quitbtim= iLoadImage("pic\\bt5.png");

 dpn1=iLoadImage("pic\\1.png");
 dpn2=iLoadImage("pic\\2.png");
 dpn3=iLoadImage("pic\\3.png");
 dpn4=iLoadImage("pic\\4.png");
 dpn5=iLoadImage("pic\\5.png");
 dpn6=iLoadImage("pic\\6.png");
 igover=iLoadImage("pic\\gmo.jpg");

}
#endif
