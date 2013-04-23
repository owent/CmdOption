#ifndef _CMDOPTIONLIST_H_
#define _CMDOPTIONLIST_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/*
 * CmdOptionList.h
 *
 *  Created on: 2011-12-29
 *      Author: owentou(欧文韬)
 *
 * 应用程序命令处理
 *
 */

#include <string>
#include <map>
#include <vector>

#include "smart_ptr.h"
#include "CmdOptionValue.h"

namespace copt
{
    class CmdOptionList
    {
    protected:
        std::shared_ptr<std::map<std::string, std::shared_ptr<CmdOptionValue> > > m_pKeyValue;
        std::vector<std::shared_ptr<CmdOptionValue> > m_stKeys;

        // 初始化Key-Value映射（用于第一次调用Get(key)时调用）
        void initKeyValueMap();

    public:
        // 类型定义
        typedef std::shared_ptr<CmdOptionValue> value_type;     // 值类型
        typedef std::vector<value_type>::size_type size_type;   // 大小类型

        // 构造函数
        CmdOptionList();
        CmdOptionList(int argv, const char* argc[]);
        CmdOptionList(const std::vector<std::string>& stCmds);

        // 增加选项
        void Add(const char* strParam);

        // 删除全部选项
        void Clear();

        // 根据键值获取选项指针，如果不存在返回默认值
        value_type Get(std::string strKey, const char* strDefault);

        // 根据键值获取选项指针，如果不存在返回空指针
        value_type Get(std::string strKey);

        // 根据下标获取选项指针，如果不存在会出现运行时错误
        value_type Get(int iIndex) const;

        // 操作符重载，功能和上面一样
        value_type operator[](int iIndex) const;

        // 获取参数数量
        size_type GetParamsNumber() const;

        // 重置Key-Value映射表
        // # 在第一次调用Get(字符串[, 默认值])后会建立映射表
        // # 如果这之后Add了参数而没有调用此函数重置映射表
        // # 新的变量将不会进入映射表
        void ResetKeyValueMap();
    };
}

#endif /* _CMDOPTIONLIST_H_ */
