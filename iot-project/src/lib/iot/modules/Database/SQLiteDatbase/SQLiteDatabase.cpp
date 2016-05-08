/*
 * SQLiteDatabase.cpp
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#include "SQLiteDatabase.h"
#include "../../Logger/LoggerFactory.h"
#include "../../Exception/Exception.h"
#include <sstream>
namespace iot {
SQLiteDatabase::SQLiteDatabase() {


}

void SQLiteDatabase::debugMessage(std::string msg) {
	LoggerFactory lf;
	std::shared_ptr<Logger> logger = lf.createProduct();
	logger->debug(msg);
}

int SQLiteDatabase::callback(void* data, int argc, char **argv, char **azColName) {
#ifdef DB_DEBUG
	int i=0;
	for(i=0; i<argc; i++){
		std::stringstream ss;
		ss<<azColName[i]<<"="<< (argv[i] ? argv[i] : "NULL")<<std::endl;
		SQLiteDatabase::debugMessage(ss.str());
	}
#endif
   	return 0;
}
int32_t SQLiteDatabase::connect(std::string conf) {
	if(sqlite3_open(conf.c_str(), &_db) != SQLITE_OK) {
		throw Exception("Nie udalo sie otworzyc bazy danych: " + conf);
	}
#ifdef DB_DEBUG
	SQLiteDatabase::debugMessage("Database opened succesfully");
	std::stringstream ss;
	ss<<"Threadsafty: "<<(sqlite3_threadsafe()?"on!":"off!")<<std::endl;
	SQLiteDatabase::debugMessage(ss.str());
#endif
	return 0;
}

int32_t SQLiteDatabase::execute(std::string query) {
	char *zErrMsg = 0;
	if(sqlite3_exec(_db, query.c_str(), SQLiteDatabase::callback, 0, &zErrMsg) != SQLITE_OK) {
		throw Exception("Unable to run query \n\r:" +
					query + "\n\r Error: " +  std::string(zErrMsg));
	}
#ifdef DB_DEBUG
	std::stringstream ss;
	ss<<"Executing: "<<query<<std::endl;
	SQLiteDatabase::debugMessage(ss.str());
#endif
	return 0;
}
int32_t SQLiteDatabase::select(std::string query, databaseCallback callback) {
	char *zErrMsg = 0;
	if(sqlite3_exec(_db, query.c_str(), callback, NULL, &zErrMsg) != SQLITE_OK) {
		throw Exception("Unable to run query \n\r:" +
                          query + "\n\r Error: " +  std::string(zErrMsg));
	}
	return 0;
}

int32_t SQLiteDatabase::select(std::string query, databaseCallback callback, void* callbackArg) {
	char *zErrMsg = 0;
	if(sqlite3_exec(_db, query.c_str(), callback, callbackArg, &zErrMsg) != SQLITE_OK) {
		throw Exception("Unable to run query \n\r:" +
                          query + "\n\r Error: " +  std::string(zErrMsg));
	}
	return 0;
}

SQLiteDatabase::~SQLiteDatabase(){
	sqlite3_close(_db);
}

} /* namespace iot */
