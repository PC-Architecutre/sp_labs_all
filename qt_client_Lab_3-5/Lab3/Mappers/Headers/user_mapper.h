#include <string>
#include "../../Entities/Headers/user.h"
#include "../../Domain/Headers/user.h"

using namespace std;

namespace Mappers
{
    class UserMapper
    {
        public:
            static Entities::UserEntity FromDomainToEntity(Domain::User user); 
            static Domain::User FromEntityToDomain(Entities::UserEntity user); 
    };
}
