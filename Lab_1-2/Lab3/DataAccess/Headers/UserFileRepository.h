#ifndef SYS_PROG_2ND_COURSE_UserFILEREPOSITORY_H
#define SYS_PROG_2ND_COURSE_UserFILEREPOSITORY_H
#include "../Abstract/user_repo.h"
#include "../../FileDatabase/Headers/user_db.h"

class UserFileRepository: public  UserRepository {
public:
    UserFileRepository();
    void Add(UserEntity& entity) override;
    void Remove(UserEntity& entity) override;
    void Update(UserEntity& entity) override;
    UserEntity& Get(int Id) override;
    vector<UserEntity>& GetAll() override;
    bool Exists(int Id);
    void Save() override;
private:
    UserFileDB _db;
};


#endif //SYS_PROG_2ND_COURSE_UserFILEREPOSITORY_H
