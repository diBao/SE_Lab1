

/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Bao Di                                                               */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/30                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Bao Di, 2014/09/30
 *
 */

#include "menu.h"
#include <string.h>
#define CMD_LEN 100

typedef struct Node
{
    ;
}tNode;

/* initial a command list*/
int InitCMDList()
{
    return SUCCESS;
}

/* destroy this command list */
int DestroyCMDList()
{
    return SUCCESS;
}

/* get user scanf */
int GetScanf()
{
    return SUCCESS;
}

/*add a new cmd */
int AddCmd(char *cmd,char *info)
{
    if(cmd == NULL || info == NULL)
    {
        return FAILURE;
    }
    return SUCCESS;
}

/* delete this cmd */
int DelCmd(char *cmd)
{
    if(cmd == NULL)
    {
        return FAILURE;
    }
    return SUCCESS;
}

/* execute cmd ,find the node by the way of one by one*/
int ExeCMD(char *cmd)
{
    if(cmd == NULL)
    {
        return FAILURE;
    }
    return SUCCESS;
}

/*show all command ,visite all nodes one by one */
int ShowAllCMD()
{
    return SUCCESS;
}
