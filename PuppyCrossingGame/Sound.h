#pragma once
#include <string>
#include <Windows.h>
#include <thread>
#include "mmsystem.h"

class SoundTrack
{
private:
    std::wstring m_file;
    std::wstring m_alias;

public:
    SoundTrack(std::wstring file, std::wstring alias) : m_file(file), m_alias(alias) {}

    void playSound() {
        std::wstring command = L"open " + m_file + L" type waveaudio alias " + m_alias;
        mciSendString(command.c_str(), NULL, 0, NULL);
        command = L"seek " + m_alias + L" to start";
        mciSendString(command.c_str(), NULL, 0, NULL);
        command = L"play " + m_alias;
        mciSendString(command.c_str(), NULL, 0, NULL);
    }
    void playSoundLoop() {
        std::wstring command = L"open " + m_file + L" type waveaudio alias " + m_alias;
        mciSendString(command.c_str(), NULL, 0, NULL);
        command = L"seek " + m_alias + L" to start";
        mciSendString(command.c_str(), NULL, 0, NULL);
        command = L"play " + m_alias + L" repeat";
        mciSendString(command.c_str(), NULL, 0, NULL);
    }
    static void playSound(std::wstring file, std::wstring alias) {
        std::wstring command = L"open " + file + L" type waveaudio alias " + alias;
        mciSendString(command.c_str(), NULL, 0, NULL);
        command = L"seek " + alias + L" to start";
        mciSendString(command.c_str(), NULL, 0, NULL);
        command = L"play " + alias;
        mciSendString(command.c_str(), NULL, 0, NULL);
    }
};