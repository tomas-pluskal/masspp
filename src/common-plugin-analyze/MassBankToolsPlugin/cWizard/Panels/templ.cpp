/**
 * @file templ
 * @brief Masspp Managerから直接 ini値のやり取りをする際に使う。
 *
 * @author M.Fukuda
 * @date 2013.03.12
 *
 * Copyright(C) 2006-2014 Eisai Co., Ltd. All rights reserved.
 */

#include "templ.hpp"
#include "../rel_stdafx.h"

ParamIniAcc::ParamIniAcc(
	const std::string& _section, 
	const std::string& _paramKey)
	: section(_section)
	, paramKey(_paramKey)
{
	kome::core::MsppManager& msppMgr = kome::core::MsppManager::getInstance();
	mparam = msppMgr.getParameters();
}

template<typename T> T ParamIniAcc::getParam(void) const {return 0;}
template<typename U> void ParamIniAcc::setParam(const U& u) {}

template<> int ParamIniAcc::getParam<int>(void) const {
	return mparam->getInt(section.c_str(), paramKey.c_str(), 0);
} // 特殊化

template<> void ParamIniAcc::setParam<int>(const int& u) {
	mparam->setInt(section.c_str(), paramKey.c_str(), u);
} // 特殊化

template<> std::string ParamIniAcc::getParam<std::string>(void) const {
	std::string rst = mparam->getString(section.c_str(), paramKey.c_str(), "");
	return rst;
}

template<> void ParamIniAcc::setParam<std::string>(const std::string& u) {
	mparam->setString(section.c_str(), paramKey.c_str(), u.c_str());
}
