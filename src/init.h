// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Ravencoin Core developers
// Copyright (c) 2025 The Bottlecaps Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CAPS_INIT_H
#define CAPS_INIT_H

#include <string>

class CScheduler;

class CWallet;

namespace boost
{
    class thread_group;
} // namespace boost

void StartShutdown();
void StartRestart();
bool ShutdownRequested();

/** Interrupt threads */
void Interrupt(boost::thread_group &threadGroup);

void Shutdown();

//!Initialize the logging infrastructure
void InitLogging();

//!Parameter interaction: change current parameters depending on various rules
void InitParameterInteraction();

/** Initialize caps core: Basic context setup.
 *  @note This can be done before daemonization. Do not call Shutdown() if this function fails.
 *  @pre Parameters should be parsed and config file should be read.
 */
bool AppInitBasicSetup();

/**
 * Initialization: parameter interaction.
 * @note This can be done before daemonization. Do not call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitBasicSetup should have been called.
 */
bool AppInitParameterInteraction();

/**
 * Initialization sanity checks: ecc init, sanity checks, dir lock.
 * @note This can be done before daemonization. Do not call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitParameterInteraction should have been called.
 */
bool AppInitSanityChecks();

/**
 * Lock caps core data directory.
 * @note This should only be done after daemonization. Do not call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitSanityChecks should have been called.
 */
bool AppInitLockDataDirectory();

/**
 * Caps core main initialization.
 * @note This should only be done after daemonization. Call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitLockDataDirectory should have been called.
 */
bool AppInitMain(boost::thread_group &threadGroup, CScheduler &scheduler);
void PrepareShutdown();

/** The help message mode determines what help message to show */
enum HelpMessageMode
{
    HMM_CAPSD,
    HMM_CAPS_QT
};

/** Help for options shared between UI and daemon (for -help) */
std::string HelpMessage(HelpMessageMode mode);

/** Returns licensing information (for -version) */
std::string LicenseInfo();

#endif // CAPS_INIT_H
