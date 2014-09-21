
/**************************************************************************************************/
/* Copyright (C) JG14225101, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Baodi                                                                */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/21                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Baodi(JG14225101), 2014/09/21
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"
#include "menu.h"

int Help();
int Writer();

#define DESC_LEN	    1024
#define CMD_NUM		    10
#define CMD_MAX_LEN     128

/* menu program */

static tDataNode data[] =
{
    {NULL,"help","this is help cmd",Help,},
    {NULL,"version","menu program v1.1",NULL,},
    {NULL,"writer", "Show the information of writer",Writer}
};

tLinkTable* head = NULL;
tLinkTable* Initialize()
{
    head = CreateLinkTable();
    AddLinkTableNode(head,(tLinkTableNode *)&data[0]);
    AddLinkTableNode(head,(tLinkTableNode *)&data[1]);
    AddLinkTableNode(head,(tLinkTableNode *)&data[2]);
    return head;
}

/*find the corresponding cmd*/
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
    printf("menu list:\n");
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n",pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

/* menu program */

int Help()
{
    ShowAllCmd(head);
    return 0;
}

int WrongCmd()
{
    printf("This is a wrong cmd !\n ");
}

int Writer()
{
    printf("This code is written by Baodi(JG14225101)\n");
    return 0;
}



