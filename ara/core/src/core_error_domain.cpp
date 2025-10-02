#include "ara/core/error/core_error_domain.h"

#include "ara/core/error/exception.h"

namespace ara::core
{
const char* CoreErrorDomain::Name() const noexcept
{
    return "ara::core";
}

const char* CoreErrorDomain::Message(CodeType code) const noexcept
{
    switch (static_cast<CoreErrc>(code))
    {
    case CoreErrc::kSuccess:
        return "success";
    case CoreErrc::kInvalidArgument:
        return "invalid argument";
    case CoreErrc::kOutOfRange:
        return "out of range";
    case CoreErrc::kWouldBlock:
        return "operation would block";
    case CoreErrc::kTryAgain:
        return "try again";
    case CoreErrc::kNoMemory:
        return "out of memory";
    case CoreErrc::kBusy:
        return "resource busy";
    case CoreErrc::kNotFound:
        return "resource not found";
    case CoreErrc::kNotSupported:
        return "operation not supported";
    case CoreErrc::kInvalidState:
        return "invalid state";
    case CoreErrc::kInternalError:
        return "internal error";
    }

    return "unknown ara::core error";
}

void CoreErrorDomain::ThrowAsException(const ErrorCode& error) const
{
    ThrowWithDefaultException(error);
}

const ErrorDomain& GetCoreErrorDomain() noexcept
{
    static const CoreErrorDomain instance{};
    return instance;
}

ErrorCode MakeErrorCode(CoreErrc code, ErrorDomain::SupportDataType data) noexcept
{
    return ErrorCode{static_cast<ErrorDomain::CodeType>(code), GetCoreErrorDomain(), data};
}
} // namespace ara::core
