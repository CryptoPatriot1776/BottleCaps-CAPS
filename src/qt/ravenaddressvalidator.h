// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Ravencoin Core developers
// Copyright (c) 2025 The Bottlecaps Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CAPS_QT_CAPSADDRESSVALIDATOR_H
#define CAPS_QT_CAPSADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class CapsAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CapsAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Caps address widget validator, checks for a valid caps address.
 */
class CapsAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CapsAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // CAPS_QT_CAPSADDRESSVALIDATOR_H
