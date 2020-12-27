#include "MidiDriver.h"
#include "log/Logging.h"
#include "MidiMessage.h"

using midi::MidiDriver;

MidiDriver::MidiDriver()
{
}

MidiDriver::~MidiDriver()
{
}

void MidiDriver::release() {
    releaseInputs();
    releaseOutputs();
}

int MidiDriver::getFirstGloballyEnableInputDevice() const
{
    int total = getMaxInputDevices();
    for (int i = 0; i < total; ++i) {
        if (inputDeviceIsGloballyEnabled(i))
            return i;
    }
    return -1;
}

void MidiDriver::setInputDevicesStatus(const QList<bool> &inputStatuses)
{
    this->inputDevicesEnabledStatuses = inputStatuses;
}

void MidiDriver::setOutputDevicesStatus(const QList<bool> &outputStatuses)
{
    this->outputDevicesEnabledStatuses = outputStatuses;
}

bool MidiDriver::inputDeviceIsGloballyEnabled(int deviceIndex) const
{
    if (deviceIndex >= 0 && deviceIndex < inputDevicesEnabledStatuses.size())
        return inputDevicesEnabledStatuses.at(deviceIndex);

    return false;
}

bool MidiDriver::outputDeviceIsGloballyEnabled(int deviceIndex) const
{
    if (deviceIndex >= 0 && deviceIndex < outputDevicesEnabledStatuses.size())
        return outputDevicesEnabledStatuses.at(deviceIndex);

    return false;
}
