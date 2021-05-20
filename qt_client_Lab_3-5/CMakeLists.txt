cmake_minimum_required(VERSION 3.17)
project(test_qt)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Sql Network)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql Qt::Network)

add_executable(${PROJECT_NAME} main.cpp window.cpp resultwindow.cpp choosetestwidget.cpp testwindow.cpp Lab3/Controllers/test_controller.cpp
        Lab3/DataAccess/FileRepositories/QuestionFileRepository.cpp Lab3/DataAccess/FileRepositories/QuestionOptionFileRepository.cpp Lab3/DataAccess/FileRepositories/TestFileRepository.cpp Lab3/DataAccess/FileRepositories/TestResultFileRepository.cpp Lab3/DataAccess/FileRepositories/TestTypeFileRepository.cpp Lab3/DataAccess/FileRepositories/UnitOfWorkFileDB.cpp Lab3/DataAccess/FileRepositories/UserFileRepository.cpp
        Lab3/Domain/test.cpp Lab3/Domain/test_result.cpp Lab3/Domain/test_type.cpp Lab3/Domain/question.cpp Lab3/Domain/question_option.cpp Lab3/Domain/user.cpp
        Lab3/FileDatabase/question_db.cpp Lab3/FileDatabase/question_option_db.cpp Lab3/FileDatabase/test_db.cpp Lab3/FileDatabase/test_result_db.cpp Lab3/FileDatabase/test_type_db.cpp Lab3/FileDatabase/user_db.cpp
        Lab3/Mappers/question_mapper.cpp Lab3/Mappers/question_option_mapper.cpp Lab3/Mappers/test_mapper.cpp Lab3/Mappers/test_result_mapper.cpp Lab3/Mappers/test_type_mapper.cpp Lab3/Mappers/user_mapper.cpp
        Lab3/Services/TestResultService.cpp Lab3/Services/TestService.cpp aboutpage.cpp selectuser.cpp Lab3/Services/UserService.cpp userresults.cpp arrangeusersbyscore.cpp arrangeusersbyscore.h choosetestforuserarrangement.cpp Lab3/DataAccess/SqlRepositories/TestSqlRepository.cpp Lab3/DataAccess/SqlRepositories/Headers/TestSqlRepository.h Lab3/DataAccess/SqlRepositories/UserSqlRepository.cpp  Lab3/DataAccess/SqlRepositories/QuestionSqlRepository.cpp Lab3/DataAccess/SqlRepositories/QuestionOptionSqlRepository.cpp  Lab3/DataAccess/SqlRepositories/TestResultSqlRepository.cpp Lab3/DataAccess/SqlRepositories/Headers/UserSqlRepository.h Lab3/DataAccess/SqlRepositories/Headers/TestResultSqlRepository.h Lab3/DataAccess/SqlRepositories/UnitOfWorkSqlDB.cpp Lab3/DataAccess/SqlRepositories/Headers/UnitOfWorkSqlDB.h
        Lab3/DataAccess/SqlRepositories/TestTypeSqlRepository.cpp Lab3/Controllers/test_controller_local.cpp Lab3/Controllers/test_controller_local.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
