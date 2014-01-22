/*
* CmdOptionList.cpp
*
*  Created on: 2011-12-29
*      Author: OWenT
*
* 应用程序命令处理
*
*/

#include "CmdOptionList.h"

namespace copt
{
    const char* binder::CmdOptionBindBase::ROOT_NODE_CMD = "@Root";

    CmdOptionList::CmdOptionList(): m_pExtParam(NULL)
    {
    }

    CmdOptionList::CmdOptionList(int argv, const char* argc[]): m_pExtParam(NULL)
    {
        for (int i = 0; i < argv; ++ i)
            m_stKeys.push_back(value_type(new CmdOptionValue(argc[i])));
    }

    CmdOptionList::CmdOptionList(const std::vector<std::string>& stCmds): m_pExtParam(NULL)
    {
        std::vector<std::string>::size_type uSize = stCmds.size();
        for (std::vector<std::string>::size_type i = 0; i < uSize; ++ i)
        {
            m_stKeys.push_back(value_type(new CmdOptionValue(stCmds[i].c_str())));
        }
    }


    void CmdOptionList::initKeyValueMap()
    {
        typedef std::map<std::string, value_type> key_map_type;
        typedef std::vector<value_type> keys_type;
        // 已经初始化，跳过
        if (m_pKeyValue.get() != NULL)
            return;

        m_pKeyValue = std::shared_ptr<key_map_type>(new key_map_type());

        keys_type::size_type uLen = (m_stKeys.size() / 2) * 2; // 去除末尾无value的key
        for (keys_type::size_type i = 0; i < uLen; i += 2) 
        {
            (*m_pKeyValue)[m_stKeys[i]->AsString()] = m_stKeys[i + 1];
        }
    }

    void CmdOptionList::Add(const char* strParam)
    {
        m_stKeys.push_back(value_type(new CmdOptionValue(strParam)));
    }

    void CmdOptionList::Clear()
    {
        m_pKeyValue.reset();    // 删除key-value映射
        m_stKeys.clear();       // 删除索引下标映射
        m_stCmdArray.clear();   // 删除指令栈集合
        m_pExtParam = NULL;     // 透传参数置空
    }

    void CmdOptionList::LoadCmdArray(const cmd_array_type& stCmds)
    {
        m_stCmdArray = stCmds;
    }

    void CmdOptionList::AppendCmd(const char* strCmd, std::shared_ptr<binder::CmdOptionBindBase> stBase)
    {
        m_stCmdArray.push_back(std::make_pair(strCmd, stBase));
    }

    void CmdOptionList::PopCmd()
    {
        m_stCmdArray.pop_back();
    }

    const CmdOptionList::cmd_array_type& CmdOptionList::GetCmdArray() const
    {
        return m_stCmdArray;
    }

    CmdOptionList::value_type CmdOptionList::Get(std::string strKey, const char* strDefault)
    {
        value_type pRet = Get(strKey);
        if (pRet.get() == NULL)
            return value_type(new CmdOptionValue(strDefault));
        return pRet;
    }

    CmdOptionList::value_type CmdOptionList::Get(std::string strKey)
    {
        initKeyValueMap();

        std::map<std::string, value_type>::const_iterator itr;
        itr = m_pKeyValue->find(strKey);
        if (itr == m_pKeyValue->end())
            return value_type();
        return itr->second;
    }

    CmdOptionList::value_type CmdOptionList::Get(int iIndex) const
    {
        return m_stKeys[iIndex];
    }

    CmdOptionList::value_type CmdOptionList::Get(size_type iIndex) const
    {
        return m_stKeys[iIndex];
    }

    // 操作符重载，功能和上面一样
    CmdOptionList::value_type CmdOptionList::operator[](int iIndex) const
    {
        return m_stKeys[iIndex];
    }

    CmdOptionList::value_type CmdOptionList::operator[](size_type iIndex) const
    {
        return m_stKeys[iIndex];
    }

    // 获取参数数量
    CmdOptionList::size_type CmdOptionList::GetParamsNumber() const
    {
        return m_stKeys.size();
    }

    // 重置Key-Value映射表
    void CmdOptionList::ResetKeyValueMap()
    {
        m_pKeyValue.reset();
    }

    void CmdOptionList::SetExtParam(void* pParam)
    {
        m_pExtParam = pParam;
    }

    void* CmdOptionList::GetExtParam() const
    {
        return m_pExtParam;
    }
}

