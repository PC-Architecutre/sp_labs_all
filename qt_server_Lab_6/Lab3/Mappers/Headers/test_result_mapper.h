#include <string>
#include "../../Entities/Headers/test_result.h"
#include "../../Domain/Headers/test_result.h"

using namespace std;

namespace Mappers
{
    class TestResultMapper
    {
        public:
            static Entities::TestResultEntity FromDomainToEntity(Domain::TestResult question); 
            static Domain::TestResult FromEntityToDomain(Entities::TestResultEntity question); 
    };
}
