#include <string>
#include "../../Entities/Headers/test.h"
#include "../../Domain/Headers/test.h"

using namespace std;

namespace Mappers
{
    class TestMapper
    {
        public:
            static Entities::TestEntity FromDomainToEntity(Domain::Test question); 
            static Domain::Test FromEntityToDomain(Entities::TestEntity question); 
    };
}
