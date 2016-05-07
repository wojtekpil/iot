/*
 * SQLiteDatabase.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_DATABASE_SQLITEDATBASE_SQLITEDATABASE_H_
#define LIB_IOT_MODULES_DATABASE_SQLITEDATBASE_SQLITEDATABASE_H_

#include "../Database.h"
#include <sqlite3.h>

namespace iot {

class SQLiteDatabase: public Database {
private:
	static void debugMessage(std::string msg);
protected:
	sqlite3 *_db=nullptr;
public:
	SQLiteDatabase();
	static int callback(void* NotUsed, int argc, char **argv, char **azColName);
	virtual int32_t connect(std::string conf);
	virtual int32_t execute(std::string query);
	virtual int32_t select(std::string query, databaseCallback callback);
	virtual int32_t select(std::string query, databaseCallback callback,
			void* callbackArg);
	virtual ~SQLiteDatabase();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_DATABASE_SQLITEDATBASE_SQLITEDATABASE_H_ */
