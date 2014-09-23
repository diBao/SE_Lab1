
/**************************************************************************************************/
/* Copyright (C) JG14225101, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  test.c                                                               */
/*  PRINCIPAL AUTHOR      :  Baodi                                                                */
/*  SUBSYSTEM NAME        :  test                                                                 */
/*  MODULE NAME           :  test                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/21                                                           */
/*  DESCRIPTION           :  This is a test program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Baodi(JG14225101), 2014/09/21
 *
 */


#include <stdio.h>
#include <string.h>
#include "menu.h"


main()
{
    ttLinkTable* head = NULL;
    head = tCreateLinkTable();
    AddCmd(head,"help","this is help cmd",Help);
    AddCmd(head,"version","menu program v1.1",Version);
    AddCmd(head,"writer", "Show the information of writer",Writer);
    
    /*User can use AddCmd to add their own command*/

    MenuBegin(head);
}






