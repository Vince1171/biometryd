#ifndef BIOMETRYD_DEVICES_ONEPLUS3_H_
#define BIOMETRYD_DEVICES_ONEPLUS3_H_

#include <biometry/devices/fingerprint_reader.h>

#include <biometry/identifier.h>
#include <biometry/template_store.h>
#include <biometry/verifier.h>
#include <biometry/operation.h>

namespace biometry
{
namespace devices
{

/// @brief Dummy is a biometry::Device.
class BIOMETRY_DLL_PUBLIC Oneplus3FingerprintReader : public FingerprintReader
{
public:
    //Constructor
    Oneplus3FingerprintReader();

    /// @brief make_descriptor returns a descriptor instance describing a Dummy device;
    static Descriptor::Ptr make_descriptor();
    
    class TemplateStore : public biometry::TemplateStore
    {
    public:
        // From biometry::TemplateStore.
        Operation<SizeQuery>::Ptr size(const biometry::Application& app, const biometry::User& user) override;
        Operation<List>::Ptr list(const biometry::Application& app, const biometry::User& user) override;
        Operation<Enrollment>::Ptr enroll(const biometry::Application& app, const biometry::User& user) override;
        Operation<Removal>::Ptr remove(const biometry::Application& app, const biometry::User& user, biometry::TemplateStore::TemplateId id) override;
        Operation<Clearance>::Ptr clear(const biometry::Application& app, const biometry::User& user) override;
    };

    class Identifier : public biometry::Identifier
    {
    public:
        // From biometry::Identifier.
        biometry::Operation<biometry::Identification>::Ptr identify_user(const biometry::Application& app, const biometry::Reason& reason) override;
    };

    class Verifier : public biometry::Verifier
    {
    public:
        // From biometry::Identifier.
        Operation<Verification>::Ptr verify_user(const Application& app, const User& user, const Reason& reason) override;
    };


};





};
};

#endif // BIOMETRYD_DEVICES_ONEPLUS3_H_
