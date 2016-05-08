/*
 * Database.h
 *
 *  Created on: 7 maj 2016
 *      Author: wojtek
 */

#ifndef LIB_IOT_MODULES_DATABASE_DATABASE_H_
#define LIB_IOT_MODULES_DATABASE_DATABASE_H_

#include <string>

namespace iot {

typedef int32_t (*databaseCallback)(void*, /* Data provided in the 4th argument of sqlite3_exec() */
	int, /* The number of columns in row */
	char**, /* An array of strings representing fields in the row */
	char** /* An array of strings representing column names */
);

/**
 * Abstract class for database communication
 */

class Database {
public:
	Database();
	virtual int32_t connect(std::string conf) = 0;
	virtual int32_t execute(std::string query) = 0;
	virtual int32_t select(std::string query, databaseCallback callback)= 0;
	virtual int32_t select(std::string query, databaseCallback callback,
			void* callbackArg)=0;
	virtual ~Database();
};

} /* namespace iot */

#endif /* LIB_IOT_MODULES_DATABASE_DATABASE_H_ */
