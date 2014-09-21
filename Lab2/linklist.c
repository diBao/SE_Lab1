/**************************************************************************************************/
/* Copyright (C) JG14225101, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  linklist.c                                                           */
/*  PRINCIPAL AUTHOR      :  Baodi                                                                */
/*  SUBSYSTEM NAME        :  SE_Lab2                                                              */
/*  MODULE NAME           :  linklist                                                             */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/17                                                           */
/*  DESCRIPTION           :  linklist for SE_Lab2 program                                         */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Baodi(JG14225101), 2014/09/17
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

tDataNode *FindCmd(tDataNode *head,char *cmd)
{
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }  
    tDataNode *p = head;
    for(; p!=NULL; p=p->next)
    {
        if(!strcmp(p->cmd, cmd))
        {
            return p;   
        }		
    }		
    return NULL;
}

int ShowAllCmd(tDataNode *head)
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
