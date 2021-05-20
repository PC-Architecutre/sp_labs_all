#include <string>
#include "../../Entities/Headers/question_option.h"
#include "../../Domain/Headers/question_option.h"

using namespace std;

namespace Mappers
{
    class QuestionOptionMapper
    {
        public:
            static Entities::QuestionOptionEntity FromDomainToEntity(Domain::QuestionOption question); 
            static Domain::QuestionOption FromEntityToDomain(Entities::QuestionOptionEntity question); 
    };
}

