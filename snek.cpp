#include <ncurses.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>

using namespace std;

struct snekblock{
	int x;
	int y;
	bool fed;
};


//directions:
//0:right
//1:down
//2:left
//3:up
struct snek{
	vector<snekblock> blocks;
	bool dead;
	int dir;
};

//displays the field 
void printField(const snek &snake, const int (&candy)[2]){
	clear();

	for(unsigned int i=0;i<snake.blocks.size();i++){
		mvprintw(snake.blocks[i].y,snake.blocks[i].x,(snake.blocks[i].fed ? "X" : "x"));
	}
	
	mvprintw(candy[1],candy[0],"O");
	refresh();
}

//moves the snake to its next position
void moveSnake(const int height, const int width, snek &snake){	
	if(snake.blocks[snake.blocks.size()-1].fed){
		snekblock newBlock;
		newBlock.fed = false;
		snake.blocks[snake.blocks.size()-1].fed = false;
		snake.blocks.push_back(newBlock);
	}

	rotate(snake.blocks.begin(), snake.blocks.begin()+snake.blocks.size()-1, snake.blocks.end());
	if(snake.blocks.size()>1){
		snake.blocks[0]=snake.blocks[1];
		snake.blocks[0].fed = false;
	}

	switch(snake.dir){
			case 0: snake.blocks[0].x++;
			break;
			case 1: snake.blocks[0].y++;
			break;
			case 2: snake.blocks[0].x--;
			break;
			case 3: snake.blocks[0].y--;
			break;
	}
	if(snake.blocks[0].y>=height) snake.blocks[0].y=0;
	if(snake.blocks[0].y<0) snake.blocks[0].y=height-1;
	if(snake.blocks[0].x>=width) snake.blocks[0].x=0;
	if(snake.blocks[0].x<0) snake.blocks[0].x = width-1;

}

//checks which direction key has been pressed
void checkDir(int &dir, snek &snake){
	switch(dir){
		case KEY_UP: 	
			if(snake.dir != 1) snake.dir=3;
		break;
		case KEY_DOWN: 
			if(snake.dir != 3) snake.dir=1;
		break;
		case KEY_LEFT: 
			if(snake.dir != 0) snake.dir=2;
		break;
		case KEY_RIGHT: 
			if(snake.dir != 2) snake.dir=0;
		break;
	}
}

//moves the candy to a new position
void moveCandy(const int &HEIGHT, const int &WIDTH, const snek &snake, int (&candy)[2]){
	bool free = true;
	
	do{
		candy[0] = rand()%(WIDTH-1);
		candy[1] = rand()%(HEIGHT-1);
		for(unsigned int i=0;i<snake.blocks.size();i++){
			if(candy[0] == snake.blocks[i].x && candy[1]==snake.blocks[i].y) free=false;
		}
	}while(!free);
}

//initiates the snake and the candy
void initSnek(const int &HEIGHT, const int &WIDTH, snek &snake, int (&candy)[2]){
	snekblock block = { WIDTH/2, HEIGHT/2, false };
	snekblock block2 = {WIDTH/2-1,HEIGHT/2, false};
	snekblock block3 = {WIDTH/2-2, HEIGHT/2, false};
	snake.blocks.push_back(block);
	snake.blocks.push_back(block2);
	snake.blocks.push_back(block3);
	snake.dead = false;	
	snake.dir = 0;
	
	moveCandy(HEIGHT, WIDTH, snake, candy);
}

void checkCandy(const int &HEIGHT, const int &WIDTH, snek &snake, int (&candy)[2]){
	if(candy[0] == snake.blocks[0].x && candy[1] == snake.blocks[0].y){
		moveCandy(HEIGHT,WIDTH,snake,candy);
		snake.blocks[0].fed = true;
	}

	for(unsigned int i=0;i<snake.blocks.size();i++){
		for(unsigned int j=0;j<snake.blocks.size();j++){
			if(i!=j && snake.blocks[i].x==snake.blocks[j].x && snake.blocks[i].y==snake.blocks[j].y) snake.dead = true;
		}
	}
}

int main(){
	srand(time(NULL));
	//ncurses init functions
	initscr();	
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr,true);
	nodelay(stdscr, true);

	//the height and the width of the field
	int width;
	int height;
	getmaxyx(stdscr, height,width);

	snek snake;
	int candy[2];
	initSnek(height,width,snake,candy);
	
	clock_t now = clock();
	clock_t before = clock();
	
	//main game loop
	while(!snake.dead){
		
		int ch = getch();		
		checkDir(ch,snake);
		if(now>=before){
			printField(snake,candy);
			before += CLOCKS_PER_SEC/10;
			moveSnake(height, width, snake);
			checkCandy(height, width, snake,candy);
		}
		now=clock();
	}

	printField(snake,candy);
	string death_msg = "You died!";
	mvprintw(height/2,width/2-death_msg.length(),death_msg.c_str());
	nodelay(stdscr, false);
	getch();
	endwin();
	return 0;
}
