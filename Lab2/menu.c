
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

/*static tDataNode data[] =
{
    {NULL,"help","this is help cmd",Help,},
    {NULL,"version","menu program v1.1",NULL,},
    {NULL,"writer", "Show the information of writer",Writer}
};*/

/*static tLinkTable* head = NULL;
head = CreateLinkTable();*/

int AddCmd(tLinkTable* head,char* command,char* desc_1,int (*handler_1)())
{
    
    static int i = 0;
    static tDataNode *data[CMD_NUM];
    data[i] = (tDataNode *)malloc(sizeof(tDataNode));
    data[i]->pNext = NULL;
    data[i]->cmd = command;
    data[i]->desc = desc_1;
    data[i]->handler = handler_1;
    AddLinkTableNode(head,(tLinkTableNode *)data[i]);
    i++;
}


/*tLinkTable* Initialize()
{
    
    AddLinkTableNode(head,(tLinkTableNode *)&data[0]);
    AddLinkTableNode(head,(tLinkTableNode *)&data[1]);
    AddLinkTableNode(head,(tLinkTableNode *)&data[2]);
    return head;
}
*/



int MenuBegin(ttLinkTable* head)
{
    ShowAllCmd(head);
    while(1)
    {
        /*head = Initialize();*/
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd  > ");
        gets(cmd);
        tDataNode *p = FindCmd(head,cmd);
        if(p == NULL)
        {
            WrongCmd();
            continue;
        }
        printf("%s - %s\n", p->cmd,p->desc);
        if(p->handler != NULL && !(strcmp(cmd,"help")))
        {
            Help(head);
        }
        else
        {
            p->handler();
        }
    }
    return 0;  
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

int Help(tLinkTable* head)
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

int Version()
{
    return 0;
}
/*int AddCmd(char *cmd1,char *desc1)
{
    tLinkTable *q = head;
    tLinkTable *m = p;
    while(1)
    {
        if(q == NULL)
        {
            q->pNext = NULL;
            q->cmd = cmd1;
            q->desc = desc1;
            q->handler = null;
            m->pNext = q;
            break;
        }
        m = q;
        q = q->pNext;
    {
}*/



