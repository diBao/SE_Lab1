
/**************************************************************************************************/
/* Copyright (C) JG14225101, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.h                                                               */
/*  PRINCIPAL AUTHOR      :  Baodi                                                                */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/21                                                           */
/*  DESCRIPTION           :  interface of menu.c                                                  */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Baodi(JG14225101), 2014/09/21
 *
 */

#include"linktable.h"

/* data struct and its operation */
typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*    cmd;
    char*    desc;
    int      (*handler)();
}tDataNode;

/*Initialize cmd*/
tLinkTable* Initialize();

/* show all the command */
int ShowAllCmd();

/*find the corresponding cmd*/
tDataNode* FindCmd();

/* show the help list */
int Help();

/* show the information of writer */
int Writer();

/* if user input a wrong command, show this */
int WrongCmd();

