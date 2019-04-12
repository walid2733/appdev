// this is main.c
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include "screen.h"		// for user-defined header, use double quotes
#include "sound.h"
#include "comm.h"
int main()
{
//	int i, arr[80];
//	for(i=0; i<80; i++)
//		arr[i] = rand()%70 + 30;
	FILE *f;
	short sd[RATE];		// for all samples in 1 second
	while(1)
{
	int ret = system(CMD);
	if(ret ==  SIGINT) break;
	f = fopen("test.wav", "r");	// open the file  for read only
	clearScreen();
	setColors(RED, bg (BLUE));
//	printf("Printed from main.\n");
//	barChart(arr);
	if (f == NULL)
	{
		printf("cannot open the wave file\n");
		return 1;
	}
	struct WAVHDR h;	// instance of wave header
	fread (&h, sizeof(h), 1 , f);	// read wave header to h
	displayWAVHDR(h);	// sjpw wav header information
	fread(&sd, sizeof(sd), 1, f);
	displayWAVDATA(sd);
	fclose(f);		// close the opened file
	sendDATA(sd);
}
	resetColors();
//	printf("Another message\n");
}
