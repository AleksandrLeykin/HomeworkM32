cmake_minimum_required(VERSION 3.26.3 FATAL_ERROR)

set(PROJECT_NAME mygTest)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} 
		src/main.cpp 
		src/DBConnection.h 
		src/ThatUsesDB.h
)

# ����������� ������� ������������
add_executable(test_DB 
		test/test_DB.cpp		
)

# �������� �������� ��� ��������� �������
target_include_directories(test_DB PRIVATE 
		"${CMAKE_CURRENT_BINARY_DIR}/src"
)

# ������� �������� ���� � ������������ gtest
add_subdirectory(external/googtest)
target_link_libraries(test_DB PRIVATE gtest gtest_main)
target_link_libraries(test_DB PRIVATE gmock gmock_main)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
