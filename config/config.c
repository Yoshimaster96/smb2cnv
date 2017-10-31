#include "config.h"

int startCount = 0;
int goalCount = 0;
int bumperCount = 0;
int bananaCount = 0;
int ignoreCount = 0;
int animCount = 0;

void parseConfig(char * configpath)
{
	FILE * config = fopen(configpath,"r");
	char line[80];
	char ident[80];
	int index;
	char param1[80];
	char param2;
	char value[80];
	while(fgets(line,80,config)!=NULL)
	{
		sscanf(line," %s [ %i ] . %s . %c = %s ",ident,&index,param1,&param2,value);
		if(strcmp(ident,"start")==0)
		{
			if(strcmp(param1,"pos")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') starts[index].posx = valuef;
				else if(param2=='y') starts[index].posy = valuef;
				else if(param2=='z') starts[index].posz = valuef;
				if((index+1)>startCount) startCount = (index+1);
			}
			else if(strcmp(param1,"rot")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') starts[index].rotx = valuef;
				else if(param2=='y') starts[index].roty = valuef;
				else if(param2=='z') starts[index].rotz = valuef;
				if((index+1)>startCount) startCount = (index+1);
			}
		}
		else if(strcmp(ident,"goal")==0)
		{
			if(strcmp(param1,"pos")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') goals[index].posx = valuef;
				else if(param2=='y') goals[index].posy = valuef;
				else if(param2=='z') goals[index].posz = valuef;
				if((index+1)>goalCount) goalCount = (index+1);
			}
			else if(strcmp(param1,"rot")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') goals[index].rotx = valuef;
				else if(param2=='y') goals[index].roty = valuef;
				else if(param2=='z') goals[index].rotz = valuef;
				if((index+1)>goalCount) goalCount = (index+1);
			}
			else if(strcmp(param1,"type")==0)
			{
				char valuec = 'B';
				sscanf(value,"%c",&valuec);
				if(valuec=='B') goals[index].type = 0;
				else if(valuec=='G') goals[index].type = 1;
				else if(valuec=='R') goals[index].type = 2;
				if((index+1)>goalCount) goalCount = (index+1);
			}
		}
		else if(strcmp(ident,"bumper")==0)
		{
			if(strcmp(param1,"pos")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') bumpers[index].posx = valuef;
				else if(param2=='y') bumpers[index].posy = valuef;
				else if(param2=='z') bumpers[index].posz = valuef;
				if((index+1)>bumperCount) bumperCount = (index+1);
			}
			else if(strcmp(param1,"rot")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') bumpers[index].rotx = valuef;
				else if(param2=='y') bumpers[index].roty = valuef;
				else if(param2=='z') bumpers[index].rotz = valuef;
				if((index+1)>bumperCount) bumperCount = (index+1);
			}
			else if(strcmp(param1,"scl")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') bumpers[index].sclx = valuef;
				else if(param2=='y') bumpers[index].scly = valuef;
				else if(param2=='z') bumpers[index].sclz = valuef;
				if((index+1)>bumperCount) bumperCount = (index+1);
			}
		}
		else if(strcmp(ident,"banana")==0)
		{
			if(strcmp(param1,"pos")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') bananas[index].posx = valuef;
				else if(param2=='y') bananas[index].posy = valuef;
				else if(param2=='z') bananas[index].posz = valuef;
				if((index+1)>bananaCount) bananaCount = (index+1);
			}
			else if(strcmp(param1,"type")==0)
			{
				char valuec = 'N';
				sscanf(value,"%c",&valuec);
				if(valuec=='N') bananas[index].type = 0;
				else if(valuec=='B') bananas[index].type = 1;
				if((index+1)>bananaCount) bananaCount = (index+1);
			}
		}
		else if(strcmp(ident,"fallout")==0)
		{
			if(strcmp(param1,"pos")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='y') fallOutPlane = valuef;
			}
		}
		else if(strcmp(ident,"background")==0)
		{
			char values[80] = "";
			sscanf(value,"%s",values);
			strcpy(ignoreList[index],values);
			if((index+1)>ignoreCount) ignoreCount = (index+1);
		}
		else if(strcmp(ident,"animobj")==0)
		{
			if(strcmp(param1,"file")==0)
			{
				FILE * fp = fopen(value,"r");
				char lineb[80];
				int indexb;
				char param1b[80];
				char param2b;
				char valueb[80];
				while(fgets(lineb,80,fp)!=NULL)
				{
					sscanf(lineb," frame [ %i ] . %s . %c = %s ",&indexb,param1b,&param2b,valueb);
					if(strcmp(param1b,"pos")==0)
					{
						float valuef = 0.0;
						sscanf(valueb,"%f",&valuef);
						if(param2b=='x') animFrame[index][indexb].posx = valuef;
						else if(param2b=='y') animFrame[index][indexb].posy = valuef;
						else if(param2b=='z') animFrame[index][indexb].posz = valuef;
						if((indexb+1)>animFrameCount[index]) animFrameCount[index] = (indexb+1);
					}
					else if(strcmp(param1b,"rot")==0)
					{
						float valuef = 0.0;
						sscanf(valueb,"%f",&valuef);
						if(param2b=='x') animFrame[index][indexb].rotx = valuef;
						else if(param2b=='y') animFrame[index][indexb].roty = valuef;
						else if(param2b=='z') animFrame[index][indexb].rotz = valuef;
						if((indexb+1)>animFrameCount[index]) animFrameCount[index] = (indexb+1);
					}
					else if(strcmp(param1b,"time")==0)
					{
						float valuef = 0.0;
						sscanf(valueb,"%f",&valuef);
						animFrame[index][indexb].time = valuef;
						if((indexb+1)>animFrameCount[index]) animFrameCount[index] = (indexb+1);
					}
				}
				fclose(fp);
				if((index+1)>animCount) animCount = (index+1);
			}
			else if(strcmp(param1,"name")==0)
			{
				char values[80] = "";
				sscanf(value,"%s",values);
				strcpy(animList[index],values);
				if((index+1)>animCount) animCount = (index+1);
			}
			else if(strcmp(param1,"center")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') animCenter[index].posx = valuef;
				else if(param2=='y') animCenter[index].posy = valuef;
				else if(param2=='z') animCenter[index].posz = valuef;
				if((index+1)>animCount) animCount = (index+1);
			}
		}
	}
	fclose(config);
}
