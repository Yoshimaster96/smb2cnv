#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <string.h>

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
} start;

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
	int type;
} goal;

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
	float sclx;
	float scly;
	float sclz;
} bumper;

typedef struct
{
	float posx;
	float posy;
	float posz;
	int type;
} banana;

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
	float time;
} frame;

typedef struct
{
	float posx;
	float posy;
	float posz;
} center;

extern int startCount;
extern int goalCount;
extern int bumperCount;
extern int bananaCount;
extern int ignoreCount;
<<<<<<< HEAD
extern int animCount;
=======
>>>>>>> c13dc21b0a6c7ce6bad252b3e3d33432b1db1281
start starts[16];
goal goals[16];
bumper bumpers[16];
banana bananas[16];
float fallOutPlane;
char ignoreList[80][80];
<<<<<<< HEAD
char animList[80][80];
int animFrameCount[80];
frame animFrame[80][256];
center animCenter[80];
=======
>>>>>>> c13dc21b0a6c7ce6bad252b3e3d33432b1db1281

void parseConfig(char * configpath);

#endif
