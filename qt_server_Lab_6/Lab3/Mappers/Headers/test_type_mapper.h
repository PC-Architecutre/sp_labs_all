#include <string>
#include "../../Entities/Headers/test_type.h"
#include "../../Domain/Headers/test_type.h"

using namespace std;

namespace Mappers
{
    class TestTypeMapper
    {
        public:
            static Entities::TestTypeEntity FromDomainToEntity(Domain::TestType question); 
            static Domain::TestType FromEntityToDomain(Entities::TestTypeEntity question); 
    };
}

