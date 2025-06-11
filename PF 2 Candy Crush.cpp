#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include <string>
#include <cmath> 
#include <GL/glut.h> 

using namespace std;


			//hassaan mudassar and usman bari

			//i230536 and i230680

			//PF-B



			//Function prototypes


			void disp();

			void click(int button, int state, int x, int y);

			void swap(int r1, int c1, int r2, int c2);

			void check();

			void rmv();

			void gen();

			void bar();

			void timer();

			void menu();

			void name(); 

			void prbutton();

			void key(unsigned char key, int x, int y);

			void hint(); 

			void makehint();



			//Global variable


			int candy[5][5];



			    void set(int w, int h)                                                      {
			    
			    glMatrixMode(GL_PROJECTION);
			    
			    glLoadIdentity();
			    
			    glOrtho(0, w, 0, h, -1, 1);
			    
			    glMatrixMode(GL_MODELVIEW);
			    
			    glLoadIdentity();
						                                                        }
						                                                        

			    void sq(int x, int y, int size, float* color) 				{
			    
			    glColor3fv(color);
			    
			    glBegin(GL_QUADS);
			    
			    glVertex2i(x, y);
			    
			    glVertex2i(x + size, y);
			    
			    glVertex2i(x + size, y + size);
			    
			    glVertex2i(x, y + size);
			    
			    glEnd();
													}

			    void circle(int x, int y, int r, float* color) 
													{
			    
			    glColor3fv(color);
			    
			    glBegin(GL_TRIANGLE_FAN);
			    
			    glVertex2i(x, y);
			    
			    for(int i=0; i<=360; i++) 							{
			    
			    float angle=i*3.14159/180;
				
			    glVertex2i(x + r * cos(angle), y + r * sin(angle));
			    										}
			    glEnd();
													
													}

			    void tri(int x1, int y1, int x2, int y2, int x3, int y3, float* color) 

													{
			    
			    glColor3fv(color);
			    
			    glBegin(GL_TRIANGLES);
			    
			    glVertex2i(x1, y1);
			    
			    glVertex2i(x2, y2);
			    
			    glVertex2i(x3, y3);
			    
			    glEnd();
													}



			    static int state=0; //initially set the game state to MENU

			    void DrawCandy()                                                            {
			    
			    
				
				float colors[5][3] =  
						                                                        {
				{1.0f, 0.0f, 0.0f},  
				
				{0.0f, 1.0f, 0.0f},  
				
				{0.0f, 0.0f, 1.0f},  
				
				{1.0f, 1.0f, 0.0f},  
				
				{1.0f, 0.0f, 1.0f}   
			    										};

			    
			    
			    //local static variables
			    
			    
			    static int r=-1; 
			    static int c=-1; 

			    for(int i=0; i<5; i++) 							{
				
			    for(int j = 0; j<5; j++) 							
			    										{
				    
			    int xPos = j * 100 + 50;
				    
			    int yPos = i * 100 + 50;

			    int s=candy[i][j];
				    
			    if(s==0) 									{
					
			    sq(xPos, yPos, 50, colors[s]);
				    									} 
			    else if(s==1) 
			    										{
					
			    circle(xPos + 25, yPos + 25, 25, colors[s]);
				    									} 
				    
			    else if(s==2) 
			    										{
					
			    tri(xPos, yPos, xPos + 50, yPos, xPos + 25, yPos + 50, colors[s]);
				    									}

				   
			    if(r==i && c==j) 								{
					
			    glColor3f(1.0f, 1.0f, 1.0f); 
					
			    glLineWidth(2.0f);
				       
			    glBegin(GL_LINE_LOOP);
					
			    glVertex2i(xPos, yPos);
				      
			    glVertex2i(xPos + 50, yPos);
					
			    glVertex2i(xPos + 50, yPos + 50);
					
			    glVertex2i(xPos, yPos + 50);
					
			    glEnd();
				   									}
				
													}
			    
			    										}
													
													}

			    void GenerateRandomCandy() 
													{
			    
			    for(int i=0; i<5; i++) 							{
				
			    for(int j=0; j<5; j++) 							{
				    
			    candy[i][j]= rand() % 3; 
													}
			    				
			    									
			    										}


													}

			    static bool stop=false;

			    void disp() 								{
			    
			    
			    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			    
			    glClear(GL_COLOR_BUFFER_BIT);

			    if(state==1) 								{
			     
			    if(!stop) 									{
				    
			    DrawCandy(); 
				  
			    bar(); 
			     
			    timer();
				    
			    makehint();
				    
													} 
			    else 
			    										{
				    
			    glColor3f(1.0f, 1.0f, 1.0f); 
				   
			    glRasterPos2f(250, 300);                             
				   
			    string text = "PAUSED";
			    
			    for(char c : text) 								{
					
			    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);     
				    									}
				
													}
			    
			    
			    										} 
			    
			    else if(state==0) 
			    										{
				
				
			    menu(); 
			    										}

			    glutSwapBuffers();
													}

			    void menu() 				
													{
			    
			    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			    
			    glClear(GL_COLOR_BUFFER_BIT);


			    
			    glColor3f(1.0f, 1.0f, 1.0f);
			    
			    
			    glRasterPos2f(150, 500);
			    
			    string playGameText = "Play Game (press Enter Key)";
			    
			    for(char c : playGameText) 							{
				
			    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
			    										}

			   
			    glRasterPos2f(100, 400);
			    
			    string showHighScoresText= "Show High Scores (press Escape key)";
			    
			    for(char c : showHighScoresText) {
				
			    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
			    }

			    

			    name(); 

			    glutSwapBuffers();
													}

			    static string playerName;

			    void name() 								{

			    glColor3f(1.0f, 1.0f, 1.0f); 
			    
			    glRasterPos2f(150, 300);
			    
			    string enterNameText = "Enter your name:";
			    
			    for(char c : enterNameText) 						{
				
			    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
			    										}


			    glRasterPos2f(300, 300);
			    
			    for(char c : playerName) 							{
				
				
			    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
			    										}


													}


			    void prbutton() 
													
													{
			    stop= !stop;

													}

			    void key(unsigned char key, int x, int y) 

													{
			    
			    switch (key) 
			    										{
			       
			    case 13: 
				    
			    state = 1;
				   
			    GenerateRandomCandy(); 
				    
			    glutPostRedisplay(); 
				   
			    break;
				
			    case 27: 
				    
			    break;
			       
			    case 32: 
				    
			    prbutton(); 
				    
			    glutPostRedisplay(); 
				    
			    break;
				
			    case 'h': 
				
			    case 'H':
				 
			    hint(); 
				    
			    break;
			    										}


													}

			    void click(int button, int state, int x, int y) 				{
			    
			    
			    static int r=-1; 
			    static int c=-1; 

			    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 			{
				
			    int col = x/100;
			       
			    int row = (600-y)/100; 

				
			    if(row >= 0 && row < x && col >= 0 && col < y) 				{
				    
			    
			    if(r == -1 && c == -1) 							{
					
			    r=row;
					
			    c=col;
				    
				    
				    									} 
				    
			    else 			
			    										{
				       
			    
			    if(abs(r - row) + abs(c - col) == 1) 					{
					    
			    swap(r, c, row, col);

					
			    check();

					 
			    r=-1;
				      
				      
			    c=-1;

			    
			    glutPostRedisplay(); 
					
											        	} 
		        
			    else 									{
					   
			    r=row;
					    
			    c=col;
													}
				   
				   		 					
				   		 							}
				
													}
			    
			    
			    										}

													}

			    void swap(int r1, int c1, int r2, int c2) 				
													{
			    
			    int temp=candy[r1][c1];
			    
			    candy[r1][c1]=candy[r2][c2];
			    
			    candy[r2][c2]=temp;
													}

			    static int score=0;


			    void check() 							        {
			    
			    bool found=false;

			   
			    for(int i = 0; i < 5; i++) 							{
				
			    int c = 1;
				
			    for(int j = 1; j < 5; j++) 							{
				    
			      
			    if(candy[i][j] == candy[i][j - 1]) 						{
					
					
			    c++;
				    									} 
			    else 
			    
			    										{
					
			    if(c >= 3) 
			    										{
					    
			    score += (c - 2) * 10; 
					    
			    found=true;
					    
					    
			    for(int k = j - 1; k >= j - c; k--) 					{
						
			    candy[i][k]=-1; 
					    								}
					
											
													}
			    c=1;
				    									}
				
													}
			    if(c >= 3) 
			    
			    										{
				    
			    score += (c - 2) * 10; 
				    
			    found = true;
				    
			    
			    
			    for(int k = 5 - 1; k >= 5 - c; k--) 					{
					
					
			    candy[i][k]=-1; 
				    									}
				
				
													}
			    
			    										}

			   
			    for(int j = 0; j < 5; j++) 							{
				
			    int c=1;
				
				
			    for(int i = 1; i < 5; i++) 							{
				    
			    if(candy[i][j] == candy[i - 1][j]) 						{
					
					
			    c++;
				    									} 
				    
			    else 		
			    										{
					
			    if(c >= 3) 
			    
			    										{
					    
			    score += (c - 2) * 10; 
					    
			    found=true;
					    
			    for(int k = i - 1; k >= i - c; k--) 					{
						
			    candy[k][j]=-1; 
					    								}
					
					
													}
			    c=1;
				    									}
				
				
													}
			    if(c >= 3) 
			    										{
				    
			    score += (c - 2) * 10; 
				    
				    
			    found=true;
			    
			    
			    for(int k = 5 - 1; k >= 5 - c; k--) 					{
					
					
			    candy[k][j]=-1; 
				    									}
				
													}
			    
			    
			    										}

			    if(found) 									{
				
			    rmv();
			    gen();
			    check(); 
			    										}

													}

			    void rmv() 

													{
			    
			    for(int j = 0; j < 5; j++) 							{
				
			    int k = 5 - 1;
				
			    for(int i = 5 - 1; i >= 0; i--) 						{
				    
			    if(candy[i][j] != -1) 
			    										{
					
					
			    candy[k][j] = candy[i][j];
					
			    k--;
				    									}
			       
			       										}
			    for(; k >= 0; k--) 
			    
			    										{
				    
				    
			    candy[k][j]=-2; 
													}
			    
			    										}

													}

			    void gen() 

													{
			    for(int j = 0; j < 5; j++) 
			    										{
			    
			    
			    int empty = 0;
				
			    for(int i = 0; i < 5; i++) 							{
				    
			    if(candy[i][j] == -2) 							{
					
			    empty++;
				    									} 
				    
			    else if(empty > 0) 
			    										{
					
			    candy[i - empty][j] = candy[i][j]; 
				    									}
				
				
													}
			    for(int i = 0; i < empty; i++) 
			    
			    										{
				    
				    
			    candy[5 - 1 - i][j] = rand() % 3; 
													}
			    
			    										}


													}

			    void bar() 									{
			    
			    glColor3f(1.0f, 1.0f, 1.0f); 
			    
			    glRasterPos2f(10, 580); 
			    
			    string scoreText = "Score: " + to_string(score);
			   
			    for(char c : scoreText) 							{
				
			    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c); 
			    										}

													}

			    static int timepassed=0;

			    void timer() 								{
			    
			    glColor3f(1.0f, 1.0f, 1.0f); 
			    
			    glRasterPos2f(540, 580); 
			    
			    int mins=timepassed / 60;
			    
			    
			    int sec=timepassed % 60;
			    
			    string clockText = (mins < 10 ? "0" : "") + to_string(mins) + ":" + (sec < 10 ? "0" : "") + to_string(sec); 
			    
			    for(char c : clockText) 							{
				
			    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c); 
			   
			   
			   										}

													}

			    void Timer(int value) 							{
			    
			    
			    if(!stop) 									{
			       
			    timepassed++;
			    										}
			    glutPostRedisplay();
			    
			    glutTimerFunc(1000, Timer, 0);
													}

			    void makehint() 

													{
			    glColor3f(1.0f, 1.0f, 1.0f); 
			    
			    glBegin(GL_QUADS);
			    
			    glVertex2i(500, 50); 
			    
			    glVertex2i(600, 50); 
			    
			    glVertex2i(600, 0); 
			    
			    glVertex2i(500, 0);
			    
			    glEnd();

			    
			    glColor3f(0.0f, 0.0f, 0.0f); 
			    
			    glRasterPos2f(520, 20); 
			    
			    string hintButtonText = "hint(h)";
			    
			    for(char c : hintButtonText) 						{
			    
			    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
			   										
			   										 }}
			    void hint() 								{
			    
			    for(int i = 0; i < 5; ++i) 							{
				
			    for(int j = 0; j < 5; ++j) 							{
				    
			    if(j < 4 && candy[i][j] != candy[i][j + 1]) 				{
				       
			    swap(i, j, i, j + 1);

					
			    check();

					
			    if(score > 0) 								{
					    
			    cout<< "hint: Swap (" << i << ", " << j << ") with (" << i << ", " << j + 1 << ")" <<endl;
					    
			    swap(i, j, i, j + 1);
					    
			    glutPostRedisplay();
					    
					    
			    return;
													}

					
			    swap(i, j, i, j + 1);
				   					 				}

				    
			    if(i < 4 && candy[i][j] != candy[i + 1][j]) 
			    										{
					
			    swap(i, j, i + 1, j);

				     
			    check();

					
			    if(score > 0) 								{
					    
			    
			    cout<< "hint: Swap (" << i << ", " << j << ") with (" << i + 1 << ", " << j << ")" <<endl;
					    
			    swap(i, j, i + 1, j); 
					    
					    
			    glutPostRedisplay();
			    return;
													}

				       
			    swap(i, j, i + 1, j);
				   									}
				
													}
			    
			    										}

			    
			    cout<<"No hints available." <<endl;
													}


			    int main(int argc, char* argv[]) 						{
			    
			    
			    srand(time(NULL)); 


			    cout<<"Enter your name: ";
			    
			    getline(cin, playerName);

			    GenerateRandomCandy(); 

			    
			    int w=600,h=600;

			    
			    glutInit(&argc, argv);
			    
			    
			    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
			    
			    glutInitWindowSize(w, h);
			    
			    glutInitWindowPosition(50, 50);
			    
			    glutCreateWindow("Welcome to our Game");
			    
			    set(w,h);

			    
			    glutKeyboardFunc(key);
			    
			    glutDisplayFunc(disp);
			    
			    glutMouseFunc(click); 
			    
			    glutTimerFunc(1000, Timer, 0); 

			    glutMainLoop();

			    return 0;
													}

			    #endif 
