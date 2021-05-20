#include <string>
#include "Headers/test_mapper.h"

namespace Mappers
{
     Entities::TestEntity TestMapper::FromDomainToEntity(Domain::Test test) 
    {
        Entities::TestEntity entityTest;
        entityTest.Id = test.GetId();
        entityTest.Name = test.GetName();
        entityTest.TimeConstraint = test.GetTimeConstraint();
        return entityTest;
    }

    Domain::Test TestMapper::FromEntityToDomain(Entities::TestEntity test)
    {
        Domain::Test domainTest;
        domainTest.SetId(test.Id);
        domainTest.SetName(test.Name);
        domainTest.SetTimeConstrain(test.TimeConstraint);
        return domainTest;
    }
}

