#include <string>
#include "../../Entities/Headers/question.h"
#include "../../Domain/Headers/question.h"

using namespace std;

namespace Mappers
{
    class QuestionMapper
    {
        public:
            static Entities::QuestionEntity FromDomainToEntity(Domain::Question question); 
            static Domain::Question FromEntityToDomain(Entities::QuestionEntity question); 
    };
}
