struct Button{
	int id;
	int x, y;
	int width, height;
	char title[50];
	bool isHover, isChoose;
	int align;
	/*
	-1: Left
	0: center
	1: right
	*/
	
	Button(int i, int xx, int yy, int wid, int hei, char s[50], int al){
		id = i;
		x = xx; y = yy; 
		width = wid; height = hei;
		strcpy(title, s);
		align = al;
	}
	
	void draw(){
		setfillstyle(SOLID_FILL, isHover ? BG_BUTTON_SELECT : BG_BUTTON_DEFAULT);
		bar(x, y, x + width, y + height);

		
		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		setbkcolor(isHover ? BG_BUTTON_SELECT : BG_BUTTON_DEFAULT);
		setcolor(isHover ? TEXT_BUTTON_SELECT : TEXT_BUTTON_DEFAULT);
		if(align == -1) outtextxy(x+10, y + (height-textheight(title))/2, title);
		else if(align == 0) outtextxy(x + width/2 - textwidth(title)/2, y + (height-textheight(title))/2, title);
		
		setbkcolor(BG_COLOR);
	}
	
	bool isMouseHover(int mx, int my){
		if(mx >= x && mx <= x+width && my >= y  && my <= y+height){
			return true;
		}
		return false;
	}
};

