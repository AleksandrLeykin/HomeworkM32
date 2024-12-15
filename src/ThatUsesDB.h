#pragma once
#include "DBConnection.h"

class ThatUsesDB {
public:
	ThatUsesDB() {}
	~ThatUsesDB() = default;

	bool openConnecnion(IDBConnection& conn) {
		return conn.open();
	}

	int useConnection(IDBConnection& conn, const std::string& name, const std::string& pass) {
		return conn.execQuery(name, pass);
	}

	bool closeConnection(IDBConnection& conn) {
		return conn.close();
	}
};
