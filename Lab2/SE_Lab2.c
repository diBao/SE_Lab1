
/**************************************************************************************************/
/* Copyright (C) JG14225101, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  SE_Lab2.c                                                            */
/*  PRINCIPAL AUTHOR      :  Baodi                                                                */
/*  SUBSYSTEM NAME        :  SE_Lab2                                                              */
/*  MODULE NAME           :  SE_Lab2                                                              */
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
#include "linktable.h"
#include "menu.h"

int Help();
int Writer();

#define DESC_LEN	1024
#define CMD_NUM		10
#define CMD_MAX_LEN     128

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*    cmd;
    char*    desc;
    int      (*handler)();
}tDataNode;

tDataNode* FindCmd(tLinkTable * head,char * cmd)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(!strcmp(pNode->cmd, cmd))
        {
            return  pNode;  
        }
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return NULL;
};
/* show all cmd in linktable*/
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n",pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
};

/* menu program */

static tDataNode data[] =
{
    {NULL,"help","this is help cmd",Help,},
    {NULL,"version","menu program v1.0",NULL,},
    {NULL,"writer", "Show the information of writer",Writer}
};
tLinkTable * head = NULL;

main()
{
    head = CreateLinkTable();
    AddLinkTableNode(head,(tLinkTableNode *)&data[0]);
    AddLinkTableNode(head,(tLinkTableNode *)&data[1]);
    AddLinkTableNode(head,(tLinkTableNode *)&data[2]);

    /*cmd line begins*/
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd  > ");
        gets(cmd);
        tDataNode *p = FindCmd(head,cmd);
        if(p == NULL)
        {
            printf("This is a wrong cmd !\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd,p->desc);
        if(p->handler != NULL)
        {
            (p->handler)();
        }
    }  
}

int Help()
{
    ShowAllCmd(head);
    return 0;
}

int Writer()
{
    printf("This code is written by Baodi(JG14225101)\n");
    return 0;
}





