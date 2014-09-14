
/**************************************************************************************************/
/* Copyright (C) JG14225101, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  SE_Lab1.c                                                            */
/*  PRINCIPAL AUTHOR      :  Baodi                                                                */
/*  SUBSYSTEM NAME        :  SE_Lab1                                                              */
/*  MODULE NAME           :  SE_Lab1                                                              */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/11                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Baodi(JG14225101), 2014/09/11
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Help();
int Writer();

#define DESC_LEN		1024
#define CMD_NUM			10
#define CMD_MAX_LEN     128			

typedef struct DataNode
{
	char*	cmd;
	char*	desc;
	int 	(*handler)();
	struct	DataNode *next;
}tDataNode;

static tDataNode head[] =
{
	{"help","this is help cmd",Help,&head[1]},
	{"version","menu program v1.0",NULL,&head[2]},
    {"writer", "Show the information of writer",Writer, NULL}
};

main()
{
	/*cmd line begins*/
	while(1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Input a cmd  > ");
		gets(cmd);
		tDataNode *p = head;
		for(; p!=NULL; p=p->next)
		{
			if(!strcmp(p->cmd, cmd))
			{
				printf("%s - %s\n", p->cmd,p->desc);
				if(p->handler != NULL)
				{
					p->handler();
				}
				break;
			}		
		}		
		if(p == NULL)
		{
			printf("This is a wrong cmd !\n ");
		}
	}
}


int Help()
{
	printf("Menu List:\n");
	tDataNode *p = head;
	while(p != NULL)
	{
		printf("%s - %s\n",p->cmd, p->desc);
		p = p->next;
	}
return 0;
}

int Writer()
{
	printf("This code is written by Baodi(JG14225101)\n");
	return 0;
}
