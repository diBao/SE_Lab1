/**************************************************************************************************/
/* Copyright (C) JG14225101, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  linklist.h                                                           */
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


/* data struct and its operation */

typedef struct DataNode
{
    char*    cmd;
    char*    desc;
    int(*handler)();
    struct   DataNode *next;
}tDataNode;

tDataNode *FindCmd(tDataNode *head,char *cmd);

int ShowAllCmd(tDataNode *head);

