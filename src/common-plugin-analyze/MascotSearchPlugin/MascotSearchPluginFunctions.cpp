/**
 * @file MascotSearchPluginFunctions.cpp
 * @brief implementation of plug-in functions
 *
 * @author Parry
 * @date 2012.01.16
 * 
 * Copyright(C) 2006-2014 Shimadzu Corporation All rights reserved.
 */


#include "stdafx.h"
#include "MascotSearchPluginFunctions.h"          
#include "MascotSearchManager.h"


using namespace kome::mascot;


#include <crtdbg.h>
#ifdef _DEBUG
    #define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )
    #define malloc( s ) _malloc_dbg( s, _NORMAL_BLOCK, __FILE__, __LINE__ )
#endif    // _DEBUG



// get PMF search engine
kome::objects::Variant getPmfSearchEngine( kome::objects::Parameters* params ) {
	// manager
	MascotSearchManager& mgr = MascotSearchManager::getInstance();

	// return value
	kome::objects::Variant ret;
	ret.prim.pt = mgr.getPmfEngine();
	ret.type = kome::objects::Variant::OTHER;

	return ret;
}

// get MIS search engine
kome::objects::Variant getMisSearchEngine( kome::objects::Parameters* params ) {
	// manager
	MascotSearchManager& mgr = MascotSearchManager::getInstance();

	// return value
	kome::objects::Variant ret;
	ret.prim.pt = mgr.getMisEngine();
	ret.type = kome::objects::Variant::OTHER;

	return ret;
}

// on update settings
kome::objects::Variant onUpdateSettings( kome::objects::Parameters* ) {
	// return value
	kome::objects::Variant ret;

	// manager
	MascotSearchManager& mgr = MascotSearchManager::getInstance();
	MascotManager& mascotMgr = MascotManager::getInstance();

	// clear databases
	mgr.getPmfEngine()->clearDatabases();
	mgr.getMisEngine()->clearDatabases();

	// As the Mascot server settings may have changed, logout from the server.
	if (!mascotMgr.logout())
	{
		LOG_ERROR( FMT( "Failed to logout from the Mascot server.") );
	}

	return ret;
}

// log out of the Mascot server
kome::objects::Variant logOutOfMascotServer( kome::objects::Parameters* ) {
	// return value
	kome::objects::Variant ret;

	// manager
	MascotManager& mgr = MascotManager::getInstance();

	// As the Mascot server settings may have changed, logout from the server.
	if (!mgr.logout())
	{
		LOG_ERROR( FMT( "Failed to logout from the Mascot server.") );
	}

	return ret;
}

// get PMF databases
kome::objects::Variant getPmfDbs( kome::objects::Parameters* params ) {
	// return value
	kome::objects::Variant ret;

	// vector
	kome::objects::Variant var = params->getValue( "enumeration" );
	std::vector< kome::plugin::SettingsValue::EnumItem >* enumeration
		= (std::vector< kome::plugin::SettingsValue::EnumItem >*)var.prim.pt;
	if( enumeration == NULL ) {
		LOG_ERROR( FMT( "Failed to get the enumeration item for the database list" ) );
		return ret;
	}

	// manager
	MascotSearchManager& mgr = MascotSearchManager::getInstance();

	// enumerations
	MascotSearchEngineBase* engine = mgr.getPmfEngine();
	const unsigned int num = engine->getNumberOfDatabases();

	if( num > 0 ) {
		enumeration->resize( num );
		for( unsigned int i = 0; i < num; i++ ) {
			std::string db = engine->getDatabase( i );
			( *enumeration )[ i ].name = db;
			( *enumeration )[ i ].value = db;
		}
	}

	return ret;
}

// get PMF taxonomies
kome::objects::Variant getPmfTaxonomies( kome::objects::Parameters* params ) {
	// return value
	kome::objects::Variant ret;

	// vector
	kome::objects::Variant var = params->getValue( "enumeration" );
	std::vector< kome::plugin::SettingsValue::EnumItem >* enumeration
		= (std::vector< kome::plugin::SettingsValue::EnumItem >*)var.prim.pt;
	if( enumeration == NULL ) {
		LOG_ERROR( FMT( "Failed to get the enumeration item for the taxonomy list" ) );
		return ret;
	}

	// manager
	MascotSearchManager& mgr = MascotSearchManager::getInstance();

	// enumerations
	MascotSearchEngineBase* engine = mgr.getPmfEngine();
	const unsigned int num = engine->getNumberOfTaxonomies();

	if( num > 0 ) {
		enumeration->resize( num );
		for( unsigned int i = 0; i < num; i++ ) {
			std::string taxonomy = engine->getTaxonomy( i );
			( *enumeration )[ i ].name = taxonomy;
			( *enumeration )[ i ].value = taxonomy;
		}
	}

	return ret;
}

// get MIS databases
kome::objects::Variant getMisDbs( kome::objects::Parameters* params ) {
	// return value
	kome::objects::Variant ret;

	// vector
	kome::objects::Variant var = params->getValue( "enumeration" );
	std::vector< kome::plugin::SettingsValue::EnumItem >* enumeration
		= (std::vector< kome::plugin::SettingsValue::EnumItem >*)var.prim.pt;
	if( enumeration == NULL ) {
		LOG_ERROR( FMT( "Failed to get the enumeration item for the database list" ) );
		return ret;
	}

	// manager
	MascotSearchManager& mgr = MascotSearchManager::getInstance();

	// enumerations
	MascotSearchEngineBase* engine = mgr.getMisEngine();
	const unsigned int num = engine->getNumberOfDatabases();

	if( num > 0 ) {
		enumeration->resize( num );
		for( unsigned int i = 0; i < num; i++ ) {
			std::string db = engine->getDatabase( i );
			( *enumeration )[ i ].name = db;
			( *enumeration )[ i ].value = db;
		}
	}

	return ret;
}

// get MIS taxonomies
kome::objects::Variant getMisTaxonomies( kome::objects::Parameters* params ) {
	// return value
	kome::objects::Variant ret;

	// vector
	kome::objects::Variant var = params->getValue( "enumeration" );
	std::vector< kome::plugin::SettingsValue::EnumItem >* enumeration
		= (std::vector< kome::plugin::SettingsValue::EnumItem >*)var.prim.pt;
	if( enumeration == NULL ) {
		LOG_ERROR( FMT( "Failed to get the enumeration item for the taxonomy list" ) );
		return ret;
	}

	// manager
	MascotSearchManager& mgr = MascotSearchManager::getInstance();

	// enumerations
	MascotSearchEngineBase* engine = mgr.getMisEngine();
	const unsigned int num = engine->getNumberOfTaxonomies();

	if( num > 0 ) {
		enumeration->resize( num );
		for( unsigned int i = 0; i < num; i++ ) {
			std::string taxonomy = engine->getTaxonomy( i );
			( *enumeration )[ i ].name = taxonomy;
			( *enumeration )[ i ].value = taxonomy;
		}
	}

	return ret;
}

// check modifications
kome::objects::Variant checkModifications( kome::objects::Parameters* params ) {
	// return value
	kome::objects::Variant ret;
	ret.type = kome::objects::Variant::STRING;
	ret.setString( "" );

	// settings
	kome::objects::SettingParameterValues* settings = kome::plugin::PluginCallTool::getSettingValues( params );
	if( settings == NULL ) {
		ret.setString( "Failed to get the parameters." );
		return ret;
	}

	// modifications
	std::string msg = MascotSearchEngineBase::checkMods( settings );
	ret.setString( msg.c_str() );

	return ret;
}
