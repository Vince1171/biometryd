#include <biometry/devices/oneplus3.h>

namespace
{
struct Oneplus3FingerprintReaderDescriptor : public biometry::Device::Descriptor
{
    //instancie le device
    //un simple copier coller avec changement de nom devrait etre suffisant pour le op3
    std::shared_ptr<biometry::Device> create(const biometry::util::Configuration&) override
    {
        return std::make_shared<biometry::devices::Oneplus3FingerprintReader>();
    }

    std::string name() const override
    {
        return "Oneplus3FingerprintReader";
    }

    std::string author() const override
    {
        return "Vincent Franchomme (franchomme.vincent@gmail.com)";
    }

    std::string description() const override
    {
        return "Specific implementation of biometry::Device for Oneplus3. It's surely crap...";
    }
};
}

biometry::Device::Descriptor::Ptr biometry::devices::Oneplus3FingerprintReader::make_descriptor()
{
    return std::make_shared<Oneplus3FingerprintReaderDescriptor>();
}
