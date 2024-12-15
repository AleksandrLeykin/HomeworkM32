#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/ThatUsesDB.h"


TEST(ThatUsesDB, useConnCase1) {
	//Arrange
	ThatUsesDB server;
	DBConnection cn;
	std::string t_name = "Ivan";
	std::string t_pass = "123";
	//Act
	//cn.m_name = "Grisha"; //error

	//Assert
	std::cout << "ASSERT\n";
	ASSERT_EQ(server.useConnection(cn, t_name, t_pass), 0);	
	EXPECT_NE(server.useConnection(cn, t_name, t_pass), -1);
	std::cout << "EXPECT\n";
}

TEST(ThatUsesDB, openConnCase2) {
	//Arrange
	ThatUsesDB server;
	DBConnection cn;
	//Act
	//cn.flag = false; //error
	//Assert
	ASSERT_TRUE(server.openConnecnion(cn));
	ASSERT_FALSE(!server.openConnecnion(cn));
}

TEST(ThatUsesDB, closeConnCase3) {
	//Arrange
	ThatUsesDB server;
	DBConnection cn;
	//Act(empty for this test)	
	//Assert
	ASSERT_TRUE(server.closeConnection(cn));
	ASSERT_FALSE(!server.closeConnection(cn));
}

class MockDBConnection : public IDBConnection {
public:
	MOCK_METHOD(bool, open, (), (override));
	MOCK_METHOD(bool, close, (), (override));
	MOCK_METHOD(int, execQuery, (const std::string&, const std::string&), (override));
};

TEST(ThatUsesDB, execQueryCase4) {
	//Arrange
	std::string t_name = "Ivan";
	std::string t_pass = "123";
	ThatUsesDB server;
	//создаем мок-объект
	MockDBConnection* mockConn = new MockDBConnection;

	EXPECT_CALL(*mockConn, execQuery).Times(1).WillOnce(::testing::Return(0)); //error Times(2)
	EXPECT_CALL(*mockConn, open).WillOnce(::testing::Return(true));
	EXPECT_CALL(*mockConn, close).WillOnce(::testing::Return(true));

	//Act

	//Assert
	server.useConnection(*mockConn, t_name, t_pass);
	server.openConnecnion(*mockConn);
	server.closeConnection(*mockConn);

	delete mockConn;
}

int main(int argc, char* argv[]) {

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}