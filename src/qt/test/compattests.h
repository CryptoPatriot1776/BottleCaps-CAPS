// Copyright (c) 2009-2016 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Ravencoin Core developers
// Copyright (c) 2025 The Bottlecaps Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CAPS_QT_TEST_COMPATTESTS_H
#define CAPS_QT_TEST_COMPATTESTS_H

#include <QObject>
#include <QTest>

class CompatTests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void bswapTests();
};

#endif // CAPS_QT_TEST_COMPATTESTS_H
