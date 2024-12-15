#pragma once
#include <iostream>
#include <string>

class IDBConnection {
public:
	IDBConnection() {}
	virtual ~IDBConnection() {}

	virtual bool open() = 0;
	virtual bool close() = 0;
	virtual int execQuery(const std::string&, const std::string&) = 0;
};

class DBConnection : public IDBConnection
{
public:
	DBConnection() {}
	~DBConnection() = default;

	bool open() override {
		if (flag)
			return true;
		else
			return false;
	}

	bool close() override {
		if (!flag)
			return false;
		return true;
	}

	int execQuery(const std::string& name, const std::string& pass) override {
		std::string selectUser = "select name, password from user";
		
		if (m_name == name && m_pass == pass) {
			return 0;
		}
		else {
			return -1;
		}
	}

	//request successful
	std::string m_name = "Ivan";
	std::string m_pass = "123";

	bool flag = true;
};