#include "ara/core/error/error_domain.h"

#include "ara/core/error/exception.h"

namespace ara::core
{
ErrorDomain::~ErrorDomain() noexcept = default;

[[noreturn]] void ErrorDomain::ThrowWithDefaultException(const ErrorCode& error) const
{
    throw Exception(error);
}
} // namespace ara::core
