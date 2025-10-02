#pragma once

#include "ara/core/error/error_code.h"

namespace ara::core
{
enum class CoreErrc : ErrorDomain::CodeType
{
    kSuccess = 0,
    kInvalidArgument = 22,
    kOutOfRange = 34,
    kWouldBlock = 11,
    kTryAgain = 35,
    kNoMemory = 12,
    kBusy = 16,
    kNotFound = 2,
    kNotSupported = 95,
    kInvalidState = 2000,
    kInternalError = 2001
};

class CoreErrorDomain final : public ErrorDomain
{
public:
    static constexpr ErrorDomainIdType kId = 0x4152413a636f7265ULL; // "ARA:core"

    constexpr CoreErrorDomain() noexcept : ErrorDomain{kId} {}

    [[nodiscard]] const char* Name() const noexcept override;
    [[nodiscard]] const char* Message(CodeType code) const noexcept override;
    [[noreturn]] void ThrowAsException(const ErrorCode& error) const override;
};

[[nodiscard]] const ErrorDomain& GetCoreErrorDomain() noexcept;
[[nodiscard]] ErrorCode MakeErrorCode(CoreErrc code,
                                      ErrorDomain::SupportDataType data = 0U) noexcept;
} // namespace ara::core
