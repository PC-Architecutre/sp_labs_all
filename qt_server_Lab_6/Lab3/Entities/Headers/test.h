#ifndef TEST_H
#define TEST_H
#include <string>

using namespace std;

namespace Entities 
{
class TestEntity
{
    public:
        int Id;
        int TestTypeId;
        string Name;
        int TimeConstraint;
};
}

#endif // TEST_H
