#ifndef _TEST_DELAYBIND_H_
#define _TEST_DELAYBIND_H_


#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <iostream>
#include <cstdio>
#include "CmdOption.h"

// 延迟绑定初始化
bool delay_print(copt::callback_param par) {
    if (par.GetParamsNumber() > 0)
        puts(par[0]->AsString());
    return false;
}

void delay_init(copt::callback_param par, copt::CmdOption* stChild) {
    printf("Delay Init Params Num: %d\n", static_cast<int>(par.GetParamsNumber()));
    stChild->BindCmd("-p, --print", delay_print);
}

void delay_bind() {
    puts("延迟初始化子绑定");
    copt::CmdOption::ptr_type f = copt::CmdOption::Create();
    std::shared_ptr<copt::CmdOption> pc = copt::CmdOption::Create();
    pc->BindCmd("@OnCallFunc", delay_init, pc.get());   // 设置初始化函数
    // 注意这里不能传入*pc
    // 因为如果传入引用，子CmdOption结构会被复制，然后作为f的子命令，而传入并延迟绑定的是pc的指针
    f->BindChildCmd("-c, --child", pc);                       

    f->Start("-c a b c -p \"Delay Init Child Option With \\\"delay_print\\\".\"");

    puts("延迟初始化子绑定 测试完成\n");
}

#endif
