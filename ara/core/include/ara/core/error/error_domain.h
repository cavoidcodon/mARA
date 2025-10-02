#pragma once

#include <cstdint>

namespace ara::core
{
class ErrorCode;

using ErrorDomainIdType = std::uint64_t;

class ErrorDomain
{
public:
    using CodeType = std::int32_t;
    using SupportDataType = std::uint32_t;

    constexpr explicit ErrorDomain(ErrorDomainIdType id) noexcept : id_{id} {}
    virtual ~ErrorDomain() noexcept;

    [[nodiscard]] constexpr ErrorDomainIdType Id() const noexcept { return id_; }

    [[nodiscard]] virtual const char* Name() const noexcept = 0;
    [[nodiscard]] virtual const char* Message(CodeType code) const noexcept = 0;
    [[noreturn]] virtual void ThrowAsException(const ErrorCode& error) const = 0;

    [[nodiscard]] bool operator==(const ErrorDomain& rhs) const noexcept { return id_ == rhs.id_; }
    [[nodiscard]] bool operator!=(const ErrorDomain& rhs) const noexcept { return !(*this == rhs); }

protected:
    [[noreturn]] void ThrowWithDefaultException(const ErrorCode& error) const;

private:
    ErrorDomainIdType id_;
};
} // namespace ara::core
