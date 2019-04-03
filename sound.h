// Constants defination
#define RATE 16000	//samples per second
#define CMD "arecord -r16000 -c1 -f S16_LE -d1 -q test.wav"
// dtata structures
struct WAVHDR{
	char ChunkID[4];	//it has to be "RIFF"
	int ChunkSize;		//4-byte number
	char Format[4];		// it has to be "WAVE"

	char Subchunk1ID[4];	//"fmt"
	int Subchunk1Size;	//PCM = 16
	short AudioFormat;	//should be 1
	short NumChannels;	// should be 1 for mono
	int SampleRate;		//16000
	int ByteRate;		//16000*NumChannels*BitsPerSample/8
	int BlockAlign;		//NumChannels*BitsPerSample/8
	short BitsPerSample;	//in our app, 16 (-f S16_LE)

	char Subchunk2ID[4];	// "data"
	int Subchunk2Size;	//
};
// Function declaras
void displayWAVHDR(struct WAVHDR h);
void displayWAVDATA(short []);
