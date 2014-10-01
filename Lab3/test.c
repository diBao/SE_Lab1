

/**************************************************************************************************/
/* Copyright (C) JG14225101, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  test.c                                                               */
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

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

#define debug printf

int results[8] = {1,1,1,1,1,1,1};
char * info[8] =
{
    "test report",
    "TC1 InitCMDList",
    "TC2 DestroyCMDList",
    "TC3 GetScanf",
    "TC4 AddCmd",
    "TC5 DelCmd",
    "TC6 ExeCMD",
    "TC7 ShowAllCMD"
};
int main()
{
    int i;
    int count =0;
    int sum = 7;
    int ret = InitCMDList();
    if(ret == SUCCESS)
    {
        debug("TC1 succ \n");
        results[1] = 0;
        count++;
    }

    ret = DestroyCMDList();
    if(ret == SUCCESS)
    {
        debug("TC2 succ \n");
        results[2] = 0;
        count++;
    }

    ret = GetScanf();
    if(ret == SUCCESS)
    {
        debug("TC3 succ \n");
        results[3] = 0;
        count++;
    }

    ret = AddCmd("","");
    if(ret == SUCCESS)
    {
        debug("TC4 succ \n");
        results[4] = 0;
        count++;
    }

    ret = DelCmd("");
    if(ret == SUCCESS)
    {
        debug("TC5 succ \n");
        results[5] = 0;
        count++;
    }
    ret = ExeCMD("");
    if(ret == SUCCESS)
    {
        debug("TC6 succ \n");
        results[6] = 0;
        count++;
    }

    ret = ShowAllCMD();
    if(ret == SUCCESS)
    {
        debug("TC7 succ \n");
        results[7] = 0;
        count++;
    }

    /* test report */
    printf("test report: correct count %d ,wrong acount %d \n",count,sum-count);
    for(i = 1; i <= 7; i++)
    {
        if(results[i] == 1)
        {
            printf("Testcase Number%d F - %s\n",i,info[i]);
        }
    }
}
