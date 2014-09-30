
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

#ifndef MENU_H
#define MENU_H

#define SUCCESS 0
#define FAILURE (-1)

/* initial a command list*/
int InitCMDList();

/* destroy this command list */
int DestroyCMDList();

/* get user scanf */
int GetScanf();

/*add a new cmd */
int AddCmd(char *cmd,char *info);

/* delete this cmd */
int DelCmd(char *cmd);

/* execute cmd ,find the node by the way of one by one*/
int ExeCMD(char *cmd);

/*show all command ,visite all nodes one by one */
int ShowAllCMD();

#endif

