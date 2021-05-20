#include <string>
#include "Headers/user_mapper.h"

namespace Mappers
{
     Entities::UserEntity UserMapper::FromDomainToEntity(Domain::User user) 
    {
        Entities::UserEntity entityUser;
        entityUser.Id = user.GetId();
        entityUser.Name = user.GetName();
        return entityUser;
    }

    Domain::User UserMapper::FromEntityToDomain(Entities::UserEntity user)
    {
        Domain::User domainUser;
        domainUser.SetId(user.Id);
        domainUser.SetName(user.Name);
        return domainUser;
    }
}
