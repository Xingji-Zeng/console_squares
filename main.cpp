#include<iostream>
#ifdef OS_WINDOWS
	#include<Windows.h>
#endif
using namespace std;

#define COL_DARK_GREEN 0x02

void setColor(int fg,int bg){
	HANDLE hcons=GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attr=0;
	if(fg & COL_INTENSITY)
		attr |=FOREGEOUND_INTENSITY;

	if(bg & COL_INTENSITY)
		attr |= BACKGROUND_INTENSITY;
}	

int main()
{
	setColor(COL_DARK_GREEN);
	cout << "white\n";
	return 1;

}
