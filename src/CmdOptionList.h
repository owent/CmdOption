#ifndef _CMDOPTIONLIST_H_
#define _CMDOPTIONLIST_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/*
 * CmdOptionList.h
 *
 *  Created on: 2011-12-29
 *      Author: OWenT
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
    class CmdOptionList;
    typedef CmdOptionList& callback_param;

    namespace binder
    {
        struct unspecified {};

        // 绑定器接口
        class CmdOptionBindBase: public std::enable_shared_from_this<CmdOptionBindBase>
        {
        protected:
            static const char* ROOT_NODE_CMD;

            std::string m_strHelpMsg;
            virtual ~CmdOptionBindBase(){}
        public:
            // 定义参数类型
            typedef callback_param param_type;

            virtual void operator()(callback_param arg) = 0;

            // 获取绑定器的帮助信息
            virtual std::string GetHelpMsg(const char* strPre = "")
            {
                return strPre + m_strHelpMsg;
            }

            // 设置绑定器的帮助信息
            virtual std::shared_ptr<CmdOptionBindBase> SetHelpMsg(const char* strHelp)
            {
                m_strHelpMsg = strHelp;
                return shared_from_this();
            }

            // 增加绑定器的帮助信息
            virtual std::shared_ptr<CmdOptionBindBase> AddHelpMsg(const char* strHelp)
            {
                m_strHelpMsg += strHelp;
                return shared_from_this();
            }
        };
    }


    class CmdOptionList
    {
    public:
        // 类型定义
        typedef std::vector< std::pair<std::string, std::shared_ptr<binder::CmdOptionBindBase> > > cmd_array_type;   // 大小类型
        typedef std::shared_ptr<CmdOptionValue> value_type;     // 值类型
        typedef std::vector<value_type>::size_type size_type;   // 大小类型

    protected:
        
        std::shared_ptr<std::map<std::string, std::shared_ptr<CmdOptionValue> > > m_pKeyValue;
        std::vector<std::shared_ptr<CmdOptionValue> > m_stKeys;
        cmd_array_type m_stCmdArray;
        void* m_pExtParam;

        // 初始化Key-Value映射（用于第一次调用Get(key)时调用）
        void initKeyValueMap();

    public:

        // 构造函数
        CmdOptionList();
        CmdOptionList(int argv, const char* argc[]);
        CmdOptionList(const std::vector<std::string>& stCmds);

        // 增加选项
        void Add(const char* strParam);

        // 删除全部选项
        void Clear();

        // 读取指令集
        void LoadCmdArray(const cmd_array_type& stCmds);

        // 添加指令
        void AppendCmd(const char* strCmd, std::shared_ptr<binder::CmdOptionBindBase> stBase);

        // 移除末尾指令
        void PopCmd();

        const cmd_array_type& GetCmdArray() const;

        // 根据键值获取选项指针，如果不存在返回默认值
        value_type Get(std::string strKey, const char* strDefault);

        // 根据键值获取选项指针，如果不存在返回空指针
        value_type Get(std::string strKey);

        // 根据下标获取选项指针，如果不存在会出现运行时错误
        value_type Get(size_type iIndex) const;

        // 操作符重载，功能和上面一样
        value_type operator[](size_type iIndex) const;

        // 获取参数数量
        size_type GetParamsNumber() const;

        // 重置Key-Value映射表
        // # 在第一次调用Get(字符串[, 默认值])后会建立映射表
        // # 如果这之后Add了参数而没有调用此函数重置映射表
        // # 新的变量将不会进入映射表
        void ResetKeyValueMap();

        // 设置透传参数列表
        void SetExtParam(void* pParam);

        // 获取透传参数列表
        void* GetExtParam() const;
    };
}

#endif /* _CMDOPTIONLIST_H_ */
