#include <string>
#include "Headers/test_type_mapper.h"

namespace Mappers
{
     Entities::TestTypeEntity TestTypeMapper::FromDomainToEntity(Domain::TestType testType) 
    {
        Entities::TestTypeEntity entityTestType;
        entityTestType.Id = testType.GetId();
        entityTestType.Name = testType.GetType();
        return entityTestType;
    }

    Domain::TestType TestTypeMapper::FromEntityToDomain(Entities::TestTypeEntity testType)
    {
        Domain::TestType domainTestType;
        domainTestType.SetId(testType.Id);
        domainTestType.SetType(testType.Name);
        return domainTestType;
    }
}

