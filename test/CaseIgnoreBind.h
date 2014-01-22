#ifndef _TEST_CASEIGNORE_BIND_H_
#define _TEST_CASEIGNORE_BIND_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif


#include <cstdio>
#include "CmdOption.h"

void bind_ci_cmd_print(copt::callback_param par)
{
    puts("ci: do nothing! - free func without parameter\n");
}

void bind_ci_cmd_print2(copt::callback_param par, double d)
{
    printf("ci: Free Fun B2 Params Num: %d, d => %lf\n", static_cast<int>(par.GetParamsNumber()), d);
}

void bind_ci_cmd_print3(copt::callback_param par, double d, int i)
{
    printf("ci: Free Fun B3 Params Num: %d, i => %d, d => %lf\n", static_cast<int>(par.GetParamsNumber()), i, d);
}

void bind_ci_cmd_init(){

    copt::CmdOptionCI::ptr_type stOpt = copt::CmdOptionCI::Create();

    stOpt->BindHelpCmd("-h, --help")->SetHelpMsg("Help (CI):");
    stOpt->BindCmd("p, print", bind_ci_cmd_print);

    stOpt->BindCmd("pd, printd", bind_ci_cmd_print2, 1.5);
    stOpt->BindCmd("pdi, printdi", bind_ci_cmd_print3, 3.5, 105)->SetHelpMsg("Cmd Ignore Case printdi");

    stOpt->Start("-H 1 2 3 5 pDi 4 5 p PD"); 
}

#endif
