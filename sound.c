#include<stdio.h>
#include<math.h>
#include"sound.h"
#include"screen.h"
// this function takes 1 sec of samples (16000 in our 
// case) and calculate 80 pieces of RMS value, and then 
// turn these values into decibles, and display them as
// a barchart
void displayWAVDATA(short s[]){
	double rms[80];		// because we have 16000 samples, 16000/80 = 200
				// therefor every 200 samples makes one RMS
	int db[80];		//for decible values
	int i, j;		// nested loop counters
	short *ptr = s;		// use pointer point to the brginning of the samples

	for(i=0; i<80; i++){		//outer loop repeats 80 times
		double sum = 0;		//initialize the sum
		for(j=0; j<200; j++){
			sum += (*ptr)*(*ptr);	//accumulate the sum
			ptr++;
		}
		rms[i] = sqrt(sum/200);
		db[i] = 20*log10(rms[i]);	//decible value
#ifdef DEBUG					//condition compilation
		printf("RMS[%d] = %f\n", i, rms[i]);
#endif
	}	//end of for
#ifndef DEBUG
	barChart(db);
#endif
}
void showID(char *name, char *value){
	printf("%s: ", name);
	for(int i=0; i<4; i++)
		printf("%c", value[i]);
		puts("");	// \n
}
//function defination
void displayWAVHDR(struct WAVHDR h){
#ifdef DEBUG
	showID("Chunk ID", h.ChunkID);
	printf("Chunk size: %d\n", h.ChunkSize);
	showID("Format", h.Format);
	showID("Subchunk1 ID", h.Subchunk1ID);
	printf("Subchunk1 size: %d\n", h.Subchunk1Size);
	printf("Audio format: %d\n", h.AudioFormat);
	printf("Num of Channels: %d\n", h.NumChannels);
	printf("Sample rate: %d\n", h.SampleRate);
	printf("Byte rate: %d\n", h.ByteRate);
	printf("Block align: %d\n", h.BlockAlign);
	printf("Bits per sample: %d\n", h.BitsPerSample);
	showID("Subchunk 2 ID: ", h.Subchunk2ID);
	printf("Subchunk 2 size: %d\n", h.Subchunk2Size);
#else
	setColors(RED, bg (BLUE));
	printf("\033[1;1H");
	printf("test.wav            \n");
	setColors(YELLOW, bg(GREEN));
	printf("\033[1;21H");
	printf("Sample rate=%d        \n", h.SampleRate);
	setColors(WHITE, bg(MAGENTA));
	printf("\033[1;61H");
	printf("Duration=%.2f          \n", (float)h.Subchunk2Size/h.ByteRate);
#endif
}
