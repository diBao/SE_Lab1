
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
/*  DESCRIPTION           :  This is a test program                                    */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Baodi(JG14225101), 2014/09/21
 *
 */

#define CMD_MAX_LEN     128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"
#include "menu.h"


main()
{
    /*cmd line begins*/
    while(1)
    {
        tLinkTable *head = Initialize();
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
        if(p->handler != NULL)
        {
            (p->handler)();
        }
    }  
}






