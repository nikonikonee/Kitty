#include "Referee.h"
#include "Logger.h" //Add inside of .cpp to avoid compiling issues



void Referee::Bypass() {
    //Threads
    Utils::ASM::Ret(Utils::getAbsoluteAddressReferee(Globals::Offsets::Referee::ThreadOne));
    Utils::ASM::Ret(Utils::getAbsoluteAddressReferee(Globals::Offsets::Referee::ThreadTwo));
    Utils::ASM::Ret(Utils::getAbsoluteAddressReferee(Globals::Offsets::Referee::ThreadThree));
    Utils::ASM::Ret(Utils::getAbsoluteAddressReferee(Globals::Offsets::Referee::ThreadFour));
    Utils::ASM::Ret(Utils::getAbsoluteAddressReferee(Globals::Offsets::Referee::ThreadFive));
    Utils::ASM::Ret(Utils::getAbsoluteAddressReferee(Globals::Offsets::Referee::ThreadSix));
    Logger::Log(clr::yellow, "[Referee] 1/2");

    //IDA
    Utils::ASM::Ret(Utils::getAbsoluteAddressReferee(Globals::Offsets::Referee::IDAOne));
    Utils::ASM::Ret(Utils::getAbsoluteAddressReferee(Globals::Offsets::Referee::IDATwo));
    Utils::ASM::Ret(Utils::getAbsoluteAddressReferee(Globals::Offsets::Referee::IDAThree));
    Logger::Log(clr::green, "[Referee] 2/2");
}